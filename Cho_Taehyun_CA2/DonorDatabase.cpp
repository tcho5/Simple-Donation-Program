#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "DonorDatabase.h"
using namespace std;

DonorDatabase::DonorDatabase(int max){
	maxDonors = max;
	donorArray = new Donor[maxDonors];
	totalDonors = 0;
	totalAmount = 0.00;
    
}

void DonorDatabase::setMaxDonors(int maxDonors){this->maxDonors = maxDonors;}
void DonorDatabase::printMaxDonors(){cout << "Max Donors: " << maxDonors << endl;}
int DonorDatabase::getTotalDonors(){return totalDonors;}
void DonorDatabase::runProgram(){
	string run = "";
	while(run != "Quit"){
		cout << endl;
		cout << "Enter a command."  << endl;
		cout << "Choose from [Login, Add, Save, Load, Report, Quit]: ";
		cin >> run;
		cout << endl; //for spacing
		if(run == "Login"){
			loginFunc();
		}else if(run == "Add"){
			if(maxDonors != 0 && totalDonors < maxDonors){addFunc();}
			else{cout << endl << "Cannot add more. Max number of Donors reached..." << endl;}
		}else if(run == "Save"){
			saveFunc();
		}else if(run == "Load"){
			loadFunc();		
		}else if(run == "Report"){
			reportFunc();
		}else{
			if (run != "Quit"){cout << "Command not recognized. Please try again." << endl;}
			//If user wants to quit, ask if they want to save. If so, call saveFunc
		}	
	}
}
void DonorDatabase::loginFunc(){ 
	bool access = false;
	string tempUserID;
	string tempPassword;

	string id;
	string password;

	while(access == false){
		cout << endl; //for spacing

		if(this->totalDonors == 0){cout << "No donors found. Please create a new account." << endl; break;}
		cout << "userID: ";
		cin >> tempUserID;
		cout << "Password: ";
		cin >> tempPassword;

		for(int i = 0; i < totalDonors; i++){
			if(tempUserID == donorArray[i].getuserID() && tempPassword == donorArray[i].getpw()){
				access = true;
				donorArray[i].memberMenu();
			}
		}
	}
	
}
void DonorDatabase::addFunc(){	
	int counter;
	int num = totalDonors;
	string tempID;
	tempID = donorArray[num].setuserID();
	bool goodID = false;
	bool idCheck;
		while (goodID == false){
			counter = 0;
			if(totalDonors == 0) {
				idCheck = checkID(tempID);
				if(idCheck == true) {donorArray[num].setUserID(tempID); break;}
			}
			else if(num < maxDonors){	
				for(int i = 0; i < totalDonors; i++){
					if(tempID != donorArray[i].getuserID()){
                        			counter++;
					}
				}
			}
			else{break; cout << endl << "Cannot add more. Max number of Donors reached..." << endl;}
			if(counter == num) {
				idCheck = checkID(tempID);
				if(idCheck == true) {donorArray[num].setUserID(tempID); break;}
			}
			cout << "Invalid ID. Please try again" << endl;
			cout << "Enter a new ID: "; 
			getline(cin, tempID);
			
		}
	donorArray[num].addFunc();
	totalDonors++;
}
bool DonorDatabase::checkID(string tempID){
	string::iterator it;
	for(it = tempID.begin(); it < tempID.end(); it++){
		if(ispunct(*it) || isspace(*it)) return false;
	}
	if (tempID.length() >= 5 && tempID.length() <= 10) {return true;}
	else{return false;}
}

