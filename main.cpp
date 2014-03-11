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
#include <glm/gtx/simd_vec4.hpp>
#include <SFML/Graphics/Color.hpp>

#include "QuadTree.hpp"

//#include "VoxelGrid.h"

const unsigned int WIDTH=800,HEIGHT=600;
sf::Uint8* targetData;
bool leftMouse = false,rightMouse = false;
unsigned char currentMaterial = 0;
glm::ivec2 cursorPos;
/*
 * 
 */
int main(int argc, char** argv) {
    
    //little testbed
    
    QuadTree::QuadTree* t=nullptr;
    Array2d<QuadTree::QuadTree*, 1> a;
    /*a.get(0,0) = t;
    QuadTree::traverseWithNeighbors<0,0>(a,nullptr, nullptr, false, false);*/
    
    
    //eot
    
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Image");
    window.setVerticalSyncEnabled(true);
    
    targetData = new sf::Uint8[WIDTH*HEIGHT*4];
    
    sf::Texture targetTex;
    sf::Sprite screenQuad;
    targetTex.create(WIDTH,HEIGHT);
    screenQuad.setTexture(targetTex);
    
    sf::CircleShape cursor(10);
    cursor.setOrigin(10,10);
    cursor.setFillColor(sf::Color(255,50,50,90));
    cursor.setOutlineColor(sf::Color(50,50,255,150));
    cursor.setOutlineThickness(2.f);
    
    //VoxelGrid grid(WIDTH/40,HEIGHT/40,40,targetData);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                if(event.key.code==sf::Keyboard::Space){
                    currentMaterial = (4+currentMaterial+1)%4;
                    
                }
               
            }
            if(event.type==sf::Event::MouseMoved){
                cursorPos.x = glm::round(event.mouseMove.x/40.f);
                cursorPos.y = glm::round(event.mouseMove.y/40.f);
                cursorPos.x = glm::clamp(cursorPos.x,0,int(WIDTH)/40-1);
                cursorPos.y = glm::clamp(cursorPos.y,0,int(HEIGHT)/40-1);
                cursor.setPosition(cursorPos.x*40,cursorPos.y*40);
            }
            if(event.type==sf::Event::MouseButtonPressed){
                if(event.mouseButton.button==sf::Mouse::Button::Left)
                        leftMouse=true;
                if(event.mouseButton.button==sf::Mouse::Button::Right)
                        rightMouse=true;
            }
            if(event.type==sf::Event::MouseButtonReleased){
                if(event.mouseButton.button==sf::Mouse::Button::Left)
                        leftMouse=false;
                if(event.mouseButton.button==sf::Mouse::Button::Right)
                        rightMouse=false;
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if(leftMouse){
            
        }
        if(rightMouse){
            
        }
        
        
        window.clear(sf::Color::Black);
        //grid.update();
        targetTex.update(targetData);
        window.draw(screenQuad);
        window.draw(cursor);
        window.display();
    }
    
    return 0;
}

