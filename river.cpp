/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "river.hpp"
#include "mammoth.hpp"

/*************************************************
                Constructor 
*************************************************/
River::River(){
  mapSymbol = 'R';
  entranceText = "You are by a river. ";
  discovered = false;
  weaponUpgradeExists = false; 
  hasEnemy = false;
  
}

/*************************************************
                  searchSpace   
  Allows user to search space for items and enemies 
  Returns a pointer to an enemy if one exists otherwise
  returns null. 
*************************************************/
Creature* River::searchSpace(Caveman* caveman){
  // Check for items
  if(weaponUpgradeExists){
    if(!caveman->checkClub()){
      cout << "\nYou found a club. Your attack strength improved!\n";
      caveman->addClub();
      weaponUpgradeExists = false; 
    }
    else if(!caveman->checkSpear()){
      cout << "\nYou found a spear. Your attack strength improved!\n";
      caveman->addSpear();
      weaponUpgradeExists = false; 
    }
  }
  // Check for enemies 
  else if(hasEnemy){
    cout << "\nYou see a mammoth drinking from the river. He sees you and charges at you. Prepare to fight!\n";
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
void River::setItem(){
  weaponUpgradeExists = true; 
}

/*************************************************
                  setEnemy 
  The river space has mammoth enemies 
*************************************************/
void River::setEnemy(){
  hasEnemy = true; 
  enemy = new Mammoth(); 
}

