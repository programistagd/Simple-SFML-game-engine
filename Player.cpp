/* 
 * File:   Player.cpp
 * Author: radek
 * 
 * Created on 30 marzec 2014, 21:19
 */

#include "Player.hpp"
#include "Obstacle.hpp"
#include "Edible.hpp"

Player::Player() : observer(*this){
}

Player::~Player() {
}

void Player::update(float dt){
    
    //MECHANICS
    eating-=3.f*dt;
    
    if(eating<0.f){
        world->changeScene("ending1.lvl");
    }
    if(health<0.f){
        world->changeScene("ending1.lvl");//TODO end2
    }
    
    
    // COLLISIONS
    //probably only dynamic obj in the game
    //try to move (differential x" equation (with g force and movement v))
    //each axis separately
    //if collides, try with half of speed until speed*dt <=1 or until it doesn't collide
    //what about force? maybe turn it off in following steps //TODO
    sf::Vector2f dx;
    dx = velocity*dt + 0.5f*acceleration*dt*dt;
    velocity += acceleration*dt;
    //Y-axis
    if(collides(vertical+image.getPosition()+dx)){ //normal version
        bool collision = true;
        for(int i=0;i<7;i++){
            dx.y*=0.5f;
            velocity.y*=0.5f;
            if(!collides(vertical+image.getPosition()+dx)){
                collision = false;
                break;
            }
        }
        if(collision){
            dx.y = 0;
            velocity.y = 0;
        }
    }
    
    if(collides(horizontal+image.getPosition()+dx)){
        bool collision = true;
        for(int i=0;i<7;i++){
            dx.x*=0.5f;
            velocity.x*=0.5f;
            if(!collides(horizontal+image.getPosition()+dx)){
                collision = false;
                break;
            }
        }
        if(collision){
            dx.x = 0;
            velocity.x = 0;
        }
    }
    image.setPosition(image.getPosition()+dx);
    world->moveView(image.getPosition()+0.5f*sf::Vector2f(image.getTexture()->getSize()));
}

void Player::draw(sf::RenderWindow& window){
    window.draw(image);
    
    //draw bars
    sf::RectangleShape b1,b2;
    b1.setPosition(image.getPosition()+sf::Vector2f(20, -30));
    b1.setSize(sf::Vector2f(health*.5f, 10));
    b1.setFillColor(sf::Color(255,0,0,160));
    window.draw(b1);
    b1.setPosition(image.getPosition()+sf::Vector2f(20, -20));
    b1.setSize(sf::Vector2f(eating*.5f, 10));
    b1.setFillColor(sf::Color(255,255,0,160));
    window.draw(b1);
}

const std::string Player::getType(){
    return "Player";
}

GameObject* Player::create(GameWorld& world, ResourceManager* rm, std::stringstream& in){
    Player* obj = new Player();
    obj->world = &world;
    float x,y;
    in>>x>>y;
    obj->image.setTexture(*rm->loadTexture("player.png"));
    obj->image.setPosition(x,y);
    
    obj->horizontal.start = sf::Vector2f(0,0+4);
    obj->horizontal.end = sf::Vector2f(obj->image.getTexture()->getSize().x,obj->image.getTexture()->getSize().y-8);
    //obj->horizontal.start = sf::Vector2f(0,obj->image.getTexture()->getSize().y/2.f);
    //obj->horizontal.end = sf::Vector2f(obj->image.getTexture()->getSize().x,obj->image.getTexture()->getSize().y/2.f);
    
    obj->vertical.start = sf::Vector2f(obj->image.getTexture()->getSize().x/2.f, 0);
    obj->vertical.end = sf::Vector2f(obj->image.getTexture()->getSize().x/2.f,obj->image.getTexture()->getSize().y);
    
    obj->feet.start = sf::Vector2f(5, obj->image.getTexture()->getSize().y-2);
    obj->feet.end = sf::Vector2f(obj->image.getTexture()->getSize().x-10, obj->image.getTexture()->getSize().y+5);
    
    world.addObserver(&obj->observer);
    
    return obj;
}


bool Player::collides(AABB aabb){
    for(GameObject* obj : world->getEntitiesOfType("Obstacle")){
        Obstacle* o = reinterpret_cast<Obstacle*>(obj);
        if(o->isJumpable()){
            if((velocity.y<=0.f || aabb.end.y-6>o->aabb.start.y) && !(aabb.start-aabb.end == feet.start - feet.end)) continue;
        }
        if(aabb.collides(o->aabb))
            return true;
    }
    return false;
}

Player::PlayerObserver::PlayerObserver(Player& p) : player(p){
    events.push_back("PressLeft");
    events.push_back("ReleaseLeft");
    events.push_back("PressRight");
    events.push_back("ReleaseRight");
    events.push_back("PressUp");
    events.push_back("PressDown");
    events.push_back("EdibleCollision");
}

std::vector<std::string> Player::PlayerObserver::getObservedEvents(){
    return events;
}

void Player::PlayerObserver::notify(GameObject* object, std::string event){
    static bool left=false, right=false;
    if(event == "PressLeft")
        left = true;
    if(event == "PressRight")
        right = true;
    if(event == "ReleaseLeft")
        left = false;
    if(event == "ReleaseRight")
        right = false;
    if(event == "PressUp" && (player.doubleJump || player.collides(player.feet+player.image.getPosition()))){
        player.velocity.y = -player.acceleration.y;
        player.doubleJump=!player.doubleJump;
    }
    if(event == "PressDown" && !player.collides(player.feet+player.image.getPosition()))
        player.velocity.y += player.acceleration.y;
    
    if(left&&right);
    else if(left)
        player.velocity.x = -player.speed;
    else if(right)
        player.velocity.x = player.speed;
    else
        player.velocity.x = 0;
    
    if(event == "EdibleCollision"){
        
        Edible* edible = reinterpret_cast<Edible*>(object);
        
        if(edible->hp>0){
            player.eating+=edible->hp;
        }
        else{
            player.health+=edible->hp;
        }
        
        object->destroy();
    }
}

Player::PlayerObserver::~PlayerObserver(){
    
}

std::string Player::dumpToString(){
    std::stringstream s;
    s<<getType()<<" "<<image.getPosition().x<<" "<<image.getPosition().y;
    return s.str();
}

bool Player::intersects(sf::Vector2f point){
    AABB pt;
    pt.start = point;
    pt.end = point;
    return pt.collides(getAABB());
}

void Player::move(sf::Vector2f relative){
    image.setPosition(relative);
}

int Player::getZIndex() const{
    return 100;
}