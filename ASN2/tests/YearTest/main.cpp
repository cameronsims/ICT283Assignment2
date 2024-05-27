#include "../../src/date/year/Year.h"
#include "../../src/date/year/YearIO.h"

#include <string>
#include <sstream>
#include <iostream>

bool test1_stream() {
    std::string str = "";

    Year y;

    for (int i = -9999; i < 9999; i++) {
        // Make a new int
        str = std::to_string(i);

        // Make a stringstream
        std::stringstream ss(str);

        // Add these to a year
        ss >> y;
    }

    return true;
}

bool test2_invalid() {
    Year y;
    // Loop for a range of vals
    bool err = false;
    for (int i = -9999; i < 9999; i++) {
        // Make the constructor
        y = Year(i);
        // If it didn't work
        if (y.getYear() != i) {
            // FLAG IT
            return false;
        }
    }

    // Test if the getters and setters work
    // Check if the test was a success
    return true;
}

int main() {

    // Since we will consider all values for the year,
    // we will just test the IO capabilities, since the Year class
    // is essentially just a wrapper for "int"


    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass = test1_stream();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    test2_invalid();
    if (!pass) { return 1; }

    return 0;
}
