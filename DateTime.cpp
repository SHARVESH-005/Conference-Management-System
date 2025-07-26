#include "DateTime.h"

DateTime::DateTime() : date("12-03-2005"), day("Sunday"), time("13:00:00") {}

std::string DateTime::displayDate(std::string format) {
    if (format == "HHHH") return day;
    if (format == "MM-DD-YYYY") return date.substr(3, 2) + '-' + date.substr(0, 2) + '-' + date.substr(6);
    if (format == "DD-MM-YYYY") return date;
    throw std::invalid_argument("Invalid date format");
}
