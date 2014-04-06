/* 
 * File:   TextSign.hpp
 * Author: radek
 *
 * Created on 6 kwiecień 2014, 21:22
 */

#ifndef TEXTSIGN_HPP
#define	TEXTSIGN_HPP

#include "GameObject.hpp"
#include <SFML/Graphics/Text.hpp>

class TextSign : public GameObject{
public:
    TextSign();
    TextSign(std::string text, float x, float y);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);
    
    virtual GameObject* create(GameWorld& world, ResourceManager* rm,  std::stringstream& in);
    virtual const std::string getType();
    
    virtual int getZIndex();
    
    virtual bool intersects(sf::Vector2f point);
    virtual void move(sf::Vector2f relative);
    
    virtual std::string dumpToString();
    
    virtual ~TextSign();
private:
    sf::Text text;
};

#endif	/* TEXTSIGN_HPP */

