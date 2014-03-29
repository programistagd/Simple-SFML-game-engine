/* 
 * File:   Observer.hpp
 * Author: radek
 *
 * Created on 29 marzec 2014, 17:44
 */

#ifndef OBSERVER_HPP
#define	OBSERVER_HPP

#include <vector>
#include <string>
#include "GameObject.hpp"

class Observer {
public:
    Observer();
    virtual std::vector<std::string> getObservedEvents()=0;
    virtual void notify(GameObject* object, std::string event)=0;
    virtual ~Observer();
private:

};

#endif	/* OBSERVER_HPP */

