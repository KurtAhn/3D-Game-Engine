#ifndef SHADERPROGRAMCACHE_H
#define SHADERPROGRAMCACHE_H

#include "Common.h"
#include "Exception.h"
#include "Cache.h"
#include "ShaderProgram.h"
#include "XMLParser.h"

class ShaderProgramCache : public Cache<ShaderProgram> {
    friend class GraphicsManager;
private:
    ShaderProgramCache() = delete;
    ShaderProgramCache(XMLNode *const &node);
    ShaderProgramCache(const ShaderProgramCache &src) = delete;
    ShaderProgramCache &operator=(const ShaderProgramCache &src) = delete;
public:
    virtual ~ShaderProgramCache();

public:
    void load(const std::string &folderPath) override;

private:
    XMLParser parser;

    GLenum getShaderType(const std::string &type);
    void loadAndCompileShader(const GLuint &shader, const std::string &path);
};

#endif // SHADERPROGRAMCACHE_H
