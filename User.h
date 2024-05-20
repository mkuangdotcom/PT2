#include <iostream>
#include <cmath>
using namespace std;

#ifndef USER_H
#define USER_H

class User {
    private:
        string username;
        string password;

        string name;
        int age;
        char gender;
        double height;
        double weight;
        double BMI;

    public:
        User(string username = "", string password = "", string name = "", int age = 0, char = ' ', double height = 0, double weight = 0, double BMI = 0);

        void setUsername(string _username) { username = _username; }
        void setPassword(string _password) { password = _password; }

        void setName(string _name) { name = _name; }
        void setAge(int _age) { age = _age; }
        void setGender(char a) { gender = a; }
        void setHeight(double _height) { height = _height; }
        void setWeight(double _weight) { weight = _weight; }
        void setBMI() { BMI = weight / pow(height, 2); }


};

#endif