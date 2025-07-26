#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    short int age;
    std::string regNO;
    std::string gender;
    std::string username;
    std::string password;
    std::string email;

public:
    // Constructor
    User(std::string name, short int age, std::string regNO,
         std::string gender, std::string username,
         std::string password, std::string email);

    // Default constructor
    User();

    // Static function to retrieve user by username
    static User* getUserByUsername(const std::string& username);

    // Getters
    std::string getName() const;
    short int getAge() const;
    std::string getRegNO() const;
    std::string getGender() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;

    // Setters
    void setName(std::string n);
    void setAge(short int a);
    void setRegNO(std::string r);
    void setGender(std::string g);
    void setUsername(std::string u);
    void setPassword(std::string p);
    void setEmail(std::string e);

    // Display user information
    void display() const;

    // Authentication
    bool verifyLogin(std::string uname, std::string pword);

    // Updaters
    void updateEmail(std::string newEmail);
    void updatePassword(std::string newPassword);
};

#endif // USER_H
