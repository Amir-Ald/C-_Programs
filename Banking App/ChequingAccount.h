/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/

#ifndef SICT_CHEQUIN_H
#define SICT_CHEQUIN_H
#include <iostream>
#include "Account.h"
namespace sict {
    class ChequingAccount : public Account {
        double transFee;
        double mnthlyFee;
    public:
        ChequingAccount(double bal, double tFee, double mFee);
        bool credit(double cred);
        bool debit(double debt);
        void monthEnd();
        void display(std::ostream& os) const;
    };

}
#endif