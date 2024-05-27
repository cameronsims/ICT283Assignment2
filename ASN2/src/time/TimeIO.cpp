#include "./TimeIO.h"

#include <sstream>

std::istream& operator>>(std::istream& p_is, Time& p_time) {
    /***************************
     * TIME IS IN FORMAT HH:SS *
     ***************************/

    // Create temp vars
    int hour, second;

    // Create string stream for the time
    std::string timeStr;
    p_is >> timeStr;
    //std::getline(p_is, timeStr, '\0');  // Get the string in format (HH:SS)
    std::stringstream ss(timeStr);      // Stringstream to get both values

    // Get hour //
    std::getline(ss, timeStr, ':');
    hour = std::stoi(timeStr);

    // Get second //
    std::getline(ss, timeStr, '\0');
    second = std::stoi(timeStr);

    // Set both to actual time //
    p_time.setHour(hour);
    p_time.setMinutes(second);

    return p_is;
}

std::ostream& operator<<(std::ostream& p_os, const Time& p_time) {
    // Vars to make things look nicer
    const int hr = p_time.getHour(),
              sec = p_time.getMinutes();
    // Print out to the ostream
    // Add a 0 if the hours are under two digits
    if (hr < 10) {
        p_os << '0';
    }
    p_os << hr << ':';

    // Add a 0 if the seconds are under two digits
    if (sec < 10) {
        p_os << '0';
    }
    p_os << sec;

    return p_os;
}
