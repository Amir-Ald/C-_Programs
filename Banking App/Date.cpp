/*
Amirreza Allahdad
aallahdad@myseneca.ca
Lab 8
*/

#include <iostream>
#include<iomanip>
#include "Date.h"
using namespace std;

namespace aid {
    void Date::errCode(int code)
    {
        error = code;
    }
    Date::Date()
    {
        year = 0;
        month = 0;
        day = 0;
        comparator = 0;
        errCode(NO_ERROR);
    }
    Date::Date(int year_, int month_, int day_) {
        if (!(year_ >= min_year && year_ <= max_year))
        {
            errCode(YEAR_ERROR);
            year = 0;
            month = 0;
            day = 0;
            comparator = 0;
        }
        else if (!(month_ >= 1 && month_ <= 12))
        {
            errCode(MON_ERROR);
            year = 0;
            month = 0;
            day = 0;
            comparator = 0;
        }
        else if (!(day_ >= 1 && day_ <= mdays(year_ ,month_)))
        {
            errCode(DAY_ERROR);
            year = 0;
            month = 0;
            day = 0;
            comparator = 0;
        }
        else
        {
            year = year_;
            month = month_;
            day = day_;
            comparator = year * 372 + month * 31 + day;
            errCode(NO_ERROR);
        }
    }
    int Date::mdays(int year, int mon) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    bool Date::operator==(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator == rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Date::operator!=(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator != rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Date::operator<(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator < rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Date::operator>(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator > rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Date::operator<=(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator <= rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Date::operator>=(const Date& rhs) const
    {
        if (comparator == 0 || rhs.comparator == 0)
        {
            return false;
        }
        else if (comparator >= rhs.comparator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Date::errCode() const {
        return error;
    }
    bool Date::bad() const {
        return (error != NO_ERROR);
    }
    std::istream& Date::read(std::istream& istr) {
        
        int year_;
        int month_;
        int day_;
        char specifier = '/';

        istr >> year_ >> specifier 
            >> month_ >> specifier >> day_;

        if (istr.fail())
        {
            errCode(CIN_FAILED);
            
        }else
        {
            if (!(year_ >= min_year && year_ <= max_year))
            {
                errCode(YEAR_ERROR);
            }
            else if (!(month_ >= 1 && month_ <= 12))
            {
                errCode(MON_ERROR);
            }
            else if (!(day_ >= 1 && day_ <= mdays(year_, month_)))
            {
                errCode(DAY_ERROR);
            }
            else if ((year_ * 372 + month_ * 31 + day_) < min_date) {
                errCode(PAST_ERROR);
            }
            else
            {
                year = year_;
                month = month_;
                day = day_;
                errCode(NO_ERROR);
            }
        }

        return istr;
    }
    std::ostream& Date::write(std::ostream& ostr) const {
        ostr << year << '/' << std::setfill('0') << std::setw(2) << month << '/' << std::setfill('0') << std::setw(2) << day;
        return ostr;
    }
    std::ostream& operator << (std::ostream& output, Date& data)
    {
        
        return data.write(output);
    }

    std::istream& operator >> (std::istream& input, Date& data)
    {
        
        return data.read(input);
    }
}