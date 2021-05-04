/* Banking.cpp is the class file that holds the classes used in the program
   @author Anthony Minunni
   @date 4/4/2021 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Banking.h"

double initial;
double deposit;
double interest;
int years;

// loaded constructor when deposits are made
Banking::Banking(double begin, double dep, double intRate, int yrs) {
	initial = begin; // initial balance
	deposit = dep; // deposit amount
	interest = intRate; //interest rate of account
	years = yrs; // number of years passed
}

/* SetInitial sets a banking's initial balance
   @param begin is initial balance */
void Banking::SetInitial(double begin) {
	initial = begin;
}

/* GetInitial returns a banking's initial balance
   @return initial balance */
double Banking::GetInitial() {
	return initial;
}

/* SetDeposit sets a banking's deposit amount
   @param dep is deposit amount */
void Banking::SetDeposit(double dep) {
	deposit = dep;
}

/* GetDeposit returns a banking's deposit amount
   @return deposit amount */
double Banking::GetDeposit() {
	return deposit;
}

/* SetIneterest changes a banking's interest rate 
   @param intRate is interest rate */
void Banking::SetInterest(double intRate) {
	interest = intRate;
}

/* GetInterest returns a banking's interest rate
   @return interest */
double Banking::GetInterest() {
	return interest;
}

/* SetYears sets the number of years of accumulation
   @param yrs is number of years */
void Banking::SetYears(int yrs) {
	years = yrs;
}

/* GetYears returns number of years of accumulation
   @return years */
int Banking::GetYears() {
	return years;
}
/* CalculateWithoutDeposits determines the amount of interest accrued during the year when no payments are made
   @param bank is a Banking object */
void Banking::CalculateWithoutDeposits() {
	cout << "     Balance and Interest without Monthly Deposits" << endl;
	cout << "======================================================" << endl;
	cout << "Year     Year-End Balance     Year-End Earned Interest" << endl;
	for (int i = 1; i <= this->GetYears(); i++) {
		double intBalance = this->GetInitial() * (this->GetInterest() / 100);
		double newInitial = this->GetInitial() + intBalance;
		this->SetInitial(newInitial);
		cout << setprecision(2) << fixed;
		cout << i << "                    " << this->GetInitial() << "                         " << intBalance << endl;
	}
}

/* CalculateWithDeposits determines the amount of interest accrued during the year when payments are made
   @param bank is a Banking object */
void Banking::CalculateWithDeposits() {
	cout << "     Balance and Interest with Monthly Deposits" << endl;
	cout << "======================================================" << endl;
	cout << "Year     Year-End Balance     Year-End Earned Interest" << endl;
	for (int i = 1; i <= this->GetYears()*12; i++) {
		double intBalance = (this->GetInitial() + this->GetDeposit()) * ((this->GetInterest() / 100) / 12);
		double newInitial = this->GetInitial() + this->GetDeposit() + intBalance;
		this->SetInitial(newInitial);
		if (i % 12 == 0) {
			cout << setprecision(2) << fixed;
			cout << i/12 << "                 " << this->GetInitial() + this->GetDeposit() << "                         " << intBalance << endl;
		}
	}
}