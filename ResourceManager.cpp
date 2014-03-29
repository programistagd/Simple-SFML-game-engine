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
        std::stringstream line(l);
        
        std::string type;
        line>>type;
        if(type == "StaticObj"){
            world.addObject(StaticObject::create(this, line));
        }
    }
}