/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_FUNCTIONS_H
#define MENU_ITEM_FUNCTIONS_H

#include "Input_Validation_Extended.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

#define SIZE 10

/**************************************************************************
 * DataType:    Class
 * Name:        Item
 * Heirarchy:   Base
 * Attributes:  Access -> Protected - name(string), description(string),
 *              cost(double), addCartLetter(char), removeCartLetter(char)
 * Methods:     Access -> Public - Item()x2, setName(string),
 *              setDescription(string), setCost(double), getName(),
 *              getDescription(), getCost(), getAddCartLetter(),
 *              getRemoveCartLetter()
 * Description: The base class for all the items in inventory.
 **************************************************************************/
class Item
{
protected:
    string name;        // name of the item
    string description; // details of the item
    double totalCost;
    int itemCount;
    char addCartLetter;    // holds option that is capital letter
    char removeCartLetter; // holds option that is lower letter

public:
    // default constructor
    Item()
    {
        name = "Item";
        description = "Good Stuff";
        totalCost = 0.0;
        itemCount = 0;
        addCartLetter = '\0';
        removeCartLetter = '\0';
    }
    // parameterized constructor
    Item(string nm, string desc, double cst, int cnt, char add, char rem)
    {
        name = nm;
        description = desc;
        totalCost = cst;
        itemCount = cnt;
        addCartLetter = add;
        removeCartLetter = rem;
    }

    // mutators methods
    void setName(string);
    void setDescription(string);
    void setCost(double);
    void setItemCount(int);
    void setTotalCost(double);
    void setAddCartLetter(char);
    void setRemoveCartLetter(char);

    // accessor methods
    string getName() const;
    string getDescription() const;
    double getCost() const;
    int getItemCount() const;
    char getAddCartLetter() const;
    char getRemoveCartLetter() const;

    // general methods
    double getTotalItemCost() const;
    void increaseCount();
    void decreaseCount();
};

/**************************************************************************
 * datatype:    class
 * name:        Snack
 * heirarchy:   derived from Item
 * attributes:  access -> private - typeOfSnack(str), tempOfSnack(bool),
 *                  iced(bool)
 * methods:     access -> public - snacks()x2, setTypeOfSnack(str),
 *              setTempOfSnack(bool), setIced(bool)
 *
 * description: This class is for snacks like food and drinks. Each snack
 *              is can be ordered to be at any temperature and drinks have
 *              the option of coming with ice or not.
 **************************************************************************/
class Snacks : public Item
{
protected:
    string typeOfSnack; // food or drink
    bool tempOfSnack;   // hot or cold (hot = true)
    bool iced;          // Does drink or food (hot soup) need ice
public:
    Snacks() : Item() { typeOfSnack = "Food / Beverage", tempOfSnack = true, iced = false; }
    Snacks(string type, bool temp, bool ice, string nm, string desc, double cst, int cnt, char add, char rem) : Item(nm, desc, cst, cnt, add, rem)
    {
        typeOfSnack = type;
        tempOfSnack = temp;
        iced = ice;
    }

    // mutator methods
    void setTypeOfSnack(string);
    void setTempOfSnack(bool);
    void setIced(bool);

    // accessor methods
    string getTypeOfSnack() const;
    bool getTempOfSnack() const;
    bool getIced() const;
};

