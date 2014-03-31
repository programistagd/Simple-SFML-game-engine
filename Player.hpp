/* 
 * File:   Player.hpp
 * Author: radek
 *
 * Created on 30 marzec 2014, 21:19
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

class Player : public GameObject{
public:
    Player();
    virtual void draw(sf::RenderWindow& window)=0;
    virtual void update(float dt)=0;

    virtual GameObject* create(ResourceManager* rm, std::stringstream& in);
    virtual const std::string getType()=0;
    
    virtual ~Player();
private:
    //sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Sprite image;

};

#endif	/* PLAYER_HPP */

