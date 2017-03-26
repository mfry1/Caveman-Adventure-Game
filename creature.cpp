/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "creature.hpp"
#include <cstdlib>
#include <ctime>

/*************************************************
                 getHealth
*************************************************/
int Creature::getHealth(){
  return health; 
}

/*************************************************
               getFullHealth
*************************************************/
int Creature::getFullHealth(){
  return fullHealth;
}

/*************************************************
                  getAttack
*************************************************/
int Creature::getAttack(){
  return attack;
}

/*************************************************
                    getMeat
*************************************************/
int Creature::getMeat(){
  return meat;
}

/*************************************************
                    getSpeed
*************************************************/
int Creature::getSpeed(){
  return speed; 
}

/*************************************************
                    getName
*************************************************/
string Creature::getName(){
  return name; 
}

/*************************************************
                     roll
  Randomly selects a number from 1 to the parameter 
  rollType. 
*************************************************/
int Creature::roll(int rollType)
{    
    return rand() % rollType + 1;
 
}

/*************************************************
                   attacking
  Returns a roll using the attack stat 
*************************************************/
int Creature::attacking(){
  return roll(attack);
}

/*************************************************
                   dodging
  Returns a roll using the speed stat
*************************************************/
int Creature::dodging(){
  return roll(speed);
} 

/*************************************************
                  changeHealth 
  Adds the parameter change to the health. Health 
  isn't allowed to go below zero or go above the 
  initial health amount. 
*************************************************/
void Creature::changeHealth(int change){
  health += change; 
    
    // Don't allow to go below zero 
    if(health < 0){
      health = 0; 
    }
    // Don't allow to go above initial health 
    else if(health > fullHealth){
      health = fullHealth; 
    }
}

