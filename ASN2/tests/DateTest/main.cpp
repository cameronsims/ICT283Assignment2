#include <iostream>
#include <sstream>
#include <string>

#include "../../src/date/Date.h"
#include "../../src/date/DateIO.h"

const int DAYS_IN_YEAR = 365;
const int DAYS_IN_LEAP_YEAR = DAYS_IN_YEAR + 1;
const int NOT_A_LEAP_YEAR = 2007;

// Default value to see if the istream worked
const Date d1;



bool isEqual(const Date& left, const Date& right) {
    return (left.getDay() == right.getDay() &&
           left.getMonth() == right.getMonth() &&
           left.getYear() == right.getYear());
}


bool test1_validStreams() {
    // Amount of times triggered
    int n = 0;

    for (int i = -99; i < 99; i++) {
        // new date we are testing to the first
        Date d2;

        // Format into i/i/i
        std::string dayMonth = std::to_string(i);
        std::string yearStr = std::to_string(1999 + i);
        std::string str = dayMonth + std::string("/") + dayMonth + std::string("/") + yearStr;
        std::stringstream ss(str);

        // Place value to date
        try {
            ss >> d2;
            // If it is a valid date
            n++;
        } catch (const InvalidDate& err) {
            // Don't do anything
        }
    }
    return (n == 12);
}

bool test2_invalidStreams() {
    // Test weird values like floats or strings
    Date d3;
    std::string str = "10.0/-5.5/3.14";
    std::stringstream ss(str);

    try {
        ss >> d3;
    } catch (const InvalidDate& err) {
        // Change month to +1
        d3.setMonth(1);
        // Causes error due to float type
        d3.setYear((int)3.14);
    }

    return isEqual(Date(10, 1, 3), d3);
}

bool test3_stringStream() {
    // Test string values
    Date d4;
    std::string str = "NOT/APPLIABLE/<?>";
    std::stringstream ss(str);

    try {
        ss >> d4;
    } catch (std::invalid_argument err) {
        d4 = Date();
    } catch (const InvalidDate& err) {
        d4 = Date();
    }

    return isEqual(Date(), d4);
}

bool test4_invalidNotation() {
    // Test invalid notation
    Date d5;
    std::string str = "A/B";
    std::stringstream ss(str);

    try {
        ss >> d5;
    } catch (std::invalid_argument err) {

    } catch (const InvalidDate& err) {

    }

    return isEqual(Date(), d5);
}

bool test5_nullInput() {
    // Test invalid notation
    Date d6;
    std::string str = "";
    std::stringstream ss(str);

    try {
        ss >> d6;
    } catch (std::invalid_argument err) {

    } catch (const InvalidDate& err) {

    }

    return isEqual(Date(), d6);
}

bool test6_normalYear() {
    Date d7;

    // Test all months
    int n = 0;
    for (int i = -100; i < 100; i++) {
        // Test all days
        for (int j = -100; j < 100; j++) {
            try {
                d7 = Date(j, i, NOT_A_LEAP_YEAR);
                n++;
            } catch (const InvalidDate& err) {
                // Don't do anything
            }


        }
    }

    // Test that all valid dates have been input
    return (n == DAYS_IN_YEAR);
}

bool test8_yearTest() {
    // The date we are testing with
    Date d8;

    int n = 0;

    // Check leap years vs non-leap years
    for (int i = 2000; i < 2020; i++) {
        try {
            d8 = Date(29, 2, i);
            n++;
        } catch (const InvalidDate& err) {
            // Don't do anything
        }
    }

    // Test that all valid dates have been input
    return (n == (20/4));
}


int main() {

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass = test1_validStreams();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test2_invalidStreams();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test3_stringStream();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 4                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test4_invalidNotation();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 5                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

     pass = test5_nullInput();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 6                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test6_normalYear();
    if (!pass) { return 1; }


    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 7                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test8_yearTest;
    if (!pass) { return 1; }

    return !pass;
}
