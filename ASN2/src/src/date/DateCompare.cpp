#include "DateCompare.h"

bool operator==(const Date& p_left, const Date&p_right) {
    // Returns true if all are the same
    return (p_left.getDay() == p_right.getDay() &&      // Check if the day is the same
            p_left.getMonth() == p_right.getMonth() &&  // Check if the month is the same
            p_left.getYear() == p_right.getYear());     // Check if the year is the same
}

bool operator!=(const Date& p_left, const Date& p_right) {
    // Return if they're not the same
    return !(p_left == p_right);
}

bool operator< (const Date& p_left, const Date& p_right) {
    // Returns true if p_left is smaller than p_right

    // If the year is smaller, return true
    if (p_left.getYear() < p_right.getYear()) {
        return true;
    }

    // If the year is bigger
    if (p_left.getYear() > p_right.getYear()) {
        return false;
    }

    // If we're here, the year is equal ////////////////////////////////

    // If the month is smaller, return true
    if (p_left.getMonth() < p_right.getMonth()) {
        return true;
    }
    // If the month is bigger, return false
    if (p_left.getMonth() > p_right.getMonth()) {
        return false;
    }

    // If we're here, the month and year are equal /////////////////////

    // If the day is smaller, return true
    if (p_left.getDay() < p_right.getDay()) {
        return true;
    }

    // If all the above works, then it is false.
    return false;
}

bool operator> (const Date& p_left, const Date& p_right) {
// Returns true if p_left is smaller than p_right

    // If the year is smaller, return true
    if (p_left.getYear() < p_right.getYear()) {
        return false;
    }

    // If the year is bigger
    if (p_left.getYear() > p_right.getYear()) {
        return true;
    }

    // If we're here, the year is equal ////////////////////////////////

    // If the month is smaller
    if (p_left.getMonth() < p_right.getMonth()) {
        return false;
    }
    // If the month is bigger
    if (p_left.getMonth() > p_right.getMonth()) {
        return true;
    }

    // If we're here, the month and year are equal /////////////////////

    // If the day is bigger, return true
    if (p_left.getDay() > p_right.getDay()) {
        return true;
    }

    // If all the above works, then it is true.
    return false;
}

bool operator<=(const Date& p_left, const Date& p_right) {
    // Returns true if smaller than is false.
    return !(p_left > p_right);
}

bool operator>=(const Date& p_left, const Date& p_right) {
    // Returns true if bigger than is false
    return !(p_left < p_right);
}