/**************************************************************************
 * FileName:    Menu_Item_Functions.h
 * Description: Contains all the member function (methods) definitions
 *              of the Menu and Items
 **************************************************************************/

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
void Item::setAddCartLetter(char add)
{
    addCartLetter = add;
}
void Item::setRemoveCartLetter(char rem)
{
    removeCartLetter = rem;
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
char Item::getAddCartLetter() const
{
    return addCartLetter;
}
char Item::getRemoveCartLetter() const
{
    return removeCartLetter;
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
 *      Snacks objects. A text file containing the details of the
 *      Snacks object wil be opened to load all the data in the the
 *      Snacks vector.
 ******************************************************************/
void loadMenuItems(vector<Snacks> &tmpSnkList)
{
    Snacks tempSnacksObj;
    vector<Snacks> *snacksObjPtr = &tmpSnkList;

    for (int i = 0; i < SIZE; i++)
    {
        snacksObjPtr->push_back(tempSnacksObj);
    }

    vector<string> items{"Burrito", "Hamburger", "Chocolate Sundae", "Apple Pie", "Chicken Sandwich", "Green Tea", "Coke", "Coffee", "Water", "Orange Juice"};
    vector<string> details{"Authentic Mexican", "1/2 Lb Angus", "Hot Fudge", "Home Made", "Organic Chicken Breast", "Refreshing", "Original Glass Bottles", "Columbian", "FIJI", "Freshly Squeezed"};
    vector<double> prices{5.00, 7.50, 3.50, 3.00, 9.50, 2.50, 1.00, .75, 3.00, 2.50};
    vector<char> defaultAddLetters{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    vector<char> defaultRemoveLetters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    for (int i = 0; i < SIZE; i++)
    {
        tmpSnkList[i].setName(items[i]);
        tmpSnkList[i].setDescription(details[i]);
        tmpSnkList[i].setCost(prices[i]);
        tmpSnkList[i].setAddCartLetter(defaultAddLetters[i]);
        tmpSnkList[i].setRemoveCartLetter(defaultRemoveLetters[i]);
    }
}

#define NO_CONTROLLER
#ifdef NO_CONTROLLER

/******************************************************************
 * Name:        displayMenu()
 *
 * Parameters:
 *      Input:  Address of a vector of Snack Objects
 *      Output: none
 *
 * Description: The function accepts an address to a vector of
 *      Snacks and displays the menu with items on screen.
 ******************************************************************/
void displayMenu(vector<Snacks> &tmpSnkList)
{
    cout << fixed << setprecision(2); // set doubles to 2 decimal
    cout << "\nThis is the what Michael Ripped-Off from DrT's Efficient Menu to Imitate\n"
         << endl;
    cout << "ADD  \tNAME \t\t  COST \t    REMOVE    COUNT\t---DESCRIPTION---" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << tmpSnkList[i].getAddCartLetter() << ")";
        cout << "      " << left << setw(16) << tmpSnkList[i].getName();
        cout << "  "
             << "$" << tmpSnkList[i].getCost() << setw(7);
        cout << right << "(" << tmpSnkList[i].getRemoveCartLetter() << ")" << left << setw(7) << right << "  ";
        cout << right << setw(2) << setfill('0') << tmpSnkList[i].getItemCount();
        cout << left << "\t" << setw(10) << setfill(' ') << tmpSnkList[i].getDescription() << endl;
    }
    cout << "\nPlease take a look at the menu to decide what snack(s) you would like to ";
    cout << "purchase.\n"
         << endl;

    cout << "*Purchase Instructions*\n";
    cout << "-----------------------\n";
    cout << "To make a selection, choose the letter (A/a - J/j) that corresponds with the snack on the Menu (Q to quit).\n";
    cout << "Once you have confirmed that the item chosen is the correct one, you can enter:\n\n";
    cout << "Add snack item to cart by entering the capital letter next to your option.\n";
    cout << "Removed the snack item from your cart by entering the lowercase letter next ";
    cout << "to the same item.\n\n";
    cout << "Example: \n"
         << "      " << right << setw(25) << "(A) - Adding snack to cart." << endl;
    cout << "      " << right << setw(25) << "(a) - Adding snack to cart.\n"
         << endl;
}
/******************************************************************
 * Name:        printReceipt()
 *
 * Parameters:
 *      Input:  Address of a vector of Snack Objects, subTotal(double)
 *              cash(double), tip(double)
 *      Output: none
 *
 * Description: The function accepts an address to a vector of
 *      Snacks objects and subTotal. The function will print a
 *      receipt showing the item, count, and total.
 ******************************************************************/
void printReceipt(vector<Snacks> &tmpSnkList, double sTotal, double cash, double tip)
{
    cout << "NAME \t\t  COST\t       QUANTITY" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (tmpSnkList[i].getItemCount() > 0)
        {
            cout << left << setw(19) << tmpSnkList[i].getName();
            cout << "$" << left << setw(7) << tmpSnkList[i].getCost() * tmpSnkList[i].getItemCount();
            cout << right << setw(8) << tmpSnkList[i].getItemCount() << endl;
        }
    }
    cout << left << setw(20) << "\nSub Total:";
    cout << "$" << left << setw(7) << sTotal << "(" << tip << "% tip included)" << endl;
    cout << left << setw(19) << "Cash Tendered:";
    cout << "$" << left << setw(7) << cash << endl
         << endl;
    cout << left << setw(19) << "Change Due:";
    if (cash == 0.0)
    {
        cout << "$" << left << setw(7) << "0.00" << endl
             << endl;
    }
    else
    {
        cout << "$" << left << setw(7) << cash - sTotal << endl
             << endl;
    }

    ofstream outFile;
    outFile.open("receipt.txt", ios::app);

    outFile << "NAME \t\t\t   COST\t       QUANTITY" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (tmpSnkList[i].getItemCount() > 0)
        {
            outFile << left << setw(19) << tmpSnkList[i].getName();
            outFile << "$" << left << setw(7) << fixed << setprecision(2) << tmpSnkList[i].getCost() * tmpSnkList[i].getItemCount();
            outFile << right << setw(8) << tmpSnkList[i].getItemCount() << endl;
        }
    }
    outFile << left << setw(20) << "\nSub Total:";
    outFile << "$" << left << setw(7) << sTotal << "(" << tip << "% tip included)" << endl;
    outFile << left << setw(19) << "Cash Tendered:";
    outFile << "$" << left << setw(7) << cash << endl
            << endl;
    outFile << left << setw(19) << "Change Due:";
    if (cash == 0.0)
    {
        outFile << "$" << left << setw(7) << "0.00" << endl
                << endl;
    }
    else
    {
        outFile << "$" << left << setw(7) << cash - sTotal << endl
                << endl;
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
void controlOrderMenu(vector<Snacks> &snackList)
{
    char choice = '\0'; // menu option chosen by user;
    int choice2 = '\0'; // cash or credit option chosen by user
    double subTotal = 0.0;
    double tip = 0.0;
    double cashAmount = 0.0; // amount of cash given
    double change = 0.0;     // amount of change

    do
    {
        cout << "\nPlease make a selection now (X to checkout): ";
        cin >> choice;

        if ((int(choice) >= 65) && (int(choice) <= 74))
        {
            snackList[int(choice) - 65].increaseCount();
            cout << "\033[2J\033[1;1H"; // clear screen
            // set total cost from cost of item multiplied by count
            subTotal += snackList[int(choice) - 65].getCost();
            displayMenu(snackList);
            cout << "\t\t\tAmount Due\t\n";
            cout << "\t\t\tTotal: " << subTotal << endl;
        } // End if((int(choice) >= 65) && (int(choice) <= 74))

        // check if choice is lowercase letter by converting char to integer and testing
        //   it to see if it is between 97(a) and 106(j
        else if ((int(choice) >= 97) && (int(choice) <= 106))
        {
            if (snackList[int(choice) - 97].getItemCount() > 0)
            {
                snackList[int(choice) - 97].decreaseCount();
                cout << "\033[2J\033[1;1H"; // clear screen
                subTotal -= snackList[int(choice) - 97].getCost();
                displayMenu(snackList);
                cout << "\t\t\tAmount Due\t\n";
                cout << "\t\t\tTotal: " << subTotal << endl;

            } // End if(snackList[i].getItemCount() >= 0)
            else
            {
                cout << "\033[2J\033[1;1H"; // clear screen
                snackList[int(choice) - 97].getCost();
                displayMenu(snackList);
                cout << "\t\t\tAmount Due\t\n";
                cout << "\nYou can't remove item: " << snackList[int(choice) - 97].getName() << " because you have " << snackList[int(choice) - 97].getItemCount() << " count of that item.\n";
            }
        } // End if((int(choice) >= 97) && (int(choice) <= 106))
        else if (toupper(choice) == 'X')
        {
            cout << "\033[2J\033[1;1H"; // clear screen
            displayMenu(snackList);
            cout << "\t\t\tAmount Due\t\n";
            cout << "\t\t\tTotal: " << subTotal << endl;
            cout << "Please enter a tip percentage starting at 20%(do not type the % sign): ";
            tip = validateDouble(tip);

            subTotal = subTotal + (subTotal * (tip / 100));

            cout << "\033[2J\033[1;1H"; // clear
            displayMenu(snackList);
            cout << "\t\t\tAmount Due\t\n";
            cout << "\t\t\tTotal: " << subTotal << endl;
            cout << "Are you paying by cash or credit?(Enter 1: cash or 2: credit): ";
            choice2 = validateInt(choice2);
            if (choice2 == 1)
            {
                cout << "\nEnter cash amount: ";
                cashAmount = validateDouble(cashAmount);
                while (cashAmount <= subTotal)
                {
                    cout << "Your cash amount of: " << cashAmount << " is below total amount due of: " << subTotal << endl;
                    cout << "Please enter a new cash amount: ";
                    cashAmount = validateDouble(cashAmount);
                }
                cout << "\033[2J\033[1;1H"; // clear screen
                displayMenu(snackList);
                cout << "\t\t\tChange Due\t\n";
                cout << "\t\t\tTotal $: " << cashAmount - subTotal << endl;
                printReceipt(snackList, subTotal, cashAmount, tip);
            }
            else if (choice2 == 2)
            {
                cout << "\033[2J\033[1;1H"; // clear screen
                displayMenu(snackList);
                cout << "\t\t\tChange Due\t\n";
                cout << "\t\t\tTotal $: " << cashAmount - subTotal << endl;
                printReceipt(snackList, subTotal, cashAmount, tip);
            }

            for (int i = 0; i < SIZE; i++)
            {
                snackList[i].setItemCount(0);
            }
            subTotal = 0.0;
            cashAmount = 0.0;
            change = 0.0;
            tip = 0.0;
            cout << "Thank you for shopping with us. Have a nice day!!" << endl;
        }
        else if (toupper(choice) != 'X')
        {
            choice = validateChar(choice);
            cout << "\nYour selection was invalid.";
        }

    } while (toupper(choice) != 'Q');
}

#endif // NO_CONTROL
#endif
//???
