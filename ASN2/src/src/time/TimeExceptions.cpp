#include "TimeExceptions.h"

const char* InvalidTime::what() const {
    return "Invalid time entered.";
}

const char* InvalidHour::what() const {
    return "Invalid hour entered, must be between 0-23.\n";
}

const char* InvalidMinute::what() const {
    return "Invalid minute entered, must be between 0-59";
}

