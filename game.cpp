/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#include "game.hpp"
#include <iostream>
#include "utils.hpp"
#include "forest.hpp"
#include "mountain.hpp"
#include "home.hpp"
#include "cave.hpp"
#include "river.hpp"
#include "caveman.hpp"
#include "creature.hpp"
#include <string>
#include <time.h>
#include <windows.h>

using namespace std; 

/*************************************************
                Constructor 
  Allocates the map creates the spaces needed. 
  Creates the caveman object. Initialzes variables. 
*************************************************/
Game::Game()
{
  
  // Allocate map array 
  map = new Space**[4];
  
  for(int i = 0; i < 4; i++){
    map[i] = new Space*[4];
  }
  
  //Set all elements to NULL
  for(int row = 0; row < 4; row++){
    for(int col = 0; col < 4; col++){
      map[row][col] = NULL;
    }
  }
  
  //Create rooms w/ items and enemies 
  River* river1 = new River; 
  river1->setItem();
  map[0][1] = river1; 
  
  River* river2 = new River;
    river2->setEnemy();
  map[0][2] = river2; 
  
  Forest* forest3 = new Forest; 
  forest3->setEnemy();
  map[1][0] = forest3;
  
  Forest* forest2 = new Forest; 
  
  forest2->setItem();
  map[1][1] = forest2;
  
  Forest* forest1 = new Forest;
  forest1->setItem();  
  map[2][1] = forest1;
  
  Mountain* mountain1 = new Mountain;
  mountain1->setItem();
  map[2][2] = mountain1; 
  
  Cave* cave1 = new Cave; 
  cave1->setItem();
  map[2][3] = cave1;
  
  Home* home = new Home; 
  map[3][1] = home; 
  
  Cave* cave2 = new Cave; 
  cave2->setEnemy();
  map[3][3] = cave2;

  
  // Connect rooms to each other 
  for(int row = 0; row < 4; row++){
    for(int col = 0; col < 4; col++){
      if(map[row][col] != NULL){
        map[row][col]->connectSpaces(map, row, col);
      }
    }
  }
  
  // Set obstacles. Has to be done have the rooms are connected since obstacles modify those connections. 
  forest2->setTreeObstacle(1 , "You see a fallen tree blocking you from going up. You'll need to find a solution. ");
  
  // Set Caveman starting location 
  cavemanLocation = map[3][1]; 
  
  // Create caveman
  caveman = new Caveman ;

  // Initial value just needs to be greater then the hour counter 
  int hungerClockCounter = 1000 ;
  
  enemy = NULL;
  inBag = false; 
  inHelp = false; 
  
 }

 /*************************************************
                Deconstructor
  Deallocates the grid and the caveman 
**************************************************/
Game::~Game(){
  delete caveman; 
    
  for(int i = 0; i < 4; i++){
    delete[] map[i];
  }
  
  delete[] map;
  
}

/*************************************************
                  intro
  Starting screen for the game. Displays intro 
  text and lets user start when ready. When user
  starts, the timer is started. 
*************************************************/
void Game::intro(){
  clearConsoleWindows(); 
  
  // Intro text 
  cout << "You are a caveman living a simple prehistoric life. Each day you wake up with the goal \nof surviving and collecting enough food for your family. You have until sunset to bring \n25 pounds of food back to your home cave. Some food can be easily picked but some will \nrequire hunting viscious animals. Don't forget hunting is hard work and you'll need to \nfeed yourself through the day as well or risk becoming weak in combat or even worse \nstarving to death! Keep your hunger meter at 6 or below to stay in peak condition.\n\nGood luck prehistoric man. It is dawn so grab your bag and get going.\n "; 

  cout << "\nEnter (1) to start or (2) to quit : ";
  int menuChoice = getIntInRange(1,2);
  
  switch(menuChoice){
    case 1: {
      timeStart = time(NULL); 
      step(); 
      break;
    }
    case 2: {
      exit(0);
      break; 
    }
  }
}

/*************************************************
                   displayHUD
  Displays to the user relevant info about their 
  stats and displays the map as it is discovered.
  Remains at the top portion of the console. 
*************************************************/
void Game::displayHUD(){
  clearConsoleWindows();
  cout << "        LIFE OF CAVEMAN \n";
  cout << "==============================\n\n";
 
  // Display useful stats about the players progress
  cout << "Time Until Sunset: " << hours <<"hr " << mins << "min" << endl;
  cout << "Health: " << caveman->getHealth() << "/" << caveman->getFullHealth()<< endl; 
  cout << "Hunger Level: " << caveman->getHunger() << "/" << caveman->getHungerMax()<< endl;
  cout << "Food on Hand: " << caveman->getFoodAmount() << "lb (get 25lb back home)" << endl; 
  
  cout << endl; 
  
  // Display the map. The caveman is marked in his current location and any discovered areas are marked with a space specific symbol 
  // A border around the grid was added to make the map feel bigger than it is. Extra '.'s are displayed around the map 
  cout << "        MAP\n";
  cout << " .  .  .  .  .  .  \n";
  for(int row = 0; row < 4; row++){
   cout << " .  ";
   for(int col = 0; col < 4; col++){
      if(map[row][col] == cavemanLocation){
        cout << "&  ";
      }
      else if(map[row][col] != NULL && map[row][col]->beenDiscovered()){
        cout << map[row][col]->getMapSymbol() << "  ";
      }
      else{
        cout << ".  ";
      }
    }
    cout << ".  ";    
    cout << endl; 
  }
   cout << " .  .  .  .  .  .  \n";
  
  // Display a map legend 
  cout << " Legend: & = You, H = Home, F = Forest, R = River, M = Mountain, C = Cave\n";
  cout << "-------------------------------------------------------------------------\n" << endl; 
}   

