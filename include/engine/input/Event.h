#ifndef EVENT_H
#define EVENT_H

#include "Common.h"
struct Event {
	Event() = default;
	Event(const Event &src) = delete;
	Event &operator=(const Event &e) = delete;
	virtual ~Event();

	virtual bool operator==(const Event &e) const = 0;
};

struct KeyEvent : public Event {
	int key;
	int action;

	KeyEvent() = delete;
	explicit KeyEvent(const int &key, const int &action);
	KeyEvent(const KeyEvent &e);
	KeyEvent &operator=(const KeyEvent &e);
	~KeyEvent();

	bool operator==(const Event &e) const; /*{return false;}*/
	bool operator==(const KeyEvent &e) const; /*{
		return key == e.key && action == e.action;
	}*/
};

//struct MouseButtonEvent : public Event {};

namespace std {
	template<>
	struct hash<Event *> {
	    size_t operator()(const Event *const &) const {
            return 0;
	    }

		size_t operator()(const KeyEvent *const &e) const {
			return hash<int>()(e->key) / 2 + hash<int>()(e->action);
		}
	};
}

#endif // EVENT_H
