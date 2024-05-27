#include "TimeStampCompare.h"

#include "../date/DateCompare.h"
#include "../time/TimeCompare.h"

bool operator==(const TimeStamp& p_left, const TimeStamp& p_right) {
    // Return true if both time and date are the same
    return (p_left.date == p_right.date &&
            p_left.time == p_right.time);
}

bool operator!=(const TimeStamp& p_left, const TimeStamp& p_right) {
    return !( p_left == p_right );
}

bool operator< (const TimeStamp& p_left, const TimeStamp& p_right) {
    // If the date is smaller
    if (p_left.date < p_right.date) {
        // Return true
        return true;
    }
    // Otherwise, if the date is bigger
    else if (p_left.date > p_right.date) {
        // Then it is false
        return false;
    }

    // If the date is equal...
    // And the time is smaller
    if (p_left.time < p_right.time) {
        // Return true
        return true;
    }

    // If the date is equal
    // And the time is equal to or bigger than
    return false;
}

bool operator> (const TimeStamp& p_left, const TimeStamp& p_right) {
    // If the date is bigger
    if (p_left.date > p_right.date) {
        // Return true
        return true;
    }
    // Otherwise, if the date is smaller
    else if (p_left.date < p_right.date) {
        // Then it is false
        return false;
    }

    // If the date is equal...
    // And the time is bigger
    if (p_left.time > p_right.time) {
        // Return true
        return true;
    }

    // If the date is equal
    // And the time is equal to or smaller than
    return false;
}

bool operator<=(const TimeStamp& p_left, const TimeStamp& p_right) {
    return !( p_left > p_right );
}

bool operator>=(const TimeStamp& p_left, const TimeStamp& p_right) {
    return !( p_left < p_right);
}
