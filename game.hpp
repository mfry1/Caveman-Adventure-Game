/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "space.hpp"
#include "utils.hpp"
#include <ctime>
#include "caveman.hpp"
#include "creature.hpp"
class Game
{
  private: 
    Space*** map;               // A grid of spaces that are connected to each other 
    Space* cavemanLocation;     // Points to the current location of the player on the map 
    time_t timeStart;           // The time the game is started. Used to calculate the game clock 
    int hours, mins;            // Time remaining displayed to user. 1 hour = 1 real life min. 1 min = 1 real life sec 
    Caveman* caveman;           // Holds information relating to the player's character 
    int hungerClockCounter;     // Used to increase hunger every hour.
    Creature* enemy;            // The enemy currently being fought. NULL if not in combat 
    bool inBag,                 // True if player is looking at the inventory menu 
         inHelp;                // True if the player is looking at the help menu 
  public: 
    Game(); 
    ~Game();
    void step(); 
    void displayHUD(); 
    void combat(); 
    void roomMenu(); 
    void intro(); 
    void lose(); 
    void win();
    void help(); 
};

#endif