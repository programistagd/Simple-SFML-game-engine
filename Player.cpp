/* 
 * File:   Player.cpp
 * Author: radek
 * 
 * Created on 30 marzec 2014, 21:19
 */

#include "Player.hpp"

Player::Player() {
}

Player::~Player() {
}

void Player::update(float dt){
    
    // COLLISIONS
    //probably only dynamic obj in the game
    //try to move (differential x" equation (with g force and movement v))
    //each axis separately
    //if collides, try with half of speed until speed*dt <=1 or until it doesn't collide
    //what about force? maybe turn it off in following steps //TODO
}

void Player::draw(sf::RenderWindow& window){
    window.draw(image);
}

const std::string Player::getType(){
    return "Player";
}

GameObject* Player::create(ResourceManager* rm, std::stringstream& in){
    //init pos, aabb, image
}