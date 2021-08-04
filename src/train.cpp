#include "train.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> //To use "toupper"
#include <fstream>

using namespace std;
using namespace train1;
int Train::refer = 0;
Train::Train()
{

        head = NULL;
		curr = NULL;
		temp = NULL;
		rhead = NULL;
		rtail = NULL;
		rcurr = NULL;
		dest = "";
		ori = "";
		dest_time = "";
		ori_time = "";
}

Train ::Train(string ori, string dest, string ori_time, string dest_time):
		ori(ori), dest(dest), ori_time(ori_time), dest_time(dest_time) {

		head = NULL;
		curr = NULL;
		temp = NULL;
		rhead = NULL;
		rtail = NULL;
		rcurr = NULL;
	}

void Train :: getDetails(){
		cout << ori << "     " << dest << "     " << ori_time << "     " << dest_time << endl;
}

void Train :: availableSeat() {


		curr = head;
		int compare = 1;
		int cont;

		if (counter == 30) {

			cout << "No available seat. Enter 99 to exit" << endl;

			return;

		}

		else if (counter == 0) {
			cout << "Pick any seat from 1 to 30." << endl;
		}

		else {

			do {

				for (int i = 0; i < 31; i++) {


					if (curr->seat != compare) {


						compare++;

					}

					else {

						if (compare > 0 && compare <= 10) {

							cont = 1;

						}

						else if (compare > 10 && compare <= 20) {
							cont = 2;
						}

						else {
							cont = 3;
						}

						cout << "Seat " << compare << " in container " << cont << " is taken." << endl;
						compare++;

					}

				}
				curr = curr->next;
				compare = 0;


			} while (curr != NULL);

		}

	}

void Train :: searchCustomer(int refernum) {
		rcurr = rhead;


		while (rhead != NULL) {

			do {

				if (rcurr->refer_num == refernum && rcurr->seat != -99) {

					curr = head;
					do {
						if (curr->id == rcurr->id) {
							cout << "Mr/Mrs " << curr->fname << " " << curr->lname << endl;
							cout << "Age: " << curr->age << endl;
							cout << "ID: " << curr->id << endl;
							cout << "Seat: " << curr->seat << endl;

							return;
						}

						else {
							curr = curr->next;
						}
					} while (curr != NULL);
				}


				else if (rcurr->refer_num == refernum && rcurr->seat == -99) {

					cout << "Booking has been canceled for this reference number." << endl;

					return;
				}

				else {

					rcurr = rcurr->next;

					if (rcurr == NULL) {
						cout << "Customer not found." << endl;
						return;

					}


				}


			} while (rcurr != NULL);

		}

}

void Train :: addCustomer(string first, string last, int umur, string id, int seat) {


		if (counter < 30) {

			custpointer c = new customer;
			c->next = NULL;
			c->fname = first;
			c->lname = last;
			c->age = umur;
			c->id = id;
			c->seat = seat;

			if (head != NULL) { //list is not empty
				curr = head;

				while (curr->next != NULL) {
					curr = curr->next;

				}

				curr->next = c;
			}


			else {
				head = c;
			}
			counter++;
		}


	}

void Train :: deleteCustomer(int refernum) {

		rcurr = rhead;
		custpointer delptr;

		if (rhead != NULL) {

			do {

				if (rcurr->refer_num == refernum && rcurr->seat != -99) {

					delptr = head;
					temp = head->next;



					while (head != NULL) {

						if (head->fname == rcurr->fname && head->next != NULL) {

							enqueue(head->fname, head->lname, head->age, head->id, -99, 20);
							head = head->next;
							delete delptr;
							counter--;

							return;
						}

						else if (head->fname == rcurr->fname && head->next == NULL) {
							enqueue(head->fname, head->lname, head->age, head->id, -99, 20);
							//head == NULL;
							delete head;
							return;
						}


						else if (temp->fname == rcurr->fname) {

							enqueue(temp->fname, temp->lname, temp->age, temp->id, -99, 20);
							delptr = temp;
							head->next = delptr->next;


							delete delptr;
							counter--;

							return;
						}

						else {

							delptr = head->next;
							temp = delptr->next;
							curr = temp->next;


							do {

								if (temp->fname == rcurr->fname) {

									delptr->next = curr;
									enqueue(temp->fname, temp->lname, temp->age, temp->id, -99, 20);
									delete temp;
									counter--;

									return;
								}

								else {
									delptr = delptr->next;
									temp = delptr->next;
									curr = temp->next;

								}



							} while (delptr != NULL);


						}
					}


				}

				else if (rcurr->seat == -99) {

					cout << "Passenger has already been deleted!" << endl;
					return;

				}

				else {
					rcurr = rcurr->next;
				}



			} while (rcurr != NULL);

		}

		else {
			cout << "No record." << endl;
		}


	}

void Train :: enqueue(string first, string last, int umur, string id, int seat, int paid) {

		referencepointer r = new reference;
		r->next = NULL;
		r->fname = first;
		r->lname = last;
		r->age = umur;
		r->id = id;
		r->seat = seat;
		r->paid_amount = paid;

		if (rhead == NULL) {
			rhead = r;
		}

		else {
			rcurr = rhead;

			while (rcurr->next != NULL) {
				rcurr = rcurr->next;

			}

			rcurr->next = r;
			rtail = r;
		}
		cout << "               ------------------------------" << endl;
		cout << "               |TRAINY MCTRAINY TICKET      " << endl;
		cout << "               |*****************************" << endl;
		cout << "               |Mr/Mrs " << first << " " << last << endl;
		cout << "               |Age: " << umur << endl;
		cout << "               |ID: " << id << endl;
		cout << "               |Seat: " << abs(seat) << endl;
		cout << "               -------------------------------" << endl;

		cout << r->refer_num << " is your reference number. Please do not forget it." << endl;

	}

