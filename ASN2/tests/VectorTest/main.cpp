#include <iostream>
#include <cmath>

#include "../../src/Vector.h"

// Bounds
constexpr int LOWER = -9999,
              UPPER = 9999;



bool test1_inserting(Vector<float>& v) {
    // Push a LOT of values
    for (int i = LOWER; i < UPPER; i++) {
        v.push((float)i);
    }

    // Show test 1 status
    return (v.size() == (UPPER - LOWER));
}

bool test2_check(Vector<float>& v) {
    // Create a new vector
    Vector<float> v2;

    // Create some vals
    for (int i = -10; i < 10; i++) {
        // Push-back values
        v2.push((float)i);
    }

    // Boolean to check if they're the same
    bool isSame = true;

    // Assign
    v = v2;

    // Check that they're the same
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != v2[i]) {
            // They're not the same
            isSame = false;
        }
    }

    return isSame;
}

bool test3_contigiousCheck() {
    // Create a new vector
    Vector<int> v3;

    // Create some random vals
    for (int i = LOWER; i < UPPER; i++) {
        v3.push(i);
    }
    // Check that all values are contingous
    for (int i = 0; i < v3.size() - 1; i++) {
        // If values aren't contigous
        if (v3[i] != (v3[i + 1] - 1)) {
            return false;
        }
    }

    return true;
}

bool test4_swapping() {
    // Inverse the vector
    Vector<float> v4(100000);
    // Loop vals
    for (int i = 0; i < 100000 - 1; i++) {
        // Assign to iteration
        v4[i] = i;
    }

    // Now we are going to reverse
    float temp;

    for (int i = 0; i < floor(v4.size() / 2); i++) {
        // get the index of the opposite side
        const int opp = (v4.size() - 1) - i;
        // Swap the values
        temp = v4[opp];
        v4[opp] = v4[i];
        v4[i] = temp;


    }

    // Check if it worked
    for (int i = 0; i < v4.size() - 1; i++) {
        // If the next value is bigger, than cancel the loop
        if (v4[i] < v4[i + 1]) {
            return false;
        }
    }
    return true;
}

bool test5_outofboundscheck() {
    Vector<float> v5(10);

    v5[16] = 16.0f;
    return (v5.size() == 16 + 1);

}

bool test6_sizecheck() {
    Vector<float> v6;

    try {
        v6 = Vector<float>(0);
    }
    catch (VectorOutOfRange err) {

    }
    return v6.size() == 0;
}

bool test7_negativeSize() {
    Vector<float> v7;

    try {
        v7 = Vector<float>(-1);
    }
    catch (const VectorOutOfRange& err) {

    }

    return (v7.size() != -1);
}




int main() {
    // Set vector to 8
    Vector<float> v(8);




    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    bool pass = test1_inserting(v);
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test2_check(v);
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test3_contigiousCheck();
    if (!pass) { return 1; }


    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 4                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    // Inverse the vector
    pass = test4_swapping();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 5                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    // Inverse the vector
    pass = test5_outofboundscheck();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 6                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test6_sizecheck();
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 7                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    pass = test7_negativeSize();
    if (!pass) { return 1; }

    return 0;
}
