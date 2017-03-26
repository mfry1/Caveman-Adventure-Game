/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "bear.hpp"
#include <cstdlib>
#include <ctime>
Bear::Bear(){
  name = "Bear";
  attack = 30;
  speed = 10;
  health = 20;
  fullHealth = 20;
  meat = 10;
  
  srand(time(NULL));
}