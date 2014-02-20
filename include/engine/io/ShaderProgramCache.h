#ifndef SHADERPROGRAMCACHE_H
#define SHADERPROGRAMCACHE_H

#include "Common.h"
#include "Exception.h"
#include "Cache.h"
#include "ShaderProgram.h"
#include "XMLParser.h"

class ShaderProgramCache : public Cache<ShaderProgram*> {
    friend class Graphics;
public:
    ShaderProgramCache(const std::string &path, const std::string &xml);
    virtual ~ShaderProgramCache();

    void load(const std::string &path) override;
    void save(const std::string &path) override;
private:
    XMLParser parser;
    ShaderProgram *activeProgram;

    GLenum getShaderType(const std::string &type);
    void loadAndCompileShader(const GLuint &shader, const std::string &path);
};

#endif // SHADERPROGRAMCACHE_H
