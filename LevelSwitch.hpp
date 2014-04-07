/* 
 * File:   LevelSwitch.hpp
 * Author: radek
 *
 * Created on 7 kwiecień 2014, 17:35
 */

#ifndef LEVELSWITCH_HPP
#define	LEVELSWITCH_HPP

#include "Obstacle.hpp"


class LevelSwitch : public Obstacle {
public:
    LevelSwitch();
    
    virtual GameObject* create(GameWorld& world, ResourceManager* rm, std::stringstream& in);
    virtual std::string dumpToString();
    virtual const std::string getType();
    
    virtual ~LevelSwitch();

    inline std::string getNextLevel() const {
        return nextLevel;
    }

private:
    std::string nextLevel;
};

#endif	/* LEVELSWITCH_HPP */

