#include "ResourceManager.h"

ResourceManager *ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() {
    using namespace FileSystem;
    createDirectory(DIR_DATA);
    createDirectory(DIR_GRAPHICS);
    createDirectory(DIR_SHADERS);
    createDirectory(DIR_MESHES);
    createDirectory(DIR_MATERIALS);
    createDirectory(DIR_PHYSICS);
    createDirectory(DIR_SOUNDS);
    createDirectory(DIR_WORLD);
    createDirectory(DIR_SETTINGS);
    createDirectory(DIR_SAVES);
}

ResourceManager::~ResourceManager() {}

ResourceManager *ResourceManager::createInstance() {
    try {
        if (instance)
            throw std::runtime_error("'instance' member already exists.");
        instance = new ResourceManager;
    } catch (const std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return instance;
}

ResourceManager *ResourceManager::getInstance() {
    return instance;
}

void ResourceManager::destroy() {
    delete instance;
}

void ResourceManager::setSaveDirectory(const std::string &saveDirectory) {
    this->saveDirectory = saveDirectory;
    FileSystem::createDirectory(saveDirectory);
}

World *ResourceManager::loadWorld() {
    World *world = new World;

    world->setCamera(new Camera);

    return world;
}



Graphics *ResourceManager::loadGraphics() {
    Graphics *graphics = new Graphics;

    // load shaders and shader programs
    loadPrograms(graphics);
    loadMeshes(graphics);
    return graphics;
}

/**
 * Load all shader programs listed in the "programs.pl" file and determine
 * the active shader program for the "graphics" object.
 */
void ResourceManager::loadPrograms(Graphics *const &graphics) {
    ShaderMap shaders = loadShaders();
    ProgramMap programs;

    std::ifstream file(FILE_PROGRAM_LIST);

    if (!file.good())
        return;

    std::string item;
    std::string activeProgram;

    file >> item;
    while (file) {
        if (*--item.end() == ':') {
            ShaderProgram *program = new ShaderProgram;

            std::string programName;

            if (*item.begin() == '#') {
                programName = item.substr(1, item.length() - 2);
                activeProgram = programName;
            } else
                programName = item.substr(0, item.length() - 1);

            while (file >> item && *--item.end() != ':') {
                auto shader = shaders.find(item);

                if (shader != shaders.end())
                    program->addShader(shader->second.first,
                                      shader->second.second);
            }

            program->link();

            programs.insert(ProgramPair(programName, program));
        }
    }

    graphics->setPrograms(programs);
    graphics->setActiveProgram(activeProgram);
}

ShaderMap ResourceManager::loadShaders() {
    using ShaderPair = std::pair<std::string, Shader>;

    ShaderMap shaders;

    std::ifstream file(FILE_SHADER_LIST);

    if (!file.good())
        return shaders;

    std::vector<GLuint> verts, frags, geoms, tescs, teses;

    std::string item;

    file >> item;
    while (file) {
        if (*--item.end() == ':') {
            GLenum type = item == "vert:" ? GL_VERTEX_SHADER :
                          item == "frag:" ? GL_FRAGMENT_SHADER :
                          item == "geom:" ? GL_GEOMETRY_SHADER :
                          item == "tesc:" ? GL_TESS_CONTROL_SHADER :
                                            GL_TESS_EVALUATION_SHADER;

            while (file >> item && *--item.end() != ':') {
                GLuint shader = glCreateShader(type);

                shaders.insert(ShaderPair(item,
                               Shader(shader, type)));

                std::ifstream sourceFile(DIR_SHADERS + item);
                if (!sourceFile.good())
                    throw IOException(DIR_SHADERS + item + " does not exist.");

                std::string line;
                std::string source;
                while (getline(sourceFile, line)) {
                    source += line + "\n";
                }

                //std::cout << source << std::endl;

                auto sourceFileC = source.c_str();

                glShaderSource(shader, 1, &sourceFileC, nullptr);

                GLint status;

                try {
                    glCompileShader(shader);
                    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

                    if (status == GL_FALSE)
                        throw GLException("Shader compilation failed.");
                } catch (const GLException &e) {
                    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &status);
                    GLchar *infoLog = new GLchar[status];
                    glGetShaderInfoLog(shader, status, nullptr, infoLog);
                    std::cerr << infoLog << std::endl;
                    LOG_ERROR(e);
                    delete[] infoLog;
                    exit(EXIT_FAILURE);
                } // END try
            } // END while
        } // END if
    } // END while

    return shaders;
} // END loadShaders



void ResourceManager::loadMeshes(Graphics *const &graphics) {
    MeshMap meshes;

    std::ifstream file(FILE_MESH_LIST);

    if (!file.good())
        return;

    std::string line;
    while (file >> line)
        loadShapesFromObj(meshes, line);

    graphics->setMeshes(meshes);

    //for (const auto &mp : meshes)
    //    std::cout << mp.first << std::endl;
}

void ResourceManager::loadShapesFromObj(MeshMap &meshes, const std::string &obj) {
    try {
        if (obj.substr(obj.find(".")) != ".obj")
            throw IOException("Mesh file must end with extension '.obj'");
    } catch (const IOException &e) {
        LOG_ERROR(e);
        return;
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned> indices;
    std::vector<vec3> normals;
    std::vector<vec2> texCoords;

    std::ifstream file(DIR_MESHES + obj);
    if (!file.good())
        return;

    std::string line;
    Mesh *m = nullptr;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string item;
        iss >> item;

        if (item == "o") {
            if (m) {
                /*for (auto i = vertices.cbegin(); i != vertices.cend(); ++i)
                    std::cout << i->position.x << " "
                              << i->position.y << " "
                              << i->position.z << std::endl;*/
                m->addVertices(vertices, indices);
                vertices.clear();
                indices.clear();
                normals.clear();
                texCoords.clear();
            }

            m = new Mesh;
            iss >> item;
            meshes.insert(MeshPair(obj + item, m));
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
        /*for (auto i = vertices.cbegin(); i != vertices.cend(); ++i)
            std::cout << i->position.x << " "
                      << i->position.y << " "
                      << i->position.z << "   "
                      << i->normal.x << " "
                      << i->normal.y << " "
                      << i->normal.z << "   "
                      << i->texCoord.x << " "
                      << i->texCoord.y << std::endl;*/
        m->addVertices(vertices, indices);
    }
} // END loadShapes

