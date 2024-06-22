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
        int day;
        int startTimes[30][2] = {0}; 
        int endTimes[30][2] = {0};


    public:
        Time(int _shour = 0, int _sminute = 0, int _ehour = 0, int _eminute = 0, int _day = 0) : shour(_shour), sminute(_sminute), ehour(_ehour), eminute(_eminute), day(_day) { };

        friend bool validDate(int day, int month, int year);
        friend bool validEdate(int eday, int emonth, int eyear, int sday, int smonth, int syear);
        void setStartTime(int _shour, int _sminute) { shour = _shour, sminute = _sminute; }
        void setEndTime(int _ehour, int _eminute) { ehour = _ehour, eminute = _eminute; }
        void setDay(int _day) { day = _day; }

        int getDay () const { return day; }
        int getStartHour() const { return shour; }
        int getStartMinute() const { return sminute; }
        int getEndHour() const { return ehour; }
        int getEndMinute() const { return eminute; }
        void setAverageSleepMinutes(int avg) {averageSleepMinutes = avg; }
        int getAverageSleepMinutes() { return averageSleepMinutes; }
        
        void dailySleepTime(int);
        bool validTime(int , int);
        void printSleepTime();
};

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

void Time::dailySleepTime(int _day) {
    int totalSleepMinutes = 0;
    setDay(_day);

    cout << endl;
    cout << "Please enter the start and end sleep time for each day (hour, minute) in 24-hour clock\n";

    for (int i = 0; i < getDay(); i++) {
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

        if (endMinutes < startMinutes) {
            endMinutes += (24 * 60);
        }
        cout << endl;
        totalSleepMinutes += endMinutes - startMinutes;
    }

    setAverageSleepMinutes(totalSleepMinutes / getDay());
}

void Time::printSleepTime() {
    cout << "\t\t\t" << "Start" << "\t\t" << "End" << endl;
    for (int i = 0; i < day; i++) {
        
        cout << "Day " << (i + 1) << ": \t\t\t";
        if (startTimes[i][0] < 10) 
            cout << "0";
        cout << startTimes[i][0];

        if (startTimes[i][1] < 10) 
            cout << "0";
        cout << startTimes[i][1] << "\t - \t";
        
        if (endTimes[i][0] < 10) 
            cout << "0";
        cout << endTimes[i][0];

        if (endTimes[i][1] < 10) 
            cout << "0";
        cout << endTimes[i][1] << endl;
    }
    cout << endl;
}

#endif 