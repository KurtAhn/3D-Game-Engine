#include "Drawable.h"

Drawable::Drawable() :
    Drawable(nullptr,
             nullptr,
             nullptr,
             nullptr) {}

Drawable::Drawable(Mesh *const &mesh,
                   Texture *const &texture,
                   Material *const &material,
                   GLMatrix4 *const &transform) :
    mesh(mesh),
    texture(texture),
    material(material),
    transform(transform) {}

Drawable::Drawable(const Drawable &src) :
    Drawable(src.mesh,
             src.texture,
             src.material,
             src.transform) {}

Drawable &Drawable::operator=(const Drawable &src) {
    mesh = src.mesh;
    texture = src.texture;
    material = src.material;
    transform = src.transform;
    return *this;
}

Drawable::~Drawable() {}

Mesh *const &Drawable::getMesh() const {
    return mesh;
}

void Drawable::setMesh(Mesh *const &mesh) {
    this->mesh = mesh;
}

Texture *const &Drawable::getTexture() const {
    return texture;
}

void Drawable::setTexture(Texture *const &texture) {
    this->texture = texture;
}

Material *const &Drawable::getMaterial() const {
    return material;
}

void Drawable::setMaterial(Material *const &material) {
    this->material = material;
}

GLMatrix4 *const &Drawable::getTransform() const {
    return transform;
}

void Drawable::setTransform(GLMatrix4 *const &transform) {
    this->transform = transform;
}
