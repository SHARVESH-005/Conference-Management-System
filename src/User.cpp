#include "User.h"
#include <iostream>
#include <map>

// Define static user map
static std::map<std::string, User*> userMap;

// Constructor
User::User(std::string name, short int age, std::string regNO,
           std::string gender, std::string username,
           std::string password, std::string email)
    : name(name), age(age), regNO(regNO), gender(gender),
      username(username), password(password), email(email) {
    userMap[username] = this;
}

// Default Constructor
User::User() : age(0) {}

// Get user by username
User* User::getUserByUsername(const std::string& username) {
    if (userMap.find(username) != userMap.end()) {
        std::cout << "User Found\n";
        return userMap[username];
    } else {
        std::cout << "User Not Found\n";
        return nullptr;
    }
}

// Getters
std::string User::getName() const { return name; }
short int User::getAge() const { return age; }
std::string User::getRegNO() const { return regNO; }
std::string User::getGender() const { return gender; }
std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }
std::string User::getEmail() const { return email; }

// Setters
void User::setName(std::string n) { name = n; }
void User::setAge(short int a) { age = a; }
void User::setRegNO(std::string r) { regNO = r; }
void User::setGender(std::string g) { gender = g; }
void User::setUsername(std::string u) { username = u; }
void User::setPassword(std::string p) { password = p; }
void User::setEmail(std::string e) { email = e; }

// Display
void User::display() const {
    std::cout << "Name: " << name << "\nAge: " << age
              << "\nRegistration Number: " << regNO
              << "\nGender: " << gender
              << "\nUsername: " << username
              << "\nEmail: " << email << std::endl;
}

// Login verification
bool User::verifyLogin(std::string uname, std::string pword) {
    return uname == username && pword == password;
}

// Update info
void User::updateEmail(std::string newEmail) { email = newEmail; }
void User::updatePassword(std::string newPassword) { password = newPassword; }
