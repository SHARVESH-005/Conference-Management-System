#include "Conference.h"

// Static member initialization
std::map<std::string, Conference*> Conference::conferenceMap;
int Conference::no_of_conferences = 0;

// Constructor
Conference::Conference() {
    conferenceMap[name] = this;
}

// Retrieve a conference by its name
Conference* Conference::getConferenceByName(const std::string& name) {
    if (conferenceMap.find(name) != conferenceMap.end())
        return conferenceMap[name];
    return nullptr;
}

// Getter for conference name
std::string Conference::getName() {
    return name;
}
