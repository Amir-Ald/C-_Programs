/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#include <iostream>
#include "ChequingAccount.h"
#include "Account.h"
using namespace std;

namespace sict {
    ChequingAccount::ChequingAccount(double bal, double tFee, double mFee) : Account(bal) {
        if (tFee > 0)
        {
            transFee = tFee;
        }
        else {
            transFee = 0.0;
        }
        if (mFee > 0)
        {
            mnthlyFee = mFee;
        }
        else {
            mnthlyFee = 0.0;
        }
    }
    bool ChequingAccount::credit(double cred) {
        Account::debit(transFee);
        return Account::credit(cred);
    }
    bool ChequingAccount::debit(double debt) {
        return Account::debit(debt + transFee);
    }

    void ChequingAccount::monthEnd() {
        Account::debit(mnthlyFee);
    }

    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        os.unsetf(std::ios::floatfield);
        os.precision(2);
        os.setf(std::ios::fixed, std::ios::floatfield);
        os << "Balance: $" << balance() << std::endl;
        os << "Per Transaction Fee: " << transFee << std::endl;
        os << "Monthly Fee: " << mnthlyFee << std::endl;

    }



}