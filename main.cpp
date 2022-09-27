//Author:   Deirdre Lyons-Keefe
//Assignment: Assignment 8, CS 161, Structs Restaurant Database
//Date: August 16, 2021
//Description: This program receives input data from the restaurant.txt file 
//and stores this in a struct. Then, it shows the user a menu where they can 
//search for a restaurant by name, print the entire restaurant dataset or quit
//Input: restaurants.txt, menu input
//Output: Search results, menu, all restaurant data
//Sources: restaurants.txt file

#include "Restaurant.h"

//global constants
const int CAP = 20;

//main function
int main() {
    //variables
    Restaurant guide[CAP]; 
    int size = 0;
    ifstream inFile; 
    char option;

    //open file
    openFile(inFile); 
    //read data and declare size
    size = readData(inFile, guide);
    //do while loop that displays menu, reads input, and executes function
    //based on user input. loop ends once char input is 'q'
    do {
        displayMenu(); 
        option = readInput(); 
        exeCommand(option, guide, size); 
    } while (tolower(option) != 'q');
    return 0;
}