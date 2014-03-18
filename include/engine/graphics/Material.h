#ifndef MATERIAL_H
#define MATERIAL_H

#include "GraphicsCommon.h"
#include "Texture.h"

class Material {
public:
    Material();
    //Material(Texture *const texture,
    //           const float &shininess,
    //           const float &specularity,
    //           const float &diffuseness,
    //           const GLVector3 &color);

    Material(const Material &src);
    Material &operator=(const Material &src);
    virtual ~Material();

private:
    Texture *texture;
    float shininess;
    float specularity;
    float diffuseness;
    GLVector3 color;

public:
    Texture *const &getTexture() const;
    void setTexture(Texture *const &texture);
    const float &getShininess() const;
    void setShininess(const float &shininess);
    const float &getSpecularity() const;
    void setSpecularity(const float &specularity);
    const float &getDiffuseness() const;
    void setDiffuseness(const float &diffuseness);
    const GLVector3 &getColor() const;
    void setColor(const GLVector3 &color);
};

#endif // MATERIAL_H
