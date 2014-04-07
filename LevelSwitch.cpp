/* 
 * File:   LevelSwitch.cpp
 * Author: radek
 * 
 * Created on 7 kwiecień 2014, 17:35
 */

#include "LevelSwitch.hpp"

LevelSwitch::LevelSwitch() : Obstacle(){
}

LevelSwitch::~LevelSwitch() {
}

GameObject* LevelSwitch::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    LevelSwitch* obj = new LevelSwitch();
    float x,y;
    std::string texture;
    in>>texture>>x>>y>>obj->nextLevel;
    sf::Texture* tex = nullptr;
    if(texture!="None"){
        tex = rm->loadTexture(texture);
        obj->image.setTexture(*tex);
        obj->image.setPosition(x,y);
    }
    if(!in.eof()){
        obj->aabb.start = sf::Vector2f(0,0);
        //obj->aabb.end = sf::Vector2f(0.1,0.1);
        in>>obj->aabb.end.x>>obj->aabb.end.y;
        obj->image.setScale(obj->aabb.end.x/tex->getSize().x,obj->aabb.end.y/tex->getSize().y);
    }
    else{
        obj->aabb.start = sf::Vector2f(0,0);
        obj->aabb.end = sf::Vector2f(tex->getSize().x,tex->getSize().y);
    }
    obj->aabb=obj->aabb+sf::Vector2f(x,y);
    
    obj->textureName = texture;
    
    return obj;
}

std::string LevelSwitch::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<textureName<<" "<<image.getPosition().x<<" "<<image.getPosition().y<<" "<<nextLevel;
    if(image.getScale()!=sf::Vector2f(1.f,1.f)){
        s<<" "<<image.getTexture()->getSize().x*image.getScale().x<<" "<<image.getTexture()->getSize().y*image.getScale().y;
    }
    return s.str();
}

const std::string LevelSwitch::getType(){
    return "LevelSwitch";
}