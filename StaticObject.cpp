/* 
 * File:   StaticObject.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 18:00
 */

#include <CEGUI/CEGUIExceptions.h>

#include "StaticObject.hpp"
#include "ResourceManager.hpp"

StaticObject::StaticObject(){
    
}

StaticObject::StaticObject(sf::Texture* texture, float x, float y) : obj(*texture){
    obj.setPosition(x,y);
}

StaticObject::~StaticObject() {
}

void StaticObject::draw(sf::RenderWindow& window){
    window.draw(obj);
}

void StaticObject::update(float dt){
    
}

GameObject* StaticObject::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    float x,y;
    std::string texture;
    in>>texture>>x>>y;
    StaticObject* obj = new StaticObject(rm->loadTexture(texture), x,y);
    obj->textureName;
    /*if(!in.eof()){
        in>>obj->aabb.start.x>>obj->aabb.start.y>>obj->aabb.end.x>>obj->aabb.end.y;
    }*/
    return obj;
}

std::string StaticObject::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<textureName<<" "<<obj.getPosition().x<<" "<<obj.getPosition().y;
    return s.str();
}

const std::string StaticObject::getType(){
    return "StaticObject";
}

bool StaticObject::intersects(sf::Vector2f point){
    if(point.x>obj.getPosition().x && point.x<obj.getPosition().x+obj.getTexture()->getSize().x && point.y>obj.getPosition().y && point.y<obj.getPosition().y+obj.getTexture()->getSize().y)
        return true;
    return false;
}

void StaticObject::move(sf::Vector2f relative){
    obj.setPosition(relative);
}