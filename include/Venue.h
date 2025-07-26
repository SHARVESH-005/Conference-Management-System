#ifndef VENUE_H
#define VENUE_H

#include <string>

class Venue {
private:
    static const int MAX_VENUES = 100;
    static std::string placeList[MAX_VENUES];
    static int numVenues;
    std::string venue_name;

public:
    Venue();
    Venue(const std::string& p);
    ~Venue();

    static void addVenue(const std::string& p);
    static void deleteVenue(const std::string& p);
    static void showVenues();
    static void editVenue(const std::string& oldPlace, const std::string& newPlace);
};

#endif
