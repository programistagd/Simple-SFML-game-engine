/* 
 * File:   GameObject.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 17:43
 */

#include "GameObject.hpp"

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

GameObject* GameObject::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    return nullptr;
}

AABB AABB::operator +(const sf::Vector2f& v){
    AABB a;
    a.start = start+v;
    a.end = end+v;
    return a;
}

//#include <iostream>

bool AABB::collides(AABB other){
    //std::cout<<start.x<<" "<<start.y<<" "<<end.x<<" "<<end.y<<", ";
    //std::cout<<other.start.x<<" "<<other.start.y<<" "<<other.end.x<<" "<<other.end.y<<"\n";
    if(end.x < other.start.x || end.y < other.start.y || start.x > other.end.x || start.y > other.end.y ) return false;
    return true;
}

int GameObject::getZIndex() const{
    return 0;//default val
}