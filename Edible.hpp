/* 
 * File:   Edible.hpp
 * Author: radek
 *
 * Created on 4 kwiecień 2014, 23:17
 */

#ifndef EDIBLE_HPP
#define	EDIBLE_HPP

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

class Edible : public GameObject{
public:
    Edible();
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);
    
    AABB aabb;
    float hp;
    
    virtual GameObject* create(GameWorld& world, ResourceManager* rm, std::stringstream& in);
    virtual std::string dumpToString();
    virtual const std::string getType();
    
    virtual ~Edible();
private:
    sf::Sprite image;
    GameWorld* world;
    std::string textureName;

};
#endif	/* EDIBLE_HPP */

