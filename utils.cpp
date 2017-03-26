#include <iostream>
#include "utils.hpp"
#include <stdlib.h>
#include <string>
// std::cout << "\033[2J\033[1;1H" << std::endl;    Clear the console in UNIX 

using namespace std; 
/*******************************************************************************************
                                       getInt 
*******************************************************************************************/
int getInt()
{
  int inputInt; 
  
  cin >> inputInt; 
  while(!cin)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter an integer: ";
    cin >> inputInt; 
  }
  return inputInt; 
}

/*******************************************************************************************
                                       getDouble
*******************************************************************************************/
double getDouble()
{
  double inputDouble; 
  
  cin >> inputDouble; 
  while(!cin)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter a number: ";
    cin >> inputDouble; 
  }
  return inputDouble; 
}

/*******************************************************************************************
                                       getIntGreaterThan
*******************************************************************************************/
int getIntGreaterThan(int lowerBoundaryInt)
{
  int inputInt = getInt(); 
  do
  {
    if(inputInt <= lowerBoundaryInt)
    {
      std::cout << "Invalid input. Please enter an integer > " << lowerBoundaryInt << ": ";
      inputInt = getInt();
    }
    else 
    {
      return inputInt; 
    }
  }while(true); 
}

/*******************************************************************************************
                                       getDoubleGreaterThanOrEqual
*******************************************************************************************/
double getDoubleGreaterThanOrEqual(double lowerBoundaryDouble)
{
  double inputDouble = getDouble(); 
  do
  {
    if(inputDouble < lowerBoundaryDouble)
    {
      cout << "Invalid input. Please enter a number >= " << lowerBoundaryDouble << ": ";
      inputDouble = getDouble();
    }
    else 
    {
      return inputDouble; 
    }
  }while(true); 
}

/*******************************************************************************************
                                       getIntBetween
*******************************************************************************************/
int getIntBetween(int lowBoundary, int highBoundary)
{
  int inputInt = getInt(); 
  do
  {
    if(inputInt <= lowBoundary || inputInt >= highBoundary)
    {
      cout << "Invalid input. Please enter an integer from " << lowBoundary + 1 << " to " << highBoundary - 1 << ": ";
      inputInt = getInt();
    }
    else 
    {
      return inputInt; 
    }
  }while(true); 
}

/*******************************************************************************************
                                       getIntInRange
*******************************************************************************************/
int getIntInRange(int lowestValidInt, int highestValidInt)
{
  int inputInt = getInt(); 
  do
  {
    if(inputInt < lowestValidInt)
    {
      cout << "Outside of acceptable range. Please enter an integer >= " << lowestValidInt << ": ";
      inputInt = getInt();
    }
    else if(inputInt > highestValidInt)
    {
      cout << "Outside of acceptable range. Please enter an integer <= " << highestValidInt << ": ";
      inputInt = getInt();
    }
    else 
    {
      return inputInt; 
    }
  }while(true); 
}

/*******************************************************************************************
                                       clearConsoleWindows 
*******************************************************************************************/
void clearConsoleWindows()
{
  std::cout << "\033[2J\033[1;1H" << std::endl;
  }