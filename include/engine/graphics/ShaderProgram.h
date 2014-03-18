#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "GraphicsCommon.h"
#include "Exception.h"
#include "Camera.h"
#include "Material.h"
#include "Drawable.h"

class ShaderProgram {
public:
    ShaderProgram();
    ShaderProgram(const ShaderProgram &src) = delete;
    ShaderProgram &operator=(const ShaderProgram &p) = delete;
    virtual ~ShaderProgram();

    bool isLinked() const;

    void addShader(GLuint shader, GLenum type);
    void link();
    void use();

    void setUniform(const std::string &name, const GLint &i);
    void setUniform(const std::string &name, const GLuint &u);
    void setUniform(const std::string &name, const GLfloat &f);
    void setUniform(const std::string &name, const GLdouble &d);
    void setUniform(const std::string &name, const GLVector2 &v);
    void setUniform(const std::string &name, const GLVector3 &v);
    void setUniform(const std::string &name, const GLVector4 &v);
    void setUniform(const std::string &name, const GLMatrix3 &m);
    void setUniform(const std::string &name, const GLMatrix4 &m);
    void setUniform(const std::string &name, const Camera &c);
    void setUniform(const std::string &name, const Drawable &d);
    void setUniform(const std::string &name, const Material &m);

protected:
    bool linked;

    const GLuint program = 0;
    GLuint vert = 0;
    GLuint frag = 0;
    GLuint geom = 0;
    GLuint tesc = 0;
    GLuint tese = 0;
};

#endif // SHADERPROGRAM_H
