#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>

using namespace std;

namespace train1{

class Train
{
    public:
        Train();
        Train(string ori, string dest, string ori_time, string dest_time);
        void getDetails();
        void availableSeat();
        void searchCustomer(int refernum);
        void addCustomer(string first, string last, int umur, string id, int seat);
        void deleteCustomer(int refernum);
        void enqueue(string first, string last, int umur, string id, int seat, int paid);
        void dequeue();
        void showBooking(int refernum);
        void sortCustomer();
        int getCounter();
        void display();
        void displayReference();
        int compareSeat(int compare);
        void editCustomer();
        void addFile(string x);
        static int refer;

    private:
 	typedef struct customer {
		string fname;
		string lname;
		int age;
		string id;

		int seat;
		customer* next;

		customer() {
			fname = "";
			lname = "";
			age = 0;
			id = "";
			seat = 0;

			next = NULL;
		};

	}*custpointer;


	typedef struct reference {
		string fname;
		string lname;
		int age;
		string id;
		int seat;

		int refer_num = 0;
		int paid_amount;
		reference* next;

		reference() {
			fname = "";
			lname = "";
			age = 0;
			id = "";
			seat = 0;
			refer++;
			refer_num = refer;
			next = NULL;
			paid_amount = 0;

		};
	}*referencepointer;




	referencepointer rhead;
	referencepointer rtail;
	referencepointer rcurr;
	referencepointer rtemp;
	custpointer head;
	custpointer curr;
	custpointer temp;
	string dest;
	string ori;
	string dest_time;
	string ori_time;
	int trainid = 0;
	int counter = 0;


};//end of Train
};//end of train1

#endif // TRAIN_H
