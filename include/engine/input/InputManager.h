/**
 * TODO
 * - Consider making InputManager non-Singleton.
 */

/*-----------------------------------------------------------------------------
COPYRIGHT NOTICE

InputManager.h
    Collects raw input from GLFW and dispatches Event objects to
    attached EventListener objects on call to process().
-----------------------------------------------------------------------------*/

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "InputCommon.h"
#include "Event.h"
#include "EventListener.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include "WindowListener.h"

class Game;

class InputManager {
private:
    /**
     * The currently bound InpuManager.
     */
    static InputManager *currentInstance;

public:
    /**
     * @return Currently bound InputManager.
     */
    static InputManager *getCurrentInstance();

    /**
     * Sets the bound InputManager.
     *
     * @param instance - Instance to bound.
     */
    static void setCurrentInstance(InputManager *const &instance);

public:
    /**
     * Called by GLFW when a key is pressed, released or held.
     *
     * @param window - The window that received the event.
     * @param key - The keyboard key that was pressed or released.
     * @param scancode - The system-specific scancode of the key.
     * @param action - GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT.
     * @param mods - Bit field describing which modifier keys were held down.
     */
	static void fireKeyEvent(GLFWwindow *window, int key, int action, int scancode, int mods);

	/**
     * Called by GLFW when a key is pressed.
     *
     * @param window - The window that received the event.
     * @param codepoint - The Unicode code point of the character.
     */
	static void fireCharEvent(GLFWwindow *window, unsigned codepoint);

    /**
     * Called by GLFW when a mouse button is pressed or released.
     *
     * @param window - The window that received the event.
     * @param button - The mouse button that was pressed or released.
     * @param action - One of GLFW_PRESS or GLFW_RELEASE.
     * @param mods - Bit field describing which modifier keys were held down.
     */
	static void fireMouseButtonEvent(GLFWwindow *window, int button, int action, int mods);

	/**
	 * Called by GLFW when the mouse cursor is moved.
	 *
	 * @param window - The window that received the event.
	 * @param xpos - The new x-coordinate, in screen coordinates, of the cursor.
	 * @param ypos - The new y-coordinate, in screen coordinates, of the cursor.
	 */
	static void fireMouseMotionEvent(GLFWwindow *window, double xpos, double ypos);

	/**
	 * Called by GLFW when the mouse cursor enters or leaves the window.
	 *
	 * @param window - The window that received the event.
	 * @param entered - GL_TRUE if the cursor entered the window's client area,
	 * or GL_FALSE if it left it.
	 */
	static void fireMouseEnterEvent(GLFWwindow *window, int entered);

	/**
	 * Called by GLFW when a scrolling device is used.
     *
     * @param window - The window that received the event.
     * @param xoffset - The scroll offset along the x-axis.
     * @param yoffset - The scroll offset along the y-axis.
	 */
	static void fireMouseScrollEvent(GLFWwindow *window, double xoffset, double yoffset);

	/**
	 * Called by GLFW when the window is moved.
	 *
	 * @param window - The window that the user moved.
	 * @param xpos - The new x-coordinate, in screen coordinates, of the upper-left corner
     * of the client area of the window.
     * @param ypos - The new y-coordinate, in screen coordinates, of the upper-left corner
     * of the client area of the window.
	 */
	static void fireWindowMotionEvent(GLFWwindow *window, int xpos, int ypos);

	/**
     * Called by GLFW when the window is resized.
     *
     * @param window - The window that the user resized.
     * @param width - The new width, in screen coordinates, of the window.
     * @param height - The new height, in screen coordinates, of the window.
	 */
	static void fireWindowResizeEvent(GLFWwindow *window, int width, int height);

	/**
	 * Called by GLFW when the close button of the window is pressed.
	 *
	 * @param window - The window that the user attempted to close.
	 */
	static void fireWindowCloseEvent(GLFWwindow *window);

	/**
	 * Called by GLFW when the client area of the window has to be redrawn.
	 *
	 * @param window - The window whose content needs to be refreshed.
	 */
	static void fireWindowRefreshEvent(GLFWwindow* window);

