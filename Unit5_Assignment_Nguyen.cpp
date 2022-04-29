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
void displayMenu(vector<Snacks> &, vector<char> &);
void controlOrderMenu(vector<Snacks>&, vector<char>&);

int main()
{ 
  //instantiate the Menu and Snacks Object
  Item itemObj;

  vector<Snacks>snackList;

  loadMenuItems(snackList);

  //display the Menu of snacks additional information and,.
  cout << "\nThe name of the first item is: " << snackList[0].getName() << endl << endl; 

  cout << "\nThe name of the second item is: " << snackList[1].getName() << endl << endl; 
  for(int i = 0; i < snackList.size(); i++)
  {
    cout << snackList[i].getName() << endl;
  }
  
  cout << "\nThe Prices on the menu are:\n ";
  for(int i = 0; i < snackList.size(); i++)
  {
    cout << snackList[i].getCost() << endl;
  }

  cout << "\nThe Letters on the menu are:\n";
  for(int i = 0; i < snackList.size(); i++)
  {
    cout << snackList[i].getAddCartLetter() << endl;
  }
  displayMenu(snackList);
  controlOrderMenu(snackList);

  return 0;
}