void Train :: dequeue() {

		rcurr = rhead->next;

		while (rhead != NULL) {

			delete rhead;

			rhead = rcurr;

			rcurr = rcurr->next;

		}
	}

void Train :: showBooking(int refernum) {
		rcurr = rhead;
		do {
			if (rcurr->refer_num == refernum) {




					cout << "Name: " << rcurr->fname << " " << rcurr->lname << endl;
					cout << "Age: " << rcurr->age << endl;
					cout << "ID: " << rcurr->id << endl;
					cout << "Seat: " << rcurr->seat << endl;



					return;



			}

			else if (rcurr->refer_num != refernum && rcurr->next == NULL) {

				cout << " Record not found." << endl;
				return;

			}

			else {
				rcurr = rcurr->next;
			}


		} while (rcurr != NULL);


	}

void Train :: sortCustomer() {



		temp = NULL;

		int swapped;

		if (curr == NULL) {
			return;
		}



		do {
			curr = head;
			swapped = 0;
			while (curr->next != temp) {


				if (curr->seat > curr->next->seat) {

					swap(curr->seat, curr->next->seat);
					swap(curr->fname, curr->next->fname);
					swap(curr->lname, curr->next->lname);
					swap(curr->age, curr->next->age);
					swap(curr->id, curr->next->id);
					swapped = 1;

				}
				curr = curr->next;

			}
		} while (swapped);


	}

int Train :: getCounter() {

		return counter;

	}

void Train :: display() {

		curr = head;
		while (head != NULL && curr != NULL) {
			cout << curr->fname << " " << curr->lname << " " << curr->age << " " << curr->id << " " << curr->seat << endl;

			curr = curr->next;
		}

	}

void Train :: displayReference() {

		rcurr = rhead;

		while (rhead != NULL && rcurr != NULL) {
			cout << rcurr->fname << " " << rcurr->lname << " " << rcurr->age << " " << rcurr->id << " " << rcurr->seat << endl;

			rcurr = rcurr->next;

		}
	}

int Train :: compareSeat(int compare) {

		curr = head;
		temp = NULL;

		while (curr != temp) {
			if (compare != curr->seat) {
				curr = curr->next;
			}

			else {
				cout << "Sorry the seat that you just entered is taken. Please choose another seat." << endl;
				return 1;
				break;
			}
		}

		return 0;
	}

void Train :: editCustomer() {


		char y;

		int z; //refer_num

		cout << "Please enter your reference number: ";
		cin >> z;



		rcurr = rhead;
		//rtemp = NULL;

		do {

			if (rcurr->refer_num == z && rcurr->seat != -99) {

				curr = head;
				do {
					if (rcurr->id == curr->id) {


						int o; //edit *-1
						int x; //case
						int s; //seat
						string d; //id
						int c; //age
						string a; //fname
						string b; //lname

						searchCustomer(z);


						cout << "\nWhich part of the information has to be modified? \n";
						cout << " 1.First name\n 2.Last name\n 3.Age\n 4.Id\n 5.Seat\n";
						cout << "Do key in 1/2/3/4/5 to modify the details. If you would like to exit, key in any number instead." << endl;
						cout << "Choice : ";

						cin >> x;
						o = curr->seat * -1; //show that after edit
						switch (x) {
						case 1:
							cout << " Please enter the new first name --> ";
							cin >> a;

							curr->fname = a;
							enqueue(a, curr->lname, curr->age, curr->id, o, 10);


							break;

						case 2:
							cout << "Please enter the new last name ---> ";
							cin >> b;

							curr->lname = b;
							enqueue(curr->fname, b, curr->age, curr->id, o, 10);


							break;

						case 3:
							cout << "Please enter the new age ----> ";
							cin >> c;

							curr->age = c;
							enqueue(curr->fname, curr->lname, c, curr->id, o, 10);


							break;

						case 4:
							cout << "Please enter the new Id ---> ";
							cin >> d;


							curr->id = d;
							enqueue(curr->fname, curr->lname, curr->age, d, o, 10);

							break;

						case 5:


							cout << "Please enter the new Seats ----> ";
							availableSeat();
							cin >> s;

							curr->seat = s;
							enqueue(curr->fname, curr->lname, curr->age, curr->id, s * -1, 10);

							break;

						default:

							return;
							break;

						}


						cout << "Your information have been updated......\n";
						system("PAUSE");
						system("cls");



					}

					else if (rcurr->id != curr->id) {

						curr = curr->next;

					}

					else {

						cout << "Invalid Reference number.....\n";
						system("PAUSE");
						return;

					}


				} while (curr != NULL);
			}

			else if (rcurr->refer_num != z) {

				rcurr = rcurr->next;

				if (rcurr == NULL) {
					cout << "Invalid Reference number.....\n";
					system("PAUSE");
					return;
				}

			}

		} while (rcurr != rtemp);

	}

void Train :: addFile(string x) {

		ofstream TrainFile;

		TrainFile.open(x + ".txt");
		rcurr = rhead;


		do {

			TrainFile << rcurr->refer_num << ")\t" << rcurr->fname << " " << rcurr->lname << " " << rcurr->id << " " << rcurr->age << endl;

			rcurr = rcurr->next;

		} while (rcurr != NULL);

		TrainFile.close();
	}






