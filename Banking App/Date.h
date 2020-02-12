/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/

#ifndef AID_DATE_H
#define AID_DATE_H
#include <iostream>
namespace aid {
    const int max_year = 2038;
    const int min_year = 2018;
    const int min_date = 751098;
    class Date {
        int year;
        int month;
        int day;
        int comparator;
        int error;
        void errCode(int errorCode);
        int mdays(int year, int month) const;
        #define NO_ERROR 0
        #define CIN_FAILED 1
        #define YEAR_ERROR 4
        #define MON_ERROR 3
        #define DAY_ERROR 2
        #define PAST_ERROR 5
    public:
        Date();
        Date(int year, int month, int day);
        bool operator == (const Date& rhs) const;
        bool operator != (const Date& rhs) const;
        bool operator < (const Date& rhs) const;
        bool operator > (const Date& rhs) const;
        bool operator <= (const Date& rhs) const;
        bool operator >= (const Date& rhs) const;
        int errCode() const;
        bool bad() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };
    std::ostream& operator << (std::ostream& output, Date& data);
    std::istream& operator >> (std::istream& input, Date& data);
}
#endif