/************************************************* 
                  step
  Controls the flow of the game. Check if victory 
  or defeat has been reached, displays the HUD, 
  calculates the time remaining, and calls the 
  appropriate game menu 
*************************************************/ 
void Game::step(){
  while(true){  
    
    // Check if victory is achieved
    if(cavemanLocation == map[3][1] && caveman->getFoodAmount() >= 25){
      win();
    }
    
    // Update sunlight counter. Seperate hours and minutes 
    hours = 11 - (time(NULL) - timeStart) / 60;
    mins = 59 - (time(NULL) - timeStart) % 60;
    
    // Gain hunger every hour 
    if(hungerClockCounter >= hours){
      hungerClockCounter = hours - 1;
      caveman->changeHunger(1);
    }
    
    displayHUD();
    
    // If 12 minutes have passed (total time), the game is over and the player has lost. 
    if(hours < 0){
      lose(); 
    }
    
    // If hunger is 10, game over
    if(caveman->getHunger() == 10){
      lose();
    }
    
    // lose if health is 0 
    if(caveman->getHealth() == 0){
      lose();
    }
    
    //Go to the correct game function that the user is currently in 
    // If enemy isn' null, the user is currently in combat 
    if(enemy != NULL){
        combat(); 
    }
    // The user is in the inventory meny 
    else if(inBag){
      inBag = caveman->inventory(); 
    }
    // The user is in the help menu
    else if(inHelp){
      clearConsoleWindows(); 
      help();
    }
    // The user is in the base room menu 
    else{
      roomMenu();
    }
  }   
}

/*************************************************
                 roomMenu 
  The basic menu displayed when entering a room. 
  All user functions branch from here. 
*************************************************/
void Game::roomMenu(){
  int menuChoice;
  Space* temp = NULL; 
  
  // Call enterSpace to get intro text for the room. 
  cavemanLocation->enterSpace(caveman);
  
  // Display the menu 
  cout << "What would you like to do? \n   (1) Move (2) Look Around (3) Check Bag (4) Help : ";
  menuChoice = getIntInRange(1,4); 
  
  switch(menuChoice){
    // Move. Call move function. If null is returned, the player doesn't move so don't set the cavemanLocation to the result 
    case 1: {
      temp = cavemanLocation->move(map);
      if(temp != NULL){
        cavemanLocation = temp;
      }
      break;
    }
    // Search. Items found are displayed in the searchSpace function. If a enemy is returned, the player is starting combat. 
    case 2: {      
      enemy = cavemanLocation->searchSpace(caveman);
      Sleep(2000);
      break;
    }
    // Inventory Menu
    case 3: {      
      inBag = true; 
      break;
    }
    // Help Menu 
    case 4: {      
      inHelp = true;  
      break;
    } 
  }
 
}

/*************************************************
                    win
  Displays text after the player has won and ends
  the game. Also gives the player how much time it 
  took to complete   
*************************************************/
void Game::win(){
  clearConsoleWindows();
  displayHUD();
  // Win text 
  cout << " YOU WON! Congradulations! \n\n You have shown your ability to survive in the viscious pre-historic world\n and at least for today, you and your family won't starve.\n"; 
 
 // Calculate and display how long it took to win 
 cout << "\n Time Taken: " << (time(NULL) - timeStart) / 60 << " minutes and " << (time(NULL) - timeStart) % 60 << " seconds. ";
  Sleep(100000);
  exit(0);
}

/*************************************************
                    lose 
  Displays text when the player loses and ends the
  game 
*************************************************/
void Game::lose(){
  clearConsoleWindows();
  
  displayHUD();
  
  //Player lost by losing all their health 
  if(caveman->getHealth() == 0){
    cout << " YOU LOSE. Sorry. \n\n You were unable to defend yourself while hunting the prehistoric creatures and have died. \n"; 
  }
  // Player lost by reaching max hunger 
  else if(caveman->getHunger() == 10){
    cout << " YOU LOSE. Sorry. \n\n You went too long without eating and have starved to death. \n"; 
  }
  // Player ran out of time 
  else{
    hours = 0;  // Set hour and min to 0 otherwise the final HUD will display a negative time 
    mins = 0;
    cout << " YOU LOSE. Sorry. \n\n You were unable to bring enough food home by sunset. You are lost in the dark and your family will starve.\n"; 
  }
  Sleep(100000);
  exit(0);
}

