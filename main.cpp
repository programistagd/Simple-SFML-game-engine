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

const unsigned int WIDTH=800,HEIGHT=600;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    window.setVerticalSyncEnabled(true);
    
    GameWorld world(window);
    
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
        }
        
        world.update(dt);
        
        window.clear(sf::Color::Black);
        world.renderFrame();
        window.display();
    }
    
    return 0;
}

