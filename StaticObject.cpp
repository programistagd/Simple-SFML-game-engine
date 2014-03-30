/* 
 * File:   StaticObject.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 18:00
 */

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

GameObject* StaticObject::create(ResourceManager* rm, std::stringstream& in){
    float x,y;
    std::string texture;
    in>>texture>>x>>y;
    StaticObject* obj = new StaticObject(rm->loadTexture(texture), x,y);
    if(!in.eof()){
        in>>obj->aabb.start.x>>obj->aabb.start.y>>obj->aabb.end.x>>obj->aabb.end.y;
    }
    return obj;
}

std::string StaticObject::getType(){
    return "StaticObject";
}