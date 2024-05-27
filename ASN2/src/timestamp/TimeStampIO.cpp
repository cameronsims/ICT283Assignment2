#include "TimeStampIO.h"

#include "../date/DateIO.h"
#include "../time/TimeIO.h"

std::istream& operator>>(std::istream& p_is, TimeStamp& p_timestamp) {
    p_is >> p_timestamp.date    // Input the date
         >> p_timestamp.time;   // Input the time
    return p_is;
}

std::ostream& operator<<(std::ostream& p_os, const TimeStamp& p_timestamp) {
    // Output the date and time
    p_os << p_timestamp.time << " "
         << p_timestamp.date;
    return p_os;
}
