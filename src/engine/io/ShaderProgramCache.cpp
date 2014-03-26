#include "ShaderProgramCache.h"

ShaderProgramCache::ShaderProgramCache(XMLNode *const &node) :
    parser(node->first_node("ShaderList")->value()) {
    load(node->first_node("Directory")->value());
}

ShaderProgramCache::~ShaderProgramCache() {}

void ShaderProgramCache::load(const std::string &folderPath) {

//#define LOAD_SHADERS_DEBUG
    std::set<std::string> shaderFileNames;
    using Shader = std::pair<std::string, GLuint>;
    std::unordered_map<std::string, GLuint> shaders;

    xml_document<> *document = parser.getDocument();

    ASSERT_NOT_NULL(document);
#ifdef LOAD_SHADERS_DEBUG
    print(std::cout, *document);
#endif // LOAD_SHADERS_DEBUG
    xml_node<> *programsNode = document->first_node("programs");

    ASSERT_NOT_NULL(programsNode);

    for (xml_node<> *programNode = programsNode->first_node("program");
         programNode != nullptr;
         programNode = programNode->next_sibling("program")) {

        std::string programName = programNode->first_attribute("name")->value();

    #ifdef LOAD_SHADERS_DEBUG
        std::cout << "Program name: " << programName << std::endl;
    #endif // LOAD_SHADERS_DEBUG

        ShaderProgram *program = new ShaderProgram;
        cache.emplace(programName, program);

        for (xml_node<> *shaderNode = programNode->first_node("shader");
                shaderNode != nullptr;
                shaderNode = shaderNode->next_sibling("shader")) {

            std::string shaderFilePath = folderPath + shaderNode->value();
            std::string shaderType = shaderNode->first_attribute("type")->value();
        #ifdef LOAD_SHADERS_DEBUG
            std::cout << "  Shader name: " << shaderFilePath << " Type: " << shaderType << std::endl;
        #endif // LOAD_SHADERS_DEBUG
            auto type = getShaderType(shaderType);

            GLuint shader;

            if (shaderFileNames.insert(shaderFilePath).second) {
                shader = glCreateShader(type);
                shaders.emplace(shaderFilePath, shader);
                loadAndCompileShader(shader, shaderFilePath);
            #ifdef LOAD_SHADERS_DEBUG
                std::cout << shaderNode->next_sibling("shader") << std::endl;
                print(std::cout, *document);
            #endif // LOAD_SHADERS_DEBUG
            } else {
                shader = shaders.find(shaderFilePath)->second;
            }

            program->addShader(shader, type);

        }

        program->link();
    }

#ifdef LOAD_SHADERS_DEBUG
#undef LOAD_SHADERS_DEBUG
#endif // LOAD_SHADERS_DEBUG
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
