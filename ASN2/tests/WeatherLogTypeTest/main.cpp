#include <iostream>

#include "../../src/weather/WeatherLogType.h"
#include "../../src/Sort.h"

#include "../../src/date/DateIO.h"
#include "../../src/time/TimeIO.h"

#include "../../src/timestamp/TimeStamp.h"
#include "../../src/timestamp/TimeStampIO.h"
#include "../../src/timestamp/TimeStampCompare.h"

int main() {

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    WeatherLogType v1(31*12*2);

    // WELCOME TO ITERATOR HELL //

    // For year
    for (int i = 2; i > 0; i--) {
        // For months
        for (int j = 12; j > 0; j--) {
            // For day
            for (int k = 31; k > 0; k--) {
                // Make date
                Date d = Date(k, j, 2000 + i);

                // Make time
                for (int l = 20; l > 0; l -= 5) {
                    // For minutes
                    for (int m = 50; m > 0; m -= 10) {
                        Time t = Time(l, m);

                        // FINALLY, ADD THE VALUE
                        WeatherRecord record;
                        record.timestamp = TimeStamp(d, t);

                        v1.push(record);
                    }
                }

            }
        }
    }

    // Show first and last
    std::cout << v1.size() << ": " << v1[0].timestamp << "-" << v1[v1.size() - 1].timestamp << "\n";

    // Sort it
    sort(v1);

    // Show first and last
    std::cout << v1.size() << ": " << v1[0].timestamp << "-" << v1[v1.size() - 1].timestamp << "\n";

    // Check if it is sorted
    bool sorted = true;
    for (int i = 1; i < v1.size(); i++) {
        // MORE NESTING HELL
        if (v1[i - 1].timestamp > v1[i].timestamp) {
            sorted = false;
        }
    }

    // Check if the test was a success (if the program hasn't crashed
    std::cout << "Test 1: " << ((sorted) ? "Success" : "Failure") << "\n";

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    // TEST AFTER BEING SORTED

    // Check if it is sorted
    sorted = true;

    sort(v1);

    for (int i = 1; i < v1.size(); i++) {

        // MORE NESTING HELL
        if (v1[i - 1].timestamp > v1[i - 1].timestamp) {
            sorted = false;
            break;
        }
    }

    std::cout << "Test 2: " << ((sorted) ? "Success" : "Failure") << "\n";



    return 0;
}
