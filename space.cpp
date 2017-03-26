/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "space.hpp" 
#include <iostream>
#include "utils.hpp"

/*************************************************
                  Constructor
*************************************************/
Space::Space(){
  mapSymbol = '.';  // An empty space is represented with a '.' on the map 
}

/*************************************************
                  Deconstructor
*************************************************/
Space::~Space(){
  delete enemy;   // Delete enemy if it wasn't deleted by being defeated 
}

/*************************************************
                  getMapSymbol 
*************************************************/
char Space::getMapSymbol(){
  return mapSymbol;
}

/*************************************************
                 beenDiscovered
*************************************************/
bool Space::beenDiscovered(){
  return discovered; 
}

/*************************************************
                  connectSpaces
  Checks the 4 spots surrounding the current space 
  for other spaces. If there is a space, the appropriate
  connecting pointer is set. Otherwise if the spot is
  empty, the pointer is set to NULL. 
*************************************************/
void Space::connectSpaces(Space*** map, int row, int col){
  
  // First check if the surrounding spot is on the grid at all. Then if it is, check if that spot is null. 
  // If the spot isn't null set the direction pointer to the adjacent space. Otherwise, set the direction 
  // pointer to null. Repeat for all four surrounding directions. 
  if((row - 1) >= 0 && map[row - 1][col] != NULL ){
    up = map[(row - 1)][col];
  }    
  else{
    up = NULL;
  }
  
  if((col + 1) < 4 && map[row][col + 1] != NULL ){
    right = map[row][col + 1];
  }    
  else{
    right = NULL;
  }
  
  if((row + 1) < 4 && map[row + 1][col] != NULL ){
    down = map[(row + 1)][col];
  }    
  else{
    down = NULL;
  }
  
  if((col - 1) >= 0 && map[row][col - 1] != NULL ){
    left = map[row][col - 1];
  }    
  else{
    left = NULL;
  } 
}

/*************************************************
                    move
  Used to move the location of the character. Prompts
  user with a menu to choose a valid direction. Only
  directions with a movable spot are displayed. 
  The function returns a pointer to the spot the user
  chooses to move to. 
*************************************************/
Space* Space::move(Space*** map)
{
  int moveChoice; 
  Space* moveTo;  // Pointer to the user chosen space to move to 
  
  // Prompt user with a menu. Only display valid moves on menu by checking if the corresponding
  // direction pointer is null. 
  cout << "\nWhich direction?\n   ";
  if(up != NULL){
    cout << "(1) Up  "; 
  }    
  if(right != NULL){
    cout << "(2) Right  ";
  }    
  if(down != NULL){
    cout << "(3) Down  "; 
  }    
  if(left != NULL){
    cout << "(4) Left  ";
  }    
  cout << "(5) Don't Move : ";
  
  // Get the user's choice 
  moveChoice = getIntInRange(1,5); 
  
  // Set moveTo to the direction pointer of the direction chosen. Set moveTo to null if the user
  // decided not to move or made an invalid selection. 
  switch(moveChoice){
    case 1: {
      moveTo = up; 
      break;
    }
    case 2: {
      moveTo = right; 
      break;
    }
    case 3: {
      moveTo = down; 
      break;
    }
    case 4: {
      moveTo = left; 
      break;    
    }  
    case 5: {  
      moveTo = NULL;
      break;
    }
    default: {
      moveTo = NULL;
      break;
    }
  }
  
  // Set the space that is being moved to to discovered
  if(moveTo != NULL){
    moveTo->discovered = true; 
  }
  
  return moveTo; 
}

/*************************************************
                 enterSpace
  Prints out the opening message for the type of 
  space when the player enters the space. 
*************************************************/
void Space::enterSpace(Caveman* cman){
  cout << entranceText; 
}

/*************************************************
                 SearchSpace
  Lets user know if there are items or enemies in 
  the space 
*************************************************/
Creature* Space::searchSpace(Caveman*){
  
}

/*************************************************
                  setItem
  Set it so there is an item in the space. Type of 
  item depends on the type of space it is in. 
*************************************************/
void Space::setItem(){

}

/*************************************************
                  setEnemy
  Set it so there is an enemy in the space. Type of 
  emey depends on the type of space it is in. 
*************************************************/
void Space::setEnemy(){
  
}

/*************************************************
                  removeEnemy
  Turn hasEnemy to false. 
*************************************************/
void Space::removeEnemy(){
  hasEnemy = false; 
}