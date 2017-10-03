#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <map>
#include <string>
#include "Donor.h"
using namespace std;

Donor::Donor(){
		last = " "; 
		first = " ";  
		streetName = " ";  
		town = " ";  
		zip = " ";  
		userId = "" ; 
		pw = " "; 
		st = " "; 
		age = 0;
		streetNum = 0;
		userAmount = 0.00;
		totalDonors = 0;
}

void Donor::memberMenu(){
	string run = "";

	while(run != "Logout"){
		cout << "Enter a command." << endl;
		cout << "Choose from [Manage, Passwd, View, Donate, Total, Logout]: ";
		cin >> run;
		cout << endl; //for spacing
		if(run == "Manage"){
			manageFunc();
		}else if(run == "Passwd"){
			passwdFunc();
		}else if(run == "View"){
			viewFunc();
		}else if(run == "Donate"){
			donateFunc();		
		}else if(run == "Total"){
			totalFunc();
		}else{
			if (run != "Logout"){cout << "Command not recognized. Please try again." << endl;}
		}	
	}
}
float Donor::getUserAmount(){
	return userAmount;
}
string Donor::getuserID(){
	return userId;
}
string Donor::getpw(){
	return pw;
}
string Donor::getLast(){
	return last;
}
string Donor::getFirst(){
	return first;
}
string Donor::getStreetName(){
	return streetName;
}
string Donor::getTown(){
	return town;
}
string Donor::getZip(){
	return zip;
}
string Donor::getState(){ 
	return st;
}
int Donor::getAge(){
	return age;
}
int Donor::getstreetNum(){
	return streetNum;
}
string Donor::setuserID(){
	string id;
	cout << "Enter a new userID: ";
	cin >> id;
	return id;
}
void Donor::setUserID(string id){
	this->userId = id;	
}
void Donor::setpw(string input){
	pw = input;
}
void Donor::setLast(string input){
	last = input;
}
void Donor::setFirst(string input){
	first = input;
}
void Donor::setAge(int input){
	age = input;
}
void Donor::setStreetNum(int input){
	streetNum = input;
}
void Donor::setStreetName(string input){
	streetName = input;
}
void Donor::setTown(string input){
	town = input;
}
void Donor::setZip(string input){
	zip = input;
}
void Donor::setUserAmount(float input){
	userAmount = input;
}
void Donor::setState(string input){
	st = input;
}

