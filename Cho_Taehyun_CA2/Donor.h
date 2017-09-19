using namespace std;

class Donor{
	public:
		Donor();
		void runProgram();
		void memberMenu();
		void addFunc(string*, string*, int*, int*, string*, string*, string*);
		void manageFunc(string*, string*, int*, int*, string*, string*, string*);
		void viewFunc();
		void donateFunc();
		void totalFunc();
		void loginFunc();
		void saveFunc();
		void loadFunc();
		void reportFunc();

	
	private:
		string last, first, streetName, town, zip, userID, pw, state;
		int age, streetNum;
		float amount = 0.00;
};
