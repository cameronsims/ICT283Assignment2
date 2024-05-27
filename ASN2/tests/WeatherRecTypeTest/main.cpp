#include <iostream>

#include "../../src/weather/WeatherRecType.h"

using namespace asn2::weather;

int main() {
    WeatherRecord record;

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    // Loop for a whole lot of negative/lower than 100 values
    int n = 0;
    bool working = true;
    for (int i = -9999; i < 99; i++) {
        // Cast i to float to clean code
        const float f = (float)i;

        // NOTE: WE ARE NOT TESTING DATE AND TIME HERE DUE TO THEIR TESTING PROJECTS

        // If solar radiations is working and gives a negative output, then the program has failed
        // If all the others fail, then the program has also failed
        record.solarRad = new int(i);
        record.airTemp = new float(f);
        record.speed = new float(f);

        // Set to fail
        if ((*record.solarRad != i) || *record.airTemp != f || *record.speed != f) {
            // Say so
            working = false;
            break;
        }

        delete record.solarRad;
        delete record.airTemp;
        delete record.speed;
    }

    // Check if the test was a success (if the program hasn't crashed
    std::cout << "Test 1: " << ((working) ? "Success" : "Failure") << "\n";


    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    n = 0;
    working = true;

    for (int i = 100; i < 9999; i++) {
        // Cast i to float to clean code
        const float f = (float)i;

        // NOTE: WE ARE NOT TESTING DATE AND TIME HERE DUE TO THEIR TESTING PROJECTS

        // If solar radiations is working and gives a negative output, then the program has failed
        // If all the others fail, then the program has also failed
        record.solarRad = new int(i);
        record.airTemp = new float(f);
        record.speed = new float(f);

        // Set to fail
        if ((*record.solarRad != i && i != 0) || *record.airTemp != f || *record.speed != f) {
            // Say so
            working = false;
            break;
        }

        delete record.solarRad;
        delete record.airTemp;
        delete record.speed;
    }

    // Check if the test was a success (if the program hasn't crashed
    std::cout << "Test 2: " << ((working) ? "Success" : "Failure") << "\n";

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    // Test for all unvalid/valid dates
    const int UNIQUE_DAYS = 31*12;

    n = 0;
    working = true;

    Date d;

    // Loop months
    for (int i = -99; i < 99; i++) {
        // Loop days
        for (int j = -99; j < 99; j++) {

            try {
                // Generate new date
                d = Date(j, i, -1);

                // See if it works
                record.timestamp.date = Date(d);

                // Increase, if catch not called
                n++;
            } catch (const InvalidDate& err) {
                // Don't do anything
            }
        }
    }

    // if we got the amount of unique days
    working = (n == UNIQUE_DAYS);

    // Check if the test was a success (if the program hasn't crashed
    std::cout << "Test 3: " << ((working) ? "Success" : "Failure") << "\n";


    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 4                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    const int UNIQUE_TIMES = 24*60;

    n = 0;
    working = true;

    Time time;

    // check for times

    // Loop for hours
    for (int i = -99; i < 99; i++) {
        // Loop days
        for (int j = -99; j < 99; j++) {

            try {// set time
                time = Time(i, j);

                // See if it works
                record.timestamp.time = Time(time);

                // Increase
                n++;
            } catch (InvalidTime& err) {
                // Do nothing
            }
        }
    }

    // if we got the amount of unique days
    working = (n == UNIQUE_TIMES);

    // Check if the test was a success (if the program hasn't crashed
    std::cout << "Test 4: " << ((working) ? "Success" : "Failure") << "\n";

    return 0;
}
