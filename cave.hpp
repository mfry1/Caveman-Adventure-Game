/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef CAVE_HPP
#define CAVE_HPP
#include "space.hpp"

class Cave : public Space 
{
  private: 
    bool weaponUpgradeExists;   // Cave can hold the weaponUpgrade ite 
    
  public: 
    Cave();
    Creature* searchSpace(Caveman*);
    void setItem();
    void setEnemy(); 
};

#endif