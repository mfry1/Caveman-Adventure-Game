/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "caveman.hpp"
#include <cstdlib>
#include <ctime>
#include "utils.hpp"
#include <windows.h>

/*************************************************
                 Constructor
  Initialize stats, sets all objects to not found, 
  and sets seed for random numbers. 
*************************************************/
Caveman::Caveman(){
  name = "Caveman";
  health = 20; 
  fullHealth = 20; 
  attack = 10;
  speed = 20;
  hunger = 4; 
  hungerMax = 10; 
  foodAmount = 0; 
  hasFire = false;  
  hasClub = false;
  hasSpear = false;
  
  srand(time(NULL));
}

/*************************************************
                getFoodAmount 
*************************************************/
int Caveman::getFoodAmount(){
 return foodAmount;  
}

/*************************************************
                getHunger
*************************************************/
int Caveman::getHunger(){
  return hunger; 
}

/*************************************************
                changeHunger
  Adds the parameter amount to the hunger level. 
  Amount should be negative if hunger is to be 
  decreased. Hunger shouldn't go below 0 so hunger 
  is set to 0 if it goes below. 
*************************************************/
void Caveman::changeHunger(int amount){
  hunger += amount;
  
  // Don't let hunger go below 0 
  if(hunger < 0 ){
    hunger = 0;
  }
}

/*************************************************
                getHungerMax
*************************************************/
int Caveman::getHungerMax(){
  return hungerMax; 
}

/*************************************************
                checkFire
*************************************************/
bool Caveman::checkFire(){
  return hasFire;
}

/*************************************************
                addFire
*************************************************/
void Caveman::addFire(){
  hasFire = true; 
}

/*************************************************
                addToFood
  Adds the parameter amount to the food amount. 
  The max food that can be carried is 27 so if that 
  is exceeded, set foodAmount to 27 and send the extra
  to the hunger level. 
*************************************************/
void Caveman::addToFood(int amount){
  foodAmount += amount; 
  
  // Check if bag capacity is exceeded 
  if(foodAmount >=27){
    cout << "You can't carry all this food. You eat as much of the leftover as you can. \n";
    Sleep(2000);
    // The extra can be eaten to reduce hunger level 
    changeHunger(27 - foodAmount); 
    foodAmount = 27; 
  }
}

/*************************************************
                  checkClub
*************************************************/
bool Caveman::checkClub(){
  return hasClub;
}

/*************************************************
                  addClub
*************************************************/
void Caveman::addClub(){
  hasClub = true; 
  attack += 10; // Having a club increases attack by 10 
}

/*************************************************
                 checkSpear
*************************************************/
bool Caveman::checkSpear(){
  return hasSpear; 
}

/*************************************************
                  addSpear
*************************************************/
void Caveman::addSpear(){
  hasSpear = true; 
  attack += 10;   // Having a spear increases attack by 10 
}

/*************************************************
                 inventory 
  Displays the inventory and given the user the 
  option to eat food to reduce hunger level. 
*************************************************/
bool Caveman::inventory(){
    bool inBag = true; // Set to false when the user is finished with the inventory menu 
    
      cout << " BAG" << endl; 
      cout << "===========================\n";
      
      // Display weapons
      cout << "Weapon: "; 
      if(hasSpear){
        cout << "Spear";
      }
      else if(hasClub){
        cout << "Club";
      }
      else{
        cout << "None";
      }
      cout << endl; 
      
      // Display misc. items
      cout << "Misc. Item: ";
      if(hasFire){
        cout << "Fire Stick";
      }
      else{
        cout << "None";
      }
      cout << endl; 
      
      // Display food carrying 
      cout << "Food: " << foodAmount << "lb  Max Capacity = 27lb" << endl; 

      
      int menuChoice; 
      cout << "\nWhat do you want to do? (1) Eat 1lb food(-1 Hunger, -1 Food) or (2) Close Bag:";
      menuChoice = getIntInRange(1,2); 
      
      // Eat food if possible and if hungry
      if(menuChoice == 1){
        // Eating is possible 
        if(foodAmount > 0 && hunger > 0){
          foodAmount -= 1; 
          hunger -= 1; 
          cout << "You ate a piece of food.";
        }
        // Can't eat because there is no food 
        else if(foodAmount == 0){
          cout << "You don't have any food!";
        }
        // Can't eat because the caveman isn't hungry 
        else if(hunger == 0){
          cout << "You aren't hungry!";
        }
        cout << endl; 
        Sleep(2000);
      }
      else{
        inBag = false; // Done with inventory menu 
      }
    return inBag; 
}