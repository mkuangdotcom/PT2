#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#ifndef TIME_H  
#define TIME_H

class Time {
    private:
        int sday, smonth, syear; 
        int eday, emonth, eyear;

        int stime, etime;


    public:
        Time(int sday = 0, int smonth = 0, int syear = 0, int eday = 0, int emonth = 0, int eyear = 0);
        void setStartDate(int _sday, int _smonth, int _syear) { sday = _sday; smonth = _smonth; syear = _syear; }
        void setEndDate(int _eday, int _emonth, int _eyear) { eday = _eday; emonth = _emonth; eyear = _eyear; }

        friend bool validDate(int day, int month, int year);

};

bool validDate(int day, int month, int year) {
    if (year < 0 || year > 2024) {
        cout << "INVALID YEAR\n";
        return false;
    }
    if (month < 1 || month > 12) {
        cout << "INVALID MONTH\n";
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }
    return true;
}




#endif 

