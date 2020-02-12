/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict {
    class SavingsAccount : public Account {
        double rate;
    public:
        SavingsAccount(double firstBalance, double interest);
        void monthEnd();        
        void display(std::ostream&) const;
    };
}
#endif