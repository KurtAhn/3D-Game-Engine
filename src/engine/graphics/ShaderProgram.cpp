#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() :
    program(glCreateProgram()) {}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(program);
    std::cout << "Program deleted." << std::endl;
    ASSERT(glIsProgram(program) == GL_FALSE,
           "ShaderProgram not deleted properly.");
}

bool ShaderProgram::isLinked() const {
    return linked;
}

void ShaderProgram::addShader(GLuint shader, GLenum type) {
    ASSERT(glIsProgram(program) == GL_TRUE,
           "Shader program is not a shader program?!");

    ASSERT(glIsShader(shader) == GL_TRUE,
           "Argument 'shader' is not an existing shader object.");

    try {
        switch (type) {
        case GL_VERTEX_SHADER:
            if (vert) throw GLException("Vertex shader already exists.");
            vert = shader;
            ASSERT(vert,
                   "'vert' member of the ShaderProgram is null.");
            break;
        case GL_FRAGMENT_SHADER:
            if (frag) throw GLException("Fragment shader already exists.");
            frag = shader;
            ASSERT(frag,
                   "'frag' member of the ShaderProgram is null.");
            break;
        case GL_GEOMETRY_SHADER:
            if (geom) throw GLException("Geometry shader already exists.");
            geom = shader;
            ASSERT(geom,
                   "'geom' member of the ShaderProgram is null.");
            break;
        case GL_TESS_CONTROL_SHADER:
            if (geom) throw GLException("Geometry shader already exists.");
            tesc = shader;
            ASSERT(vert,
                   "'tesc' member of the ShaderProgram is not set.");
            break;
        case GL_TESS_EVALUATION_SHADER:
            if (tese) throw GLException("Tessellation evaluation shader already exists.");
            tese = shader;
            ASSERT(tese,
                   "'tese' member of the ShaderProgram is null.");
            break;
        }
    } catch (GLException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    glAttachShader(program, shader);
    glDeleteShader(shader);
}

void ShaderProgram::link() {
    ASSERT(glIsProgram(program) == GL_TRUE,
           "Shader program is not a shader program?!");

    GLint status;
    try {
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if (status == GL_FALSE)
            throw GLException("Shader program linking failed.");

        glValidateProgram(program);
        glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
        if (status == GL_FALSE)
            throw GLException("Shader program validation failed.");
    } catch (GLException e) {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &status);
        GLchar *infoLog = new GLchar[status];
        glGetProgramInfoLog(program, status, nullptr, infoLog);
        std::cerr << infoLog << std::endl;
        delete[] infoLog;
        linked = false;
        exit(EXIT_FAILURE);
    }

    linked = true;
}

void ShaderProgram::use() {
    ASSERT(glIsProgram(program) == GL_TRUE,
           "Shader program is not a program?!");

    glUseProgram(program);
}



void ShaderProgram::setUniform(const std::string &name, const GLint &i) {
    glUniform1i(glGetUniformLocation(program, name.c_str()), i);
}

void ShaderProgram::setUniform(const std::string &name, const GLuint &u) {
    glUniform1ui(glGetUniformLocation(program, name.c_str()), u);
}

void ShaderProgram::setUniform(const std::string &name, const GLfloat &f) {
    glUniform1f(glGetUniformLocation(program, name.c_str()), f);
}

void ShaderProgram::setUniform(const std::string &name, const GLdouble &d) {
    glUniform1d(glGetUniformLocation(program, name.c_str()), d);
}

void ShaderProgram::setUniform(const std::string &name, const GLVector2 &v) {
    glUniform2f(glGetUniformLocation(program, name.c_str()), v.x, v.y);
}

void ShaderProgram::setUniform(const std::string &name, const GLVector3 &v) {
    glUniform3f(glGetUniformLocation(program, name.c_str()), v.x, v.y, v.z);
}

void ShaderProgram::setUniform(const std::string &name, const GLVector4 &v) {
    glUniform4f(glGetUniformLocation(program, name.c_str()), v.x, v.y, v.z, v.w);
}

void ShaderProgram::setUniform(const std::string &name, const GLMatrix3 &m) {
    GLfloat a[] {
        m[0][0], m[1][0], m[2][0],
        m[0][1], m[1][1], m[2][1],
        m[0][2], m[1][2], m[2][2]
    };

    glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()),
                1,
                GL_FALSE,
                a);
}

void ShaderProgram::setUniform(const std::string &name, const GLMatrix4 &m) {
    GLfloat a[] {
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3]
    };

    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()),
                1,
                GL_FALSE,
                a);
}


void ShaderProgram::setUniform(const std::string &name, const Camera &c) {
    setUniform((name + ".zNear").c_str(), c.getZNear());
    setUniform((name + ".zFar").c_str(), c.getZFar());
    setUniform((name + ".fov").c_str(), c.getFov());
    setUniform((name + ".aspect").c_str(), c.getAspect());
    setUniform((name + ".scale").c_str(), c.getScale());
    setUniform((name + ".position").c_str(), c.getPosition());
    setUniform((name + ".xAxis").c_str(), c.getXAxis());
    setUniform((name + ".yAxis").c_str(), c.getYAxis());
    setUniform((name + ".zAxis").c_str(), c.getZAxis());
}

void ShaderProgram::setUniform(const std::string &name, const Drawable &d) {
    setUniform((name + ".transform").c_str(), *(d.getTransform()));
    setUniform((name + ".material").c_str(), *(d.getMaterial()));
}

void ShaderProgram::setUniform(const std::string &name, const Material &m) {
    //sampler
    //shininess
    //specularity
    //diffuseness
    //color
}
