//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019


#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Menu_Item_Classes.h"
#include"Menu_Item_Functions.h"

using namespace std; 
int main() 


{
  cout << "Is this program working? \n" << endl;

  Food hotDog;

  hotDog.setDescription("Fucking GOod");

  cout << hotDog.getDescription() << endl;

  hotDog.setCost(12.44);

  cout << "The Hotdog cost:  " << hotDog.getCost();

  
  cout << "Program is working at the moment!\n"; 
  return 0; 
}