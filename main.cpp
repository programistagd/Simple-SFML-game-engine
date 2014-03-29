/* 
 * File:   main.cpp
 * Author: radek
 *
 * Created on 28 styczeń 2014, 12:11
 */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <glm/glm.hpp>
#include <SFML/Graphics/Color.hpp>

#include "GameObject.hpp"
#include "GameWorld.hpp"
#include "ResourceManager.hpp"

const unsigned int WIDTH=800,HEIGHT=600;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    window.setVerticalSyncEnabled(true);
    
    GameWorld world(window);
    ResourceManager resourceManager;
    resourceManager.loadWorld(world, "level1.lvl");
    
    sf::Clock timer;
    while (window.isOpen())
    {
        float dt = timer.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        world.notify(nullptr, std::string("PressLeft"));
                        break;
                    case sf::Keyboard::Right:
                        world.notify(nullptr, std::string("PressRight"));
                        break;
                    case sf::Keyboard::Down:
                        world.notify(nullptr, std::string("PressUp"));
                        break;
                    case sf::Keyboard::Up:
                        world.notify(nullptr, std::string("PressDown"));
                        break;
                }
            }
            if (event.type == sf::Event::KeyReleased){
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        world.notify(nullptr, std::string("ReleaseLeft"));
                        break;
                    case sf::Keyboard::Right:
                        world.notify(nullptr, std::string("ReleaseRight"));
                        break;
                    case sf::Keyboard::Down:
                        world.notify(nullptr, std::string("ReleaseUp"));
                        break;
                    case sf::Keyboard::Up:
                        world.notify(nullptr, std::string("ReleaseDown"));
                        break;
                }
            }
        }
        
        world.update(dt);

        window.clear(sf::Color::Black);
        world.renderFrame();
        window.display();
    }
    
    return 0;
}

