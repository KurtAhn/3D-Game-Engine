#include "Keyboard.h"

Keyboard::Keyboard() {}

Keyboard::Keyboard(const KeyMap &keyMap) {
    setKeyMap(keyMap);
}

Keyboard::~Keyboard() {}

void Keyboard::setKeyMap(const KeyMap &keyMap) {
    for (const auto &k : keyMap) {
        if (k.first == "forward") {
            space.fd = k.second;
        } else if (k.first == "back") {
            space.bk = k.second;
        } else if (k.first == "left") {
            space.lt = k.second;
        } else if (k.first == "right") {
            space.rt = k.second;
        } else if (k.first == "up") {
            space.up = k.second;
        } else if (k.first == "down") {
            space.dn = k.second;
        } else if (k.first == "pause") {
            space.ps = k.second;
        }
    }
}

/** @TODO
 *  -Support various key actions (eg: toggle, hold)
 */
void Keyboard::performAction(Game *const &game) const {
    GLFWwindow *window = nullptr;
    World *world = nullptr;
    Camera *camera = nullptr;

    try {
        if (!game)
            throw NullPointerException("'game'is null.");
        if (!(window = game->getWindow()))
            throw NullPointerException("'window' is null.");
        if (!(world = game->getWorld()))
            throw NullPointerException("'world' is null.");
        if (!(camera = world->getCamera()))
            throw NullPointerException("'camera' is null.");
    } catch (const NullPointerException &e) {
        LOG_ERROR(e);
        RETHROW;
    }

    if (glfwGetKey(window, space.ps))
        game->setPaused(true);

    float x = 0.0f, y = 0.0f, z = 0.0f;

    if (glfwGetKey(window, space.fd) == GLFW_PRESS) {
        z -= 1.0f;
    } if (glfwGetKey(window, space.bk) == GLFW_PRESS) {
        z += 1.0f;
    } if (glfwGetKey(window, space.lt) == GLFW_PRESS) {
        x -= 1.0f;
    } if (glfwGetKey(window, space.rt) == GLFW_PRESS) {
        x += 1.0f;
    } if (glfwGetKey(window, space.up) == GLFW_PRESS) {
        y += 1.0f;
    } if (glfwGetKey(window, space.dn) == GLFW_PRESS) {
        y -= 1.0f;
    }

    //Temp
    std::cout << x << " " << y << " " << z << std::endl;

//    glm::vec3 direction = c->getLateral() * x + c->getLongitudinal() * z;
//    direction.y = y;

    //c->translate(direction, 0.001f);
    //c->zoom(s * 0.001f);
}
