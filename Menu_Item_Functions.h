/**************************************************************************
 * FileName:    Menu_Item_Functions.h
 * Description: Contains all the member function (methods) definitions 
 *              of the Menu and Items
 **************************************************************************/
#ifndef MENU_ITEM_FUNCTIONS_H
#define MENU_ITEM_FUNCTIONS_H

#include<iostream>
#include<string>
#include"Input_Validation_Extended.h"
#include"Menu_Item_Classes.h"

/**************************************************************************
 * CLASS METHOD DEFINITIONS
 * name:        Menu
 * heirarchy:   Base
 **************************************************************************/
  //mutator methods
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

    //accessor methods
    char Menu::getLetter()const
    {
        return letter;
    }
    int Menu::getItemCount()const
    {
        return itemCount;
    }

    //general methods
    double Menu::getTotalItemCost()const
    {
        return totalItemCost;
    }
    void Menu::increaseCount(MenuItem& itemObj)
    {
        
    }
/*     void Menu::decreaseCount(MenuItem&);
    void Menu::displayMenu();
    void Menu::controlMenu(Menu&); */


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