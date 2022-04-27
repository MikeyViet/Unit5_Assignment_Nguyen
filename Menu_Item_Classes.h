/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_CLASSES_H
#define MENU_ITEM_CLASSES_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Menu_Item_Functions.h"

using namespace std;

#define SIZE 10 // size of our vector for items

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
    string name;        // name of the item
    string description; // details of the item
    double totalCost;
    int itemCount;

public:
    // default constructor
    Item()
    {
        name = "Item";
        description = "Good Stuff";
        totalCost = 0.0;
        itemCount = 0;
    }
    // parameterized constructor
    Item(string nm, string desc, double cst, int cnt)
    {
        name = nm;
        description = desc;
        totalCost = cst;
        itemCount = cnt;
    }

    // mutators methods
    void setName(string);
    void setDescription(string);
    void setCost(double);
    void setItemCount(int);
    void setTotalCost(double);

    // accessor methods
    string getName() const;
    string getDescription() const;
    double getCost() const;
    int getItemCount() const;

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
private:
    string typeOfSnack; // food or drink
    bool tempOfSnack;   // hot or cold (hot = true)
    bool iced;          // Does drink or food (hot soup) need ice
public:
    Snacks() : Item() { typeOfSnack = "Food / Beverage", tempOfSnack = true, iced = false; }
    Snacks(string type, bool temp, bool ice, string nm, string desc, double cst, int cnt) : Item(nm, desc, cst, cnt)
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



#endif
