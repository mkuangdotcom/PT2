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
        int dday, dmonth, dyear;

        int shour, sminute, ehour, eminute;


    public:
        Time(int sday = 0, int smonth = 0, int syear = 0, int eday = 0, int emonth = 0, int eyear = 0, int stime = 0, int etime = 0);
        void setStartDate(int _sday, int _smonth, int _syear) { sday = _sday; smonth = _smonth; syear = _syear; }
        void setEndDate(int _eday, int _emonth, int _eyear) { eday = _eday; emonth = _emonth; eyear = _eyear; }
        friend bool validDate(int day, int month, int year);
        friend bool validEdate(int eday, int emonth, int eyear, int sday, int smonth, int syear);
        void diffDate();


        void setStartTime(int _shour, int _sminute) { shour = _shour, sminute = _sminute; }
        void setEndTime(int _ehour, int _eminute) { ehour = _ehour, eminute = _eminute; }
        friend bool validTime(int hour, int minute);
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
        cout << "INVALID DAY\n";
        return false;
    }
    if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29) {
                cout << "INVALID MONTH\n";
                return false;
            }
        } else {
            if (day > 28) {
                cout << "INVALID MONTH\n";
                return false;
            }
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            cout << "INVALID MONTH\n";
            return false;
        }
    }
    return true;
}


bool validEdate (int eday, int emonth, int eyear, int sday, int smonth, int syear) {
    if (eyear < syear) {
        cout << "INVALID YEAR\n";
        return false;
    }
    if (eyear == syear) {
        if (emonth < smonth) {
            cout << "INVALID MONTH\n";
            return false;
        }
        if (emonth == smonth) {
            if (eday < sday) {
                cout << "INVALID DAY\n";
                return false;
            }
        }
    } else if (eyear > syear) {
        if (emonth < smonth) {
            cout << "INVALID MONTH\n";
            return false;
        } else if (emonth == smonth) {
            if (eday < sday) {
                cout << "INVALID DAY\n";
                return false;
            }
        }
    }
    return true;
}

void Time :: diffDate() {
    dyear = eyear - syear;
    dmonth = emonth - smonth;
    dday = eday - sday;
}


bool validTime(int hour, int minute) {
    if (hour < 0 || hour > 23) {
        cout << "INVALID HOUR\n";
        return false;
    }
    if (minute < 0 || minute > 59) {
        cout << "INVALID MINUTE\n";
        return false;
    }
    return true;
}



#endif 

