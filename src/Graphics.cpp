#include "Graphics.h"

Graphics::Graphics() {
    init();
}

Graphics::~Graphics() {
//    delete lighting;
}

const ProgramMap &Graphics::getPrograms() {
    return programs;
}

void Graphics::setPrograms(const ProgramMap &programs) {
    this->programs = programs;
}

ShaderProgram *&Graphics::getProgram(const std::string &key) {
    try {
        if (programs.find(key) == programs.end())
            throw std::runtime_error("No corresponding value exists.");
    } catch (const std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return programs.find(key)->second;
}

ShaderProgram *const &Graphics::getActiveProgram() {
    return activeProgram;
}

void Graphics::setActiveProgram(const std::string &key) {
    if (programs.find(key) != programs.end()) {
        activeProgram = programs.at(key);
        return;
    }

    throw std::logic_error("No corresponding value exists.");
}

const MeshMap &Graphics::getMeshes() {
    return meshes;
}

void Graphics::setMeshes(const MeshMap &meshes) {
    this->meshes = meshes;
}

Mesh *const &Graphics::getMesh(const std::string &key) const {
    return meshes.find(key)->second;
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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    activeProgram->use();
    activeProgram->setUniform("c", *(world->getCamera()));

    //for (const auto &e : world->getEntities())
    //    e.second->render();

    glfwSwapBuffers(window);
}
