// A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
#include "Menu_Item_Functions.h"
#include "Menu_Item_Classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

//global constants
#define SIZE 10 //size of our vector for items
//global function prototypes
void loadMenuItems(vector<Snacks>&);
void displayMenu(vector<Snacks> &, vector<char> &);
void controlOrderMenu(vector<Snacks>&, vector<char>&);

int main()
{   
  //instantiate the Menu and Snacks Object
  Item itemObj;

  //create a vector with room for 10 Snacks objects
  vector<Snacks>snackList;
  //created char vector to hold letters to allow for easy population of 
  //  the vector of objects
  vector<char>downLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  //load the snacklist with the details of the snacks it contains
  loadMenuItems(snackList);
  //display the Menu of snacks additional information and option to add
  // or remove from shopping cart
  displayMenu(snackList, downLetters);

  //display messate to confirm program runs.
  // cout << "\nProgram is working at the moment!\n";

  // controlOrderMenu(snackList, downLetters);

  return 0;
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
void controlOrderMenu(vector<Snacks> &snackList, vector<char> &letters)
{
  char choice = '\0'; //menu option chosen by user;
  double subTotal = 0.0;

  cout << "\nPlease take a look at the menu to decide what snack(s) you would like to ";
  cout << "purchase.\n" << endl;

  cout << "*Purchase Instructions*\n";
  cout << "-----------------------\n";
  cout << "To make a selection, choose the letter (A/a - J/j) that corresponds with the snack on the Menu.\n";
  cout << "Once you have confirmed that the item chosen is the correct one, you can enter:\n\n";
  cout << "Add snack item to cart by entering the capital letter next to your option.\n";
  cout << "Removed the snack item from your cart by entering the lowercase letter next ";
  cout << "to the same item.\n\n";
  cout << "Example: \n" << "      " << right << setw(25) << "(A) - Adding snack to cart." << endl;
  cout << "      " << right << setw(25) << "(a) - Adding snack to cart.\n" << endl;

  do
  {
    cout << "Please make a selection now: ";
    cin >> choice;

    for(int i = 0; i < snackList.size(); i++)
    {
      //check if choice is capital letter by converting char to integer and testing
      //  it to see if it is between 65(A) and 74(J)
      if((int(choice) >= 65) && (int(choice) <= 74))
      {
        snackList[i].increaseCount();
        //set total cost from cost of item multiplied by count
        snackList[i].setTotalCost((snackList[i].getCost() + snackList[i].getTotalItemCost()));
        subTotal += snackList[i].getCost();
        displayMenu(snackList, letters);
        cout << "\tAmount Due\t\n";
        cout << "\tTotal: " << subTotal;
      }// End if((int(choice) >= 65) && (int(choice) <= 74))
      
      //check if choice is lowercase letter by converting char to integer and testing
      //  it to see if it is between 97(a) and 106(j)
      else if((int(choice) >= 97) && (int(choice) <= 106))
      {
        if(snackList[i].getItemCount() > 0)
        {
          snackList[i].decreaseCount();
          snackList[i].setTotalCost(snackList[i].getTotalItemCost() - snackList[i].getCost());
          subTotal -= snackList[i].getCost();
          displayMenu(snackList, letters);
          cout << "\tAmount Due\t\n";
          cout << "\tTotal: " << subTotal;
        
        }// End if(snackList[i].getItemCount() >= 0)
        else
        {
          cout << "You can't remove item: " << snackList[i].getName() << " because you have " << snackList[i].getItemCount() << " count of that item.\n";
        }
      }// End if((int(choice) >= 97) && (int(choice) <= 106))
      else
      {
        if(toupper(choice) != 'X')
        {
          choice = validateChar(choice);
          cout << "Your selection was invalid.";
        }
      }



    }// End for(t i = 0; i < snackList.size(); i++)

    system("pause");

  }while(toupper(choice) != 'X');
   
  cout << "Thank you for shopping with us. Have a nice day!!" << endl;




}