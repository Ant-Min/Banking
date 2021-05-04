/* Source is the main location where Banking.cpp and Banking.h will be used
   @author Anthony Minunni
   @date 4/4/2021 */

#include <iostream>

#include "Banking.h"

int main() {

	string begin; //variable that will take value of intitial balance
	string depAmount; //variable that will take value of deposit amount
	string interestRate; //variable that will take value of interest rate
	string numYears; //variable that will take value of number of years
	double initial = 0; //will be used to convert begin into double
	double deposit = -1; //will be used to convert depAmount to double
	double interest = 0; //will be used to convert interestRate to double
	int years = 0; //will be used to convert numYears to int
	string next; //string that will be used when user wants to move forward in program

	cout << "*****AIRGEAD BANKING*****" << endl;
	cout << "Initial Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	cout << endl;

	//while loop that will run if all entered values are positive
	while (initial < 1 || deposit < 0 || interest < 1 || years < 1) {
		cout << "Enter initial amount" << endl;
		getline(cin, begin);
		cout << "Enter monthly deposit" << endl;
		getline(cin,depAmount);
		cout << "Enter interest rate" << endl;
		getline(cin,interestRate);
		cout << "Enter number of years" << endl;
		getline(cin,numYears);
		
		//try-catch block in event letters are entered instead of numbers
		try {
			//four variables below are conversion from entered strings to double variables
			initial = stod(begin);
			deposit = stod(depAmount);
			interest = stod(interestRate);
			years = stoi(numYears);
		}
		catch (exception e) {
			begin = "null";
			depAmount = "null";
			interestRate = "null";
			numYears = "null";
			cout << "Invalid entries. Try again." << endl;
			cout << "Press any key to continue." << endl;
			getline(cin,next);
			cin.clear();
			continue;
		}

		if (initial < 1 || deposit < 0 || interest < 1 || years < 1) {
			//variables reset for organization purposes
			initial = 0;
			deposit = -1;
			interest = 0;
			years = 0;
			cout << "Non-Positive values entered. Please try again." << endl;
			cout << "Press any key to continue." << endl;
			getline(cin,next);
			cin.clear();
		}
	}

	Banking bank(initial, deposit, interest, years); //declares banking object and puts variables into constructor

	cout << "*****AIRGEAD BANKING*****" << endl;
	cout << "Initial Amount: $" <<  bank.GetInitial() << endl;
	cout << "Monthly Deposit: $" << deposit << endl;
	cout << "Annual Interest: " << bank.GetInterest() << "%" << endl;
	cout << "Number of Years: " << bank.GetYears() << endl;
	cout << "Enter any key to see timeline." << endl;
	cin >> next;
	cout << endl;
	
	bank.CalculateWithoutDeposits(); //method that will calculate without deposits

	bank.SetInitial(initial); //this is to reset initial balance to be what user originally entered
	cout << endl;

	bank.CalculateWithDeposits(); //method that will calulcate with deposits

}