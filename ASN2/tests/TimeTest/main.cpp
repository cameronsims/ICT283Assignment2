#include <iostream>

#include "./../../src/Time/Time.h"
#include "./../../src/Time/TimeIO.h"

#include <iostream>
#include <sstream>


bool test1_hourTest() {

    Time t1, t2, t3;

    std::stringstream ss("01:05");

    ss >> t1;

    t2 = t1;
    t3 = t1;

    t2.setHour(12);

    return (t2.getHour() == 12);
}

bool test2_minuteTest() {
    Time t1;
    t1.setMinutes(59);
    return (t1.getMinutes() == 59);
}

bool test3_invalidTest() {
    Time t1;
    int n = 0;
    // Loop through hours
    for (int i = -99; i < 99; i++) {
        // Loop through minutes
        for (int j = -99; j < 99; j++) {
            // Try to do the following
            try {
                // Create a time
                t1 = Time(i, j);

                // Increment if there was no error
                n++;
            }
            // Catch an int error
            catch (InvalidTime& err) {
                // Do nothing
            }
        }
    }

    return (n == 24*60);
}


int main() {
    Time t1, t2, t3;

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                           Test  1/2                           //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass =test1_hourTest();

    if (!pass) { return 1; }

    pass = test2_minuteTest();

    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test3_invalidTest();


    return !pass;
}
