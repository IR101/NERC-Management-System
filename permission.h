#ifndef permission.h
#define permission
#include "MyForm.h"

using namespace std;

class iff {
public:
	int x=0;
	void set(int n) {
		x = n;
	}
	bool permission_create() {
		if (x == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool permission_forget() {
		if (x == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool permission_reg() {
		if (x == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};

#endif
