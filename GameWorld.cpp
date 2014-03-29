/* 
 * File:   GameWorld.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 17:45
 */

#include <list>

#include "GameWorld.hpp"

GameWorld::GameWorld(sf::RenderWindow& window) :window(window) {
}

GameWorld::~GameWorld() {
}

void GameWorld::renderFrame(){
    for(GameObject* i : entities){
        i->draw(window);
    }
}

void GameWorld::update(float dt){
    for(std::list<GameObject*>::iterator i = entities.begin();i!=entities.end();i++){//remove "dead" enities
        if((*i)->shouldBeRemoved())
            i=entities.erase(i);
    }
    for(GameObject* i : entities){
        i->update(dt);
    }
}