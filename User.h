#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept> // for std::invalid_argument
using namespace std;

#ifndef USER_H
#define USER_H


class User {
    protected:
        string username;
        string password;

    public:
        User(string _username = "", string _password = ""): username(_username), password(_password) { } // Default constructor (with default values

        void setUsername(string _username) { username = _username; }
        void setPassword(string _password) { password = _password; }
        string getUsername() { return username; }
        string getPassword() { return password; }

};


    
 

#endif