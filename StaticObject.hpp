/* 
 * File:   StaticObject.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 18:00
 */

#ifndef STATICOBJECT_HPP
#define	STATICOBJECT_HPP

#include "GameObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StaticObject : public GameObject{
public:
    StaticObject();
    StaticObject(sf::Texture* texture, float x, float y);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);
    
    virtual GameObject* create(GameWorld& world, ResourceManager* rm,  std::stringstream& in);
    virtual const std::string getType();
    
    virtual bool intersects(sf::Vector2f point);
    virtual void move(sf::Vector2f relative);
    
    virtual std::string dumpToString();
    
    virtual ~StaticObject();
private:
    sf::Sprite obj;
    std::string textureName;
};

#endif	/* STATICOBJECT_HPP */