void Donor::addFunc(){
	int looper = 1;
	bool check;
	while(looper == 1){
		cout << "Enter a password: ";
		cin.ignore();
		getline(cin,pw);
		check = checkpw(pw);
		if(check == true) break;
	}

	while(looper == 1){
		cout << "Last Name: ";
		getline(cin,last);
		check = checkStrings(last);
		if(check == true) break;
	}

	while(looper == 1){
		cout << "First Name: ";
		getline(cin,first);
		check = checkStrings(first);
		if(check == true) break;
	}

	cout << "Age: ";
	cin >> age;
	while (age < 18){
		cout << "You have entered an invalid age. Please try again..." << endl << "Age: ";
		cin >> age;
	}

	while(looper ==1){
		cout << "House Number: ";
		cin >> streetNum; 
		if(streetNum > 0)break;
	}
	cout << "Street Name: ";
	cin.ignore(); getline(cin,streetName);

	cout << "Town: ";
	getline(cin,town);

	while(looper == 1){
		cout << "State (NY, PA, RI, NH, VT, MA, CT, ME): ";
		cin >> st;
		check = stateCheck(st);
		if (check == true) {break;}

	}
	
	while(looper ==1){
		cout << "Zip Code: ";
		cin >> zip;
		check = zipCheck(zip);
		if (check == true) {break;}
	}	
	

	userAmount = 0.00;
}
bool Donor::checkpw(string password){
	string::iterator it;
	int counter1 = 0;
	int counter2 = 0;
	if (password.length() + 1 < 6) {return false;}
	for(it = password.begin(); it < password.end(); it++){
		if(ispunct(*it)) {counter1++;}
		if(isdigit(*it)) {counter2++;}	
	}
	if (counter1 >= 1 && counter2 >= 1) return true;
	return false;
}
bool Donor::checkStrings(string input){
	string::iterator it;
	for(it = input.begin(); it < input.end(); it++){
		if(!isalpha(*it)) return false;
	}
	return true;

}
bool Donor::zipCheck(string zip){
	string::iterator it;
	if (zip.length() != 5) return false;
	for(it = zip.begin(); it < zip.end(); it++){
		if(!isdigit(*it)) return false;
	}
	return true;
}
bool Donor::stateCheck(string st){
	map<string, State> mp;
	mp["NY"] = NY;
	mp["PA"] = PA;
	mp["RI"] = RI;
	mp["NH"] = NH;
	mp["VT"] = VT;
	mp["MA"] = MA;
	mp["CT"] = CT;
	mp["ME"] = ME;
	try{
		if( mp.at(st) >= 0 && mp.at(st) < 8)return true;
	}catch(const std::out_of_range& e){}
	return false;	
}
void Donor::manageFunc(){
	int looper = 1; string userInput;
	bool check;
	while(looper = 1){
		cout << "Please Enter which field you would like to update... " << endl;
		cout << "Options: [Name, Age, Address] " << endl;
		cout << "User Input: ";
		cin >> userInput;
		if (userInput == "Name"){
			while(looper == 1){
				cout << "Last Name: ";
				cin.ignore();
				getline(cin,last);
				check = checkStrings(last);
				if(check == true)break;
			}

			while(looper == 1){
				cout << "First Name: ";
				//cin.ignore();
				getline(cin,first);
				check = checkStrings(first);
				if(check == true) break;
			}
			break;

		}else if(userInput == "Age"){
			cout << "Age: ";
			cin >> age;
			while (age < 18){
				cout << "You have entered an invalid age. Please try again.." << endl << "Age: ";
				cin >> age;
			}
			break;
		}

		else if(userInput == "Address"){
			while(looper ==1){
				cout << "House Number: ";
				cin >> streetNum; 
				if(streetNum > 0)break;
			}
			cout << "Street Name: ";
			cin.ignore(); getline(cin,streetName);

			cout << "Town: ";
			getline(cin,town);

			cout << "State (NY, PA, RI, NH, VT, MA, CT, ME): ";
			cin >> st;
			//eNums coming soon....
	
			while(looper ==1){
				cout << "Zip Code: ";
				cin >> zip;
				check = zipCheck(zip);
				if (check == true) {break;}
			}
			break;	
		}
		else{cout << "Invalid input. please try again." << endl;}
	}
	
}
void Donor::passwdFunc(){
	string userInput;
	string userInput2;
	string userInput3;
	int looper = 1;
	bool check;
	cout << "You have requested a password change..." << endl;
	cout << "Please enter your old password: ";
	cin >> userInput;
	cout << endl;

	if(userInput == pw){
		//check if the password is correct to database of user
		if(userInput == pw){
			while(looper == 1){
				cout << "Enter a new password: ";
				cin.ignore();
				getline(cin,userInput2);
				cout << "Please re-enter the new password: ";
				getline(cin,userInput3);

				if(userInput2 == userInput3)check = checkpw(userInput2);
				if(check == true) {
					cout << "Password Successfully changed..." << endl;
					pw = userInput2; break;
                    
				}
			}
		}
		else{cout << "Password entered did not match old Password... Request canceled" << endl;}
	}
	else{cout << "Password entered did not match. Password change request canceled" << endl;}
}

void Donor::viewFunc(){
	cout << "Donor Info " << endl;
	cout << "UserID: " << userId << endl;
	cout << "Name: " << first << " " << last << endl;
	cout << "age: " << age << endl;
	cout << "Address: "  << endl;
	cout << streetNum << " " << streetName << endl;
	cout << town << ", " << st << " " << zip << endl;
	cout << "Current Amount Donated: " << "$" << fixed << setprecision(2) << userAmount << endl;
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
			balanceOver = userAmount;
			balanceOver += userInput; 
			if (balanceOver > 5000) {
				cout << "Invalid amount entered. Total amount donated cannot grow beyond $5,000" << endl;
				break;
			}
			else{
				userAmount += userInput; 
				cout << "$" << userInput << fixed << setprecision(2) << " donated." << endl;
				balanceChecker = false;
			}
		}
	}	
}
void Donor::totalFunc(){
	cout << last << " $" << fixed << setprecision(2) << userAmount << endl;
}


//isalpha(*it)  check letters
//ispunc 		check special char
//isdigit(*it)  check numbers 
//isspace(*it) 	checks for spaces 
