/* 
 * File:   QuadTree.hpp
 * Author: radek
 *
 * Created on 10 marzec 2014, 20:57
 */

#ifndef QUADTREE_HPP
#define	QUADTREE_HPP

#include <glm/glm.hpp>
#include "Array2d.hpp"
#include <functional>

namespace QuadTree{

    struct QuadTree {
        QuadTree();
        QuadTree* children[4];
        bool sign;
        glm::vec2 position;
        virtual ~QuadTree();
        
        inline bool hasChildren(){
            return (children[0]!=nullptr);//an assertion
            ///
            for(unsigned int i = 0; i<4;i++)
                if(children[i]!=nullptr) return true;
            return false;
        }
    };

    //I wanted to make an universal function and use it everywhere with function pointers, but we want speed so each function will be specialized, program memory is not a big deal
    //void mergeTrees(QuadTree* destination, QuadTree* modifier, glm::vec3
    
    struct Area{
        glm::vec2 start, end;
        Area();
        Area(glm::vec2 start, glm::vec2 end);
        Array<Area,4> split();
    };
    
    //void increaseLOD(QuadTree* start, )
    

};



/*
 * 
 * this code was really nice and universal etc. but it got too bulky and complicated, we don't need to handle so many cases
 * we need specialized, fast and readable code
 * for now we only need 1 neighbor in each direction and maybe 2 for special operations
 * 
 * 
 template<int N> Array2d<QuadTree*,2*N> goDownTree(const Array2d<QuadTree*,N>& nodes){//optimization possible: only parts of neighbours needed?
        Array2d<QuadTree*, 2*N> ret;
        for(unsigned int x=0;x<N;x++){
            for(unsigned int y=0;y<N;y++){
                for(unsigned int i=0;i<2;i++){
                    for(unsigned int j=0;j<2;j++){
                        QuadTree* v = nodes.get(x,y);
                        if(v==nullptr)
                            ret.get(2*x+i,2*y+j) = nullptr;
                        else
                            ret.get(2*x+i,2*y+j) = (v->children[i+2*j]!=nullptr) ? (v->children[i+2*j]) : v;
                    }
                }
            }
        }
        return ret;
    }

    template <int leftNeighbors, int rightNeighbors> void traverseWithNeighbors(Array2d<QuadTree*,(leftNeighbors+1+rightNeighbors)> nodes, std::function<bool(Array2d<QuadTree*,(leftNeighbors+1+rightNeighbors)>)> condition, std::function<void(Array2d<QuadTree*,(leftNeighbors+1+rightNeighbors)>)> action, bool continueAfterCondition, bool extendWithNeighbors){
        if(nodes.get(leftNeighbors,leftNeighbors)==nullptr)return;//if the center node is leaf, we're done
        if(condition(nodes)){
            action(nodes);
            if(!continueAfterCondition) return;
        }
        //if(nodes.areAllNull()) return;//we are at leaf so nothing to continue with //this optimizaion could be removed, but may be nice
        
        Array2d<QuadTree*,2*(leftNeighbors+1+rightNeighbors)> children = goDownTree(nodes);

        for(unsigned int i=0;i<2;i++){
            for(unsigned int j=0;j<2;j++){
                if(nodes.get(leftNeighbors,leftNeighbors)->children[i+2*j]==nullptr && !extendWithNeighbors) continue;
                Array2d<QuadTree*,(leftNeighbors+1+rightNeighbors)> destination;
                for(unsigned int iprim=0;iprim<(leftNeighbors+1+rightNeighbors);iprim++){
                    for(unsigned int jprim=0;jprim<(leftNeighbors+1+rightNeighbors);jprim++){
                        destination.get(iprim,jprim) = children.get(leftNeighbors+i+iprim,leftNeighbors+j+jprim);
                    }
                }
                //TODO make sure algorithm will terminate, try to nullify some leaves, like check nodes neighbors if having children and if noone has then give up
                traverseWithNeighbors<leftNeighbors,rightNeighbors>(destination, condition, action, continueAfterCondition, extendWithNeighbors);
            }
        }

    }
 */

#endif	/* QUADTREE_HPP */

