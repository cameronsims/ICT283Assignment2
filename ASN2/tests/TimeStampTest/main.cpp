#include <iostream>

#include "../../src/timestamp/TimeStamp.h"
#include "../../src/timestamp/TimeStampIO.h"
#include "../../src/timestamp/TimeStampCompare.h"

// Create custom incrementor
TimeStamp& operator++(TimeStamp& ts, int) {
    int min = ts.time.getMinutes(),
        hr = ts.time.getHour(),
        d = ts.date.getDay(),
        m = ts.date.getMonth(),
        y = ts.date.getYear();

    {
        // Increment min
        min++;

        if (min > 59) {
            // Set it back to 0
            min = 0;

            // Increment the hour
            hr++;

            // If hour has reached max
            if (hr > 23) {
                // Reset the hour
                hr = 0;

                // Increment the day
                d++;

                // If day has reached max
                try {
                    // Check if the new day is valid
                    Date(d, m, y);

                    // If it is don't do anything further
                }
                // If it is not a valid day
                catch (const InvalidDay& e) {
                    // Reset the day
                    d = 1;

                    // Then we want to check the month
                    try {
                        Date(d, m, y);
                    } catch (const InvalidMonth& e) {
                        // Then reset the month
                        m = 1;
                        y++;
                    }
                }
            }
        }
    }

    ts = TimeStamp(Date(d, m, y), Time(hr, min));
}

bool test1_validTest() {
    // 1440 (min/day) * 365 (day/year) * 4 (years) + 1 day for a leap year
    const int SIZE = 1440;//4*365*1440 + 1440;

    bool pass = true;

    // Create some memory
    TimeStamp* arr = new TimeStamp[SIZE];

    // These represent where we are in the date
    int d = 1, m = 1, y = 2000;
    int hr = 0, min = 0;

    // This is the class we're setting
    TimeStamp ts(Date(d, m, y), Time(hr, min));

    // Make a very long amount of timestamps
    for (int i = 0; i < SIZE; i++) {
        // Make element parts
        Time time(hr, min);
        Date date(d, m, y);

        // Create element
        arr[i] = ts;

        // Increment the class
        ts++;

    }

    // Check to see if the array is in order
    for (int i = 1; i < SIZE; i++) {
        // If the one behind is bigger, we failed...
        if (arr[i - 1] > arr[i]) {
            pass = false;
        }
    }

    // Free memory
    delete[] arr;

    return pass;
}

int main() {

    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    return !test1_validTest();
}
