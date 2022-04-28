/**************************************************************************
 * FileName:    Menu_Item_Functions.h
 * Description: Contains all the member function (methods) definitions
 *              of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_FUNCTIONS_H
#define MENU_ITEM_FUNCTIONS_H

#include "Input_Validation_Extended.h"
#include "Menu_Item_Classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Item
 * heirarchy:   Base
 **************************************************************************/
// mutator methods
void Item::setName(string nm)
{
    name = nm;
}
void Item::setDescription(string desc)
{
    description = desc;
}
void Item::setCost(double cst)
{
    totalCost = cst;
}
void Item::setItemCount(int cnt)
{
    itemCount = cnt;
}
void Item::setTotalCost(double cst)
{
    totalCost = cst;
}
// accessor methods
string Item::getName() const
{
    return name;
}
string Item::getDescription() const
{
    return description;
}
double Item::getCost() const
{
    return totalCost;
}
// mutator methods
int Item::getItemCount() const
{
    return itemCount;
}
// general methods
double Item::getTotalItemCost() const
{
    return totalCost;
}
void Item::increaseCount()
{
    itemCount++;
}
void Item::decreaseCount()
{
    itemCount--;
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Snack
 * heirarchy:   Derived from Item
 **************************************************************************/
// mutator methods
void Snacks::setTypeOfSnack(string s)
{
    typeOfSnack = s;
}
void Snacks::setTempOfSnack(bool tmp)
{
    tempOfSnack = tmp;
}
void Snacks::setIced(bool ice)
{
    iced = ice;
}
// accessor methods
bool Snacks::getTempOfSnack() const
{
    return tempOfSnack;
}
bool Snacks::getIced() const
{
    return iced;
}

// Function Definitions

/******************************************************************
 * Name:        loadMenuItems()
 *
 * Parameters:
 *      Input:  Address of a vector of Snack Objects
 *      Output: none
 *
 * Description: The function accepts an address to a vector of
 *      Snacks objects. The vector will be loaded with 10 Snack
 *      objects. 4 vectors with details for the Snacks object will
 *      be loaded into vectors in order to load them all into each
 *      Snack object in the vector.
 ******************************************************************/
void loadMenuItems(vector<Snacks> &tmpSnkList)
{
    // create vector pointer to point to the address of the vector of
    //   snacks objects
    vector<Snacks> *snkPtr = &tmpSnkList;

    // loop to fill the vector with Snacks objects. A temp snack object
    //   will be created and loaded into vector each loop. The Snacks
    //   object should be repeated created and replaced.
    for (int i = 1; i <= SIZE; i++)
    {
        Snacks temp;             // instantiate a temporary snack object
        snkPtr->push_back(temp); // push the temp snack object to vector
    }

    // Load values of the items that will be on menu into vectors to populate the objects
    vector<string> items{"Burrito", "Hamburger", "Chocolate Sundae", "Apple Pie", "Chicken Sandwich", "Green Tea", "Coke", "Coffee", "Water", "Orange Juice"};
    vector<string> details{"Authentic Mexican", "1/2 Lb Angus", "Hot Fudge", "Home Made", "Organic Chicken Breast", "Refreshing", "Original Glass Bottles", "Columbian", "FIJI", "Freshly Squeezed"};
    vector<double> prices{5.00, 7.50, 3.50, 3.00, 9.50, 2.50, 1.00, .75, 3.00, 2.50};
    vector<string> type{"Breakfast", "Lunch", "Ice Cream", "Bakery", "Lunch", "Tea", "Soda", "Coffee", "Water", "Juice"};

    // Load details of the Snacks object in the vector
    for (int i = 0; i < SIZE; i++)
    {
        tmpSnkList[i].setName(items[i]);
        tmpSnkList[i].setDescription(details[i]);
        tmpSnkList[i].setCost(prices[i]);
        tmpSnkList[i].setTypeOfSnack(type[i]);
    }
}

void displayMenu(vector<Snacks> &tmpSnkList, vector<char> &letters)
{
    cout << fixed << setprecision(2); // set doubles to 2 decimal
    cout << "\nThis is the what Michael Ripped-Off from DrT's Efficient Menu to Imitate\n"
         << endl;
    cout << "ADD  \tNAME \t\t  COST \t    REMOVE    COUNT\t---DESCRIPTION---" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << static_cast<char>(toupper(letters[i])) << ")";
        cout << "      " << left << setw(16) << tmpSnkList[i].getName();
        cout << "  "
             << "$" << tmpSnkList[i].getCost() << setw(7);
        cout << right << "(" << letters[i] << ")" << left << setw(7) << right << "  ";
        cout << left << setw(2) << setfill('0') << tmpSnkList[i].getItemCount();
        cout << left << "\t" << setw(10) << setfill(' ') << tmpSnkList[i].getDescription() << endl;
    }
}
/******************************************************************
 * Name:        controlOrderMenu()
 *
 * Parameters:
 *      Input:  Address of a vector of Snack Objects
 *      Output: none
 *
 * Description: The function accepts an address to a vector of
 *      Snacks objects. The function will allow user to add or
 *      remove a snack item from the menu displayed on the screen
 *      updateing the total of snacks and total dollar amount
 *      accordingly
 ******************************************************************/
