#include "Organiser.h"
#include <iostream>

Organiser::Organiser() {}

Organiser::Organiser(std::string name, short int age, std::string regNO, std::string gender,
                     std::string username, std::string password, std::string email,
                     std::string orgName, std::string title)
    : User(name, age, regNO, gender, username, password, email),
      organisationName(orgName), organiserTitle(title) {}

void Organiser::setOrganisationName(std::string orgName) {
    organisationName = orgName;
}

std::string Organiser::getOrganisationName() const {
    return organisationName;
}

void Organiser::setOrganiserTitle(std::string title) {
    organiserTitle = title;
}

std::string Organiser::getOrganiserTitle() const {
    return organiserTitle;
}

void Organiser::displayOrganiserInfo() const {
    display(); // base class display
    std::cout << "Organisation Name: " << organisationName
              << "\nOrganiser Title: " << organiserTitle << std::endl;
}
