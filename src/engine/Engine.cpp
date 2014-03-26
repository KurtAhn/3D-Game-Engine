#include "Engine.h"

Engine *Engine::instance = nullptr;

Engine *const &Engine::getInstance() {
    return instance;
}

Engine *const &Engine::createInstance(const std::string &configFilePath) {
    instance = new Engine(configFilePath);
    return instance;
}

void Engine::destroy() {
    delete instance;
    glfwTerminate();
}

Engine::Engine(const std::string &configFilePath) :
    Engine(XMLParser(configFilePath).getDocument()->first_node("Engine")) {}

Engine::Engine(XMLNode *const &node) {

    try {
        ilInit();

        if (glfwInit() == GL_FALSE)
            throw GLFWException("GLFW initialization failed.");

        XMLNode *windowNode = node->first_node("Window");

        window = glfwCreateWindow(boost::lexical_cast<int>(
                                    windowNode->first_node("Width")->value()),
                                  boost::lexical_cast<int>(
                                    windowNode->first_node("Height")->value()),
                                  windowNode->first_node("Title")->value(),
                                  nullptr,
                                  nullptr);

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
            throw GLEWException("GLEW initialization failed.");

        InputManager::currentInstance = this;
        InputManager::init(window, node->first_node("InputManager"));

        GraphicsManager::currentInstance = this;
        GraphicsManager::init(window, node->first_node("GraphicsManager"));

        glfwIconifyWindow(window);
        glfwRestoreWindow(window);

    } catch (std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Engine::~Engine() {
    glfwDestroyWindow(window);
}

bool Engine::isCloseRequested() const {
    return glfwWindowShouldClose(window);
}

void Engine::setCloseRequested(const bool &closeRequested) {
    glfwSetWindowShouldClose(window, closeRequested);
}

void Engine::update() const {
    glfwSwapBuffers(window);
}
