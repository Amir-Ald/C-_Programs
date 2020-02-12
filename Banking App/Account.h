/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"
namespace sict {
    class Account : public iAccount {
        
    public:
        Account(double newBalance);
        Account() = default;
        bool credit(double debt);
        bool debit(double price);
    protected:
        double balance() const;
        double accBalance;
    };
}
#endif