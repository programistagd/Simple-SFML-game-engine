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

#include <fstream>

#include "GameObject.hpp"
#include "GameWorld.hpp"
#include "ResourceManager.hpp"
#include "StaticObject.hpp"
#include "Obstacle.hpp"
#include "Edible.hpp"
#include "Player.hpp"

#include <iostream>

const unsigned int WIDTH=800,HEIGHT=600;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    window.setVerticalSyncEnabled(true);
    window.setView(sf::View(sf::Vector2f(-500,300), sf::Vector2f(WIDTH, HEIGHT)));
    
    GameWorld world(window);
    ResourceManager resourceManager;
    resourceManager.registerType(new StaticObject());
    resourceManager.registerType(new Obstacle());
    resourceManager.registerType(new Edible());
    resourceManager.registerType(new Player());
    std::fstream gameFile("level1.lvl");
    resourceManager.loadWorld(world, gameFile);
    
    std::stringstream temporaryFile;
    resourceManager.saveWorld(world, temporaryFile);
    
    sf::Clock timer;
    
    sf::Vector2f editorMovement;
    
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
                        editorMovement.x = -10.f;
                        break;
                    case sf::Keyboard::Right:
                        world.notify(nullptr, std::string("PressRight"));
                        editorMovement.x = 10.f;
                        break;
                    case sf::Keyboard::Up:
                        world.notify(nullptr, std::string("PressUp"));
                        editorMovement.y = -10.f;
                        break;
                    case sf::Keyboard::Down:
                        world.notify(nullptr, std::string("PressDown"));
                        editorMovement.y = 10.f;
                        break;
                    case sf::Keyboard::P:
                        bool _pp = world.isPaused();
                        if(_pp){
                            temporaryFile.str("");
                            temporaryFile.clear();
                            resourceManager.saveWorld(world, temporaryFile);
                            std::cout<<temporaryFile.str()<<"\n\n\n";
                        }
                        else{
                            world.cleanUp();
                            resourceManager.loadWorld(world, temporaryFile);
                        }
                        world.setPaused(!_pp);
                        break;
                }
            }
            if (event.type == sf::Event::KeyReleased){
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        world.notify(nullptr, std::string("ReleaseLeft"));
                        editorMovement.x = 0.f;
                        break;
                    case sf::Keyboard::Right:
                        world.notify(nullptr, std::string("ReleaseRight"));
                        editorMovement.x = 0.f;
                        break;
                    case sf::Keyboard::Down:
                        world.notify(nullptr, std::string("ReleaseUp"));
                        editorMovement.y = 0.f;
                        break;
                    case sf::Keyboard::Up:
                        world.notify(nullptr, std::string("ReleaseDown"));
                        editorMovement.y = 0.f;
                        break;
                }
            }
            // catch the resize events
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::View v = window.getView();
                v.setSize(event.size.width,event.size.height);
                window.setView(v);
            }
        }
        
        if(world.isPaused()){
            world.moveView(window.getView().getCenter()+editorMovement*dt*170.f);
        }
        
        world.update(dt);

        window.clear(sf::Color::Black);
        world.renderFrame();
        window.display();
    }
    
    return 0;
}

