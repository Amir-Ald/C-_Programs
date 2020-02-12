/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#include <iostream>
#include "iAccount.h"
#include "SavingsAccount.h"


namespace sict {
#define INTEREST 0.05
    iAccount* CreateAccount(const char* type, double firstBalance) {
        iAccount* newAcc = nullptr;
        if (type[0] == 'S')
        {
            newAcc = new SavingsAccount(firstBalance, INTEREST);
        }
        return newAcc;
    }
}
