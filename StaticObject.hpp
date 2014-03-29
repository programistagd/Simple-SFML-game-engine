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
    StaticObject(sf::Texture* texture, float x, float y);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);
    
    static GameObject* create(ResourceManager* rm,  std::stringstream& in);
    
    virtual ~StaticObject();
private:
    sf::Sprite obj;
};

#endif	/* STATICOBJECT_HPP */
