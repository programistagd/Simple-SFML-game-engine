/* 
 * File:   GameWorld.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 17:45
 */

#ifndef GAMEWORLD_HPP
#define	GAMEWORLD_HPP

#include "GameObject.hpp"
#include <list>

class GameWorld {
public:
    GameWorld(sf::RenderWindow& window);
    void update(float dt);
    void renderFrame();
    void addObject(GameObject* object);
    virtual ~GameWorld();
private:
    sf::RenderWindow& window;
    std::list<GameObject*> entities;
};

#endif	/* GAMEWORLD_HPP */

