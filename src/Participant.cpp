#include "Participant.h"
#include <iostream>
#include <limits>

Participant::Participant() : conferenceScheduled(false) {}

Participant::Participant(const User& user) : User(user), conferenceScheduled(false) {}

Participant::~Participant() {}

void Participant::scheduleConference(std::string name, std::string day, std::string time) {
    if (conferenceScheduled && scheduledDay == day && scheduledTime == time) {
        std::cout << "There is already a conference scheduled on " << day << " at " << time << ". Please choose another time." << std::endl;
        return;
    }
    conferenceName = name;
    scheduledDay = day;
    scheduledTime = time;
    conferenceScheduled = true;
    std::cout << "Conference '" << conferenceName << "' scheduled successfully on " << day << " at " << time << std::endl;
    showConference();
}

void Participant::showConference() {
    if (!conferenceScheduled) {
        std::cout << "No conference scheduled." << std::endl;
        return;
    }
    std::cout << "Scheduled Conference:" << std::endl;
    std::cout << "Conference Name: " << conferenceName << std::endl;
    std::cout << "Day: " << scheduledDay << ", Time: " << scheduledTime << std::endl;
}

void Participant::showTime() {
    std::cout << "Available Time Slots:" << std::endl;
    std::cout << "8:00 AM - 10:00 AM" << std::endl;
    std::cout << "10:00 AM - 12:00 PM" << std::endl;
    std::cout << "2:00 PM - 5:00 PM" << std::endl;
    std::cout << "5:00 PM - 7:00 PM" << std::endl;
}
