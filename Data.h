#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "NewUser.h" // Include the User header file
#include "Time.h"
using namespace std;

#ifndef DATA_H
#define DATA_H

class Data {
    protected:
        char category;
        NewUser userData; // Use NewUser instead of User

    public:
        Data(char _category = ' ', NewUser _userData = NewUser()) : category(_category), userData(_userData) { } // Default constructor (with default values

        void setCategory(char _category) { category = _category; }
        char getCategory() { return category; }


        void analyzeSleep(int);
        void displayMessage();
        void calculateSleepDiff(int );
};


void Data::analyzeSleep(int day) {
     Time timeInstance;
        int averageSleep = timeInstance.averageSleepTime(day); // averageSleep is in minutes
        int age = userData.getAge();

        if (age < 1) {
            if (averageSleep < 14*60) {
                category = 'B';
            } else if (averageSleep > 15*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 3) {
            if (averageSleep < 12*60) {
                category = 'B';
            } else if (averageSleep > 14*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 6) {
            if (averageSleep < 10*60) {
                category = 'B';
            } else if (averageSleep > 12*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 13) {
            if (averageSleep < 9*60) {
                category = 'B';
            } else if (averageSleep > 10*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 18) {
            if (averageSleep < 8*60) {
                category = 'B';
            } else if (averageSleep > 9*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 65) {
            if (averageSleep < 7*60) {
                category = 'B';
            } else if (averageSleep > 8*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else {
            if (averageSleep < 7*60) {
                category = 'B';
            } else if (averageSleep > 8*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        }
}

void Data::displayMessage() {
    switch(category) {
        case 'A':
            cout << "Good sleep quality." << endl;
            break;
        case 'B':
            cout << "Poor sleep quality (less than average)." << endl;
            break;
        case 'C':
            cout << "Overslept." << endl;
            break;
        default:
            cout << "Invalid category." << endl;
            break;
    }
}

void Data::calculateSleepDiff(int day) {
    Time timeInstance;
    int averageSleepMinutes = timeInstance.averageSleepTime(day);
    int age = userData.getAge();
    int averageSleepForAgeGroup;

    if (age < 1) {
        averageSleepForAgeGroup = 14.5*60; // Average of 14 and 15 hours
    } else if (age < 3) {
        averageSleepForAgeGroup = 13*60; // Average of 12 and 14 hours
    } else if (age < 6) {
        averageSleepForAgeGroup = 11*60; // Average of 10 and 12 hours
    } else if (age < 13) {
        averageSleepForAgeGroup = 9.5*60; // Average of 9 and 10 hours
    } else if (age < 18) {
        averageSleepForAgeGroup = 8.5*60; // Average of 8 and 9 hours
    } else {
        averageSleepForAgeGroup = 7.5*60; // Average of 7 and 8 hours
    }

    int differenceInMinutes = abs(averageSleepMinutes - averageSleepForAgeGroup);
    int differenceInHours = differenceInMinutes / 60;
    differenceInMinutes %= 60;

    if (averageSleepMinutes < averageSleepForAgeGroup && category == 'B') {
        cout << "Sleeping less than average by: " << differenceInHours << " hours and " << differenceInMinutes << " minutes" << endl;
    } else if (averageSleepMinutes > averageSleepForAgeGroup && category == 'D') {
        cout << "Sleeping more than average by: " << differenceInHours << " hours and " << differenceInMinutes << " minutes" << endl;
    }
}



#endif