/* 
 * File:   GameWorld.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 17:45
 */

#ifndef GAMEWORLD_HPP
#define	GAMEWORLD_HPP

#include "GameObject.hpp"
class Observer;
#include "Observer.hpp"
#include <list>
#include <SFML/Graphics/RectangleShape.hpp>

class GameWorld {
    friend ResourceManager;
public:
    GameWorld(sf::RenderWindow& window);
    void update(float dt);
    void renderFrame();
    void addObject(GameObject* object);
    virtual ~GameWorld();
    
    void addObserver(Observer* o);
    void removeObserver(Observer* o);
    
    const std::list<GameObject*>& getEntitiesOfType(std::string typeName);
    
    void notify(GameObject* object, std::string event);
    
    void moveView(sf::Vector2f newCenter);
    
    void cleanUp();

    inline bool isPaused() const {
        return paused;
    }

    inline void setPaused(bool paused) {
        this->paused = paused;
    }

    
    
private:
    sf::RenderWindow& window;
    std::list<GameObject*> entities;
    std::map<std::string, std::list<GameObject*>> entitiesByType;
    std::map<std::string,std::list<Observer*>> observers;
    
    sf::Vector2f viewCenter = sf::Vector2f(400,300);
    
    bool paused = false;
    
    sf::RectangleShape dim;
};

#endif	/* GAMEWORLD_HPP */

