#include "ShaderProgramCache.h"

ShaderProgramCache::ShaderProgramCache(
    const std::string &path, const std::string &xml) :
    Cache<ShaderProgram*>(path),
    parser(xml),
    activeProgram(nullptr) {

    load(path);
}

ShaderProgramCache::~ShaderProgramCache() {}

void ShaderProgramCache::load(const std::string &path) {
    std::set<std::string> shaderFileNames;
    using Shader = std::pair<std::string, GLuint>;
    std::unordered_map<std::string, GLuint> shaders;

    xml_document<> *document = parser.getDocument();
    print(std::cout, *document);

    for (xml_node<> *programNode = document->first_node("programs")->first_node("program");
            programNode != nullptr;
            programNode = programNode->next_sibling()) {
        std::string programName = programNode->first_attribute("name")->value();
        std::string programActive =
            programNode->first_attribute("active")->value();
        //temp
        std::cout << programName << std::endl;

        ShaderProgram *program = new ShaderProgram;
        cache.emplace(programName, program);

        for (xml_node<> *shaderNode = programNode->first_node("shader");
                shaderNode != nullptr;
                shaderNode = shaderNode->next_sibling()) {
            std::string shaderFileName = shaderNode->value();
            //temp
            std::cout << shaderFileName << std::endl;

            auto type = getShaderType(shaderNode->first_attribute("type")->value());
            GLuint shader;

            if (shaderFileNames.insert(shaderFileName).second) {
                shader = glCreateShader(type);
                shaders.emplace(shaderFileName, shader);
                loadAndCompileShader(shader, path + shaderFileName);
            } else {
                shader = shaders.find(shaderFileName)->second;
            }

            program->addShader(shader, type);
        }

        program->link();
        //temp
        std::cout << "program linked correctly." << std::endl;

        if (programActive.compare("true") == 0) {
            activeProgram = program;
            std::cout << "program active." << std::endl;
        } if (!activeProgram)
            activeProgram = program;
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

void ShaderProgramCache::loadAndCompileShader(
    const GLuint &shader, const std::string &path) {
    // GL error-check
    GLint status;

    try {
        // open source
        std::ifstream file(path);
        if (!file)
            throw IOException(path + " is not a valid file.");

        // load source line by line
        std::string source;
        std::string line;
        while (getline(file, line))
            source += line + "\n";

        auto sourceCstr = source.c_str();
        glShaderSource(shader, 1, &sourceCstr, nullptr);

        // compile shader
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
            throw GLException("Shader compilation failed.");

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

void ShaderProgramCache::save(const std::string &path) {
    // no impelementation
}
