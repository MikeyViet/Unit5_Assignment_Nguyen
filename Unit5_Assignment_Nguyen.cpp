/********************************************************************
 *  Assignment: Unit 5 
 *  Title:      Fast Food Restaurant Menu
 *  Student:    Michael Nguyen
 *  Teacher:    Tyson McMillan
 *  Date:       04/26/2022
 *
 *  Description: This program builds on a structure driven menu created
 *               by Dr. Tyson McMillan. The menu was converted from 
 *               structure based to class based. The assignment helped
 *               further understanding of vectors and classes. 
 *
 *********************************************************************/
#include "Menu_Item_Functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

#define SIZE 10

//global function prototypes
void loadMenuItems(vector<Snacks>&);
void displayMenu(vector<Snacks>&);
void controlOrderMenu(vector<Snacks>&);
void printReceipt(vector<Snacks>&, double, double, double);

int main()
{ 
  //instantiate the Menu and Snacks Object
  Item itemObj;
  // create vector of snacks objects
  vector<Snacks>snackList;
  // load object into Menu
  loadMenuItems(snackList);
  // displayMenu 
  displayMenu(snackList);
  // control Menu
  controlOrderMenu(snackList);

  return 0;
}
