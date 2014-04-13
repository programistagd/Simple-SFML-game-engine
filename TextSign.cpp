/* 
 * File:   TextSign.cpp
 * Author: radek
 * 
 * Created on 6 kwiecień 2014, 21:22
 */

#include "TextSign.hpp"
#include "ResourceManager.hpp"

TextSign::TextSign(){
    
}

extern sf::Font globalMainFont;

TextSign::TextSign(std::string txt, float x, float y){
    text.setFont(globalMainFont);
    text.setCharacterSize(28);
    text.setColor(sf::Color::Black);
    text.setString(txt);
    text.setPosition(x,y);
}

TextSign::~TextSign() {
}

void TextSign::draw(sf::RenderWindow& window){
    window.draw(text);
}

void TextSign::update(float dt){
    
}

GameObject* TextSign::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    float x,y;
    std::string text;
    std::getline(in, text, in.widen('\"'));
    in>>x>>y;
    TextSign* obj = new TextSign(text.substr(1), x,y);
    return obj;
}

std::string TextSign::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<std::string(text.getString())<<"\" "<<text.getPosition().x<<" "<<text.getPosition().y;
    return s.str();
}

const std::string TextSign::getType(){
    return "TextSign";
}

bool TextSign::intersects(sf::Vector2f point){
    if(point.x>text.getPosition().x && point.x<text.getPosition().x+text.getLocalBounds().width && point.y>text.getPosition().y && point.y<text.getPosition().y+text.getLocalBounds().height)
        return true;
    return false;
}

void TextSign::move(sf::Vector2f relative){
    text.setPosition(relative);
}

int TextSign::getZIndex(){
    return 5;
}