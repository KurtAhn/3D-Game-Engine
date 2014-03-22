#ifndef MATERIAL_H
#define MATERIAL_H

#include "GraphicsCommon.h"

class Material {
public:
    Material() = delete;
    Material(const float &shininess,
             const float &specularity,
             const float &diffuseness,
             const GLVector4 &color);
    Material(const Material &src);
    Material &operator=(const Material &src);
    virtual ~Material();

private:
    float shininess;
    float specularity;
    float diffuseness;
    GLVector4 color;

public:
    const float &getShininess() const;
    void setShininess(const float &shininess);
    const float &getSpecularity() const;
    void setSpecularity(const float &specularity);
    const float &getDiffuseness() const;
    void setDiffuseness(const float &diffuseness);
    const GLVector4 &getColor() const;
    void setColor(const GLVector4 &color);
};

#endif // MATERIAL_H
