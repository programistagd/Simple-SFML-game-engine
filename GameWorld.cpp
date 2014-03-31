/* 
 * File:   GameWorld.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 17:45
 */

#include <list>
#include <set>

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
            entitiesByType[(*i)->getType()].remove(*i);
            delete *i;
            i=entities.erase(i);
        }
    }
    for(GameObject* i : entities){
        i->update(dt);
    }
}

void GameWorld::addObject(GameObject* object){
    if(object==nullptr) return;
    entities.push_back(object);
    entitiesByType[object->getType()].push_back(object);
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

void GameWorld::cleanUp(){
    /*std::set<Observer*> toRemove;
    for(std::map<std::string,std::list<Observer*>>::iterator i = observers.begin();i!=observers.end();i++){
        for(Observer* o : (i->second))
                toRemove.insert(o);
    }
    for(Observer* o : toRemove){
        delete [] o;
    }*/ //observers should be removed by owners
    for(GameObject* obj : entities){
        delete [] obj;
    }
    observers.clear();
    entities.clear();
}

const std::list<GameObject*>& GameWorld::getEntitiesOfType(std::string typeName){
    return entitiesByType[typeName];
}