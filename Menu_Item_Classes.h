/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_CLASSES_H
#define MENU_ITEM_CLASSES_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Menu_Item_Functions.h"

using namespace std;

/**************************************************************************
 * DataType:    Class
 * Name:        Item
 * Heirarchy:   Base
 * Attributes:  Access -> Protected - name(string), description(string),
 *              cost(double)
 * Methods:     Access -> Public - Item()x2, setName(string), 
 *              setDescription(string), setCost(double), getName(), 
 *              getDescription(), getCost()
 *
 * Description: The base class for all the items in inventory.  
 **************************************************************************/
class Item
{
protected:
    string name; // name of the item
    string description; //details of the item
    double cost; // amount of money item is worth

public:
    // default constructor
    Item(){name = "Item 1"; description = "Good Stuff"; cost = 0.0;} 
    // parameterized constructor
    Item(string nm, string desc, double cst){name = nm; description = desc; cost = cst;}  
    
    //mutators methods
    void setName(string);
    void setDescription(string);
    void setCost(double);
    
    //accessor methods
    string getName()const;
    string getDescription()const;
    double getCost() const;

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
private:
    string typeOfSnack; //food or drink
    bool tempOfSnack;   //hot or cold (hot = true)
    bool iced;          //Does drink or food (hot soup) need ice
public:
    Snacks() : Item(){typeOfSnack = "Food / Beverage", tempOfSnack = true, iced = false;}
    Snacks(string type, bool temp, bool ice,  double cst, string nm, string desc) : Item(nm, desc, cst){
        typeOfSnack = type;
        tempOfSnack = temp;
        iced = ice;
    }

    //mutator methods
    void setTypeOfSnack(string);
    void setTempOfSnack(bool);
    void setIced(bool);

    //accessor methods
    string getTypeOfSnack()const;
    bool getTempOfSnack()const;
    bool getIced()const;
}; 

/**************************************************************************
 * DataType:    Class
 * Name:        Menu
 * Heirarchy:   Base
 * Attributes:  Access -> Private - letter(char), count()
 * Methods:     Access -> Public - Menu(), setLetter(), setCount(),
 *              getLetter(), getCount()
 *               
 *
 * Description: The base class for the menu that displays a number of
 *              items along with details about the item. The menu is
 *              only responsible for keeping total count of the item,
 *              total cost of item, and allowing addition or removal 
 *              of item from menu.
 **************************************************************************/
class Menu
{
private:
    char letter;
    int itemCount;
    double totalItemCost;
public:
    //default constructor
    Menu(){letter = ' '; itemCount = 0; totalItemCost = 0.0;}
    //Parameterized constructor
    Menu(char l, int i, double  ){letter = l; itemCount = i; totalItemCost = 0.0;}

    //mutator methods
    void setLetter(char);
    void setItemCount(int);
    void setTotalCost(double);

    //accessor methods
    char getLetter()const;
    int getItemCount()const;
    
    //general methods
    double getTotalItemCost()const;
    void increaseCount();
    void decreaseCount();
    void displayMenu();
    void controlMenu(Item&);
  //  
};

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Menu
 * heirarchy:   Base
 **************************************************************************/

// mutator methods
void Menu::setLetter(char l)
{
    letter = l;
}
void Menu::setItemCount(int cnt)
{
    itemCount = cnt;
}
void Menu::setTotalCost(double cst)
{
    totalItemCost = cst;
}
// accessor methods
char Menu::getLetter() const
{
    return letter;
}
int Menu::getItemCount() const
{
    return itemCount;
}
// general methods
double Menu::getTotalItemCost() const
{
    return totalItemCost;
}
void Menu::increaseCount()
{
    itemCount++;
}
void Menu::decreaseCount()
{
    itemCount--;
}
void Menu::displayMenu()
{
    
}
void Menu::controlMenu(Item &menuObj)
{
    
        cout << fixed << setw(40) << setprecision(2); // set doubles to 2 decimal places
        cout << "This is DrT's Efficient Menu to Imitate" << endl;
        cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC" << endl;
        cout << letter << ")" << setw(10) << setw(5) << 
                "$" << totalItemCost << setw(5) << "(" << "char" << 
                ")" << setw(7) << itemCount << setw(13) << 
                menuObj.getDescription() << endl; 
        
    
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Item
 * heirarchy:   Base
 **************************************************************************/
//mutator methods
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
    cost = cst;
}
//accessor methods
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
    return cost;
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Snack
 * heirarchy:   Derived from Item
 **************************************************************************/
//mutator methods
void Snacks::setTempOfSnack(bool tmp)
{
    tempOfSnack = tmp;
}
void Snacks::setIced(bool ice)
{
    iced = ice;
}
//accessor methods
bool Snacks::getTempOfSnack() const
{
    return tempOfSnack;
}
bool Snacks::getIced() const
{
    return iced;
}

#endif

