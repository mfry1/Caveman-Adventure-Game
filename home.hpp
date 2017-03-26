/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef HOME_HPP
#define HOME_HPP
#include "space.hpp"
#include "Creature.hpp"

class Home : public Space  
{
  private: 
  
  public: 
    Home();
    Creature* searchSpace(Caveman*); 
};

#endif