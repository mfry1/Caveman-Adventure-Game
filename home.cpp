/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "home.hpp"

/*************************************************
                constructor 
*************************************************/
Home::Home(){ 
  mapSymbol = 'H';
  entranceText = "You are at home. ";
  discovered = true;
  
}

/*************************************************
                  searchSpace
  There are no items or enemies possible for the 
  home space. 
*************************************************/
Creature* Home::searchSpace(Caveman* caveman){
    cout << "\nNothing was found.\n"; 
  return NULL; 
}