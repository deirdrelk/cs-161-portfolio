#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAXCHAR = 101;

//struct definition
struct Restaurant {
    char rName[MAXCHAR]; 
    char rType[MAXCHAR];
    double rating;
};

// Function prototypes
// opens txt file
void openFile(ifstream& inFile);
// reads input file into struct
int readData(ifstream& inFile, Restaurant guide[]);
// displays menu options to user
void displayMenu();
// reads their menu choice 
char readInput();
// takes the option returned from char readInput and goes from there
void exeCommand(char option, Restaurant guide[], int size); 
// prints menu
void printGuide(Restaurant guide[], int size);
// search menu by name
void searchName(Restaurant guide[], int size);

#endif