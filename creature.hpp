/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>

class Creature{
  protected: 
    int health,       // The current amount of health 
        fullHealth,   // The original amount of health 
        attack,       // The attack stat level 
        speed,        // The speed stat level
        meat;         // The amount of food that a creature gives when defeated 
    std::string name; // The name of the creature 
    
  public: 
    int getHealth();
    int getFullHealth();
    int getAttack();
    int getSpeed();
    int getMeat(); 
    std::string getName(); 
    int roll(int);
    int attacking();
    int dodging(); 
    void changeHealth(int);  
};

#endif