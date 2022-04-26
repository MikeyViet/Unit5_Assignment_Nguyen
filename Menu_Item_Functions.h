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
 * name:        MenuItem
 * heirarchy:   Derived from MenuItem
 **************************************************************************/
void MenuItem::setCost(double cst)
{
    cost = cst;
}
void MenuItem::setCount(int cnt)
{
    count = cnt;
}
double MenuItem::getCost() const
{
    return cost;
}
int MenuItem::getCount() const
{
    return count;
}
void MenuItem::showMenu(MenuItem& MenuObj)
{
    
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