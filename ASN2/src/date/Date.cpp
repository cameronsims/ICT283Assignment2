#include "Date.h"

Date::Date() {
    this->setYear(1);
    this->setMonth(1);
    this->setDay(1);

}

Date::~Date() {

}

Date::Date(int p_day, int p_month, int p_year) {
    // Needs to be in Year -> Month -> Day order
    this->setYear(p_year);
    this->setMonth(p_month);
    this->setDay(p_day);
}


Date& Date::setDay(int p_day) {
    // Check if it is valid
    if (!Date::m_isValid(p_day, this->getMonth(), this->getYear())) {
        throw InvalidDay();
    }

    // Otherwise, allow it using our parent's function
    Day::setDay(p_day);
    return *this;
}

Date& Date::setMonth(int p_month) {
    // Check if it is valid
    if (!Date::m_isValid(this->getDay(), p_month, this->getYear())) {
        throw InvalidMonth();
    }

    // Otherwise, allow it using our parent's function
    Month::setMonth(p_month);
    return *this;
}

Date& Date::setYear(int p_year) {
    // Check if it is valid
    if (!Date::m_isValid(this->getDay(), this->getYear(), p_year)) {
        throw InvalidDate();
    }

    // Otherwise, allow it using our parent's function
    Year::setYear(p_year);
    return *this;
}

bool Date::m_isValid(int p_day, int p_month, int p_year) {
    // Check if day is valid (1-31)
    if (p_day < 1 || p_day > 31) {
        // Throw that the day is invalid
        return false;
    }
    // Check if month is valid (1-12)
    if (p_month < 1 || p_month > 12) {
        return false;
    }

    // Check the Day again, for the amount per month

    // If the month is divisible by 2, before (7) July
    // Then it is a 30 day month
    if ((p_month % 2 == 0 && p_month <= 6) ||
        (p_month % 2 == 1 && p_month >= 8)) {
        // Otherwise, if the day is over 30 don't allow it
        if (p_day > 30) {
            return false;
        }
    }

    // If the month is February...
    if (p_month == 2) {
        // If the year we're on is a leap year (any year divisible by 4)
        // But it also must not be divisible by 100
        if (p_year % 4 == 0 && !(p_year % 4 == 100)) {
            // The year must also be divisible by 400 to be a leap year
            if (p_year % 400 == 0) {
                // If we're on any day  past 29
                if (p_day > 29) {
                    // Throw an error
                    return false;
                }
            }
        }
        // Or if its just a normal February (we're past the 28/2 on a normal year)
        else if (p_day > 28) {
            return false;
        }
    }

    return true;
}
