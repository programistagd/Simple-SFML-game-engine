/* 
 * File:   Obstacle.cpp
 * Author: radek
 * 
 * Created on 4 kwiecień 2014, 19:13
 */

#include "Obstacle.hpp"

Obstacle::Obstacle() {
}

Obstacle::~Obstacle() {
}

void Obstacle::update(float dt){
    
}

void Obstacle::draw(sf::RenderWindow& window){
    window.draw(image);
}

const std::string Obstacle::getType(){
    return "Obstacle";
}

GameObject* Obstacle::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    Obstacle* obj = new Obstacle();
    float x,y;
    std::string texture;
    in>>texture>>x>>y;
    sf::Texture* tex = rm->loadTexture(texture);
    obj->image.setTexture(*tex);
    obj->image.setPosition(x,y);
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
    
    return obj;
}