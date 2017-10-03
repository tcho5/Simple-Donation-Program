#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "DonorDatabase.h"

int main(int argc, char *argv[]) {

	int num1;
	string file;
	DonorDatabase *newDonorDatabase;
   	if (argc == 2){
   		istringstream buf(argv[1]); // create an input string stream
   	   	buf >> num1; // use the extraction operator
		newDonorDatabase = new DonorDatabase(num1);
   		newDonorDatabase->runProgram();
   	}
   	else if (argc == 3){
   		istringstream buf(argv[1]); // create an input string stream
   	   	buf >> num1; // use the extraction operator
		newDonorDatabase = new DonorDatabase(num1);
		istringstream buff(argv[2]);
		buff >> file;
		newDonorDatabase->loadFunc(file);
   		newDonorDatabase->runProgram();
   	}

   	delete newDonorDatabase;
    
	return 0;
}
