#include "Material.h"

Material::Material(const float &shininess,
                   const float &specularity,
                   const float &diffuseness,
                   const GLVector4 &color) :
    shininess(shininess),
    specularity(specularity),
    diffuseness(diffuseness),
    color(color) {}

Material::Material(const Material &src) :
    shininess(src.shininess),
    specularity(src.specularity),
    diffuseness(src.diffuseness),
    color(src.color) {}

Material &Material::operator=(const Material &src) {
    shininess = src.shininess;
    specularity = src.specularity;
    color = src.color;
    return *this;
}

Material::~Material() {}

const float &Material::getShininess() const {
    return shininess;
}

void Material::setShininess(const float &shininess) {
    this->shininess = shininess;
}

const float &Material::getSpecularity() const {
    return specularity;
}

void Material::setSpecularity(const float &specularity) {
    this->specularity = specularity;
}

const float &Material::getDiffuseness() const {
    return diffuseness;
}

void Material::setDiffuseness(const float &diffuseness) {
    this->diffuseness = diffuseness;
}

const GLVector4 &Material::getColor() const {
    return color;
}

void Material::setColor(const GLVector4 &color) {
    this->color = color;
}
