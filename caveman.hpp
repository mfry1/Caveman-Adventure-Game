/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef CAVEMAN_HPP
#define CAVEMAN_HPP
#include "Creature.hpp"

class Caveman : public Creature
{
  private: 
    int foodAmount,   // The amount of food being carried by the caveman
        hunger,       // The level of hunger the caveman has 
        hungerMax;    // The hunger level at which starvation is reached
    bool hasFire,     // Whether or not the user has found the fire item 
         hasClub,     // Wheter or not the user has found the first weapon upgrade
         hasSpear;    // Wheter or not the user has found the second weapon upgrade
         
  public: 
    Caveman(); 
    int getFoodAmount();
    void addToFood(int);    
    int getHunger();
    int getHungerMax();
    void changeHunger(int);
    bool checkFire(); 
    bool checkClub();
    bool checkSpear();
    void addClub();
    void addSpear(); 
    void addFire();
    bool inventory(); 
};
#endif 