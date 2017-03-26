/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "forest.hpp"
#include <string>
#include "caveman.hpp"
#include <windows.h>
#include "tiger.hpp"

/*************************************************
                  Constructor 
*************************************************/
Forest::Forest(){ 
  mapSymbol = 'F'; 
  entranceText = "You are in a forest. ";
  discovered = false;
  obstaclesExist = false; 
  
}

/*************************************************
                  setTreeObstacle
  Sets up an obstacle in the space. The direction 
  is inputted and the specific text for the obstacle
  is given 
*************************************************/
void Forest::setTreeObstacle(int direction, string text){
  obstaclesExist = true; 
  obstacleText1 = text;
 
  obstacleDirection = direction; 
  
  // Block passage by removing the direction pointer from the space and holding it in obstacleTemp
  // When the obsacle is cleared, the pointer is put back into the direction pointer 
  if(obstacleDirection == 1){
    obstacleTemp = up;
    up = NULL; 
  }
  else if(obstacleDirection == 2){
    obstacleTemp = right;
    right = NULL;
  }
  else if(obstacleDirection == 3){
    obstacleTemp = down;
    down = NULL;
  }
  else if(obstacleDirection == 4){
    obstacleTemp = left;
    left = NULL;
  }
}

/*************************************************
                 enterSpace
  Displays normal entrance text along with obstacle
  text if there is a obstacle in the space. 
*************************************************/
void Forest::enterSpace(Caveman* caveman){
  cout << entranceText; 
 
 // Check if the player has the necessary item to clear the obstacle 
  if(caveman->checkFire() && obstaclesExist){
    cout << "You use your fire to burn the fallen tree blocking your way. ";
    obstaclesExist = false;
    
    // Reset the direction pointer 
    if(obstacleDirection == 1){
      up = obstacleTemp;
    }
    else if(obstacleDirection == 2){
      right = obstacleTemp;
    }
    else if(obstacleDirection == 3){
      down = obstacleTemp;
    }
    else if(obstacleDirection == 4){
      left = obstacleTemp;
    }
  }
  else if(obstaclesExist){
    cout << obstacleText1; 
     
  }
  
}

/*************************************************
                   searchSpace
  Allows player to search space for items and enemies
  
*************************************************/
Creature* Forest::searchSpace(Caveman* caveman){
  // Forest may have berry item. 
  if(berriesExist){
    cout << "\nYou found some berries! +2 to food. \n";
    berriesExist = false; 
    caveman->addToFood(2); 
  }
  // Check if there is an enemy 
  else if(hasEnemy){
    cout << "\nYou see a saber-toothed tiger lurking in the trees. Prepare to fight!\n";
    return enemy; 
  }
  else{
    cout << "\nNothing was found.\n";
  }
  return NULL; 
}

/*************************************************
                    setItem
*************************************************/
void Forest::setItem(){
  berriesExist = true; 
}

/*************************************************
                  setEnemy 
  The forest space ha the saber-toothed tiger 
  enemey 
*************************************************/
void Forest::setEnemy(){
  hasEnemy = true; 
  enemy = new Tiger(); 
}


