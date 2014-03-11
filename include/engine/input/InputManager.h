#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Common.h"
#include "Exception.h"
//#include "InputDeclaration.h"
//#include "XMLParser.h"
#include "Event.h"
#include "EventListener.h"
//#include "Interactable.h"
//#include "Actor.h"
//#include "Context.h"

class Game;

/**
 * A singleton input management module based on event callbacks.
 *
 * The module is initialized with an external input configuration xml file.
 * Prior to every frame, GLFW event callbacks are called when user inputs are
 * fired. These events are stored in an event queue. The queue is polled when
 * process() is called. As the queue is being polled, each event is mapped to
 * a corresponding reaction. If the event successfully maps to an existing
 * reaction within the current context, the reaction is executed.
 */

class InputManager {
// Singleton instance
private:
    static InputManager *instance;
public:
    static InputManager *const &getInstance();
    static InputManager *const &createInstance(GLFWwindow *const &window);

// Static callbacks
public:
	static void fireKeyEvent(GLFWwindow *window, int key, int action, int scancode, int mods);
	static void fireCharEvent(GLFWwindow *window, unsigned codepoint);
	static void fireMouseButtonEvent(GLFWwindow *window, int button, int action, int mods);
	static void fireMouseMotionEvent(GLFWwindow *window, double xpos, double ypos);
	static void fireMouseEnterEvent(GLFWwindow *window, int entered);
	static void fireMouseScrollEvent(GLFWwindow *window, double xoffset, double yoffset);
	static void fireWindowMotionEvent(GLFWwindow *window, int xpos, int ypos);
	static void fireWindowResizeEvent(GLFWwindow *window, int width, int height);
	static void fireWindowCloseEvent(GLFWwindow *window);
	static void fireWindowRefreshEvent(GLFWwindow* window);
	static void fireWindowIconifyEvent(GLFWwindow *window, int iconified);
	static void fireWindowFocusEvent(GLFWwindow *window, int focused);
	static void fireFrameBufferResizeEvent(GLFWwindow *window, int width, int height);

// Constructor, destructor, copy control
private:
    InputManager() = delete;
    InputManager(GLFWwindow *const &window);
    InputManager(const InputManager &src) = delete;
    InputManager &operator=(const InputManager &src) = delete;
public:
    virtual ~InputManager();

// Member data and getters/setters
private:
	std::vector<KeyListener *> keyListeners;
	std::vector<MouseListener *> mouseListeners;
	std::vector<WindowListener *> windowListeners;

	std::deque<KeyEvent *> keyEventRequests;
	std::deque<CharEvent *> charEventRequests;
	std::deque<MouseButtonEvent *> mouseButtonEventRequests;
	std::deque<MouseMotionEvent *> mouseMotionEventRequests;
	std::deque<MouseEnterEvent *> mouseEnterEventRequests;
	std::deque<MouseScrollEvent *> mouseScrollEventRequests;
	std::deque<WindowMotionEvent *> windowMotionEventRequests;
	std::deque<WindowResizeEvent *> windowResizeEventRequests;
	std::deque<WindowCloseEvent *> windowCloseEventRequests;
	std::deque<WindowRefreshEvent *> windowRefreshEventRequests;
	std::deque<WindowFocusEvent *> windowFocusEventRequests;
	std::deque<WindowIconifyEvent *> windowIconifyEventRequests;
	std::deque<FrameBufferResizeEvent *> frameBufferResizeEventRequests;
public:
	void addKeyListener(KeyListener *const &l);
	void removeKeyListener(const std::size_t &index);
	void addMouseListener(MouseListener *const &l);
	void removeMouseListener(const std::size_t &index);
	void addWindowListener(WindowListener *const &l);
	void removeWindowListener(const std::size_t &index);
// Other interfaces
public:
    void process();

};

#endif // INPUTMANAGER_H
