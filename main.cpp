#include "User.h"
#include "Time.h"



#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>  // To store data in a file
#include <map>      // STL map
using namespace std;

int main() {    
    string username, password, password2;
    char userType;


    map<string, User> users;        // Map to store all users

    ifstream inFile("users.txt");
    while (inFile >> username >> password) {
        users[username] = User(username, password);
    }
    inFile.close();
    
    cout << "Welcome to Dream Catcher: " << endl;
    cout << "Please select the user type: " << endl;
    cout << "1. New User" << endl;
    cout << "2. Existing User" << endl;
    cin >> userType;

    // 1. New user
    if (userType == '1') {
        cout << "Enter username: ";
        cin >> username;
        do {
            cout << "Enter password: ";
            cin >> password;
        } while (!checkPassword(password));
    
        do { 
            cout << "Please re-enter password: ";
            cin >> password2;
        
        } while (!samePassword(password, password2));   

        User newUser(username, password);       // Create a new User object
        users["username"] = newUser;    // Add the new user to the map

        // Save the new user to file
        ofstream outFile("users.txt", ios::app);
        outFile << username << " " << password << "\n";
        outFile.close();
        
        // 2. Existing user
    } else if (userType == '2') {
        cout << "Enter username: ";
        cin >> username;

        // Check if the user exists
        if (users.find(username) == users.end()) {  // check if an element exists in the container
            cout << "User does not exist\n";
        } else {
            while (true) {
                cout << "Enter password: ";
                cin >> password;

                // Check if the password is correct
                if (users[username].getPassword() == password) {
                    cout << "Welcome " << username << endl;
                    break;
                } else {
                    cout << "Incorrect password, Please try again\n";
                }
            }
        }
    }

    return 0;
}