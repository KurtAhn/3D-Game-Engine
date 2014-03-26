#include "ImageCache.h"

ImageCache::ImageCache(XMLNode *const &node) {
    load(node->first_node("Directory")->value());
}

ImageCache::~ImageCache() {}

void ImageCache::load(const std::string &folderPath) {
   namespace fs = boost::filesystem;

    try {
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath))
            throw IOException(folderPath + " is not a valid directory");

        fs::directory_iterator last;

        for (fs::directory_iterator it(folderPath); it != last; ++it) {
            if (fs::is_regular_file(it->status())) {
                auto filePath = it->path();

                Cache<Image>::put(filePath.filename().string(),
                                    new Image(filePath.string()));

                std::cout << filePath.filename().string()
                          << " loaded." << std::endl;
            }
        }
    } catch (IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}
