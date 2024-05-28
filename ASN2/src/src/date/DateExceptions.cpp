#include "DateExceptions.h"

const char* InvalidDate::what() const {
    return "Date is not in correct format/invalid number.";
}

const char* InvalidDay::what() const {
    return "Day is not in correct format/invalid number.";
}

const char* InvalidMonth::what() const {
    return "Month is not in correct format/invalid number (should be 1-12)";
}
