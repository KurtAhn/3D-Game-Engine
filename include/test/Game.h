#ifndef GAME_H
#define GAME_H

#include "Engine.h"

class Game {
private:
	Game();
	explicit Game(const std::string &save);
	Game(const Game &src) = delete;
	Game &operator=(const Game &src) = delete;
public:
	~Game();
	
private:
	Engine engine;
	
};

#endif //GAME_H