#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include "EventListener.h"

class MouseListener : public EventListener {
public:
    MouseListener() = default;
    MouseListener(const MouseListener &src) = delete;
    MouseListener &operator=(const MouseListener &src) = delete;
    virtual ~MouseListener() = 0;


public:
	virtual void mouseButtonPressed(MouseButtonEvent *const &e) = 0;
	virtual void mouseCursorMoved(MouseMotionEvent *const &e) = 0;
	virtual void mouseCursorEntered(MouseEnterEvent *const &e) = 0;
	virtual void mouseWheelScrolled(MouseScrollEvent *const &e) = 0;
};

#endif // MOUSELISTENER_H
