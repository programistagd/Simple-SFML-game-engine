/* 
 * File:   Player.hpp
 * Author: radek
 *
 * Created on 30 marzec 2014, 21:19
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>
#include "GameWorld.hpp"
#include "Observer.hpp"

class Player : public GameObject{
public:
    Player();
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float dt);

    virtual GameObject* create(GameWorld& world, ResourceManager* rm, std::stringstream& in);
    virtual const std::string getType();
    
    virtual ~Player();
private:
    //sf::Vector2f position;
    sf::Vector2f velocity, acceleration=sf::Vector2f(0,400);
    float speed = 100.f;
    sf::Sprite image;
    bool collides(AABB aabb);
    AABB horizontal, vertical, feet;
    GameWorld* world;
    class PlayerObserver : public Observer{
    public:
        PlayerObserver(Player& p);
        virtual std::vector<std::string> getObservedEvents();
        virtual void notify(GameObject* object, std::string event);
        virtual ~PlayerObserver();
    private:
        std::vector<std::string> events;
        Player &player;
    } observer;
    

};

#endif	/* PLAYER_HPP */

