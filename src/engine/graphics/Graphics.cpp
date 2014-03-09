#include "Graphics.h"

Graphics::Graphics() :
    programs("data\\graphics\\shaders\\",
             "data\\graphics\\shaders\\programs.xml"),
    meshes("data\\graphics\\meshes\\") {
    init();
}

Graphics::~Graphics() {
//    delete lighting;
}

//const ShaderProgramMap &Graphics::getShaderPrograms() {
//    return programs;
//}

//void Graphics::setShaderPrograms(const ShaderProgramMap &programs) {
//    this->programs = programs;
//}

ShaderProgram *&Graphics::getShaderProgram(const std::string &key) {
    auto program = programs.cache.find(key);

    try {
        if (program == programs.cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found in 'programs.cache'");
    } catch (const NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return program->second;
}

ShaderProgram *const &Graphics::getActiveShaderProgram() {
    return programs.activeProgram;
}

void Graphics::setActiveShaderProgram(const std::string &key) {
    try {
        auto program = programs.cache.find(key);

        if (program == programs.cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found in 'programs.cache'");

        programs.activeProgram = program->second;
    } catch (const NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

//const MeshMap &Graphics::getMeshes() {
//    return meshes;
//}

//void Graphics::setMeshes(const MeshMap &meshes) {
//    this->meshes = meshes;
//}

Mesh *const &Graphics::getMesh(const std::string &key) const {
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

void Graphics::init() {
    ASSERT(glfwGetCurrentContext(),
           "GL context not set.");

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}



void Graphics::render(GLFWwindow *const &window, World *const &world) const {
    ASSERT(glfwGetCurrentContext(),
           "GL context not set.");
    ASSERT(programs.activeProgram,
           "'this->programs.activeProgram' is null.");
    ASSERT(world,
           "'world' is null.");
    ASSERT(world->getActor(),
           "'world->actor' is null.");
    ASSERT(world->getActor()->getCamera(),
           "'world->actor->camera' is null.");
/*
    try {
        if (!programs.activeProgram)
            throw NullPointerException("'programs.activeProgram' member is null.");
        if (!world)
            throw NullPointerException("'world' argument is null.");
        if (world->getActor()) {

        }
        if (!window)
            throw NullPointerException("'window' argument is null.");
        if (glfwGetCurrentContext() != window)
            throw GLFWException("'window' argument is not the current GL context.");
    } catch (const NullPointerException &e) {
        LOG_ERROR(e);
        RETHROW;
    } catch (const GLFWException &e) {
        LOG_ERROR(e);
        glfwMakeContextCurrent(window);
    }
*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    programs.activeProgram->use();
    //programs.activeProgram->setUniform("c", *(world->getCamera()));
    programs.activeProgram->setUniform("c", *(world->getActor()->getCamera()));

    //for (const auto &e : world->getEntities())
    //    e.second->render();

    for (const auto &m : meshes.cache) {
        m.second->render();
        //std::cout << m.first << std::endl;
    }

    glfwSwapBuffers(window);
}
