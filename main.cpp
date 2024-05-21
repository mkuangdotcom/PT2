#include "User.h"
#include "Time.h"



#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#include <map>      // STL map
using namespace std;

int main() {    
    string username, password;


    map<string, User> users;        // Map to store all users


    char userType;
    cout << left << setw(15) << "Welcome to Dream Catcher: " << endl;
    cout << left << setw(15) << "Please select the user type: " << endl;
    cout << left << setw(15) << "1. New User" << endl;
    cout << left << setw(15) << "2. Existing User" << endl;
    cin >> userType;

    // 1. New user
    if (userType == '1') {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        User newUser(username, password);       // Create a new User object
        users["username"] = newUser;    // Add the new user to the map
        
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