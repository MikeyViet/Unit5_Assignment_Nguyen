// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

#define SIZE 10

//global function prototypes
void loadMenuItems(vector<Snacks>&);
void displayMenu(vector<Snacks>&);
void controlOrderMenu(vector<Snacks>&);
void printReceipt(vector<Snacks>&, double, double, double);

int main()
{ 
  //instantiate the Menu and Snacks Object
  Item itemObj;
  // create vector of snacks objects
  vector<Snacks>snackList;
  // load object into Menu
  loadMenuItems(snackList);
  // displayMenu 
  displayMenu(snackList);
  // control Menu
  controlOrderMenu(snackList);

  return 0;
}