	/**
	 * Called by GLFW when the window is iconified or restored.
	 *
	 * @param window - The window that was iconified or restored.
     * @param iconified - GL_TRUE if the window was iconified, or GL_FALSE if it was restored.
	 */
	static void fireWindowIconifyEvent(GLFWwindow *window, int iconified);

	/**
	 * Called by GLFW when the window gains or loses focus.
	 *
	 * @param window - The window that was focused or defocused.
	 * @param focused - GL_TRUE if the window was focused, or GL_FALSE if it was defocused.
	 */
	static void fireWindowFocusEvent(GLFWwindow *window, int focused);

	/**
	 * Called by GLFW when the frame buffer of the window is resized.
	 *
	 * @param window - The window whose framebuffer was resized.
	 * @param width - The new width, in pixels, of the framebuffer.
	 * @param height - The new height, in pixels, of the framebuffer.
	 */
	static void fireFrameBufferResizeEvent(GLFWwindow *window, int width, int height);


public:
    /**
     * Deleted default constructor.
     */
    InputManager() = delete;

    /**
     * Constructs an InputManager object with a window to listen to.
     *
     * @param window - The window the InputHandler listens to.
     */
    explicit InputManager(GLFWwindow *const &window);

    /**
     * Copy constructor deleted.
     */
    InputManager(const InputManager &src) = delete;

    /**
     * Assignment operator deleted.
     */
    InputManager &operator=(const InputManager &src) = delete;

public:
    /**
     * Destructor.
     */
    virtual ~InputManager();

private:
    /**
     * Target window.
     */
    GLFWwindow *window;

	/**
	 * Attached KeyListeners.
	 */
	std::vector<KeyListener *> keyListeners;

	/**
	 * Attached MouseListeners.
	 */
	std::vector<MouseListener *> mouseListeners;

	/**
	 * Attached WindowListeners.
	 */
	std::vector<WindowListener *> windowListeners;


    /**
     * KeyEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<KeyEvent *> keyEventRequests;

    /**
     * CharEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<CharEvent *> charEventRequests;

    /**
     * MouseButtonEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<MouseButtonEvent *> mouseButtonEventRequests;

    /**
     * MouseMotionEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<MouseMotionEvent *> mouseMotionEventRequests;

    /**
     * MouseEnterEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<MouseEnterEvent *> mouseEnterEventRequests;

    /**
     * MouseScrollEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<MouseScrollEvent *> mouseScrollEventRequests;

    /**
     * WindowMotionEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowMotionEvent *> windowMotionEventRequests;

    /**
     * WindowResizeEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowResizeEvent *> windowResizeEventRequests;

    /**
     * WindowCloseEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowCloseEvent *> windowCloseEventRequests;

    /**
     * WindowRefreshEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowRefreshEvent *> windowRefreshEventRequests;

    /**
     * WindowFocusEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowFocusEvent *> windowFocusEventRequests;

    /**
     * WindowIconifyEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<WindowIconifyEvent *> windowIconifyEventRequests;

    /**
     * FrameBufferResizeEvent requests made by GLFW since last call to InputManager::process()
     */
	std::deque<FrameBufferResizeEvent *> frameBufferResizeEventRequests;

public:
    /**
     * Attaches a KeyListener.
     *
     * @param l - KeyListener to attach.
     */
	void addKeyListener(KeyListener *const &l);

    /**
     * Removes all attached instances KeyListener but does not delete them.
     *
     * @param l - KeyListener to remove.
     */
	void removeKeyListener(KeyListener *const &l);

    /**
     * Attaches a MouseListener.
     *
     * @param l - MouseListener to attach.
     */
	void addMouseListener(MouseListener *const &l);

    /**
     * Removes all attached instances of the MouseListener but does not delete them.
     *
     * @param l - MouseListener to remove.
     */
	void removeMouseListener(MouseListener *const &l);

    /**
     * Attach a WindowListener.
     *
     * @param l - WindowListener to attach.
     */
	void addWindowListener(WindowListener *const &l);

    /**
     * Removes all attached instances of the WindowListener but does not delete them.
     *
     * @param l - WindowListener to remove.
     */
	void removeWindowListener(WindowListener *const &l);

public:
    /**
     * Forwards all Event requests made since previous call to
     * attached listeners and deletes all the requests.
     */
    void process();
};

#endif // INPUTMANAGER_H
