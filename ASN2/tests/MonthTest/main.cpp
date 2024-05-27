#include <iostream>
#include <string>
#include <sstream>

#include "../../src/date/month/Month.h"
#include "../../src/date/month/MonthIO.h"

// Default Constructor
const Month def;
constexpr int MAX_MONTHS = 12;


bool test1_invalidMonth() {
    // Loop through values, should only trigger 12 times
    int n = 0;
    for (int i = -9999; i < 9999; i++) {
        // Try-catch the constructor
        try {
            Month m = Month(i);
            // If the constructor worked, increase n
            std::cout << m << " ";
            // Increment
            n++;
        } catch (int err) {
            // Do nothing
        }
    }

    // Check if the test was a success
    return (n == MAX_MONTHS);
}

bool test2_streams() {
    // Make a loop will of values that'll be used for the iostream
    std::string str = "";
    for (int i = -5; i < MAX_MONTHS + 5; i++) {
        // Add to string
        str += std::to_string(i) + " ";
    }

    // Assign a stringstream
    std::stringstream ss(str);

    // Make a month class
    Month m;

    // Reset the number
    int n = 0;
    int i = -5;

    // Make a try for the last /
    try {
        // While the stringstream is going on
        while (!ss.eof()) {
            // Try
            try {
                // Create a object
                ss >> m;

                // Check if valid inputs were input
                n++;
            } catch (const InvalidMonth& err) {
                // Do nothing
            }
            // Increase value
            i++;
        }
    } catch (const std::invalid_argument& err) {
        // Ensure we are able to catch it
        return true;
    }

    return false;
}


int main() {



    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass = test1_invalidMonth();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                           Test 2/3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test2_streams();
    if (!pass) { return 1; }

    return !pass;
}
