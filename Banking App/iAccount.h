/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
namespace sict {
    class iAccount {
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;
        virtual ~iAccount() = default;
    };
    iAccount* CreateAccount(const char* type, double firstBalance);
}
#endif