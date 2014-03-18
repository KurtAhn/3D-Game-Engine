#include "GraphicsManager.h"

GraphicsManager *GraphicsManager::currentInstance = nullptr;

GraphicsManager *GraphicsManager::getCurrentInstance() {
    return currentInstance;
}

void GraphicsManager::setCurrentInstance(GraphicsManager *const instance) {
    currentInstance = instance;
}

GraphicsManager::GraphicsManager(GLFWwindow *const &window) :
    window(window),
    shaderPrograms("", ""),
    meshes(""),
    camera(nullptr) {



    ASSERT(glfwGetCurrentContext(),
           "GL context not set.");

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

GraphicsManager::~GraphicsManager() {}

ShaderProgram *const &GraphicsManager::getActiveShaderProgram() const {
    return shaderPrograms.activeProgram;
}

void GraphicsManager::setActiveShaderProgram(const std::string &key) {
    try {
        auto program = shaderPrograms.cache.find(key);

        if (program == shaderPrograms.cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found in 'shaderPrograms.cache'");

        shaderPrograms.activeProgram = program->second;
    } catch (const NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

ShaderProgram *const &GraphicsManager::getShaderProgram(const std::string &key) const  {
    auto program = shaderPrograms.cache.find(key);

    try {
        if (program == shaderPrograms.cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found in 'shaderPrograms.cache'");
    } catch (const NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return program->second;
}

Mesh *const &GraphicsManager::getMesh(const std::string &key) const {
    auto mesh = meshes.cache.find(key);

    try {
        if (mesh == meshes.cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found in 'meshes.cache'");
    } catch (const NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return mesh->second;
}

void GraphicsManager::render(Drawable *const &drawable) const {
    //ASSERT(glfwGetCurrentContext(),
    //       "GL context not set.");
    ASSERT(camera,
           "'this->camera' is null.");
    ASSERT(shaderPrograms.activeProgram,
           "'this->shaderPrograms.activeProgram' is null.");
    ASSERT(drawable,
           "'drawable' is null.");

    glfwMakeContextCurrent(window);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderPrograms.activeProgram->use();
    shaderPrograms.activeProgram->setUniform("camera", *camera);
    shaderPrograms.activeProgram->setUniform("drawable", *drawable);
    drawable->render();

    glfwSwapBuffers(window);

    /* temporary
    for (const auto &m : meshes.cache) {
        m.second->render();
        //std::cout << m.first << std::endl;
    }
    */
}
