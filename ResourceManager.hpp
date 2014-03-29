/* 
 * File:   ResourceManager.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 18:09
 */

#ifndef RESOURCEMANAGER_HPP
#define	RESOURCEMANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>
class GameWorld;
#include "GameWorld.hpp"

class ResourceManager {
public:
    ResourceManager();
    virtual ~ResourceManager();
    sf::Texture* loadTexture(std::string file);
    
    void loadWorld(GameWorld& world, std::string file);
private:
    std::map<std::string, sf::Texture> textures;
};

#endif	/* RESOURCEMANAGER_HPP */

