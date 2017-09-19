#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Donor.h"
using namespace std;

Donor::Donor(){}

void Donor::runProgram(){
	string run = "Testing";
	while(run != "Quit"){
		cout << endl;
		cout << "Enter a command."  << endl;
		cout << "Choose from [Login, Add, Save, Load, Report, Quit]: ";
		cin >> run;
		cout << endl; //for spacing
		if(run == "Login"){
			loginFunc();
		}else if(run == "Add"){
			addFunc(&last, &first, &age, &streetNum, &streetName, &town, &zip);
		}else if(run == "Save"){
			saveFunc();
		}else if(run == "Load"){
			loadFunc();		
		}else if(run == "Report"){
			reportFunc();
		}else{
			if (run != "Quit"){cout << "Command not recognized. Please try again." << endl;}
		}	
	}
}
void Donor::memberMenu(){
	cout << "This is the call to the memberMenu... Not complete yet!" << endl;

}

void Donor::loginFunc(){ 
	bool access = false;
	string tempUserID;
	string tempPassword;

	while(access == false){
	cout << endl; //for spacing
	cout << "userID: ";
	cin >> tempUserID;
	cout << "Password: ";
	cin >> tempPassword;

	//If id and password correct: 
	access = false;
	memberMenu(); //Perhaps pass on an array index of the user??? or something as parameter 
	
	
	//If id and password not correct
	/*	
	cout << "Incorrect UserId and password. Please Try again." << endl;	

	*/
	}
	//maybe have a for loop that checks the object array to see if user and password is correct
	//Then allow access to 2nd level menu
	//If not, then tell user the id and pw is not correct

}
void Donor::saveFunc(){
	//Function that saves all current donor database information into a file. 
	//Prompt user for name of file to save information to and open and write. Warn if exists
		//Allow user to select a different file or overwrite 
	cout << "saveFunction being worked on..." << endl;
	
}
void Donor::loadFunc(){
	cout << "load Function being worked on..." << endl;
	cout << endl;
	cout << "Please enter the name of the file: " << endl;
	//Replace any information "in memory" overwritten by contents of the file user inputs
	//Format must match the output file for save
	
	
}
void Donor::reportFunc(){
	cout << "REPORT REPORT" << endl;
	cout << "Report:" << endl;
	cout << endl;

	cout << "Total number of donors in the database: "; // Fill in later
	cout << "Total amount donated to campaign: "; //Fill in later.	
}

void Donor::addFunc(string *last, string *first,int *age, int *streetNum, string *streetName, string *town, string *zip){
	string ln, fn, sName, t, z;
	int a, sNum; 

	cout << "Last Name: ";
	cin >> ln;
	cout << "First Name: ";
	cin >> fn;
	cout << "Age: ";
	cin >> a;
	cout << "House Number: ";
	cin >> sNum;
	cout << "Street Name: ";
	cin >> sName;
	cout << "Town: ";
	cin >> t;
	cout << "Zip Code: ";
	cin >> z;
	
	*last =  ln;
	*first = fn;
	*age = a;
	*streetNum = sNum;
	*streetName = sName;
	*town = t;
	*zip = z;
}
void Donor::manageFunc(string *last, string *first,int *age, int *streetNum, string *streetName, string *town, string *zip){
	string ln, fn, sName, t, z;
	int a, sNum;
	cout << "Last Name: ";
	cin >> ln;
	cout << "First Name: ";
	cin >> fn;
	cout << "Age: ";
	cin >> a;
	cout << "House Number: ";
	cin >> sNum;
	cout << "Street Name: ";
	cin >> sName;
	cout << "Town: ";
	cin >> t;
	cout << "Zip Code: ";
	cin >> z;
	
	*last =  ln;
	*first = fn;
	*age = a;
	*streetNum = sNum;
	*streetName = sName;
	*town = t;
	*zip = z;
}
void Donor::viewFunc(){
	cout << "Donor Info " << endl;
	cout << first << " " << last << ": " << "age " << age << endl;
	cout << streetNum << " " << streetName << endl;
	cout << town << ", " << "NY" << " " << zip << endl;
	cout << "Current Amount Donated: " << "$" << fixed << setprecision(2) << amount << endl;
}
void Donor::donateFunc(){
	float userInput;
	bool balanceChecker = true;
	float balanceOver = 0.00;
	while(balanceChecker == true){
		cout << "Enter Amount to Donate: ";
		cin >> userInput;
		if(userInput < 0){cout<< "Invalid amount entered. Please try again..." << endl;}
		else{
			balanceOver = amount;
			balanceOver += userInput; 
			if (balanceOver > 5000) {
				cout << "Invalid amount entered. Total amount donated cannot grow beyond $5,000" << endl;
			}
			else{
				amount += userInput; 
				cout << "$" << userInput << fixed << setprecision(2) << " donated." << endl;
				balanceChecker = false;
			}
		}
	}	
}
void Donor::totalFunc(){
	cout << "$" << fixed << setprecision(2) << amount << endl;
}