/*************************************************
                  combat
  Displays stats of both fighters. Calls attacks
  and speed checks for each attack. Performs 2
  attacks each time, one from each figther. 
  
  attack = 1 to attack 
  speed = 1 to speed
  
  If attack > speed, the difference is done as damage 
*************************************************/
void Game::combat(){
  
  // Display the 2 fighters' stats 
  cout << caveman->getName() << "                         " << enemy->getName() << endl;
  cout << "HEALTH: " << caveman->getHealth() << "/" << caveman->getFullHealth()<< "                   " << "HEALTH: " << enemy->getHealth() << "/" << enemy->getFullHealth() << endl;
  cout << "ATTACK: " << caveman->getAttack() << "                      " << "ATTACK: " << enemy->getAttack() << endl;
  cout << "SPEED : " << caveman->getSpeed() << "                      " << "SPEED : " << enemy->getSpeed() << endl;
  
 
  cout << endl; 
  
  // Display menu to let user attack again or run from fight 
  int menuChoice; 
  cout << "What do you do? (1) Attack (2) run away :"; 
  menuChoice = getIntInRange(1,2);
  if(menuChoice == 2){
    enemy = NULL; // If enemy is NULL, the player is not actively in combat 
  }
  else{
    // Get attack roll for caveman. 
    int attackDamage = caveman->attacking(); 
    // Can be modified if hunger is high. If 7 or higher, attack is reduced 20%
    if(caveman->getHunger() >= 7){
      cout << "You feel weak from hunger. Your attack is weaker. ";
      attackDamage = attackDamage * 3/4;
    }
    
    // Get enemy speed roll 
    int dodgeAmount = enemy->dodging(); 
    
    // Display attack text with correct weapon 
    if(caveman->checkSpear()){
      cout << "You attacked with your spear ";
    }
    else if(caveman->checkClub()){
      cout << "You attacked with your club ";
    }
    else{
      cout << "You attacked ";
    }
    
    // If damage is done, change health and display damage done 
    if(attackDamage > dodgeAmount){
      enemy->changeHealth(dodgeAmount - attackDamage );
      cout << "and did " << attackDamage - dodgeAmount << " damage to the " << enemy->getName() << endl << endl; ; 
    }
    // No damage done 
    else{
      cout << "but the " << enemy->getName() << " dodged it. " << endl << endl; 
    }
    
    // Check if enemy was defeated. 
    if(enemy->getHealth() == 0){
      //Get food from enemy and add to caveman's amount 
      cout << "You defeated the " << enemy->getName() << "! You collected " << enemy->getMeat() << " food from it.\n";
      caveman->addToFood(enemy->getMeat());
      delete enemy; // The enemy is no longer needed 
      enemy = NULL; 
      cavemanLocation->removeEnemy(); 
      Sleep(5000);
    }
    // The enemy gets to attack 
    else{
      
     Sleep(2000);
      
      attackDamage = enemy->attacking(); 
      dodgeAmount = caveman->dodging(); 
      
      cout << "The " << enemy->getName() << " attacked "; 
      if(attackDamage > dodgeAmount){
        caveman->changeHealth(dodgeAmount - attackDamage );
        cout << "and did " << attackDamage - dodgeAmount << " damage to you "<< endl << endl;
      }
      else{
        cout << "but you dodged it. " << endl << endl; 
      }
       
      Sleep(2000);
    }
  }

}

/*************************************************
                   help
  Displays text to help the user understand the 
  game's mechanics 
*************************************************/
void Game::help(){
  cout << "How To Win:\n";
  cout << "\tCollect at least 25lb of food and return home. You must still have 25lb when \narriving at home.\n\n"; 

  cout << "Ways To Lose:\n"; 
  cout << "\t-The hunger meter becomes full\n";
  cout << "\t-Your health reaches 0\n";
  cout << "\t-Time until sunset reaches 0\n\n";
  
  cout << "Time Until Sunset:\n";
  cout << "\t-You must complete the task before sunset. This gives you 12 hours. Each real \nlife second counts as 1 in game minute.\n\n"; 
 
  cout << "Hunger: \n";
  cout << "\t-Hunger increases by 1 every hour. It can be decreased by eating food in the \nbag menu. If it reaches 10, you lose. If it is above 6, you are weaker in combat.\n\n";
  
  cout << "Weapons:\n"; 
  cout << "\t-Your attack strength can be improved by finding weapons. The weapons available \nare a club and a spear. Each raises your attack by 10 points.\n\n";

  cout << "Combat:\n"; 
  cout << "\t-When starting combat, you always get to attack first because you are approaching \nthe enemy. When you or an enemy are attacking, a roll is done from 1 to attack strength. \nThe defender rolls from 1 to speed strength to see if the attack is dodged. If the attack \nroll is greater than the speed roll, the attack hits and does the difference of the rolls \nas damage.\n";
  cout << "\t-You may flee in between pairs of attacks. The enemy will be in the same condition \nwhen you return.\n";
  cout << "\t-If your hunger is greater than 6, your attacks are weakened. The attack roll is \ndecreased 25%.\n\n"; 

int menuChoice;
cout << "What do you want to do? (1) Back to game: ";
menuChoice = getIntInRange(1,1);
inHelp = false;  

}