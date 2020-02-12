/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

namespace sict {
    SavingsAccount::SavingsAccount(double firstBalance, double interest){
        if (interest > 0)
        {
            rate = interest;
        }
        else {
            rate = 0.0;
        }
        if (firstBalance > 0)
        {
            accBalance = firstBalance;
        }
        else {
            accBalance = 0.0;
        }
    }

    void SavingsAccount::monthEnd() {
        accBalance = accBalance * (1 + rate);
    }

    void SavingsAccount::display(ostream& os) const {
        os << "Account type: Savings" << endl
            << fixed << setprecision(2)
            << "Balance: $" << accBalance << endl
            << "Interest Rate (%): " << rate * 100 << endl;
    }
}