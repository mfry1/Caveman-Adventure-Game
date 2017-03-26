/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef FOREST_HPP
#define FOREST_HPP
#include "space.hpp"
#include <string>

class Forest : public Space 
{
  private: 
    bool obstaclesExist,  // An obstacle may exist to block moving in 1 direction 
         berriesExist;    // Berries may exist. Berries are food that is obtained without combat 
    string obstacleText1;  // Text displayed when user enters space to notify them of the obstacle 
    int obstacleDirection; // Direction obstacle is blocking 
    Space* obstacleTemp;  
    
  public: 
    Forest();
    void setTreeObstacle(int,string); 
    void enterSpace(Caveman*);
    Creature* searchSpace(Caveman*); 
    void setItem();
    void setEnemy();
};

#endif