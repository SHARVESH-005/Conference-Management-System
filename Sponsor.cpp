#include "Sponsor.h"
#include <iostream>

Sponsor::Sponsor() {}

Sponsor::Sponsor(std::string name, short int age, std::string regNO, std::string gender,
                 std::string username, std::string password, std::string email,
                 std::string event, double amt)
    : User(name, age, regNO, gender, username, password, email),
      sponsoredEvent(event), amount(amt) {}

void Sponsor::display() {
    std::cout << "Sponsor: ";
    User::display();
    std::cout << "Event: " << sponsoredEvent << ", Amount: ₹" << amount << std::endl;
}
