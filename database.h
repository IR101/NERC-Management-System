#ifndef database.h
#define database
#include <string>
#include <fstream>
#include "link.h"

using namespace std;

class save {
protected:
	save() {}
	string email;
	string password;
};

class user_data :public save {
public:
	user_data() {}
	node obj;
	void get(string x, string y) {
		email = x;
		password = y;
	}
	bool check() {              // check if username exist or not
		ifstream read;
		read.open("User.csv", ios::in);
		string e,p;
		while (!read.eof()) {
			getline(read, e,',');
			getline(read, p, '\n');
			obj.insert(e);
		}
		if (obj.checkT_F(email)) {        // cheT_F() is method of node class which exist in link.h
			return false;
		}
		else {
			return true;
		}
	}

	void create(string n, string p) {    // register user login credentials
		ofstream write;
		write.open("User.csv",ios::app | ios::out);
		write << n << "," << p << endl;
		write.close();
	}

	bool match() {               // check if the user is in list or not
		ifstream read;
		read.open("User.csv", ios::in);
		string e, p;
		while (!read.eof()) {
			getline(read, e, ',');
			getline(read, p, '\n');
			if (email == e && password == p) {
				return true;
			}
		}
		return false;
	}

	bool isempty() {            // check is the file is empty or not
		int count = 0;
		string line;
		ifstream read;
		read.open("User.csv", ios::in);
		while (!read.eof()) {
			getline(read, line);
			count++;
		}
		if (count <= 2) {
			return true;
		}
		else {
			return false;
		}
	}
	bool set_reset_data(string n,string p) {
		node obj;
		ifstream read;
		read.open("User.csv", ios::in);
		string e, pp;
			while (!read.eof()) {
				getline(read, e, ',');
				getline(read, pp, '\n');
				obj.insert(e);
				obj.insert(pp);
			}
			if (obj.upd(n, p)) {
				return true;
			}
			return false;
	}
	bool reset_match() {               // check if the user is in list or not when reseting password
		ifstream read;
		read.open("User.csv", ios::in);
		string e, p;
		while (!read.eof()) {
			getline(read, e, ',');
			getline(read, p, '\n');
			if (email == e ) {
				return true;
			}
		}
		return false;
	}
	bool checkreg(string n) {          // function which ensure us that a team is registered only once unique team_name
		ifstream read;
		read.open("Registration.csv", ios::in);
		string e, p;
		while (!read.eof()) {
			getline(read, e, ',');
			getline(read, p, '\n');
			if (n==e) {
				return false;
				break;
			}
		}
		return true;
	}
};
#endif
