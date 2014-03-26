#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "GraphicsCommon.h"
#include "Exception.h"
#include "Camera.h"
#include "Material.h"
#include "Drawable.h"
#include "Lighting.h"

class ShaderProgram {
public:
    ShaderProgram();
    ShaderProgram(const ShaderProgram &src) = delete;
    ShaderProgram &operator=(const ShaderProgram &p) = delete;
    virtual ~ShaderProgram();

public:
    bool isLinked() const;

    void addShader(GLuint shader, GLenum type);
    void link();
    void use() const;

public:
    void setUniform(const std::string &name, const GLint &i) const;
    void setUniform(const std::string &name, const GLuint &u) const;
    void setUniform(const std::string &name, const GLfloat &f) const;
    void setUniform(const std::string &name, const GLdouble &d) const;
    void setUniform(const std::string &name, const GLVector2 &v) const;
    void setUniform(const std::string &name, const GLVector3 &v) const;
    void setUniform(const std::string &name, const GLVector4 &v) const;
    void setUniform(const std::string &name, const GLMatrix3 &m) const;
    void setUniform(const std::string &name, const GLMatrix4 &m) const;
    void setUniform(const std::string &name, const Camera &c) const;
    void setUniform(const std::string &name, const Texture &t) const;
    void setUniform(const std::string &name, const Material &m) const;
    void setUniform(const std::string &name, const Drawable &d) const;
    void setUniform(const std::string &name, const Attenuation &a) const;
    void setUniform(const std::string &name, const AmbientLight &l) const;
    void setUniform(const std::string &name, const DirectionalLight &l) const;
    void setUniform(const std::string &name, const PointLight &l) const;
    void setUniform(const std::string &name, const SpotLight &l) const;

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
