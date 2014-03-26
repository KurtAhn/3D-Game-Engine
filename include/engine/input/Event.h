#ifndef EVENT_H
#define EVENT_H

#include "InputCommon.h"

/**
 * Base Event class. Event objects are generated when
 * user inputs are registered.
 */
struct Event {
	GLFWwindow *window;

	Event() = delete;
	Event(GLFWwindow *const &window);
	virtual ~Event() = 0;
};

struct KeyEvent : public Event {
	int key;
	int scancode;
	int action;
	int mods;

	KeyEvent() = delete;
	KeyEvent(GLFWwindow *const &window,
				const int &key,
				const int &action,
				const int &scancode,
				const int &mods);
	KeyEvent(const KeyEvent &src);
	KeyEvent &operator=(const KeyEvent &src);
	~KeyEvent();
};

struct CharEvent : public Event {
	int key;

	CharEvent() = delete;
	CharEvent(GLFWwindow *const &window, const int &key);
	CharEvent(const CharEvent &src);
	CharEvent &operator=(const CharEvent &src);
	~CharEvent();
};

struct MouseButtonEvent : public Event {
	int button;
	int action;
	int mods;

	MouseButtonEvent() = delete;
	MouseButtonEvent(GLFWwindow *const &window, const int &button, const int &action, const int &mods);
	MouseButtonEvent(const MouseButtonEvent &src);
	MouseButtonEvent &operator=(const MouseButtonEvent &src);
	~MouseButtonEvent();
};

struct MouseMotionEvent : public Event {
	double xpos;
	double ypos;

	MouseMotionEvent() = delete;
	MouseMotionEvent(GLFWwindow *const &window, const double &xpos, const double &ypos);
	MouseMotionEvent(const MouseMotionEvent &src);
	MouseMotionEvent &operator=(const MouseMotionEvent &src);
	~MouseMotionEvent();
};

struct MouseEnterEvent : public Event {
	bool entered;

	MouseEnterEvent() = delete;
	MouseEnterEvent(GLFWwindow *const &window, const bool &entered);
	MouseEnterEvent(const MouseEnterEvent &src);
	MouseEnterEvent &operator=(const MouseEnterEvent &src);
	~MouseEnterEvent();
};

struct MouseScrollEvent : public Event {
	double xoffset;
	double yoffset;

	MouseScrollEvent() = delete;
	MouseScrollEvent(GLFWwindow *const &window, const double &xoffset, const double &yoffset);
	MouseScrollEvent(const MouseScrollEvent &src);
	MouseScrollEvent &operator=(const MouseScrollEvent &src);
	~MouseScrollEvent();
};

struct WindowMotionEvent : public Event {
	int xpos;
	int ypos;

	WindowMotionEvent() = delete;
	WindowMotionEvent(GLFWwindow *const &window, const int &xpos, const int &ypos);
	WindowMotionEvent(const WindowMotionEvent &src);
	WindowMotionEvent &operator=(const WindowMotionEvent &src);
	~WindowMotionEvent();
};

struct WindowResizeEvent : public Event {
	int width;
	int height;

	WindowResizeEvent() = delete;
	WindowResizeEvent(GLFWwindow *const &window, const int &width, const int &height);
	WindowResizeEvent(const WindowResizeEvent &src);
	WindowResizeEvent &operator=(const WindowResizeEvent &src);
	~WindowResizeEvent();
};

struct WindowCloseEvent : public Event {
	WindowCloseEvent() = delete;
	WindowCloseEvent(GLFWwindow *const &window);
	WindowCloseEvent(const WindowCloseEvent &src);
	WindowCloseEvent &operator=(const WindowCloseEvent &src);
	~WindowCloseEvent();
};

struct WindowRefreshEvent : public Event {
	WindowRefreshEvent() = delete;
	WindowRefreshEvent(GLFWwindow *const &window);
	WindowRefreshEvent(const WindowRefreshEvent &src);
	WindowRefreshEvent &operator=(const WindowRefreshEvent &src);
	~WindowRefreshEvent();
};

struct WindowFocusEvent : public Event {
	bool focused;

	WindowFocusEvent() = delete;
	WindowFocusEvent(GLFWwindow *const &window, const bool &focused);
	WindowFocusEvent(const WindowFocusEvent &src);
	WindowFocusEvent &operator=(const WindowFocusEvent &src);
	~WindowFocusEvent();
};

struct WindowIconifyEvent : public Event {
    bool iconified;

    WindowIconifyEvent() = delete;
    WindowIconifyEvent(GLFWwindow *const &window, const bool &iconified);
    WindowIconifyEvent(const WindowIconifyEvent &src);
    WindowIconifyEvent &operator=(const WindowIconifyEvent &src);
    ~WindowIconifyEvent();
};

struct FrameBufferResizeEvent : public Event {
    int width;
    int height;

    FrameBufferResizeEvent() = delete;
    FrameBufferResizeEvent(GLFWwindow *const &window, const int &width, const int &height);
    FrameBufferResizeEvent(const FrameBufferResizeEvent &src);
    FrameBufferResizeEvent &operator=(const FrameBufferResizeEvent &src);
    ~FrameBufferResizeEvent();
};

#endif // EVENT_H
