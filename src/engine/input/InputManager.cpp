#include "InputManager.h"

InputManager *InputManager::instance = nullptr;

InputManager *const &InputManager::getInstance() {
    return instance;
}

InputManager *const &InputManager::createInstance(GLFWwindow *const &window) {
    instance = new InputManager(window);
    //instance->loadActivities();
    //instance->loadContexts();
    return instance;
}



void InputManager::keyPressed(GLFWwindow *window,
                              int key,
                              int scancode,
                              int action,
                              int mods) {
    InputManager::getInstance()->requests.push_back(
        new KeyEvent(key, action));
}



InputManager::InputManager(GLFWwindow *const &window) {
    //setCurrentContext("normal");// TEMPORARY

    // set glfw call-back functions
    glfwSetKeyCallback(window, keyPressed);
    //glfwSetMouseButtonCallback(window, mouseButtonPressed);
}

InputManager::~InputManager() {}


Actor *const &InputManager::getActor() const {
    return actor;
}

void InputManager::setActor(Actor *const &actor) {
    this->actor = actor;
}

Context *const &InputManager::getCurrentContext() const {
    return currentContext;
}

void InputManager::setCurrentContext(const std::string &key) {
    auto index = contexts.find(key);

    try {
        if (index == contexts.cend())
            throw NoSuchEntryException(
                "No entry found in contexts with the key: " + key);
    } catch (NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    currentContext = contexts.find(key)->second;
}

const ContextMap &InputManager::getContexts() const {
    return contexts;
}

void InputManager::setContexts(const ContextMap &contexts) {
    this->contexts = contexts;
}

const EventQueue &InputManager::getRequests() const {
    return requests;
}

void InputManager::setRequests(const EventQueue &requests) {
    this->requests = requests;
}

void InputManager::pushRequest(Event *const &request) {
    requests.push_back(request);
}

void InputManager::init(Actor *const &actor) {
    this->actor = actor;
    loadActivities();
    loadContexts();
}

void InputManager::process() {
    glfwPollEvents();

    ASSERT(currentContext,
           "currentContext is null.");

    while (!requests.empty()) {
        auto reaction = (currentContext->findReaction(requests.front()));

        if (reaction) {
            if (reaction->activity)
            //    setCurrentContext((actor->*(reaction->activity))());
                (actor->*(reaction->activity))();
            //if (reaction->transition)
            //    setCurrentContext(transition);
        }

        requests.pop_front();
    }
    /*
    for (auto e : requests) {
        auto r = currentContext->findReaction(e);
        if (r->activity) (actor->*(r->activity))();
    }*/
}

Context *InputManager::findContext(const std::string &key) const {
    Context *value = nullptr;
    auto index = contexts.find(key);

    try {
        if (index == contexts.cend()) {
            for (const auto &c : contexts) {
                if ((value = c.second->findContext(key)))
                    return value;
            }

            throw NoSuchEntryException(
                "No entry found in 'contexts' with key: " + key);
        }
    } catch (NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    return value;
}

Activity InputManager::findActivity(const std::string &key) const {
    //for (const auto &a : activities)
    //    std::cout << a.first << std::endl;

    auto value = activities.find(key);
    try {
        if (value == activities.cend())
            throw NoSuchEntryException(
                "No entry found in 'activities' with key: " + key);
    } catch (NoSuchEntryException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
    return activities.find(key)->second;
}

inline
void InputManager::loadActivities() {
    activities.emplace("move_forward", &Actor::moveForward);
    activities.emplace("move_backward", &Actor::moveBackward);
    activities.emplace("move_left", &Actor::moveLeft);
    activities.emplace("move_right", &Actor::moveRight);
    activities.emplace("move_up", &Actor::moveUp);
    activities.emplace("move_down", &Actor::moveDown);
}

inline
void InputManager::loadContexts(const std::string &path) {
    using namespace rapidxml;

    xml_document<> *doc = XMLParser(path).getDocument();

    xml_node<> *contextNode =
        doc->first_node("contexts")->first_node("context");

    while (contextNode) {
        std::string name = contextNode->first_attribute("name")->value();
        Context *context = new Context(contextNode);

        contexts.emplace(name, context);
        contextNode = contextNode->next_sibling("context");
    }
}
