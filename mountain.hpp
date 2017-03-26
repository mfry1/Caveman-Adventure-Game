/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP
#include "space.hpp"
#include "caveman.hpp"

class Mountain : public Space 
{
  private: 
    bool fireItemExists;  // The fire item can exist in mountain spaces 
  public: 
    Mountain();
    Creature* searchSpace(Caveman*);
    void setItem();
};

#endif