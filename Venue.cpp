#include "Venue.h"
#include <iostream>

std::string Venue::placeList[MAX_VENUES];
int Venue::numVenues = 0;

Venue::Venue() {}

Venue::Venue(const std::string& p) {
    for (int i = 0; i < numVenues; ++i) {
        if (placeList[i] == p) {
            venue_name = p;
            std::cout << "Venue Found\nVenue Chosen Successfully.\n";
            return;
        }
    }
}

Venue::~Venue() {}

void Venue::addVenue(const std::string& p) {
    for (int i = 0; i < numVenues; ++i)
        if (placeList[i] == p) return;
    if (numVenues < MAX_VENUES)
        placeList[numVenues++] = p;
}

void Venue::deleteVenue(const std::string& p) {
    int index = -1;
    for (int i = 0; i < numVenues; ++i)
        if (placeList[i] == p) {
            index = i;
            break;
        }
    if (index != -1)
        for (int i = index; i < numVenues - 1; ++i)
            placeList[i] = placeList[i + 1];
    --numVenues;
}

void Venue::showVenues() {
    for (int i = 0; i < numVenues; ++i)
        std::cout << "- " << placeList[i] << '\n';
}

void Venue::editVenue(const std::string& oldPlace, const std::string& newPlace) {
    for (int i = 0; i < numVenues; ++i)
        if (place
