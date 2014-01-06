#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "Common.h"
#include "Exception.h"
#include "Camera.h"

class ShaderProgram {
public:
    ShaderProgram();
    virtual ~ShaderProgram();

    bool isLinked();

    void addShader(GLuint shader, GLenum type);
    void link();
    void use();

    void setUniform(const std::string &name, const GLint &i);
    void setUniform(const std::string &name, const GLuint &u);
    void setUniform(const std::string &name, const GLfloat &f);
    void setUniform(const std::string &name, const GLdouble &d);
    void setUniform(const std::string &name, const glm::vec2 &v);
    void setUniform(const std::string &name, const glm::vec3 &v);
    void setUniform(const std::string &name, const glm::vec4 &v);
    void setUniform(const std::string &name, const glm::mat3 &m);
    void setUniform(const std::string &name, const glm::mat4 &m);

    void setUniform(const std::string &name, const Camera &c);
protected:
    bool linked;

    const GLuint program = 0;
    GLuint vert = 0;
    GLuint frag = 0;
    GLuint geom = 0;
    GLuint tesc = 0;
    GLuint tese = 0;
private:

};

#endif // SHADERPROGRAM_H
