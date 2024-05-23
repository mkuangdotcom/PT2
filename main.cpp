#include "User.h"
#include "Time.h"
#include "Data.h"



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
void newUserPage(map<string, User>& users) {
    string username, password, password2, name;
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

        cout << "Name\t\t: ";
        cin.ignore();
        getline(cin, name);

        cout << "Age\t\t: ";
        cin >> age;

        cout << "Gender (M/F)\t: ";
        cin >> gender;

        cout << "Height (m)\t: ";
        cin >> height;

        cout << "Weight (kg)\t: ";
        cin >> weight;

        newUser.setName(name);
        newUser.setAge(age);
        newUser.setGender(gender);
        newUser.setHeight(height);
        newUser.setWeight(weight);
        users[username] = newUser;   

        ofstream outFile("users.txt", ios::app);
        outFile << username << " " << password << " " << name << " " << age << " " << gender << " " << height << " " << weight << endl;
        outFile.close();
}

//! Existing User Page
void existingUser(map<string, User>& users) {
    string username, password;

    printLines();
    cout << setw(52) << "LOGIN: " << endl;

    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) == users.end()) {  
        cout << "User does not exist" << endl;
    } else {
        while (true) {
            try {
                cout << "Enter password: ";
                cin >> password;

                if (users[username].getPassword() != password) {
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
    }
}

//! Main Menu Page
void mainMenu() {
    int Menu;

    cout << endl << endl << endl;
    printLines();
    cout << setw(52) << "MAIN MENU: " << endl;
    printLines();

    cout << "Please select an option: " << endl;
    cout << "\t\t1 - Sleep Analyzer" << endl;
    cout << "\t\t2 - Sleep Symphony" << endl;
    cout << "\t\t3 - Quit Program" << endl << endl;
    cout << "Enter your choice: ";
    cin >> Menu;
    printLines();

    switch(Menu) {
        case 1:
            cout << "Sleep Analyzer" << endl;
            break;
        case 2:
            cout << "Sleep Symphony" << endl;
            break;
        case 3:
            cout << "Quitting Program" << endl;
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
    map<string, User> users;        

    ifstream inFile("users.txt");
    if (!inFile) {
        cout << "Unable to open file";
        return 1; 
    }

    while (inFile >> username >> password >> name >> age >> gender >> height >> weight) {
        NewUser user(username, password);
        user.setName(name);
        user.setAge(age);
        user.setGender(gender);
        user.setHeight(height);
        user.setWeight(weight);
        users[username] = user;
    }
    inFile.close();
    
    loginPage();
    cin >> userType;

        if (userType == '1') 
            newUserPage(users);
            
        else if (userType == '2') 
            existingUser(users);
        


        cout << endl << "Please wait while we redirect you to the main menu..." << endl;
        sleep(3);

        mainMenu();

            

    return 0;
}

