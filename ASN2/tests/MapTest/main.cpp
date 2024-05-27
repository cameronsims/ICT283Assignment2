#include <string>
#include <iostream>

#include "../../src/stl/Map.h"

// Size of the test
constexpr int SIZE = 256;

bool test1_insert(Map<int, int>& m) {
    // Insert the vals
    for (int i = 0; i < SIZE; i++) {
        // Make it n-i-1 to make it interesting
        m[ SIZE - (i + 1)] = i + 1;
    }

    // Return true if all is good
    return true;
}

bool test2_search(const Map<int, int>& m) {
    // Search all entered values
    for (int i = 0; i < SIZE; i++) {
        try {
            // Set it to a value
            int temp = m[i];
        } catch (const MapKeyNotFound& err) {
            // Can't find? its giving... ERROR!!!
            return false;
        }
    }

    return true;
}


int main() {
    // This is the map
    Map<int, int> m1;

    // This is the status of the program
    bool status;


    // Insert some values
    status = test1_insert(m1);

    // if status is false
    if (!status) {
        return 2;
    }



    // Search all values
    status = test2_search(m1);

    // if status is false
    if (!status) {
        return 3;
    }

    return 0;
}
