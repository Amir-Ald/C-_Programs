/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#include <iostream>
#include "Account.h"

namespace sict {
    Account::Account(double newBalance) {
        if (newBalance == 0.0 || newBalance < 0)
        {
            accBalance = 0.0;
        }
        else {
            accBalance = newBalance;
        }
    }
    bool Account::credit(double debt) {
        if (debt > 0)
        {
            accBalance += debt;
        }
        return (debt > 0);
    }
    bool Account::debit(double price) {
        if (price > 0)
        {
            accBalance -= price;
        }
        return (price > 0);
    }
    double Account::balance() const {
        return accBalance;
    }

}