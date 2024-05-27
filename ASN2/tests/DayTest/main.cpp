#include <iostream>

#include "../../src/date/day/Day.h"
#include "../../src/date/day/DayIO.h"

#include <string>
#include <sstream>

const Day def = Day();
constexpr int MAX_DAYS = 31;

bool test1_invalidDay() {
    // The amount of constructors that worked
    int n = 0;

    // Test vals, only 31 may remain.
    for (int i = -9999; i < 9999; i++) {

        // Try-Catch values that won't work
        try {
            // Construct
            Day d = Day(i);

            // Check if constructor worked
            // If it did, increment
            n++;
        } catch (int err) {
            // Don't do anything
        }

    }

    // See if tezt succeeded
    return (n == MAX_DAYS);
}

bool test2_testDay() {
    Day d;
    int n = 0;

    constexpr int LOWER = -5,
                  UPPER = MAX_DAYS + 5;

    // Make a blank array
    std::string str = "";

    // Repeat for vals
    for (int i = LOWER; i < UPPER; i++) {
        // Make a string full of vals
        str += std::to_string(i) + " ";
    }

    // Make a string stream
    std::stringstream ss(str);

    // Put it to the test
    int i = LOWER;
    while(!ss.eof()) {
        try {
            // We will test
            ss >> d;

            // Test if it is equal to i
            n++;
        } catch (const std::invalid_argument& err) {
            // Check if the error handler works
            std::cout << "Test 2: Success\n";
        } catch (int err) {
            // Do nothing
        }

        // Increment val
        i++;
    }

    return true;
}

int main() {



    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass = test1_invalidDay();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test2_testDay();
    if (!pass) { return 1; }

    return !pass;
}
