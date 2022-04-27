// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Functions.h"
#include "Menu_Item_Classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

#define SIZE 10 //size of our vector for items

void loadMenuItems(vector<Snacks>&);


void displayMenu(vector<Snacks> &, vector<char> &);
void controlMenu(Item &);


int main()

{   
  //instantiate the Menu and Snacks Object
  Item itemObj;

  //create a vector with room for 10 Snacks objects
  vector<Snacks>snackList;
  vector<char>downLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

  loadMenuItems(snackList);
  displayMenu(snackList, downLetters);

  //menuObj.controlMenu();

  cout << "Program is working at the moment!\n";
  return 0;
}

//Function Definitions

/******************************************************************
 * Name:        loadMenuItems()
 *
 * Parameters:
 *      Input:  Address of Item Object
 *      Output: none
 *
 * Description: The function accepts an address to an object of type
 *      Item in order to populate the items with values that
 *      have been loaded into vectors.
 ******************************************************************/
void loadMenuItems(vector<Snacks> &tmpSnkList)
{
  
  vector<Snacks> *snkPtr = &tmpSnkList;
  //loop to fill the vector with Snacks objects. A temp snack object
  //  will be created and loaded into vector each loop. The Snacks 
  //  object should be repeated created and replaced.
  for(int i = 1; i <= SIZE; i++)
  {
    Snacks temp;                //instantiate a temporary snack object
    snkPtr->push_back(temp); //push the temp snack object to vector

  }//end for (Snacks val : tmpSnkList) loop

  // Load values of the items that will be on menu into vectors to populate the objects
  vector<string> items {"Burrito", "Hamburger", "Chocolate Sundae", "Apple Pie", "Chicken Sandwich", "Green Tea", "Coke", "Coffee", "Water", "Orange Juice"};
  vector<string> details{"Authentic Mexican", "1/2 Lb Angus", "Hot Fudge", "Home Made", "Organic Chicken Breast", "Refreshing", "Original Glass Bottles", "FIJI", "Lemon-lime"};
  vector<double> prices{5.00, 7.00, 3.50, 3.00, 10.00, 2.50, 1.00, .75, 3.00, 2.50};
  vector<string> type {"Breakfast", "Lunch", "Ice Cream", "Bakery", "Lunch", "Tea", "Soda", "Coffee", "Water", "Juice"};

  for(int i = 1; i <= 10; i++)
  {
    tmpSnkList[i].setName(items[i]);
    tmpSnkList[i].setDescription(details[i]);
    tmpSnkList[i].setCost(prices[i]);
    tmpSnkList[i].setTypeOfSnack(type[i]);
    

  }
}

void displayMenu(vector<Snacks> &tmpSnkList, vector<char> &letters)
{
    cout << fixed << setw(40) << setprecision(2); // set doubles to 2 decimal places
    cout << "This is DrT's Efficient Menu to Imitate" << endl;
    cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC" << endl;
for (int i = 0; i < SIZE; i++)
{
    cout << fixed << setw(15) << setprecision(2); // set doubles to 2 decimal places
    cout << static_cast<char>(toupper(letters[i])) << ")" << setw(10) << tmpSnkList[i].getName() <<  
    setw(5) << "$" << tmpSnkList[i].getCost() << setw(5) << "(" << letters[i] << ")" <<
      setw(7) << tmpSnkList[i].getItemCount() << setw(13) << setfill(' ') << right << 
      tmpSnkList[i].getDescription() << endl;
}
}