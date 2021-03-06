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
#include "TextSign.hpp"
#include "LevelSwitch.hpp"

#include <iostream>

const unsigned int WIDTH=800,HEIGHT=600;

extern bool _world__compareZObj(const GameObject* a, const GameObject* b);

sf::Font globalMainFont;

void saveFile(std::string fname, std::string data){
    std::ofstream out;
    out.open(fname, std::ios::out|std::ios::trunc);
    out<<data;
    out.close();
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    window.setVerticalSyncEnabled(true);
    window.setView(sf::View(sf::Vector2f(-500,300), sf::Vector2f(WIDTH, HEIGHT)));
   
    
    globalMainFont.loadFromFile("FreeSans.ttf");
    
    ResourceManager resourceManager;
    resourceManager.setPath("assets/");
    GameWorld world(window, resourceManager);
    resourceManager.registerType(new StaticObject());
    resourceManager.registerType(new Obstacle());
    resourceManager.registerType(new Edible());
    resourceManager.registerType(new Player());
    resourceManager.registerType(new TextSign());
    resourceManager.registerType(new LevelSwitch());
    {
        std::fstream gameFile("level1.lvl");
        resourceManager.loadWorld(world, gameFile);
    }
    
    std::stringstream temporaryFile;
    resourceManager.saveWorld(world, temporaryFile);
    
    sf::Clock timer;
    
    sf::Vector2f editorMovement;bool editing = false;
    
    /*sf::Vector2f mouseStart;*/
    GameObject* moving=nullptr;
    
    while (window.isOpen())
    {
        if(world.hasChanged()){
            temporaryFile.str("");
            temporaryFile.clear();
            resourceManager.saveWorld(world, temporaryFile);
        }

        
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
                    case sf::Keyboard::Equal:
                    {
                        sf::View vv = window.getView();
                        vv.zoom(.5f);
                        window.setView(vv);
                    }
                    break;
                    case sf::Keyboard::Dash:
                    {
                        sf::View vv = window.getView();
                        vv.zoom(2.f);
                        window.setView(vv);
                    }
                    break;
                    case sf::Keyboard::P:
                        {
                            bool _pp = world.isPaused();
                            if(_pp){
                                if(editing){
                                    temporaryFile.str("");
                                    temporaryFile.clear();
                                    resourceManager.saveWorld(world, temporaryFile);
                                    //std::cout<<temporaryFile.str()<<"\n\n\n";
                                }
                                editing = false;
                                moving = nullptr;
                            }
                            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
                                world.cleanUp();
                                std::stringstream tmpStr(temporaryFile.str());
                                resourceManager.loadWorld(world, tmpStr);
                                editing = true;
                            }
                            world.setPaused(!_pp);
                        }
                        break;
                    case sf::Keyboard::S:
                        {
                            std::stringstream str;
                            resourceManager.saveWorld(world, str);
                            saveFile("savedLevel.lvl", str.str());
                        }
                        break;
                    case sf::Keyboard::R:
                        world.changeScene("savedLevel.lvl");
                        break;
                    case sf::Keyboard::A:
                        std::cout<<"Input spawn pattern: ";
                        std::string s;
                        std::getline(std::cin, s, '\n');
                        std::stringstream sprim(s);
                        resourceManager.loadWorld(world, sprim);//using the feature that world isnt cleared by default
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
            
            if((world.isPaused() || editing) && event.type == sf::Event::MouseButtonPressed){
                sf::Vector2f mouseCur = window.getView().getCenter()+sf::Vector2f(event.mouseButton.x,event.mouseButton.y)-.5f*window.getView().getSize();
                std::list<GameObject*> lista =world.getEntitiesOfType("");
                lista.sort(_world__compareZObj);
                lista.reverse();
                for(GameObject* o : lista ){
                    if(o->intersects(mouseCur)){
                        //mouseStart = mouseCur;
                        moving = o;
                        //std::cout<<"Caught!\n";
                        break;
                    }
                }
            }
            if((world.isPaused() || editing) && event.type == sf::Event::MouseMoved && moving!=nullptr){
                sf::Vector2f mouseCur = window.getView().getCenter()-.5f*window.getView().getSize()+sf::Vector2f(event.mouseMove.x,event.mouseMove.y);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    moving->move(sf::Vector2f(((int)mouseCur.x/35)*35,((int)mouseCur.y/32)*32));
                else
                    moving->move(mouseCur);
            }
            if((world.isPaused() || editing) && event.type == sf::Event::MouseButtonReleased && moving!=nullptr){
                moving = nullptr;
            }
            
        }
        
        if(world.isPaused()){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)||sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                world.moveView(window.getView().getCenter()+editorMovement*dt*600.f);
            else
                world.moveView(window.getView().getCenter()+editorMovement*dt*170.f);
        }
        
        world.update(dt);

        window.clear(sf::Color::Black);
        world.renderFrame();
        window.display();
    }
    
    return 0;
}

