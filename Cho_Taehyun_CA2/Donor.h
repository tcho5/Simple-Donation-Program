#include <string.h>
using namespace std;

class Donor{

	enum State {NY, PA, RI, NH, VT, MA, CT, ME};

	public:
		Donor();
		void memberMenu();
		void addFunc();
		void manageFunc();
		void passwdFunc();
		void viewFunc();
		void donateFunc();
		void totalFunc();

		string setuserID();
		void setUserID(string);
		void setpw(string);
		void setLast(string);
		void setFirst(string);
		void setAge(int);
		void setStreetNum(int);
		void setStreetName(string);
		void setTown(string);
		void setZip(string);
		void setUserAmount(float);
		void setState(string);
				

		bool checkpw(string);
		bool checkStrings(string);
		bool zipCheck(string);
		bool stateCheck(string);

		string getuserID();
		string getpw();
		string getLast();
		string getFirst();
		string getStreetName();
		string getTown();
		string getZip();
		string getState();
		int getAge();
		int getstreetNum();
		float getUserAmount();
		

	
	private:
		string last, first, streetName, town, zip, userId, pw, st;
		int age, streetNum;
		float userAmount;
		int totalDonors;
		State state;
};
