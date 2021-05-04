/* Banking.h is the header file that keeps track of classes and variables used in Banking.
   @author Anthony Minunni
   @date 4/4/2021 */

#ifndef BANKING_H
#define BANKING_H

#include <string>
using namespace std;

class Banking {
public:
	Banking(double begin, double dep, double intRate, int yrs);
	void SetInitial (double initial);
	double GetInitial();
	void SetDeposit (double deposit);
	double GetDeposit();
	void SetInterest (double interest);
	double GetInterest();
	void SetYears (int years);
	int GetYears();
	void CalculateWithoutDeposits();
	void CalculateWithDeposits();
private:
	double initial;
	double deposit;
	double interest;
	int years;
};

#endif