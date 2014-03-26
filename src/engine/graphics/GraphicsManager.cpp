#include "GraphicsManager.h"

GraphicsManager *GraphicsManager::currentInstance = nullptr;

GraphicsManager::~GraphicsManager() {
    delete shaderPrograms;
    delete meshes;
    delete images;
    delete materials;
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

Mesh *const &GraphicsManager::getMesh(const std::string &key) const {
    return meshes->get(key);
}

Image *const &GraphicsManager::getImage(const std::string &key) const {
    return images->get(key);
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

void GraphicsManager::init(Window *const &window,
                           XMLNode *const &node) {
    //ASSERT(glfwGetCurrentContext(),
    //       "GL context not set.");

    this->window = window;

    glfwMakeContextCurrent(window);

    shaderPrograms = new ShaderProgramCache(node->first_node("Shaders"));
    meshes = new MeshCache(node->first_node("Meshes"));
    images = new ImageCache(node->first_node("Images"));
    materials = new MaterialCache(node->first_node("Materials"));

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CCW);
    //glCullFace(GL_BACK);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void GraphicsManager::render(Drawable *const &drawable) const {
    ASSERT_NOT_NULL(camera);
    ASSERT_NOT_NULL(activeShaderProgram);
    ASSERT_NOT_NULL(drawable);

    glfwMakeContextCurrent(window);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    activeShaderProgram->use();
    activeShaderProgram->setUniform("camera", *camera);
    activeShaderProgram->setUniform("drawable", *drawable);
    drawable->render();
}
