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

        int stime, etime;


    public:
        Time(int sday = 0, int smonth = 0, int syear = 0, int eday = 0, int emonth = 0, int eyear = 0, int stime = 0, int etime = 0);
        void setStartDate(int _sday, int _smonth, int _syear) { sday = _sday; smonth = _smonth; syear = _syear; }
        void setEndDate(int _eday, int _emonth, int _eyear) { eday = _eday; emonth = _emonth; eyear = _eyear; }
       bool validE () {
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
            /*if (emonth < smonth) {
                cout << "INVALID MONTH\n";
                return false;
            }
            if (eday < sday) {
                cout << "INVALID DAY\n";
                return false;
            }
            return true;
        }*/
    

        friend bool validDate(int day, int month, int year);
        friend bool diffDate(Time t1, Time t2);


        void setStartTime(int _stime) { stime = _stime; }
        void setEndTime(int _etime) { etime = _etime; }
        /*bool operator> (Time t) {
            this->etime > t.stime;
        }; */

        friend bool validTime(int sday, int smonth, int syear, int eday, int emonth, int eyear); ;
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

bool validTime(int time) {
    if (time < 0 || time > 2400) {
        cout << "INVALID TIME\n";
        return false;
    }
    return true;
}

int diffTime(int sday, int smonth, int syear, int eday, int emonth, int eyear) {
    if (eyear < syear) {

        return true;
    }
    return false;
}

#endif 

