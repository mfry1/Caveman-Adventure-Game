/***************************************************************************************
 Author: Matt Fry 
 Date: 12/2/16
 Description: 
 
***************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "caveman.hpp"
#include "creature.hpp"

class Space
{
  protected: 
    Space *up, *right, *down, *left;  // Pointers to the spaces surrounding the space. If there is no space in that direction, the pointer is null 
    bool discovered,                  // Holds whether or not the space has been visited by the character
         hasEnemy;                    // Holds whether the space has an enemy in it or not 
    char mapSymbol;                   // The character that is displayed for this space on the map 
    std::string entranceText;         // The text that is displayed upon the character entering this space 
    Creature* enemy; 
    
  public: 
    Space();
    ~Space(); 
    char getMapSymbol();            
    bool beenDiscovered(); 
    virtual void setEnemy(); 
    virtual void setItem(); 
    void removeEnemy();
    void connectSpaces(Space***, int row, int col); 
    Space* move(Space***); 
    virtual void enterSpace(Caveman*); 
    virtual Creature* searchSpace(Caveman*); 
};

#endif