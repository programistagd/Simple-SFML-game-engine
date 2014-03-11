/* 
 * File:   QuadTree.cpp
 * Author: radek
 * 
 * Created on 10 marzec 2014, 20:57
 */

#include "QuadTree.hpp"

namespace QuadTree{

QuadTree::QuadTree() {
}

QuadTree::~QuadTree() {
    
}

//void QuadTree::traverseWithNeighbors1(Array2d<QuadTree*,2> nodes, std::function<bool(Array2d<QuadTree*,2>)> condition, std::function<void(Array2d<QuadTree*,2>)> action, bool continueAfterCondition){
//    if(condition(nodes)){
//        action(nodes);
//        if(!continueAfterCondition) return;
//    }
//    if(nodes.areAllNull()) return;//we are at leaf so nothing to continue with
//    Array2d<QuadTree*,4> children = goDownTree(nodes);
//}

Area::Area(glm::vec2 start, glm::vec2 end):start(start),end(end){}

Area::Area(){
    start = glm::vec2(0);
    end=glm::vec2(1);
}

Array<Area,4> Area::split(){
    Array<Area,4> r;
    glm::vec2 half = (start+end)*0.5f;
    r[0].start=start;
    r[0].end = start + 0.5f*half;
    r[1].start = glm::vec2(half.x, start.y);
    r[1].end = glm::vec2(end.x, half.y);
    r[2].start = glm::vec2(start.x,half.y);
    r[2].end = glm::vec2(half.x, end.y);
    r[3].start = start + 0.5f*half;
    r[3].end = end;
    return r;
}

};