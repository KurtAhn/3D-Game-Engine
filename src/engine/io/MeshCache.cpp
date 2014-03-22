#include "MeshCache.h"

MeshCache::MeshCache(const std::string &folderPath) {
    load(folderPath);
}

MeshCache::~MeshCache() {
    //for (const auto &m : cache)
    //    delete m.second;
}

void MeshCache::load(const std::string &folderPath) {
    namespace fs = boost::filesystem;

    try {
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath))
            throw IOException(folderPath + " is not a valid directory");

        fs::directory_iterator last;

        for (fs::directory_iterator it(folderPath); it != last; ++it) {
            if (fs::is_regular_file(it->status())) {
                auto filePath = it->path();
                Cache<Mesh>::put(filePath.filename().string(),
                                 loadOBJ(filePath));
                std::cout << filePath.filename().string()
                          << " loaded." << std::endl;
            }
        }
    } catch (IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

/*
void MeshCache::loadOBJ(const std::string &obj) {
    std::ifstream file(obj);

    try {
        if (!file.good())
            throw IOException("Cannot open " + obj + ".");
        if (obj.substr(obj.find(".")) != ".obj")
            throw IOException("Mesh file must end with extension '.obj'");
    } catch (const IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned> indices;
    std::vector<GLVector3> normals;
    std::vector<GLVector2> texCoords;

    std::string line;
    Mesh *m = nullptr;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string item;
        iss >> item;

        if (item == "o") {
            if (m) {
                for (auto i = vertices.cbegin(); i != vertices.cend(); ++i)
                //std::cout << i->position.x << " "
                //          << i->position.y << " "
                //          << i->position.z << std::endl;
                m->addVertices(vertices, indices);
                vertices.clear();
                indices.clear();
                normals.clear();
                texCoords.clear();
            }

            m = new Mesh;
            iss >> item;
            Cache<Mesh*>::put(obj + item, m);
            //cache.insert(MeshPair(obj + item, m));
        } else if (item == "v") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            iss >> item;
            float z = boost::lexical_cast<float>(item);
            vertices.push_back(
                Vertex{GLVector3(x, y, z),
                        GLVector3(0, 0, 0),
                        GLVector2(-1, -1)});
        } else if (item == "vt") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            texCoords.push_back(GLVector2{x, y});
        } else if (item == "vn") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            iss >> item;
            float z = boost::lexical_cast<float>(item);
            normals.push_back(GLVector3(x, y, z));
        } else if (item == "f") {
            for (int i = 0; iss >> item && i != 4; ++i) {
                //std::cout << item << std::endl;

                if (i == 3) {
                    indices.push_back(indices.at(indices.size() - 3));
                    indices.push_back(indices.at(indices.size() - 2));
                }

                size_t a;
                if ((a = item.find("//")) != std::string::npos) {
                    //std::cout << item.substr(0, a) << std::endl;
                    //std::cout << item.substr(a + 2) << std::endl;

                    int v = boost::lexical_cast<unsigned>(item.substr(0, a)) - 1;
                    int vn = boost::lexical_cast<unsigned>(item.substr(a + 2)) - 1;

                    indices.push_back(v);
                    vertices.at(v).setNormal(normals.at(vn));
                } else {
                    a = item.find("/");
                    int v = boost::lexical_cast<unsigned>(item.substr(0, a)) - 1;

                    int vt;

                    size_t b;
                    if ((b = item.find("/", a + 1)) != std::string::npos) {
                        //std::cout << b << std::endl;
                        //std::cout << item.substr(a + 1, b - a - 1) << std::endl;
                        vt = boost::lexical_cast<unsigned>(item.substr(a + 1, b - a - 1)) - 1;

                        //std::cout << item.substr(b + 1) << std::endl;
                        int vn = boost::lexical_cast<unsigned>(item.substr(b + 1)) - 1;
                        vertices.at(v).setNormal(normals.at(vn));
                    } else {
                        //std::cout << item.substr(a + 1) << std::endl;
                        vt = boost::lexical_cast<unsigned>(item.substr(a + 1)) - 1;
                    }

                    indices.push_back(v);
                    vertices.at(v).setTexCoord(texCoords.at(vt));
                } // END else
            } // END for
        } // END else if
    } // END while

    if (m) {
        //for (auto i = vertices.cbegin(); i != vertices.cend(); ++i)
        //    std::cout << i->position.x << " "
        //              << i->position.y << " "
        //              << i->position.z << "   "
        //              << i->normal.x << " "
        //              << i->normal.y << " "
        //              << i->normal.z << "   "
        //              << i->texCoord.x << " "
        //              << i->texCoord.y << std::endl;
        m->addVertices(vertices, indices);
    }
} // END loadShapes
*/

Mesh *MeshCache::loadOBJ(const boost::filesystem::path &filePath) {
//#define LOAD_OBJ_DEBUG

    std::ifstream file(filePath.string());

    try {
        if (!file.good())
            throw IOException("Cannot open " + filePath.string() + ".");
        if (filePath.extension().string() != ".obj")
            throw IOException("Mesh file must end with extension '.obj'");
    } catch (const IOException &e) {
        LOG_ERROR(e);
        return nullptr;
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned> indices;
    std::vector<GLVector3> normals;
    std::vector<GLVector2> texCoords;

    std::string line;
    Mesh *m = new Mesh;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string item;
        iss >> item;

        if (item == "v") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            iss >> item;
            float z = boost::lexical_cast<float>(item);
            vertices.push_back(
                Vertex{GLVector3(x, y, z),
                        GLVector3(0, 0, 0),
                        GLVector2(-1, -1)});
        } else if (item == "vt") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            texCoords.push_back(GLVector2(x, y));
        } else if (item == "vn") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            iss >> item;
            float z = boost::lexical_cast<float>(item);
            normals.push_back(GLVector3(x, y, z));
        } else if (item == "f") {
            for (int i = 0; iss >> item && i != 4; ++i) {
            #ifdef LOAD_OBJ_DEBUG
                std::cout << item << std::endl;
            #endif
                if (i == 3) {
                    indices.push_back(indices.at(indices.size() - 3));
                    indices.push_back(indices.at(indices.size() - 2));
                }

                size_t a;
                if ((a = item.find("//")) != std::string::npos) {
                #ifdef LOAD_OBJ_DEBUG
                    std::cout << item.substr(0, a) << std::endl;
                    std::cout << item.substr(a + 2) << std::endl;
                #endif
                    int v = boost::lexical_cast<unsigned>(item.substr(0, a)) - 1;
                    int vn = boost::lexical_cast<unsigned>(item.substr(a + 2)) - 1;

                    indices.push_back(v);
                    vertices.at(v).setNormal(normals.at(vn));
                } else {
                    a = item.find("/");
                    int v = boost::lexical_cast<unsigned>(item.substr(0, a)) - 1;

                    int vt;

                    size_t b;
                    if ((b = item.find("/", a + 1)) != std::string::npos) {
                    #ifdef LOAD_OBJ_DEBUG
                        std::cout << b << std::endl;
                        std::cout << item.substr(a + 1, b - a - 1) << std::endl;
                    #endif
                        vt = boost::lexical_cast<unsigned>(item.substr(a + 1, b - a - 1)) - 1;
                    #ifdef LOAD_OBJ_DEBUG
                        std::cout << item.substr(b + 1) << std::endl;
                    #endif
                        int vn = boost::lexical_cast<unsigned>(item.substr(b + 1)) - 1;
                        vertices.at(v).setNormal(normals.at(vn));
                    } else {
                    #ifdef LOAD_OBJ_DEBUG
                        std::cout << item.substr(a + 1) << std::endl;
                    #endif
                        vt = boost::lexical_cast<unsigned>(item.substr(a + 1)) - 1;
                    }

                    indices.push_back(v);
                    vertices.at(v).setTexCoord(texCoords.at(vt));
                } // END else
            } // END for
        } // END else if
    } // END while

#ifdef LOAD_OBJ_DEBUG
    for (auto i = vertices.cbegin(); i != vertices.cend(); ++i)
        std::cout << i->getPosition().x << " "
                  << i->getPosition().y << " "
                  << i->getPosition().z << "   "
                  << i->getNormal().x << " "
                  << i->getNormal().y << " "
                  << i->getNormal().z << "   "
                  << i->getTexCoord().x << " "
                  << i->getTexCoord().y << std::endl;
#endif

    m->addVertices(vertices, indices);

    return m;
#ifdef LOAD_OBJ_DEBUG
    #undef LOAD_OBJ_DEBUG
#endif
}
