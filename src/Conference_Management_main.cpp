#include <iostream>
#include <string>
#include "User.h"
#include "Conference.h"
#include <limits>
#include "DateTime.h"
#include "Venue.h"
#include "Sponsor.h"
#include "Participant.h"
#include "Organiser.h"
#include <map>

void page_1();

void exploreConferences(User &user)
{
    int i = 1;
    for (const auto& pair : Conference::conferenceMap)
        std::cout << i++ << ". " << pair.first << "\n";

    std::cout << "Enter the number of the conference you want to explore: ";
    int choice;
    std::cin >> choice;

    auto it = Conference::conferenceMap.begin();
    std::advance(it, choice - 1);
    Conference* selectedConference = it->second;

    std::cout << "You selected: " << selectedConference->getName() << "\n";
    std::cout << "1. Join\n2. Organise\n3. Sponsor\n4. Back to main menu\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            Participant p(user);
            p.showTime();
            char ch;
            do {
                std::string name, day, time;
                std::cin.ignore();
                std::cout << "\nEnter the name of the conference: ";
                getline(std::cin, name);
                std::cout << "Enter the date (YYYY-MM-DD): ";
                getline(std::cin, day);
                std::cout << "Enter the time (e.g., 10:00 AM): ";
                getline(std::cin, time);
                p.scheduleConference(name, day, time);
                std::cout << "\nDo you want to schedule another conference? (y/n): ";
                std::cin >> ch;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (ch == 'y' || ch == 'Y');
            break;
        }
        case 2:
        case 3:
        case 4:
        default:
            std::cout << "Invalid choice.\n";
    }
}

void createConferences() {
    // Placeholder for creation logic
}

void page_2(User &user)
{
    std::cout << "\t\tMAIN MENU\n1. Explore Conferences\n2. Create Conference\n3. Exit\n";
    int resp;
    std::cin >> resp;
    do {
        switch (resp) {
            case 1:
                exploreConferences(user);
                break;
            case 2:
                createConferences();
                break;
            case 3:
                exit(0);
            default:
                std::cout << "Invalid response\n";
        }
    } while (true);
}

void sign_up()
{
    std::string name, regNO, gender, username, password, email;
    short int age;
    std::cout << "Enter your details:\n";
    std::cout << "Name: "; std::cin >> name;
    std::cout << "Age: "; std::cin >> age;
    std::cout << "Registration Number: "; std::cin >> regNO;
    std::cout << "Gender: "; std::cin >> gender;
    std::cout << "Username: "; std::cin >> username;
    std::cout << "Password: "; std::cin >> password;
    std::cout << "Email: "; std::cin >> email;

    new User(name, age, regNO, gender, username, password, email);
    std::cout << "Signed up successfully.\n";
    page_1();
}

void sign_in()
{
    std::string username, password;
    std::cout << "Username: "; std::cin >> username;
    std::cout << "Password: "; std::cin >> password;

    User* user = User::getUserByUsername(username);
    if (user && user->getPassword() == password)
        std::cout << "Signed in successfully.\n";
    else
        std::cout << "Invalid username or password.\n";

    page_2(*user);
}

void page_1()
{
    std::cout << "\t\tMAIN MENU\n1. Sign-In\n2. Sign-Up\n3. Exit\n";
    int resp;
    std::cin >> resp;
    do {
        switch (resp) {
            case 1:
                sign_in();
                break;
            case 2:
                sign_up();
                break;
            case 3:
                exit(0);
            default:
                std::cout << "Invalid response\n";
        }
    } while (true);
}

int main() {
    page_1();
    return 0;
}
