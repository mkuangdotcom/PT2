#include <iostream>
#include <string>
#include <vector>
#include "NewUser.h" // Include the User header file
using namespace std;

#ifndef DATA_H
#define DATA_H

class Data {
    protected:
        char category;
        NewUser userData; // Use NewUser instead of User
        vector<double> sleepHours; // Vector to store daily sleep hours

    public:
        Data(char _category = ' ', NewUser _userData = NewUser()) : category(_category), userData(_userData) { } // Default constructor (with default values

        void setCategory(char _category) { category = _category; }
        char getCategory() { return category; }
        void addSleepHours(double hours) { sleepHours.push_back(hours); } // Add daily sleep hours

        double calculateAverageSleep() { // Calculate average sleep hours
            double sum = 0;
            for (double hours : sleepHours) {
                sum += hours;
            }
            return sum / sleepHours.size();
        }

        void analyzeSleep() { // Analyze sleep based on average sleep hours, BMI, and age
            double averageSleep = calculateAverageSleep();
            double bmi = userData.getBMI();
            int age = userData.getAge();

            // Analyze sleep and set category based on average sleep hours, BMI, and age
            // This is a very simplistic analysis and might not accurately reflect the actual sleep needs of a person
            if (averageSleep < 7 || bmi < 18.5 || bmi > 24.9) {
                category = 'A'; // Category A: Needs improvement
            } else if (age < 18 && averageSleep < 9) {
                category = 'B'; // Category B: Needs improvement (for people under 18)
            } else {
                category = 'C'; // Category C: Good
            }
        }

        void displayMessage();
};

#endif