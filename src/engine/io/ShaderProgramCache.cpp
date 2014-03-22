#include "ShaderProgramCache.h"

ShaderProgramCache::ShaderProgramCache(const std::string &folderPath,
                                       const std::string &xmlPath) :
    parser(xmlPath) {

    load(folderPath);
}

ShaderProgramCache::~ShaderProgramCache() {
    //for (const auto &p : cache)
    //    delete p.second;
}

void ShaderProgramCache::load(const std::string &folderPath) {
    std::set<std::string> shaderFileNames;
    using Shader = std::pair<std::string, GLuint>;
    std::unordered_map<std::string, GLuint> shaders;

    xml_document<> *document = parser.getDocument();
    //print(std::cout, *document);

    xml_node<> *programsNode = document->first_node("programs");

    for (xml_node<> *programNode = programsNode->first_node("program");
            programNode != nullptr;
            programNode = programNode->next_sibling("program")) {

        std::string programName = programNode->first_attribute("name")->value();
        //std::string programActive = programNode->first_attribute("active")->value();

        //std::cout << "Program name: " << programName << " Active? " << programActive << std::endl;

        ShaderProgram *program = new ShaderProgram;
        cache.emplace(programName, program);

        //xml_node<> *shaderNode;
        for (xml_node<> *shaderNode = programNode->first_node("shader");
                shaderNode != nullptr;
                shaderNode = shaderNode->next_sibling("shader")) {
            std::string shaderFilePath = folderPath + shaderNode->value();
            std::string shaderType = shaderNode->first_attribute("type")->value();

            //std::cout << "  Shader name: " << shaderName << " Type: " << shaderType << std::endl;

            auto type = getShaderType(shaderType);

            GLuint shader;

            if (shaderFileNames.insert(shaderFilePath).second) {
                shader = glCreateShader(type);
                shaders.emplace(shaderFilePath, shader);
                loadAndCompileShader(shader, shaderFilePath);
                //std::cout << shaderNode->next_sibling("shader") << std::endl;
                //print(std::cout, *document);
            } else {
                shader = shaders.find(shaderFilePath)->second;
            }

            program->addShader(shader, type);

        }

        program->link();
        //temp
        //std::cout << "program linked correctly." << std::endl;

        //if (programActive.compare("true") == 0) {
            //activeProgram = program;
            //std::cout << "program active." << std::endl;
        //} if (!activeProgram)
        //    activeProgram = program;
    }
}

GLenum ShaderProgramCache::getShaderType(const std::string &type) {
    try {
        if (type == "vert")
            return GL_VERTEX_SHADER;
        if (type == "frag")
            return GL_FRAGMENT_SHADER;
        if (type == "geom")
            return GL_GEOMETRY_SHADER;
        if (type == "tesc")
            return GL_TESS_CONTROL_SHADER;
        if (type == "tese")
            return GL_TESS_EVALUATION_SHADER;

        throw std::logic_error(type + " is not a valid shader type.");
    } catch (std::logic_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return 0;
}

void ShaderProgramCache::loadAndCompileShader(const GLuint &shader,
                                              const std::string &filePath) {
    // GL error-check
    GLint status;

    try {
        // open source
        std::ifstream file(filePath);
        if (!file)
            throw IOException(filePath + " is not a valid file.");

        std::ostringstream buffer;
        buffer << file.rdbuf();
        auto cstr = buffer.str().c_str();
        glShaderSource(shader, 1, &cstr, nullptr);

        // compile shader
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
            throw GLException("Shader compilation failed.");

        file.close();
    } catch (IOException &e) {
        LOG_ERROR(e);
        RETHROW;
    } catch (GLException &e) {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &status);
        GLchar *infoLog = new GLchar[status];
        glGetShaderInfoLog(shader, status, nullptr, infoLog);
        std::cerr << infoLog << std::endl;
        delete[] infoLog;
        LOG_ERROR(e);
        RETHROW;
    }
}
