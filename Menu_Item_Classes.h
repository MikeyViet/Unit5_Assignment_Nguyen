/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_CLASSES_H
#define MENU_ITEM_CLASSES_H

#include "Menu_Item_Functions.h"
#include <string>

using namespace std;

/**************************************************************************
 * DataType:    Class
 * Name:        MenuItem
 * Heirarchy:   Base
 * Attributes:  Access -> Protected - cost(double)
 * Methods:     Access -> Public - MenuItem()x2, setCost(), getCost(),
 *              
 *
 * Description: The base class for all the items on the menu. It only 
 *              contains item cost.
 **************************************************************************/
class MenuItem
{
protected:
    double cost; // amount of money item is worth
    string name; // name of the item
    string description; //details of the item
public:
    // default constructor
    MenuItem(){cost = 0.0; name = "Item 1"; description = "Good Stuff";} 
    // parameterized constructor
    MenuItem(double cst, string nm, string desc){cost = cst; name = nm; description = desc;}  
    
    //mutators methods
    void setCost(double cst);
    
    //accessor methods
    double getCost() const;
    
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
    void controlMenu(MenuItem&);
  //  
};
/**************************************************************************
 * DataType:    Class
 * Name:        Food
 * Heirarchy:   Derived from MenuItem
 * Attributes:  Access -> Protected - name(string), description(string)
 * Methods:     Access -> Public - Food()x2, setName(), setDescription(),
 *              getName(), getDescription(), 
 *
 * Description: This class holds the name and description of the Item that
 *              a person can eat.
 **************************************************************************/
class Food : public MenuItem
{
protected:
    bool heated;        // food required hot or cold (hot = true)
public:
    // default constructor call to base constructor
    Food() : MenuItem(){heated = true;}
    // parameterized constructor with passes to base class
    Food(double cst, string nm, string desc, bool heat) : MenuItem(cst, nm, desc){name = nm; description = desc; heated = heat;}

    //mutator methods
    void setName(string nm);
    void setDescription(string desc);
    void setHeated(bool heat);

    //accessor methods
    string getName() const;
    string getDescription() const;
    bool getHeated() const;
    
};

/**************************************************************************
 * DataType:    Class
 * Name:        Drink
 * Heirarchy:   Derived from Food
 * Attributes:  Access -> Protected - temp(string), ice(bool)
 * Methods:     Access -> Public - Drink()x2, setTemp(), setIced(),
 *              getTemp(), getIced(), 
 *
 * Description: This class holds the temperature (hot, cold, warm) and if
 *              the drinkable item needs to have ice or without.
 **************************************************************************/
class Drink : public Food
{
protected:
    string temp; // hold the state of the drink (warm, hot, or cold)
    bool iced;   // Does drink need ice? (yes = true)
public:
    // default constructor call to base constructor
    Drink() : Food(){temp = ""; iced = true;}
    // parameterized constructor with passes to base class
    Drink(string tmp, bool ice, string nm, string desc, bool heat, double cst) : Food(cst, nm, desc, heat){temp = tmp;iced = ice;}
    
    //mutator methods
    void setTemp(string tmp);
    void setIced(bool ice);

    //accessor methods
    string getTemp() const;
    bool getIced() const;
    
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
void Menu::controlMenu(MenuItem &menuObj)
{
    
        cout << fixed << setprecision(2); // set doubles to 2 decimal places
        cout << "This is DrT's Efficient Menu to Imitate" << endl;
        cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC" << endl;
/*         cout << letter << ")" << setw(10) << setw(5) << 
                "$" << totalItemCost << setw(5) << "(" << "char" << 
                ")" << setw(7) << itemCount << setw(13) << 
                menuObj.description << endl; */
        
    
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        MenuItem
 * heirarchy:   Derived from MenuItem
 **************************************************************************/
void MenuItem::setCost(double cst)
{
    cost = cst;
}
double MenuItem::getCost() const
{
    return cost;
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Food
 * heirarchy:   Derived from MenuItem
 **************************************************************************/
void Food::setName(string nm)
{
    name = nm;
}
void Food::setDescription(string desc)
{
    description = desc;
}
void Food::setHeated(bool heat)
{
    heated = heat;
}
string Food::getName() const
{
    return name;
}
string Food::getDescription() const
{
    return description;
}
bool Food::getHeated() const
{
    return heated;
}

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Drink
 * heirarchy:   Derived from Food
 **************************************************************************/
void Drink::setTemp(string tmp)
{
    temp = tmp;
}
void Drink::setIced(bool ice)
{
    iced = ice;
}
string Drink::getTemp() const
{
    return temp;
}
bool Drink::getIced() const
{
    return iced;
}

#endif

