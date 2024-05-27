#include "./TimeCompare.h"

bool operator==(const Time& p_left, const Time& p_right) {
    // if both the hour and minutes are the same
    return (p_left.getHour() == p_right.getHour() &&
            p_left.getMinutes() == p_right.getMinutes());
}

bool operator!=(const Time& p_left, const Time& p_right) {
    // Return the negative of equals
    return !( p_left == p_right );
}

bool operator< (const Time& p_left, const Time& p_right) {
    // If the hour is smaller
    if (p_left.getHour() < p_right.getHour()) {
        return true;
    }
    // If the hour is bigger
    else if (p_left.getHour() > p_right.getHour()) {
        return false;
    }

    // If the hour is the same, minutes are smaller
    if (p_left.getMinutes() < p_right.getMinutes()) {
        return true;
    }

    // If not, return false
    return false;
}

bool operator> (const Time& p_left, const Time& p_right) {
    // If the hour is bigger
    if (p_left.getHour() > p_right.getHour()) {
        return true;
    }
    // If the hour is smaller
    else if (p_left.getHour() < p_right.getHour()) {
        return false;
    }

    // If the hour is the same, minutes are bigger
    if (p_left.getMinutes() > p_right.getMinutes()) {
        return true;
    }

    // If not, return false
    return false;
}

bool operator<=(const Time& p_left, const Time& p_right)  {
    // Returns true if smaller than is false.
    return !(p_left > p_right);
}

bool operator>=(const Time& p_left, const Time& p_right) {
    // Returns true if bigger than is false
    return !(p_left < p_right);
}
