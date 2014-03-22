#include "MaterialCache.h"

MaterialCache::MaterialCache(const std::string &folderPath) {
    load(folderPath);
}

MaterialCache::~MaterialCache() {
    //for (const auto &m : cache)
    //    delete m.second;
}

void MaterialCache::load(const std::string &folderPath) {
    namespace fs = boost::filesystem;

    try {
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath))
            throw IOException(folderPath + " is not a valid directory");

        fs::directory_iterator last;

        for (fs::directory_iterator it(folderPath); it != last; ++it) {
            if (fs::is_regular_file(it->status())) {
                auto filePath = it->path();
                Cache<Material>::put(filePath.filename().string(),
                                     loadMTL(filePath.string()));
                std::cout << filePath.filename().string()
                          << " loaded." << std::endl;
            }
        }
    } catch (IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Material *MaterialCache::loadMTL(const boost::filesystem::path &filePath) {
    //std::ifstream file(filePath.string());

    try {
        //if (!file.good())
        //    throw IOException("Cannot open " + filePath.string() + ".");
        if (filePath.extension().string() != ".mat")
            throw IOException("Mesh file must end with extension '.mat'");
    } catch (const IOException &e) {
        LOG_ERROR(e);
        return nullptr;
    }

    XMLParser parser(filePath.string());

    auto materialNode = parser.getDocument()->first_node("material");

    return new Material(boost::lexical_cast<float>(materialNode->first_node("shininess")->
                        first_attribute("value")->value()),
                        boost::lexical_cast<float>(materialNode->first_node("specularity")->
                        first_attribute("value")->value()),
                        boost::lexical_cast<float>(materialNode->first_node("diffuseness")->
                        first_attribute("value")->value()),
                        GLVector4(boost::lexical_cast<float>(materialNode->first_node("color")->
                                  first_attribute("r")->value()),
                                  boost::lexical_cast<float>(materialNode->first_node("color")->
                                  first_attribute("g")->value()),
                                  boost::lexical_cast<float>(materialNode->first_node("color")->
                                  first_attribute("b")->value()),
                                  boost::lexical_cast<float>(materialNode->first_node("color")->
                                  first_attribute("a")->value())
                                  )
                        );

}
