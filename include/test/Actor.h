#ifndef ACTOR_H
#define ACTOR_H

#include "Engine.h"

/**
 * An interactable game object that "acts" upon other
 * interactable objects based on user input.
 *
 * Activity functions, i.e. Actor member functions that
 * can be called by an InputManager must be placed in
 * InputManager::activities before they can be used.
 */

class Actor : public Camera,
                     KeyListener,
                     MouseListener,
                     WindowListener {
public:
    Actor();
    virtual ~Actor();

private:
    bool movingForward = false;
    bool movingBackward = false;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;

    struct Mouse {
        bool centered = true;
        bool justEntered = true;
        double xpos = 0.0;
        double ypos = 0.0;

    } mouse;

    struct Window {
        int xpos = 0;
        int ypos = 0;
        int width = 0;
        int height = 0;
    } window;

public:
    void update();

public:
    void keyPressed(KeyEvent *const &e);
    void keyTyped(CharEvent *const &e);

	void mouseButtonPressed(MouseButtonEvent *const &e);
	void mouseCursorMoved(MouseMotionEvent *const &e);
	void mouseCursorEntered(MouseEnterEvent *const &e);
	void mouseWheelScrolled(MouseScrollEvent *const &e);

	void windowMoved(WindowMotionEvent *const &e);
	void windowResized(WindowResizeEvent *const &e);
	void windowClosing(WindowCloseEvent *const &e);
	void windowRefreshed(WindowRefreshEvent *const &e);
	void windowFocused(WindowFocusEvent *const &e);
	void windowIconified(WindowIconifyEvent *const &e);
	void frameBufferResized(FrameBufferResizeEvent *const &e);
};

#endif // ACTOR_H