void DonorDatabase::saveFunc(){
	string fileName;
	string userInput, temp;
	ofstream saveFile;
	bool looper = true;	
	cout << "Please Enter a file name to save as: ";
	cin.ignore(); getline(cin,fileName);

	if(checkFile(fileName)){
		while(looper == true){
			cout << endl << "File exist! You can overwrite, save to New file or Cancel " << endl; 
			cout << "Options [Overwrite, New, Cancel] : "; 
			cin >> userInput;
			if(userInput == "Overwrite"){
				saveFile.open(fileName);	
				for(int i = 0; i < totalDonors; i++){
					saveFile << donorArray[i].getuserID() << endl 
					<< donorArray[i].getpw() << endl
					<< donorArray[i].getLast() << endl 
					<< donorArray[i].getFirst() << endl
					<< donorArray[i].getAge() << endl
					<< donorArray[i].getstreetNum() << endl  
					<< donorArray[i].getStreetName() << endl 
					<< donorArray[i].getTown() << endl 
					<< donorArray[i].getState() << endl 
					<< donorArray[i].getZip() << endl  
					<< donorArray[i].getUserAmount() << endl;
				}
				break;
			}
			else if(userInput == "New"){
				cout << "Please Enter a file name to save as: ";
				cin.ignore(); getline(cin,fileName);
				ofstream saveFile(fileName);
				if(!checkFile(fileName)){ // File doesn't exist
					saveFile.open(fileName);
					for(int i = 0; i < totalDonors; i++){
					saveFile << donorArray[i].getuserID() << endl 
					<< donorArray[i].getpw() << endl
					<< donorArray[i].getLast() << endl 
					<< donorArray[i].getFirst() << endl
					<< donorArray[i].getAge() << endl
					<< donorArray[i].getstreetNum() << endl 
					<< donorArray[i].getStreetName() << endl
					<< donorArray[i].getTown() << endl
					<< donorArray[i].getState() << endl
					<< donorArray[i].getZip() << endl  
					<< donorArray[i].getUserAmount() << endl;
					}
					break;
				}
			}
			else if(userInput == "Cancel"){break;}
			else{cout << "Invalid input.. try again" << endl;}

		}
	}else{
		saveFile.open(fileName);
			for(int i = 0; i < totalDonors; i++){
				saveFile << donorArray[i].getuserID() << endl 
					<< donorArray[i].getpw() << endl  
					<< donorArray[i].getLast() << endl  
					<< donorArray[i].getFirst() << endl  
					<< donorArray[i].getAge() << endl  
					<< donorArray[i].getstreetNum() << endl  
					<< donorArray[i].getStreetName() << endl  
					<< donorArray[i].getTown() << endl 
					<< donorArray[i].getState() << endl  
					<< donorArray[i].getZip() << endl 
					<< donorArray[i].getUserAmount() << endl;
			}

	}
	saveFile.close();
	cout << endl << "Command, " << userInput << " has been finished." << endl;	
		
}
bool DonorDatabase::checkFile(string file){
	if (ifstream(file)){
		return true;
	}return false;
}
void DonorDatabase::loadFunc(){
	ifstream loadfile;
	string str, str2, line, fileName;
	int i = 0;
	string ln, fn, id, password, sName, t, s, z;
	string temp0, temp, temp2, temp3;
	int a, sNum;
	float userAm;
	totalDonors = 0;

	cout << "Please enter the name of the file to load: ";
	cin.ignore();
	getline(cin,fileName);
	
    if(checkFile(fileName)){
        loadfile.open(fileName);
    }else{
        cout << endl << "FILE DOES NOT EXIST!" << endl;
        cout << "Request denied... " << endl;
    }
	while(!loadfile.eof()){
		loadfile >> id;
		loadfile >> password;
		loadfile >> ln;
		loadfile >> fn;

		loadfile >> temp;
		istringstream buf(temp);
		buf >> a;

		loadfile >> temp2;
		istringstream buf2(temp2);
		buf2 >> sNum;
		//loadfile.ignore();

		getline(loadfile, sName);
		getline(loadfile, t);

		loadfile >> s;
		loadfile >> z;

		loadfile >> temp3;
		istringstream buf3(temp3);
		buf3 >> userAm;

		donorArray[i].setUserID(id);
		donorArray[i].setpw(password);
		donorArray[i].setLast(ln);
		donorArray[i].setFirst(fn);
		donorArray[i].setAge(a);
		donorArray[i].setStreetNum(sNum);
		donorArray[i].setStreetName(sName);
		donorArray[i].setTown(t);
		donorArray[i].setState(s);
		donorArray[i].setZip(z);
		donorArray[i].setUserAmount(userAm);
		i++;

	}
	totalDonors = i - 1;
	loadfile.close();

}
void DonorDatabase::loadFunc(string file){
	ifstream loadfile;
	string str, str2, line;
	loadfile.open(file);	
	int i = 0;
	string ln, fn, id, password, sName, t, s, z;
	string temp0, temp, temp2, temp3;
	int a, sNum;
	float userAm;
	totalDonors = 0;
	while(!loadfile.eof()){

		loadfile >> id;
		loadfile >> password;
		loadfile >> ln;
		loadfile >> fn;

		loadfile >> temp;
		istringstream buf(temp);
		buf >> a;

		loadfile >> temp2;
		istringstream buf2(temp2);
		buf2 >> sNum;
		loadfile.ignore();

		getline(loadfile, sName);
		getline(loadfile, t);

		loadfile >> s;
		loadfile >> z;

		loadfile >> temp3;
		istringstream buf3(temp3);
		buf3 >> userAm;

		donorArray[i].setUserID(id);
		donorArray[i].setpw(password);
		donorArray[i].setLast(ln);
		donorArray[i].setFirst(fn);
		donorArray[i].setAge(a);
		donorArray[i].setStreetNum(sNum);
		donorArray[i].setStreetName(sName);
		donorArray[i].setTown(t);
		donorArray[i].setState(s);
		donorArray[i].setZip(z);
		donorArray[i].setUserAmount(userAm);
		i++;

	}
	totalDonors = i - 1;
	loadfile.close();
}

void DonorDatabase::reportFunc(){
	float val;
	cout << "Report:" << endl;
	cout << endl;

	for(int i = 0; i < totalDonors; i++) {
		val = donorArray[i].getUserAmount();
		totalAmount += val;

	}
	cout << "Total number of donors in the database: " << totalDonors << endl;
	cout << "Total amount donated to campaign: " << " $" << fixed << setprecision(2) << totalAmount << endl;
	totalAmount = 0;
}

