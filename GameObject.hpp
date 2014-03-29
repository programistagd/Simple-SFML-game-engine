/* 
 * File:   GameObject.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 17:43
 */

#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
public:
    GameObject();
    virtual void draw(sf::RenderWindow& window)=0;
    virtual void update(float dt)=0;
    
    inline bool shouldBeRemoved(){return shouldbedestroyed;}
    virtual ~GameObject();
protected:
    inline void destroy(){shouldbedestroyed=true;}
private:
    bool shouldbedestroyed = false;

};

#endif	/* GAMEOBJECT_HPP */

