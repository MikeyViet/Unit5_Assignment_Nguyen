// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Classes.h"
//#include "Menu_Item_Functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void loadMenuItems(Item*);

int main()

{   
  Item menuItemObj;

  Item *mItemObjPtr;

  mItemObjPtr = &menuItemObj;

  loadMenuItems(mItemObjPtr);



  cout << "Program is working at the moment!\n";
  return 0;
}

//Function Definitions

/******************************************************************
 * Name:        loadMenuItems(MenuItem*)
 *
 * Parameters:
 *      Input:  Pointer to an object(MenuItem)
 *      Output: none
 *
 * Description: The function accepts a pointer to an object of type
 *      MenuItem in order to populate the items with values that
 *      have been loaded into vectors.
 ******************************************************************/
void loadMenuItems(Item *mItemPtr)
{
  
  
    // Load values of the items that will be on menu into vectors to populate the objects
    vector<string> items {"Burrito", "Hamburger", "Chocolate Sundae", "Apple Pie", "Chicken Sandwich", "Green Tea", "Coke", "Coffee", "Water", "Orange Juice"};
    vector<string> details{"Authentic Mexican", "1/2 Lb Angus", "Hot Fudge", "Home Made", "Organic Chicken Breast", "Refreshing", "Original Glass Bottles", "FIJI", "Lemon-lime"};
    vector<char> upLetters {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    vector<char> downLetters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    vector<double> prices{5.00, 7.00, 3.50, 3.00, 10.00, 2.50, 1.00, .75, 3.00, 2.50};
}
