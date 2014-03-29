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
        if((*i)->shouldBeRemoved()){
            delete *i;
            i=entities.erase(i);
        }
    }
    for(GameObject* i : entities){
        i->update(dt);
    }
}

void GameWorld::addObject(GameObject* object){
    entities.push_back(object);
}

void GameWorld::addObserver(Observer* o){
    for(std::string e : o->getObservedEvents()){
        observers[e].push_back(o);
    }
}

void GameWorld::removeObserver(Observer* o){
    for(std::string e : o->getObservedEvents()){
        observers[e].remove(o);
    }
}

void GameWorld::notify(GameObject* object, std::string event){
    for(Observer* o : observers[event]){
        o->notify(object, event);
    }
}