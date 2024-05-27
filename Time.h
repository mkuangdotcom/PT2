#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#ifndef TIME_H  
#define TIME_H

class Time {
    protected:
        int shour, sminute, ehour, eminute;
        int averageSleepMinutes;
        int startTimes[30][2]; 
        int endTimes[30][2];

    public:
        Time(int _shour = 0, int _sminute = 0, int _ehour = 0, int _eminute = 0) : shour(_shour), sminute(_sminute), ehour(_ehour), eminute(_eminute) { };

        friend bool validDate(int day, int month, int year);
        friend bool validEdate(int eday, int emonth, int eyear, int sday, int smonth, int syear);

        void setStartTime(int _shour, int _sminute) { shour = _shour, sminute = _sminute; }
        void setEndTime(int _ehour, int _eminute) { ehour = _ehour, eminute = _eminute; }
        int getStartHour() { return shour; }
        int getStartMinute() { return sminute; }
        int getEndHour() { return ehour; }
        int getEndMinute() { return eminute; }
        int getAverageSleepMinutes() { return averageSleepMinutes; }
        void dailySleepTime(int);
        bool validTime(int , int);
        void printSleepTime(int );
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


bool Time::validTime(int hour, int minute) {
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

void Time::dailySleepTime(int day) {
    int totalSleepMinutes = 0;

    cout << endl;
    cout << "Please enter the start and end sleep time for each day (hour, minute) in 24-hour clock\n";

    for (int i = 0; i < day; i++) {
        int shour, sminute, ehour, eminute;
        cout << "Day " << (i + 1) << ": " << endl;

        do {
            std::cout << "Start - \t";
            std::cin >> shour >> sminute;
        } while (!validTime(shour, sminute));

        do {
            std::cout << "End - \t\t";
            std::cin >> ehour >> eminute;
        } while (!validTime(ehour, eminute));

        setStartTime(shour, sminute);
        setEndTime(ehour, eminute);

        startTimes[i][0] = getStartHour();
        startTimes[i][1] = getStartMinute();
        endTimes[i][0] = getEndHour();
        endTimes[i][1] = getEndMinute();


        int startMinutes = getStartHour() * 60 + getStartMinute();
        int endMinutes = getEndHour() * 60 + getEndMinute();

        // If the end time is less than the start time, it means the sleep period extended to the next day
        if (endMinutes < startMinutes) {
            endMinutes += 24 * 60;
        }
        cout << endl;
        totalSleepMinutes += endMinutes - startMinutes;
    }

    averageSleepMinutes = totalSleepMinutes / day ;

}

void Time::printSleepTime(int day) {
    cout << "\t" << "Start" << "\t\t" << "End" << endl;
    for (int i = 0; i < day; i++) {
        cout << "Day " << (i + 1) << ": \t" << startTimes[i][0] << startTimes[i][1] << "\t - \t" << endTimes[i][0] << endTimes[i][1] << endl;
    }
    cout << endl;
}


 


#endif 

