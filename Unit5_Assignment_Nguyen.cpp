// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Functions.h"
#include "Menu_Item_Classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

//global constants
#define SIZE 10 //size of our vector for items
//global function prototypes
void loadMenuItems(vector<Snacks>&);
void displayMenu(vector<Snacks> &, vector<char> &);
void controlOrderMenu(vector<Snacks>&, vector<char>&);

int main()
{   
  //instantiate the Menu and Snacks Object
  Item itemObj;
  
  //create a vector with room for 10 Snacks objects
  vector<Snacks>snackList;
  //created char vector to hold letters to allow for easy population of 
  //  the vector of objects
  vector<char> downLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  //load the snacklist with the details of the snacks it contains
  loadMenuItems(snackList);
  //display the Menu of snacks additional information and option to add
  // or remove from shopping cart
  displayMenu(snackList, downLetters);

  //display messate to confirm program runs.
  cout << "\nProgram is working at the moment!\n";

  controlOrderMenu(snackList, downLetters);

  return 0;
}

