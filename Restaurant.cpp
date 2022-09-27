#include "Restaurant.h"


// Opens txt file
void openFile(ifstream& inFile) {
    char filename[MAXCHAR] = "restaurant.txt"; 
    inFile.open(filename); 
    if(!inFile) {
        cout << "Could not open source file. Terminating program." << endl;
        exit (0);
    }
}
// Reads input file into struct
int readData(ifstream& inFile, Restaurant guide[]) {
    int size = 0; 
    while(!inFile.eof()) {
        inFile >> guide[size].rName >> guide[size].rType >> guide[size].rating; 
        size++;
    }
    return size;
}
// Displays menu options to user
void displayMenu() {
    cout << "Welcome to my restaurant database!" << endl;
    cout << "Pick from one of the following options:" << endl; 
    cout << "(p) Print the restaurant list" << endl;
    cout << "(s) Search the restaurant list by name" << endl;
    cout << "(q) Quit" << endl;
}
// Reads their menu choice
char readInput() {
    char option; 
    cin.get(option); 
    cin.ignore(100, '\n');
    return option; 
}
// Takes the option returned from char readInput and goes from there
void exeCommand(char option, Restaurant guide[], int size) {
    switch (tolower(option)){
        case 'p': 
            printGuide(guide, size); //prints menu
            break;
        case 's': 
            searchName(guide, size); //searches the guide by name
            break;
        case 'q': 
            cout << "Thank you for visiting my restaurant database. Goodbye!"; 
            break;
        default:
        cout << "Invalid input. Please try again." << endl;
    }
}
// Prints menu
void printGuide(Restaurant guide[], int size) {
    for (int i = 0; i < size; i++){
        cout << fixed << showpoint << setprecision(1);
        cout << guide[i].rName << " " << guide[i].rType << " " << guide[i].rating; 
        cout << endl;
    }
}
// Searches menu by name
void searchName(Restaurant guide[], int size) {
    char srchStr[MAXCHAR]; 
    bool found = false; 
    cout << "Please enter a name to search for: "; 
    cin.getline(srchStr, MAXCHAR); 
    for (int i = 0; i < size; i++) {
        if (strstr(guide[i].rName, srchStr) != NULL) {
            cout << fixed << showpoint << setprecision(1);
            cout << guide[i].rName << " " << guide[i].rType << " "; 
            cout << guide[i].rating << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Restaurant not found." << endl;
    }
}