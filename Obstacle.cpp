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
    in>>texture>>x>>y>>obj->jumpable;
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
    
    obj->textureName = texture;
    
    return obj;
}

std::string Obstacle::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<textureName<<" "<<image.getPosition().x<<" "<<image.getPosition().y<<" "<<jumpable;
    if(image.getScale()!=sf::Vector2f(1.f,1.f)){
        s<<" "<<image.getLocalBounds().width<<" "<<image.getLocalBounds().height;
    }
    return s.str();
}

bool Obstacle::intersects(sf::Vector2f point){
    AABB pt;
    pt.start = point;
    pt.end = point;
    return pt.collides(aabb);
}

void Obstacle::move(sf::Vector2f relative){
    aabb = aabb + (-1.f*image.getPosition());
    image.setPosition(relative);
    aabb = aabb + image.getPosition();
}