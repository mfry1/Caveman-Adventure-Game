/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef RIVER_HPP
#define RIVER_HPP
#include "space.hpp"

class River : public Space 
{
  private: 
    bool weaponUpgradeExists;   // Whether or not the space has a weapon upgrade item 
  public: 
    River();
    Creature* searchSpace(Caveman*);
    void setItem();
    void setEnemy(); 
};

#endif