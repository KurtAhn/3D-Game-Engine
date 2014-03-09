#include "MeshCache.h"

MeshCache::MeshCache(const std::string &path) :
    Cache<Mesh*>(path) {

    load(path);
}

MeshCache::~MeshCache() {

}

void MeshCache::load(const std::string &path) {
    namespace fs = boost::filesystem;

    try {
        if (!fs::exists(path) || !fs::is_directory(path))
            throw IOException(path + " is not a valid directory");

        fs::directory_iterator last;

        for (fs::directory_iterator it(path); it != last; ++it) {
            if (fs::is_regular_file(it->status())) {
                loadObj(it->path().string());
                //std::cout << it->path().string() + " loaded." << std::endl;
            }
        }
    } catch (IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}


void MeshCache::save(const std::string &path) {

}

void MeshCache::loadObj(const std::string &obj) {
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
    std::vector<vec3> normals;
    std::vector<vec2> texCoords;

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
            vertices.push_back(Vertex{x, y, z, 0, 0, 0, -1, -1});
        } else if (item == "vt") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            texCoords.push_back(vec2{x, y});
        } else if (item == "vn") {
            iss >> item;
            float x = boost::lexical_cast<float>(item);
            iss >> item;
            float y = boost::lexical_cast<float>(item);
            iss >> item;
            float z = boost::lexical_cast<float>(item);
            normals.push_back(vec3{x, y, z});
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
                    vertices.at(v).normal = normals.at(vn);
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
                        vertices.at(v).normal = normals.at(vn);
                    } else {
                        //std::cout << item.substr(a + 1) << std::endl;
                        vt = boost::lexical_cast<unsigned>(item.substr(a + 1)) - 1;
                    }

                    indices.push_back(v);
                    vertices.at(v).texCoord = texCoords.at(vt);
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
