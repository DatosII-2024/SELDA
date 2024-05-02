#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "glog/logging.h"
#ifndef SELDA_GAME_H
#define SELDA_GAME_H
using namespace sf;

class Game {
private:
    RenderWindow window;
public:
    Game() ;
    ~Game();
protected:
    void move();
    void sword();
    void scudo();
};

#endif //SELDA_GAME_H
