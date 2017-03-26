#ifndef UTILS_HPP
#define UTILS_HPP

int getInt();                 // Gets integer from user. Doesn't accept non-numeric symbols 
double getDouble(); 
int getIntGreaterThan(int);   // Gets integer from user greater than the given integer
double getDoubleGreaterThanOrEqual(double);
int getIntBetween(int, int);  // Gets integer from user greater than the first parameter and lower than the second parameter. 
int getIntInRange(int, int); 
void clearConsoleWindows();
#endif