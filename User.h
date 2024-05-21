#include <iostream>
#include <cmath>
#include <string>
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
        friend bool checkPassword(string _password);        // Checks whether password is at least 8 characters long
        friend bool samePassword(string _password, string _password2);      // Checks whether the two passwords match
        

};

class newUser : public User {       // Inheritance - extended from User class.
    private:
        string name;
        int age;
        char gender;
        double height;
        double weight;
        double BMI;

    public:
        newUser(string _name = "", int _age = 0, char _gender = ' ', double _height = 0, double _weight = 0, double _BMI = 0) : 
        User("",""), name(_name), age(_age), gender(_gender), height(_height), weight(_weight), BMI(_BMI) {};

        string getName() { return name; }
        int getAge() { return age; }
        char getGender() {return gender; }
        double getHeight() { return height; }
        double getWeight() { return weight; }
        double getBMI() { return BMI; }

        void setName(string _name) { name = _name; }
        void setAge(int _age) { age = _age; }
        void setGender(char a) { gender = a; }
        void setHeight(double _height) { height = _height; }
        void setWeight(double _weight) { weight = _weight; }
        void calcBMI() { BMI = weight / pow(height, 2); }

};

bool checkPassword(string _password) {
    if (_password.length() < 8) {
        cout << "Password must be at least 8 characters long\n";
        return false;
    }
    return true;
}

bool samePassword(string _password, string _password2) {
    if (_password != _password2) {
        cout << "Passwords do not match\n";
        return false;
    }
    return true;
}



#endif