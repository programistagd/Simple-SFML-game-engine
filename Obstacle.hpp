/* 
 * File:   Obstacle.hpp
 * Author: radek
 *
 * Created on 4 kwiecień 2014, 19:13
 */

#ifndef OBSTACLE_HPP
#define	OBSTACLE_HPP

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

class Obstacle : public GameObject{
public:
    Obstacle();
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);
    
    AABB aabb;
    
    virtual GameObject* create(GameWorld& world, ResourceManager* rm, std::stringstream& in);
    virtual const std::string getType();
    
    virtual ~Obstacle();
private:
    sf::Sprite image;

};

#endif	/* OBSTACLE_HPP */

