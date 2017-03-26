/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "mammoth.hpp"
#include <cstdlib>
#include <ctime>

Mammoth::Mammoth(){
  name = "Mammoth";
  attack = 20;
  speed = 10;
  health = 30;
  fullHealth = 30;
  meat = 15;
  
  srand(time(NULL));
}