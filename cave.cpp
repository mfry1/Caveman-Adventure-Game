/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "cave.hpp"
#include <windows.h>
#include "creature.hpp"
#include "bear.hpp"

/*************************************************
                  Constructor
*************************************************/
Cave::Cave(){
  mapSymbol = 'C';
  entranceText = "You are in a cave. ";
  discovered = false;
  weaponUpgradeExists = false;
  hasEnemy = false;   
}

/*************************************************
                 searchSpace 
  Allows user to search the space for items or
  enemies. Returns a pointer to an enemy or null if
  one doesn't exist 
*************************************************/
Creature* Cave::searchSpace(Caveman* caveman){
  // Get Weapon upgrade item if it exists. Check which weapon the user currently has and ugrade appropriately
  if(weaponUpgradeExists){
    if(!caveman->checkClub()){
      cout << "\nYou found a club. Your attack strength improved!\n";
      caveman->addClub();
      weaponUpgradeExists = false; 
      //Sleep(2000);
    }
    else if(!caveman->checkSpear()){
      cout << "\nYou found a spear. Your attack strength improved!\n";
      caveman->addSpear();
      weaponUpgradeExists = false; 
      //Sleep(2000);
    }
  }
  // Check if the space has an enemey. If so, return it 
  else if(hasEnemy){
    cout << "\nYou see a giant bear behind a rock. Prepare to fight!\n";
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
void Cave::setItem(){
  weaponUpgradeExists = true; 
}

/*************************************************
                  setEnemy
  Cave spaces have the bear enemy 
*************************************************/
void Cave::setEnemy(){
  hasEnemy = true; 
  enemy = new Bear(); 
}