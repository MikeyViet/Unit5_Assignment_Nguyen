// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Menu_Item_Classes.h"
#include "Menu_Item_Functions.h"

void loadMenuItems(MenuItem*);

using namespace std;
int main()

{
  //instantiate item object to hold the starting details 
  MenuItem itemObj;
  //create pointer to point to the address of the item
  MenuItem *itemObjPtr = &itemObj;

  //Load values of the items that will be on menu into vectors to populate the objects
  vector<string> items {"Burrito", "Hamburger", "Chocolate Sundae", "Apple Pie", "Chicken Sandwich", "Green Tea", "Coke", "Coffee", "Water", "Orange Juice"};
  vector<string> details {"Authentic Mexican", "1/2 Lb Angus", "Hot Fudge", "Home Made", "Organic Chicken Breast", "Refreshing", "Original Glass Bottles", "FIJI", "Lemon-lime"};
  vector<char> upLetters {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  vector<char> downLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  vector<double> prices {5.00, 7.00, 3.50, 3.00, 10.00, 2.50, 1.00, .75, 3.00, 2.50};


  // just test codes

  MenuItem Item;

  Menu MenuObj;

  MenuObj.controlMenu(Item);
  cout << "Is this program working? \n"
       << endl;

  Food hotDog;

  hotDog.setDescription("Fucking GOod");

  cout << hotDog.getDescription() << endl;

  hotDog.setCost(12.44);

  cout << "The Hotdog cost:  " << hotDog.getCost();

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
void loadMenuItems(MenuItem *mItemPtr)
{

}