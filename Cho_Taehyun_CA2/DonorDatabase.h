#include "Donor.h"
using namespace std;

class DonorDatabase{
	public:
		DonorDatabase(int);
		void runProgram();
		void setMaxDonors(int);
		int getTotalDonors();
		void printMaxDonors();
		void loginFunc();
		void addFunc();
		void saveFunc();
		void loadFunc();
		void loadFunc(string);
		void reportFunc();
		bool checkFile(string);
		bool checkID(string);

	private:
		int maxDonors;
		Donor * donorArray;
		int totalDonors;
		float totalAmount;
};
