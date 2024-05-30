#include "User.h"
#include "Time.h"
#include "Data.h"
#include "NewUser.h"
#include "User.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>  // To store data in a file
#include <map>      // STL map
#include <exception>
#include <stdexcept>
#include <unistd.h>     // For sleep function
using namespace std;

// Function Prototypes
void mainMenu(NewUser&);
void Quit();

void printLines() {
    for (int i = 0; i < 100; i++) 
        cout << "-";
    cout << endl;
}

//! Login Page
void loginPage() {
    printLines();
    cout << setw(62) << "Welcome to Dream Catcher: " << endl;
    printLines();
    cout << "Please select the user type: " << "\t\t1 - New User" << "\t\t2 - Existing User\t\t";
}

//! New User Page
NewUser newUserPage(map<string, NewUser>& users) {
    string username, password, password2;
    int age;
    char gender;
    double height, weight;

    printLines();
    cout << setw(52) << "LOGIN: " << endl ;
    
    cout << "Please enter a username  : ";
    cin >> username;
    NewUser tempUser(username, ""); 

        while (true) {
            try {
                cout << "Enter password           : ";
                cin >> password;
                tempUser.checkPassword(password);

                break;

            } catch (std::invalid_argument&) {
                cout << "Invalid password. Password must be at least 8 characters long! " << endl;
                continue;
            }
        }

        while (true) {
            try {
                cout << "Please re-enter password : ";
                cin >> password2;
                tempUser.samePassword(password, password2);   

                break; 
            } 
            catch (std::invalid_argument&) {
                cout << "Invalid password. Both passwords does not match! " << endl;
            }
        }

        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Welcome to Dream Catcher!\t" << username << endl;
        cout << "Before we proceed further. Please provide some personal information. Thank You! " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        NewUser newUser(username, password);  

        cout << "Age\t\t: ";
        cin >> age;

        cout << "Gender (M/F)\t: ";
        cin >> gender;

        cout << "Height (m)\t: ";
        cin >> height;

        cout << "Weight (kg)\t: ";
        cin >> weight;

        newUser.setAge(age);
        newUser.setGender(gender);
        newUser.setHeight(height);
        newUser.setWeight(weight);
        users[username] = newUser;   

        ofstream outFile("users.txt", ios::app);
        outFile << username << " " << password << " " << age << " " << gender << " " << height << " " << weight << endl;
        outFile.close();

        return users[username];
}


//! Existing User Page
NewUser existingUser(map<string, NewUser>& users) {
    string username, password;

    printLines();
    cout << setw(52) << "LOGIN: " << endl;

    bool validUser = false;
    do {
        cout << "Enter username: ";
        cin >> username;

        if (users.find(username) == users.end()) 
            cout << "User does not exist" << endl;
        else 
            validUser = true;
    } while (!validUser);
            
    while (true) {
        try {
            cout << "Enter password: ";
            cin >> password;

            if (password != users[username].getPassword()) {
                throw std::invalid_argument("Incorrect password");
            }

            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Welcome back to Dream Catcher!\t" << username << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
            
        } catch (std::invalid_argument&) {
            cout << "Incorrect password, Please try again" << endl;
        }
    }
    return users[username];
}



//! Sleep Analyzer Page
void sleepAnalyzer(NewUser& user) {
    char choice;
    do {
        Time time;
        Data data;
        int numDays;
        cout << endl << endl;
        printLines();
        cout << setw(58) << "SLEEP ANALYZER: " << endl;
        printLines();

        cout << "Enter the number of days you want to analyze: ";
        cin >> numDays;
        time.dailySleepTime(numDays);

        cout << endl << endl;
        cout << setw(55) << "Sleep Report for " << user.getUsername() << endl;
        printLines();
        cout << "Name: \t\t" << user.getUsername() << endl;
        cout << "Age: \t\t" << user.getAge() << endl;
        if (user.getGender() == 'M')
            cout << "Gender: \tMale" << endl;
        else if (user.getGender() == 'F')
            cout << "Gender: \tFemale" << endl;

        cout << "Height: \t" << user.getHeight() << " m" << endl;
        cout << "Weight: \t" << user.getWeight() << " kg" << endl;
        printLines();
        time.printSleepTime();
        printLines();

        int averageTime = time.getAverageSleepMinutes();
        int age = user.getAge();

        data.analyzeSleep(averageTime, age);
        data.displayMessage();
        data.calculateSleepDiff(averageTime, age);



        cout << endl << endl;
        cout << "1 - Generate a new report" << endl;
        cout << "Q - Quit system" << endl;
        cout << "Press any key to return to the main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice == '1');

    switch (toupper(choice)) {
        case 'Q':
            Quit();
            break;
        
        default:
            mainMenu(user);
            break;
    }
}

//! Exit System
void Quit() {
    cout << endl;
    printLines();
    cout << "Thank you for using Dream Catcher. Have a good day!" << endl;
    printLines();
    cout << endl;
    exit(0);

}

//! Main Menu Page
void mainMenu(NewUser &user) {
    int Menu;

    cout << endl << endl << endl;
    printLines();
    cout << setw(52) << "MAIN MENU: " << endl;
    printLines();

    cout << "Please select an option: " << endl;
    cout << "\t\t1 - Sleep Analyzer" << endl;
    cout << "\t\t2 - Sleep Symphony" << endl;
    cout << "\t\tQ - Quit Program" << endl << endl;
    cout << "Enter your choice: ";
    cin >> Menu;

    switch(toupper(Menu)) {
        case 1:
            sleepAnalyzer(user);
            break;
        case 2:

            break;
        case 3:

            break;
    }
}


int main() {    
    string username, password, password2, name;
    char userType;
    int age;
    char gender;
    double height, weight;

    // Map to store all users
    map<string, NewUser> users;        

    ifstream inFile("users.txt");
    if (!inFile) {
        cout << "Unable to open file";
        return 1; 
    }

    while (inFile >> username >> password >> age >> gender >> height >> weight) {
        NewUser user(username, "");
        user.setPassword(password);
        user.setAge(age);
        user.setGender(gender);
        user.setHeight(height);
        user.setWeight(weight);
        users[username] = user;
    }
    inFile.close();
    
    do {
        loginPage();
        cin >> userType;

        if (userType != '1' && userType != '2') 
            cout << "Invalid input. Please enter 1 for New User or 2 for Existing User." << endl;
        
    } while (userType != '1' && userType != '2');

    NewUser currentUser;
    if (userType == '1') 
        currentUser = newUserPage(users);
    else if (userType == '2') 
        currentUser = existingUser(users);

    cout << endl << "Please wait while we redirect you to the main menu..." << endl;
    sleep(1);

    mainMenu(currentUser);   

    return 0;
}

