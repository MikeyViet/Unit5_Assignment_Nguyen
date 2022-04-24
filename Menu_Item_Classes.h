/**************************************************************************
 * FileName:    Menu_Item_Classes.h
 * Description: Contains all the class definitions of the Menu and Items  
 **************************************************************************/
#ifndef MENU_ITEM_CLASSES.H 
#define MENU_ITEM_CLASSES.H
#include<string>

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
class MenuItem{
protected:
    double cost;    //amount of money item is worth
    int count;      //a total value of the item
public:
    MenuItem()  //dafault constructor
    {
        cost = 0.0;
        count = 0;
    }
    MenuItem(double cst, int cnt)   //parameterized constructor
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
    double getCost()const
    {
        return cost;
    }
    int getCount()const
    {
        return count;
    }
    ~MenuItem();    //destructor for base class
};

/**************************************************************************
 * DataType:    Class
 * Name:        Food
 * Heirarchy:   Derived from MenuItem
 * Attributes:  Access -> Protected - cost(double), count(int)
 * Methods:     Access -> Public - MenuItem()x2, setCost(), setCount(),
 *              getCost(), getCount(), ~MenuItem()
 *   
 * Description: The base class for all the items on the menu. It contains
 *              protected attributes that are only numerical values
 **************************************************************************/
class Food : public MenuItem{
protected:
    string name;    //name of the food
    string description; //description of the food
public:
    //default constructor call to base constructor
    Food() : MenuItem()  
    {
        name = "";
        description = "";
    }
    //parameterized constructor with passes to base class
    Food(double cst, int cnt, string nm, string desc) : MenuItem(cst, cnt)   
    {
        name = nm;
        description = desc;
    }
    void setName(string nm)
    {
        name = nm;
    }
    void setDescription(string desc)
    {
        description = desc;
    }
    string getName()const
    {
        return name;
    }
    string getDescription()const
    {
        return description;
    }
    ~Food();    //destructor for derived class
};

#endif