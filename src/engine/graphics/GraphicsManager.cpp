#include "GraphicsManager.h"

GraphicsManager *GraphicsManager::currentInstance = nullptr;

GraphicsManager *GraphicsManager::getCurrentInstance() {
    return currentInstance;
}

void GraphicsManager::setCurrentInstance(GraphicsManager *const &instance) {
    currentInstance = instance;
}

GraphicsManager::GraphicsManager(GLFWwindow *const &window) :
    GraphicsManager(window,
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr) {}

GraphicsManager::GraphicsManager(GLFWwindow *const &window,
                                 ShaderProgramCache *const &shaderPrograms,
                                 MeshCache *const &meshes,
                                 ImageCache *const &images,
                                 MaterialCache *const &materials,
                                 Camera *const &camera) :
    window(window),
    shaderPrograms(shaderPrograms),
    activeShaderProgram(nullptr),
    meshes(meshes),
    images(images),
    materials(materials),
    camera(camera) {

    ASSERT(glfwGetCurrentContext(),
           "GL context not set.");

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

GraphicsManager::~GraphicsManager() {}

ShaderProgramCache *const &GraphicsManager::getShaderPrograms() const {
    return shaderPrograms;
}

ShaderProgram *const &GraphicsManager::getActiveShaderProgram() const {
    return activeShaderProgram;
}

void GraphicsManager::setActiveShaderProgram(const std::string &key) {
    activeShaderProgram = shaderPrograms->get(key);
}

ShaderProgram *const &GraphicsManager::getShaderProgram(const std::string &key) const  {
    return shaderPrograms->get(key);
}

MeshCache *const &GraphicsManager::getMeshes() const {
    return meshes;
}

void GraphicsManager::setMeshes(MeshCache *const &meshes) {
    this->meshes = meshes;
}

Mesh *const &GraphicsManager::getMesh(const std::string &key) const {
    return meshes->get(key);
}

ImageCache *const &GraphicsManager::getImages() const {
    return images;
}

void GraphicsManager::setImages(ImageCache *const &images) {
    this->images = images;
}

Image *const &GraphicsManager::getImage(const std::string &key) const {
    return images->get(key);
}

MaterialCache *const &GraphicsManager::getMaterials() const {
    return materials;
}

void GraphicsManager::setMaterials(MaterialCache *const &materials) {
    this->materials = materials;
}

Material *const &GraphicsManager::getMaterial(const std::string &key) const {
    return materials->get(key);
}

Camera *const &GraphicsManager::getCamera() const {
    return camera;
}

void GraphicsManager::setCamera(Camera *const &camera) {
    this->camera = camera;
}

void GraphicsManager::render(Drawable *const &drawable) const {
    //ASSERT(glfwGetCurrentContext(),
    //       "GL context not set.");
    //ASSERT(camera,
    //       "null pointer.");
    ASSERT_NOT_NULL(camera);
    ASSERT_NOT_NULL(activeShaderProgram);
    ASSERT_NOT_NULL(drawable);

    glfwMakeContextCurrent(window);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    activeShaderProgram->use();
    activeShaderProgram->setUniform("camera", *camera);
    activeShaderProgram->setUniform("drawable", *drawable);
    drawable->render();

    //glfwSwapBuffers(window);
}
