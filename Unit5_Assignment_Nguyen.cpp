// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Functions.h"
#include "Menu_Item_Classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>


//global function prototypes
void loadMenuItems(vector<Snacks>&);
// void displayMenu(vector<Snacks> &, vector<char> &);
// void controlOrderMenu(vector<Snacks>&, vector<char>&);

int main()
{ 
  //instantiate the Menu and Snacks Object
  Item itemObj;
  

  vector<Snacks>snackList;
  //load the snacklist with the details of the snacks it contains
  loadMenuItems(snackList);
  //display the Menu of snacks additional information and option to add
  // or remove from shopping cart
  
  cout << "\nThe name of the first item is: " << snackList[0].getName() << endl << endl; 
  
 
  // displayMenu(snackList, downLetters);
  // controlOrderMenu(snackList, downLetters);

  return 0;
}
