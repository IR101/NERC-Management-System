#ifndef link.h
#define link

#include <fstream>
#include <string>

using namespace std;

class node{
public:
	string data;
	node* next;
	node* head=NULL;

	node() {

	}
	~node() {
		delete head;
		head = NULL;
	}
	void insert(string v) {
		if (head == NULL) {
			node* temp = new node;
			temp->data = v;
			temp->next = NULL;
			head = temp;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			node* n = new node;
			n->data = v;
			n->next = NULL;
			temp->next = n;

		}
	}
	bool checkT_F(string v) {
		node* temp = head;
		while (temp->next != NULL) {
			if (v == temp->data) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool upd(string n,string p) {
		bool flag = 0;
		ofstream write;
		write.open("User.csv", ios::out);
		node* temp = head;
		while (temp != NULL) {
			if (temp->data == n) {
				temp->next->data = p;
				write << temp->data << ",";
				write << temp->next->data << "\n";
				flag = 1;
			}
			else {
				if (temp->data == "") {
					break;
				}
				else {
					write << temp->data << ",";
					write << temp->next->data << "\n";
				}
			}
			temp = temp->next->next;
		}
		if (flag == 1) {
			return true;
		}
		return false;
	}
};


#endif