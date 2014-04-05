/* 
 * File:   Edible.cpp
 * Author: radek
 * 
 * Created on 4 kwiecień 2014, 23:17
 */

#include "Edible.hpp"
#include "Player.hpp"

Edible::Edible() {
}

Edible::~Edible() {
}

void Edible::update(float dt){
    for(GameObject* obj : world->getEntitiesOfType("Player")){
        Player* player = reinterpret_cast<Player*> (obj);
        if(player->getAABB().collides(aabb)){
            world->notify(this, "EdibleCollision");
        }
    }
}

void Edible::draw(sf::RenderWindow& window){
    window.draw(image);
}

const std::string Edible::getType(){
    return "Edible";
}

GameObject* Edible::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    Edible* obj = new Edible();
    obj->world = &world;
    float x,y;
    std::string texture;
    in>>texture>>x>>y;
    //TODO check if texture <= template, then use it
    sf::Texture* tex = rm->loadTexture(texture);
    obj->image.setTexture(*tex);
    obj->image.setPosition(x,y);
    
    
        obj->aabb.start = sf::Vector2f(0,0);
        obj->aabb.end = sf::Vector2f(tex->getSize().x,tex->getSize().y);
    
    obj->aabb=obj->aabb+sf::Vector2f(x,y);
    
    obj->textureName = texture;
    
    return obj;
}

std::string Edible::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<textureName<<" "<<image.getPosition().x<<" "<<image.getPosition().y;
    return s.str();
}

bool Edible::intersects(sf::Vector2f point){
    AABB pt;
    pt.start = point;
    pt.end = point;
    return pt.collides(aabb);
}

void Edible::move(sf::Vector2f relative){
    aabb = aabb + (-1.f*image.getPosition());
    image.setPosition(relative);
    aabb = aabb + image.getPosition();
}