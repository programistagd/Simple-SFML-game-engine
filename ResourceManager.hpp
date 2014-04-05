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
    
    void registerType(GameObject* templ);
    
    void loadWorld(GameWorld& world, std::istream& stream);
    void saveWorld(GameWorld& world, std::ostream& stream);
private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, GameObject*> templates;
};

#endif	/* RESOURCEMANAGER_HPP */

