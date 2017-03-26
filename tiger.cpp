/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "tiger.hpp"
#include <cstdlib>
#include <ctime>

Tiger::Tiger(){
  name = "Saber-toothed Tiger";
  attack = 20;
  speed = 30;
  health = 10;
  fullHealth = 10;
  meat = 5;
  
  srand(time(NULL));
}