//============================================================================
// Name        : Project2_BankingInvestment.cpp
// Author      : Luna Saccoia
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//Declare variables for input
	float initialInvestment, monthlyDeposit, annualInterest, months, years;

	//Declare variables to store year end total amount, interest, and year end interest
	float totalAmount, interestAmount, yearlyTotalInterest;

	//Display menu to the user
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//Press any key to continue command
	system("PAUSE");

	//Get user input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> years;
	months = years * 12;

	system("PAUSE");

	//Update total amount to initial investment
	totalAmount = initialInvestment;

	//Display year end data if no monthly deposits
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculate yearly interest and year end total
	for (int i=0; i < years; i++) {
		//Calculate yearly interest amount
		interestAmount = ((totalAmount) * (annualInterest / 100));

		//Calculate year end total
		totalAmount = totalAmount + interestAmount;

		//Show decimal as dollar amount correctly with set precision to 2 decimal places
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}

	//Calculate monthly interest and month end total
	totalAmount = initialInvestment;

	//Display year end data with monthly deposits
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculate yearly interest and year end total
	for (int i = 0; i < years; i++) {
		//Initialize yearly interest to 0
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//Calculate monthly interest amount
			interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

			//Calculate month end interest
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			//Calculate month end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
	}
	return 0;
}
