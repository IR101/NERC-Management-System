#ifndef regsave.h
#define regsave

#include <string>
#include <fstream>
#include "database.h"
using namespace std;

class data_entry {
public:
	string team_name;
	string leader;
	string senior;
	string category;
	string tm1;
	string tm2;
	string tm3;
	string tm4;
	string tm5;
	string tm6;
	string uni;
	string accomodation;
	string mess;
	data_entry() {
		team_name = "";
		leader = "";
		senior = "";
		category = "";
		tm1 = "";
		tm2 = "";
		tm3 = "";
		tm4 = "";
		tm5 = "";
		tm6 = "";
		uni = "";
		accomodation = "";
		mess = "";
	}
	void get_team(string t_n, string lead, string seni,string un,string cate) {
		team_name = t_n;
		leader = lead;
		senior = seni;
		uni = un;
		category = cate;
	}
	void get_members(string t1,string t2, string t3, string t4, string t5, string t6) {
		tm1 = t1;
		tm2 = t2;
		tm3 = t3;
		tm4 = t4;
		tm5 = t5;
		tm6 = t6;
	}
	void get_Hostel(string accom,string m) {
		accomodation = accom;
		mess = m;
	}
	bool save(string n) {
		user_data obj;
		if (obj.checkreg(n)) {
			ofstream write;
			write.open("Registration.csv", ios::out | ios::app);
			write << team_name << "," << leader << "," << senior << "," << category << "," << tm1 << "," <<
				tm2 << "," << tm3 << "," << tm4 << "," << tm5 << "," << tm6 << "," << accomodation << "," << mess << "\n";
			return true;
		}
		else {
			return false;
		}
	}
};

#endif