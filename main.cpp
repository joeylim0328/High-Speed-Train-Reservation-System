
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> //To use "toupper"
#include <fstream>
#include "train.h"

using train1::Train;
using namespace std;




//main function
int main()
{

	int choice; //choice for the main menu
	char choice_train; // choice to choose train
	char choice_payment;
	char answer;
	//Train details can be modified here//
	Train A("Delhi", "IPOH", "1.00PM", "2.00PM");
	Train B("KL", "MELAKA", "1.00PM", "2.00PM");
	Train C("KL", "JOHOR", "1.00PM", "2.00PM");


	Train* trainpointer{};


	string fname, lname, id;
	int age, seat;
	int counter;
	int compare;
	int seatprice = 0;


	do {
		cout << "              ####################################################################################" << endl;
		cout << "              ####################################################################################" << endl;
		cout << "              ########                               WELCOME                              ########" << endl;
		cout << "              ########                                  TO                                ########" << endl;
		cout << "              ########                        TRAINY MCTRAIN STATION                      ########" << endl;
		cout << "              ####################################################################################" << endl;
		cout << "              ####################################################################################" << endl << endl;

		cout << " --------------------------------------------------------------------------------------------------------------------" << endl;


		cout << "Hello and welcome to Trainy McTrain Station! What would you like to do now?" << endl;
		cout << "Please type in the number to do the following. (1/2/3/4)" << endl;
		cout << "1. Buy ticket " << endl;
		cout << "2. Cancel reservation " << endl;
		cout << "3. Modify your information " << endl;
		cout << "4. Display ticket details " << endl;
		cout << "If you want to exit, do key in any other numbers." << endl;
		cout << "Choice : ";
		cin >> choice;
		system("cls");


		switch (choice) {
		case 1: //Buy ticket

			cout << "********************************************" << endl;
			cout << "*Train A* " << endl;
			A.getDetails();
			cout << "*Train B*" << endl;
			B.getDetails();
			cout << "*Train C*" << endl;
			C.getDetails();
			cout << "********************************************" << endl;

			do {
				cout << "Choose a train :) " << endl;
				cout << "Train : ";
				cin >> choice_train;

				choice_train = toupper(choice_train);
				endl(cout);

				switch (choice_train) {

				case 'A':
					trainpointer = &A;
					break;

				case 'B':
					trainpointer = &B;
					break;

				case 'C':
					trainpointer = &C;
					break;

				default:
					cout << "Invalid input. Do key in A/B/C." << endl;

				}
			} while (choice_train != 'A' && choice_train != 'B' && choice_train != 'C');

			counter = trainpointer->getCounter();
			if (counter == 30) {

				cout << "full." << endl;
				break;

			}

			else {

				do {
					cout << "Please key in your details." << endl;
					cout << "First name : ";
					cin >> fname;
					cout << "Last name : ";
					cin >> lname;
					cout << "Age : ";
					cin >> age;
					cout << "ID : ";
					cin >> id;
					endl(cout);
					cout << "-------------------------------------------------------------------------" << endl;




					cout << "Please enter the seat number that you want." << endl;
					cout << "**************************************************" << endl;
					cout << "*First class       : Seat No.1-10------- RM 50.00*" << endl;
					cout << "*Business class    : Seat No.11-20------ RM 40.00*" << endl;
					cout << "*Economy class     : Seat No.21-30------ RM 30.00*" << endl;
					cout << "**************************************************" << endl;
					cout << "Seats that are taken : ";
					endl(cout);
					trainpointer->availableSeat();
					endl(cout);
					do {
						do {
							cout << "Seat : ";
							cin >> seat;
							compare = trainpointer->compareSeat(seat);



							if (seat > 0 && seat < 11) {
								seatprice = 50;
							}

							else if (seat > 10 && seat < 21) {
								seatprice = 40;
							}

							else if (seat > 20 && seat < 31) {
								seatprice = 30;
							}



							if (seat > 30) {
								cout << "Seat ranges from 1 to 30 only. Please try again" << endl;
							}




						} while (seat > 30 || compare == 1);
						system("cls");
						cout << "The ticket is RM " << seatprice << ", do you want to continue with the payment? (Y/N)" << endl;
						cout << "Choice :";
						cin >> choice_payment;
						choice_payment = toupper(choice_payment);
					} while (choice_payment == 'N');




					trainpointer->addCustomer(fname, lname, age, id, seat);
					trainpointer->enqueue(fname, lname, age, id, seat, seatprice);
					trainpointer->sortCustomer();
					//trainpointer->display();

					cout << "Do you want to continue buying the ticket in this train? (Y/N)" << endl;
					cout << "Choice : ";
					cin >> answer;
					answer = toupper(answer);

					system("PAUSE");
					system("cls");
				} while (answer == 'Y');
			}
			break;
			/*End of buy ticket*/
		case 2: //Cancel reservation
			int rn;//reference number
			char choice_cancel;
			cout << "===================================" << endl;
			cout << "==    CANCEL RESERVATION PAGE    ==" << endl;
			cout << "===================================" << endl;
			endl(cout);
			cout << "Do note that you need to pay an extra fee of RM 50 if you cancel the reservation." << endl;
			do {
				cout << "Which train ticket you would like to cancel? (A/B/C)";

				cin >> choice_cancel;
				choice_cancel = toupper(choice_cancel);
				endl(cout);

				switch (choice_cancel) {

				case 'A':
					trainpointer = &A;
					break;

				case 'B':
					trainpointer = &B;
					break;

				case 'C':
					trainpointer = &C;
					break;

				default:
					cout << "Invalid input. Do key in A/B/C." << endl;

				}
			} while (choice_train != 'A' && choice_train != 'B' && choice_train != 'C');
			endl(cout);
			cout << "Enter your reference number please : ";
			cin >> rn;

			trainpointer->deleteCustomer(rn);
			cout << "Your reservation is successfully deleted." << endl;
			system("PAUSE");
			system("cls");

			break;
			/*End of cancel reservation*/
		case 3: //Modify information
			do {
				cout << "Choose a train :) " << endl;
				cout << "Train : ";
				cin >> choice_train;

				choice_train = toupper(choice_train);
				endl(cout);

				switch (choice_train) {

				case 'A':
					trainpointer = &A;
					break;

				case 'B':
					trainpointer = &B;
					break;

				case 'C':
					trainpointer = &C;
					break;

				default:
					cout << "Invalid input. Do key in A/B/C." << endl;

				}
			} while (choice_train != 'A' && choice_train != 'B' && choice_train != 'C');
			trainpointer->editCustomer();
			trainpointer->display();
			system("cls");

			break;
			/*End of Modify Information*/
		case 4: //Display details
			int number;
			cout << "####################################" << endl;
			cout << "####         DISPLAY DETAILS     ###" << endl;
			cout << "####################################" << endl;

			cout << "Key in your reference number to search for your details. " << endl;
			cout << "Reference number : ";
			cin >> number;
			do {
				cout << "Choose a train :) " << endl;
				cout << "Train : ";
				cin >> choice_train;

				choice_train = toupper(choice_train);
				endl(cout);

				switch (choice_train) {

				case 'A':
					trainpointer = &A;
					break;

				case 'B':
					trainpointer = &B;
					break;

				case 'C':
					trainpointer = &C;
					break;

				default:
					cout << "Invalid input. Do key in A/B/C." << endl;

				}
			} while (choice_train != 'A' && choice_train != 'B' && choice_train != 'C');
			trainpointer->showBooking(number);
			system("PAUSE");
			system("cls");

			break;
			/*End of display details*/
		}//end switch case

	} while (choice == 1 || choice == 2 || choice == 3 || choice == 4);



	trainpointer = &A;
	trainpointer->addFile("A");
	trainpointer->dequeue();
	trainpointer = &B;
	trainpointer->addFile("B");
	trainpointer->dequeue();
	trainpointer = &C;
	trainpointer->addFile("C");
	trainpointer->dequeue();

	return 0;



}


