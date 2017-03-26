/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "mountain.hpp" 

/*************************************************
                  Constructor 
*************************************************/
Mountain::Mountain(){
  mapSymbol = 'M';
  entranceText = "You are on a mountain. ";
  discovered = false;
  fireItemExists = false; 
  
}

/*************************************************
                  searchSpace
  A mountain space may have a fire item. If searched, 
  add the item to the caveman's inventory and remove
  it from the space. 
*************************************************/
Creature* Mountain::searchSpace(Caveman* caveman){
  if(fireItemExists){
    cout << "\nYou found a stick on fire. You take it. \n";
    fireItemExists = false; // Remove item from space
    caveman->addFire();     // Add item to caveman's inventory 
  }
  else{
    cout << "\nNothing was found.\n"; 
  }
  return NULL; 
}

/*************************************************
                  setItem
  Makes it so an item is available in this instance 
  of moutain
*************************************************/
void Mountain::setItem(){
  fireItemExists = true; 
}

