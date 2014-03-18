#include "Drawable.h"

Drawable::Drawable() :
    mesh(nullptr),
    material(nullptr) {}

Drawable::Drawable(Mesh *const &mesh,
                   Material *const &material) :
    mesh(mesh),
    material(material) {}

Drawable::~Drawable() {}

Mesh *const &Drawable::getMesh() const {
    return mesh;
}

void Drawable::setMesh(Mesh *const &mesh) {
    this->mesh = mesh;
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

void Drawable::render() const {
    mesh->render();
}
