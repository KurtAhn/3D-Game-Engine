#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

class EventListener {
public:
    virtual ~EventListener() = 0;
};

class KeyListener : public EventListener {
public:
	virtual void keyPressed(KeyEvent *const &e) = 0;
	virtual void keyTyped(CharEvent *const &e) = 0;
};

class MouseListener : public EventListener {
public:
	virtual void mouseButtonPressed(MouseButtonEvent *const &e) = 0;
	virtual void mouseCursorMoved(MouseMotionEvent *const &e) = 0;
	virtual void mouseCursorEntered(MouseEnterEvent *const &e) = 0;
	virtual void mouseWheelScrolled(MouseScrollEvent *const &e) = 0;
};

class WindowListener : public EventListener {
public:
	virtual void windowMoved(WindowMotionEvent *const &e) = 0;
	virtual void windowResized(WindowResizeEvent *const &e) = 0;
	virtual void windowClosing(WindowCloseEvent *const &e) = 0;
	virtual void windowRefreshed(WindowRefreshEvent *const &e) = 0;
	virtual void windowFocused(WindowFocusEvent *const &e) = 0;
	virtual void windowIconified(WindowIconifyEvent *const &e) = 0;
	virtual void frameBufferResized(FrameBufferResizeEvent *const &e) = 0;
};

#endif // EVENTLISTENER_H
