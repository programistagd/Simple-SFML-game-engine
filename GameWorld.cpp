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
    dim.setFillColor(sf::Color(255,255,255,90));
}

GameWorld::~GameWorld() {
}

void GameWorld::renderFrame(){
    for(GameObject* i : entities){
        i->draw(window);
    }
    if(paused){
        sf::Vector2f size = window.getView().getSize();
        dim.setPosition(window.getView().getCenter()-0.5f*size);
        dim.setSize(size);
        window.draw(dim);
    }
}

void GameWorld::update(float dt){
    sf::View view = window.getView();
    if(view.getCenter()!=viewCenter){
        view.setCenter(view.getCenter()*0.9f+viewCenter*0.1f);
        window.setView(view);
    }
    
    for(std::list<GameObject*>::iterator i = entities.begin();i!=entities.end();i++){//remove "dead" enities
        if((*i)->shouldBeRemoved()){
            entitiesByType[(*i)->getType()].remove(*i);
            delete *i;
            i=entities.erase(i);
        }
    }
    
    if(paused){
        return;
    }
    for(GameObject* i : entities){
        i->update(dt);
    }
}

void GameWorld::addObject(GameObject* object){
    if(object==nullptr) return;
    entities.push_back(object);
    entitiesByType[object->getType()].push_back(object);
    updateZOrder();
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
        delete obj;
    }
    observers.clear();
    entities.clear();
}

const std::list<GameObject*>& GameWorld::getEntitiesOfType(std::string typeName){
    if(typeName == "" or typeName == "*") return entities;
    return entitiesByType[typeName];
}

void GameWorld::moveView(sf::Vector2f newCenter){
    viewCenter = newCenter;
}

bool compareZObj(const GameObject* a, const GameObject* b){
    return (a->getZIndex()<b->getZIndex());
}

void GameWorld::updateZOrder(){
    entities.sort(compareZObj);
}