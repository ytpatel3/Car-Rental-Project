/*
Yash Patel
Car Rental Project
6/3/22
Extra: option to view the company's favorite cars (option 5)
*/

#include <iostream>
#include <iomanip>
#include <string> 
#include <vector>

using namespace std;

//declare structures
//user's personal information will be stored in a structure
struct info{
  string name, cardOwner, emergencyContact, address;
  vector<string> vehicleName;
  vector<double> vehiclePrice;
  int days, members;
  bool roadsideAssistance, gasCoverage, faultCoverage;
  int choice;
  double totalCost;
};

struct vehicles {
  //parallel vectors to store vehicle names and prices in an aligned manner
  vector<string> smallCars = {"Tesla Model 3", "Maserati GranTurismo", "BMW i8", "Chevrolet Corvette", "Ferrari Portofino", "Lamborghini Aventador"};
  vector<double> smallCarPrice = {46990, 150980, 147500, 60900, 213054, 501953};
  vector<string> bigCars = {"Tesla Cybertruck", "Lincoln Navigator", "BMW X7", "Land Rover Range Rover", "Cadillac Escalade", "Lamborghini Urus"};
  vector<double> bigCarPrice = {69900, 77000, 74900, 93800, 77795, 218009};
};


int main() {
  
  cout << "\n               Welcome to Yash's Car Rental Service!\n"; //welcome message

  //variable to access structure variables and vectors
  struct info variables;

  bool run = true; //to run program again
  string choice2;

  do{
    bool errorTrap = true; //error trapping true/false variable
    while(errorTrap == true) {
      string s;
      cout << "\nSelect an option to continue:\n";
      cout << "1.) Register a user\n";
      cout << "2.) Choose a vehicle\n";
      cout << "3.) Add-ons\n";
      cout << "4.) Payment information\n";
      cout << "5.) Recommended cars\n";
      cout << "6.) Exit program\n";
      getline(cin, s); //getline throughout the program will result in a smooth program
      variables.choice = stoi(s); //changes s to an integer type
      if(variables.choice > 0 && variables.choice <= 6) { //error trapping
        errorTrap = false;
      }
      else {
        cout << "\nInvalid option. Please try again.\n";
      }
    }

    if(variables.choice == 1) { //registering a user
      //name
      cout << "\nEnter your name: ";
      getline(cin, variables.name);
      //number of members in group
      errorTrap = true;
      while(errorTrap == true) {
        string s;
        cout << "Enter the number of members in your group: ";
        getline(cin, s); //getline throughout the program will result in a smooth program
        variables.members = stoi(s); //changes s to an integer type
        if(variables.members > 0) { //error trapping
          errorTrap = false;
        }
        else {
          cout << "\nInvalid option. Please try again.\n";
        }
      }
      //address
      cout << "Enter your address: ";
      getline(cin, variables.address);
      //number of days to rent
      errorTrap = true;
      while(errorTrap == true) {
        string s;
        cout << "Enter the number of days you want to rent the vehicle: ";
        getline(cin, s); //getline throughout the program will result in a smooth program
        variables.days = stoi(s); //changes s to an integer type
        if(variables.days > 0) { //error trapping
          errorTrap = false;
        }
        else {
          cout << "\nInvalid option. Please try again.\n";
        }
      }
      //card owner
      cout << "Enter credit card owner's name: ";
      getline(cin, variables.cardOwner);
      //emergency contact
      do {
			  cout << "Enter the emergency contact number: ";
			  getline(cin, variables.emergencyContact);
			} while(!(variables.emergencyContact.length() == 10));

      cout << "\n\n" << variables.name << " is registered!\n";
    }

    if(variables.choice == 2) {
      //variable for calling vehicles structure
      struct vehicles vehicleType;
      
      if(variables.members <= 5) { //smallCars if there are 5 or less members
        errorTrap = true;
        while(errorTrap == true) {
          cout << "\nChoose a car meant for 5 people or less:\n";
          for(int i = 0; i < vehicleType.smallCars.size(); i++) {
            cout << i + 1 << ".)  ";
            cout.width(30); cout << left << vehicleType.smallCars[i];
            cout << "Price: $" << vehicleType.smallCarPrice[i];
            cout << "\n";    
          }
          string s;
          getline(cin, s);
          if(stoi(s) > 0) {
  variables.vehicleName.push_back(vehicleType.smallCars[stoi(s)-1]);
  variables.vehiclePrice.push_back(vehicleType.smallCarPrice[stoi(s)-1]);
            errorTrap = false;
          } 
          else {
            cout << "\nInvalid option. Please try again.\n";
          }
        }
      }

      if(variables.members >= 6 && variables.members <= 8) { //bigCars if there are 6, 7, or 8 people
        errorTrap = true;
        while(errorTrap == true) {
          cout << "\nChoose a car meant for 6-8 people:\n";
          for(int i = 0; i < vehicleType.bigCars.size(); i++) {
            cout << i + 1 << ".)  ";
            cout.width(30); cout << left << vehicleType.bigCars[i];
            cout << "Price: $" << vehicleType.bigCarPrice[i];
            cout << "\n";  
          }
          string s;
          getline(cin, s);
          if(stoi(s) > 0) {
  variables.vehicleName.push_back(vehicleType.bigCars[stoi(s)-1]);
  variables.vehiclePrice.push_back(vehicleType.bigCarPrice[stoi(s)-1]);
            errorTrap = false;
          } 
          else {
            cout << "\nInvalid option. Please try again.\n";
          }
        }
      }

      cout << "\n\n" << variables.name << " purchased a vehicle!\n";
    }

    if(variables.choice == 3) {
      int services; //user choice from add-on services
      
      errorTrap = true;
      while(errorTrap == true) {
        string s;
        vector<string> types = {"Roadside Assistance", "Gas Fill Coverage", "Driver Fault Coverage"};
        vector<double> typesPrices = {25, 50, 80};
        cout << "\nSelect an add-on:\n";
        for(int i = 0; i < types.size(); i++) {
          cout << i + 1 << ".)  ";
          cout.width(30); cout << left << types[i];
          cout << "Price: $" << typesPrices[i] << " per day";
          cout << "\n";  
        }
        
        getline(cin, s);
        variables.choice = stoi(s);
        if(variables.choice > 0 && variables.choice <= 3) { //error trapping
          errorTrap = false;
        }
        else {
          cout << "\nInvalid option. Please try again.\n";
        }
      }

      if(services == 1) { //roadside assistance
        variables.vehiclePrice.push_back(25); //add 25 to price
        cout << "\nYou purchased roadside assistance!\n";        
      }
      if(services == 2) { //gas coverage
        variables.vehiclePrice.push_back(50); //add 50 to price
        cout << "\nYou purchased gas fill coverage!\n";        
      }
      if(services == 3) { //fault coverage
        variables.vehiclePrice.push_back(80); //add 80 to price
        cout << "\nYou purchased driver fault coverage!\n";        
      }

      cout << "\nYou purchased an add-on service!\n";
    }

    if(variables.choice == 4) {
      //payment information
      cout << "\nPayment information for " << variables.name << ":\n";
      for(int i = 0; i < variables.vehiclePrice.size(); i++) {
        cout << "Item #" << i + 1 << ": $" << variables.vehiclePrice[i] << "\n";
        variables.totalCost += variables.vehiclePrice[i];
      }
      cout << "\nTotal Cost: $" << variables.totalCost << "\nBilled to: " << variables.cardOwner << "\n";
    }

    if(variables.choice == 5) { //extra
      cout << "\nOur Top 5 Cars:\n";
      cout << "1.) Tesla Model 3\n";
      cout << "2.) Lamborghini Aventador\n";
      cout << "3.) BMW i8\n";
      cout << "4.) Cadillac Escalade\n";
      cout << "5.) Tesla Cybertruck\n";
    }
    
    if(variables.choice == 6) {
      cout << "\nFinal Receipt:\n";
      for(int i = 0; i < variables.vehiclePrice.size(); i++) {
        cout << "Item #" << i + 1 << ": $" << variables.vehiclePrice[i] << "\n";
        variables.totalCost += variables.vehiclePrice[i];
      }
      cout << "\nTotal Cost: $" << variables.totalCost << "\nBilled to: " << variables.cardOwner << "\n";

      cout << "\n\nThank you for using our service!\n";

      return 0;
      
    }
    
  }while(run == true);
  
}