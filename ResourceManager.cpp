/* 
 * File:   ResourceManager.cpp
 * Author: radek
 * 
 * Created on 29 marzec 2014, 18:09
 */

#include "ResourceManager.hpp"
#include "StaticObject.hpp"
#include <fstream>
#include <sstream>

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
    for(std::map<std::string, GameObject*>::iterator i=templates.begin();i!=templates.end();i++){
        delete (i->second);
    }
}

sf::Texture*  ResourceManager::loadTexture(std::string file){
    if(textures.find(file)!=textures.end()) return &textures[file];
    
    sf::Texture& tx = textures[file];
    tx.loadFromFile(file);
    return &tx;
}

void ResourceManager::loadWorld(GameWorld& world, std::string file){
    std::fstream f;
    f.open(file);
    if(!f.good()) return;
    
    while(!f.eof()){
        std::string l;
        getline(f, l);
        
        std::stringstream line;
        if(l.find('#')!=std::string::npos){
            line<<l.substr(0, l.find('#'));
        }
        else{
            line<<l;
        }
        std::string type;
        line>>type;
        if(templates[type]!=nullptr){
            world.addObject(templates[type]->create(this, line));
        }
        
    }
}

void ResourceManager::registerType(GameObject* templ){
    templates[templ->getType()] = templ;
}