void controlOrderMenu(vector<Snacks> &snackList, vector<char> &letters)
{
    char choice = '\0'; // menu option chosen by user;
    double subTotal = 0.0;

    cout << "\nPlease take a look at the menu to decide what snack(s) you would like to ";
    cout << "purchase.\n"
         << endl;

    cout << "*Purchase Instructions*\n";
    cout << "-----------------------\n";
    cout << "To make a selection, choose the letter (A/a - J/j) that corresponds with the snack on the Menu.\n";
    cout << "Once you have confirmed that the item chosen is the correct one, you can enter:\n\n";
    cout << "Add snack item to cart by entering the capital letter next to your option.\n";
    cout << "Removed the snack item from your cart by entering the lowercase letter next ";
    cout << "to the same item.\n\n";
    cout << "Example: \n"
         << "      " << right << setw(25) << "(A) - Adding snack to cart." << endl;
    cout << "      " << right << setw(25) << "(a) - Adding snack to cart.\n"
         << endl;

    do
    {
        cout << "Please make a selection now: ";
        cin >> choice;

        for (int i = 0; i < snackList.size(); i++)
        {
            // check if choice is capital letter by converting char to integer and testing
            //   it to see if it is between 65(A) and 74(J)
            if ((int(choice) >= 65) && (int(choice) <= 74))
            {
                snackList[i].increaseCount();
                // set total cost from cost of item multiplied by count
                snackList[i].setTotalCost((snackList[i].getCost() + snackList[i].getTotalItemCost()));
                subTotal += snackList[i].getCost();
                displayMenu(snackList, letters);
                cout << "\tAmount Due\t\n";
                cout << "\tTotal: " << subTotal;
            } // End if((int(choice) >= 65) && (int(choice) <= 74))

            // check if choice is lowercase letter by converting char to integer and testing
            //   it to see if it is between 97(a) and 106(j)
            else if ((int(choice) >= 97) && (int(choice) <= 106))
            {
                if (snackList[i].getItemCount() > 0)
                {
                    snackList[i].decreaseCount();
                    snackList[i].setTotalCost(snackList[i].getTotalItemCost() - snackList[i].getCost());
                    subTotal -= snackList[i].getCost();
                    displayMenu(snackList, letters);
                    cout << "\tAmount Due\t\n";
                    cout << "\tTotal: " << subTotal;

                } // End if(snackList[i].getItemCount() >= 0)
                else
                {
                    snackList[i].getCost();
                    displayMenu(snackList, letters);
                    cout << "\tAmount Due\t\n";
                    cout << "You can't remove item: " << snackList[i].getName() << " because you have " << snackList[i].getItemCount() << " count of that item.\n";
                }
                // End if((int(choice) >= 97) && (int(choice) <= 106))
                else
                {
                    if (toupper(choice) != 'X')
                    {
                        choice = validateChar(choice);
                        cout << "Your selection was invalid.";
                    }
                }
                // End for(t i = 0; i < snackList.size(); i++)

                system("pause");
            }
            while (toupper(choice) != 'X')
                ;
        }
        cout << "Thank you for shopping with us. Have a nice day!!" << endl;
    }
#endif