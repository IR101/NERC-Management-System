#ifndef reset.h
#define reset

#include "database.h"

class confirm {
public:
	confirm() {

	}
	user_data obj;
	bool confirm_data(string ne, string con) {
		if (!obj.check()) {
			if (ne == con) {
				return true;
			}
		}
		else false;
	}

};


#endif