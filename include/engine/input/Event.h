#ifndef EVENT_H
#define EVENT_H

#include "Common.h"
#include "InputDeclaration.h"

enum EventType {
    KEY_EVENT
};

/**
 * Base Event class. Event objects are generated when
 * user inputs are registered.
 */
struct Event {
    EventType type;

    Event() = delete;
	Event(const EventType &type);
	Event(const Event &src) = delete;
	Event &operator=(const Event &e) = delete;
	virtual ~Event();

	virtual bool operator==(const Event &e);
};

struct KeyEvent : public Event {
	int key;
	int action;

	KeyEvent() = delete;
	explicit KeyEvent(const int &key, const int &action);
	explicit KeyEvent(rapidxml::xml_node<> *const &node);
	KeyEvent(const KeyEvent &e);
	KeyEvent &operator=(const KeyEvent &e);
	~KeyEvent();

	bool operator==(const Event &e) const;
	bool operator==(const KeyEvent &e) const;
};

//struct MouseButtonEvent : public Event {};

namespace std {
	template<>
	struct hash<Event *> {
	    size_t operator()(Event *const &e) const {
            switch (e->type) {
            case KEY_EVENT:
                //std::cout << operator()(static_cast<KeyEvent *const>(e)) << std::endl;
                return operator()(static_cast<KeyEvent *const>(e));
            default: return 0;
            }
	    }

		size_t operator()(KeyEvent *const &e) const {
			return e->key + e->action;
		}
	};

	template<>
	struct equal_to<Event *> {
        bool operator() (Event *const &x, Event *const &y) const {return *x == *y;}
	};
}

#endif // EVENT_H
