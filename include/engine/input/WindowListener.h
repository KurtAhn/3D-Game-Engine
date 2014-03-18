#ifndef WINDOWLISTENER_H
#define WINDOWLISTENER_H

#include "EventListener.h"

class WindowListener : public EventListener {
public:
    WindowListener() = default;
    WindowListener(const WindowListener &src) = delete;
    WindowListener &operator=(const WindowListener &src) = delete;
    virtual ~WindowListener() = 0;

public:
	virtual void windowMoved(WindowMotionEvent *const &e) = 0;
	virtual void windowResized(WindowResizeEvent *const &e) = 0;
	virtual void windowClosing(WindowCloseEvent *const &e) = 0;
	virtual void windowRefreshed(WindowRefreshEvent *const &e) = 0;
	virtual void windowFocused(WindowFocusEvent *const &e) = 0;
	virtual void windowIconified(WindowIconifyEvent *const &e) = 0;
	virtual void frameBufferResized(FrameBufferResizeEvent *const &e) = 0;
};

#endif // WINDOWLISTENER_H
