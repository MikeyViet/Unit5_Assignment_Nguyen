/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_CLASSES_H
#define MENU_ITEM_CLASSES_H
#include <string>

using namespace std;

/**************************************************************************
 * DataType:    Class
 * Name:        MenuItem
 * Heirarchy:   Base
 * Attributes:  Access -> Protected - cost(double), count(int)
 * Methods:     Access -> Public - MenuItem()x2, setCost(), setCount(),
 *              getCost(), getCount(), ~MenuItem()
 *
 * Description: The base class for all the items on the menu. It contains
 *              protected attributes that are only numerical values
 **************************************************************************/
class MenuItem
{
protected:
    double cost; // amount of money item is worth
    int count;   // a total value of the item
public:
    MenuItem() // dafault constructor
    {
        cost = 0.0;
        count = 0;
    }
    MenuItem(double cst, int cnt) // parameterized constructor
    {
        cost = cst;
        count = cnt;
    }
    void setCost(double cst)
    {
        cost = cst;
    }
    void setCount(int cnt)
    {
        count = cnt;
    }
    double getCost() const
    {
        return cost;
    }
    int getCount() const
    {
        return count;
    }
    ~MenuItem(); // destructor for base class
};

/**************************************************************************
 * DataType:    Class
 * Name:        Food
 * Heirarchy:   Derived from MenuItem
 * Attributes:  Access -> Protected - name(string), description(string)
 * Methods:     Access -> Public - Food()x2, setName(), setDescription(),
 *              getName(), getDescription(), ~Food()
 *
 * Description: This class holds the name and description of the Item that
 *              a person can eat.
 **************************************************************************/
class Food : public MenuItem
{
protected:
    string name;        // name of the food
    string description; // description of the food
    bool heated;        // food required hot or cold (hot = true)
public:
    // default constructor call to base constructor
    Food() : MenuItem()
    {
        name = "";
        description = "";
        heated = true;
    }
    // parameterized constructor with passes to base class
    Food(double cst, int cnt, string nm, string desc, bool heat) : MenuItem(cst, cnt)
    {
        name = nm;
        description = desc;
        heated = heat;
    }
    void setName(string nm)
    {
        name = nm;
    }
    void setDescription(string desc)
    {
        description = desc;
    }
    void setHeated(bool heat)
    {
        heated = heat;
    }
    string getName() const
    {
        return name;
    }
    string getDescription() const
    {
        return description;
    }
    bool getHeated() const
    {
        return heated;
    }
    ~Food(); // destructor for derived class
};

/**************************************************************************
 * DataType:    Class
 * Name:        Drink
 * Heirarchy:   Derived from Food
 * Attributes:  Access -> Protected - temp(string), ice(bool)
 * Methods:     Access -> Public - Drink()x2, setTemp(), setIced(),
 *              getTemp(), getIced(), ~Drink()
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
    Drink() : Food()
    {
        temp = "";
        iced = true;
    }
    // parameterized constructor with passes to base class
    Drink(string tmp, bool ice, string nm, string desc, bool heat, double cst, int cnt) : Food(cst, cnt, nm, desc, heat)
    {
        temp = tmp;
        iced = ice;
    }
    void setTemp(string tmp)
    {
        temp = tmp;
    }
    void setIced(bool ice)
    {
        iced = ice;
    }
    string getTemp() const
    {
        return temp;
    }
    bool getIced() const
    {
        return iced;
    }
    ~Drink(); // destructor for derived class
};

#endif