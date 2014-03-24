#include "Actor.h"

Actor::Actor() :
    camera(new Camera) {
    ASSERT(InputManager::getCurrentInstance(),
           "InputManager current instance is null.");

    InputManager::getCurrentInstance()->addKeyListener(this);
    InputManager::getCurrentInstance()->addMouseListener(this);
    InputManager::getCurrentInstance()->addWindowListener(this);
}

Actor::~Actor() {
    //delete camera;
}

Camera *const &Actor::getCamera() const {
    return camera;
}

void Actor::setCamera(Camera *const &camera) {
    this->camera = camera;
}

void Actor::update() {
    camera->translate(camera->getXAxis() * static_cast<float>(movingRight - movingLeft)
                      + camera->getYAxis() * static_cast<float>(movingUp - movingDown)
                      + camera->getZAxis() * static_cast<float>(movingBackward - movingForward),
                      0.005f);
}

////////
void Actor::keyPressed(KeyEvent *const &e) {
    if (e->key == GLFW_KEY_W)
        movingForward = e->action;
    if (e->key == GLFW_KEY_S)
        movingBackward = e->action;
    if (e->key == GLFW_KEY_A)
        movingLeft = e->action;
    if (e->key == GLFW_KEY_D)
        movingRight = e->action;
    if (e->key == GLFW_KEY_SPACE)
        movingUp = e->action;
    if (e->key == GLFW_KEY_LEFT_SHIFT)
        movingDown = e->action;
    if (e->key == GLFW_KEY_ESCAPE && e->action == GLFW_PRESS) {
        mouse.centered = !mouse.centered;
        std::cout << "Mouse centered? " << mouse.centered << std::endl;
    }
}

void Actor::keyTyped(CharEvent *const &e) {
    std::cout << static_cast<char>(e->key) << std::endl;
}

///////
void Actor::mouseButtonPressed(MouseButtonEvent *const &e) {

}

void Actor::mouseCursorMoved(MouseMotionEvent *const &e) {
    if (mouse.justEntered)
        mouse.justEntered = false;
    else {
        camera->rotate(glm::vec3(0, 1, 0), (mouse.xpos - e->xpos) / 500.0f);
        camera->rotate(camera->getXAxis(), (mouse.ypos - e->ypos) / 500.0f);
    }

    if (mouse.centered) {
        glfwSetCursorPos(e->window, window.width / 2, window.height / 2);
        mouse.xpos = window.width / 2;
        mouse.ypos = window.height / 2;
        std::cout << "Center: " << window.width / 2 << " " << window.height / 2 << std::endl;
    } else {
        mouse.xpos = e->xpos;
        mouse.ypos = e->ypos;
    }


}

void Actor::mouseCursorEntered(MouseEnterEvent *const &e) {
    if (e->entered)
        mouse.justEntered = true;
}

void Actor::mouseWheelScrolled(MouseScrollEvent *const &e) {
    camera->zoom(e->yoffset / 10.0f);
}

///////
void Actor::windowMoved(WindowMotionEvent *const &e) {
    window.xpos = e->xpos;
    window.ypos = e->ypos;
    std::cout << "Window Moved" << std::endl;
    //std::cout << e->xpos << " " << e->ypos << std::endl;
}

void Actor::windowResized(WindowResizeEvent *const &e) {
    window.width = e->width;
    window.height = e->height;
    if (e->height)
        camera->setAspect(e->width / e->height);
    std::cout << "Window Resized" << std::endl;
}

void Actor::windowClosing(WindowCloseEvent *const &e) {
    std::cout << "Window Closing" << std::endl;
}

void Actor::windowRefreshed(WindowRefreshEvent *const &e) {
    std::cout << "Window Refreshed" << std::endl;
}

void Actor::windowFocused(WindowFocusEvent *const &e) {
    std::cout << "Window Focused" << std::endl;
}

void Actor::windowIconified(WindowIconifyEvent *const &e) {
    std::cout << "Window Iconified" << std::endl;
}

void Actor::frameBufferResized(FrameBufferResizeEvent *const &e) {
    std::cout << "Frame Buffer Resized" << std::endl;
}
