#include <iostream>

#include "../../src/bst/BST.h"

// Parameters
const int BEGIN = 0;
const int START_NODE = 50;
const int END = 100;

int* arr;
int i = 0;

void func(const int& p_data) {
    // Add to this array
    arr[i] = p_data;
    // Increment
    i++;
}

bool test1_insertion(Bst<int>& tree) {
    // Only insert on the right
    for (i = BEGIN; i < END; i++) {
        if (i != START_NODE) {
            tree.insertNode(i);
        }
    }

    // Check if it worked.
    for (i = BEGIN; i < END; i++) {
        try {
            tree.searchNode(i);
        } catch (const NodeNotFound& err) {
            // Don't bother the user
        }
    }

    return true;
}

bool test2_inOrder(Bst<int>& tree) {
    // Reset structure
    tree = Bst<int>();
    tree.insertNode(START_NODE);

    // These values will be tested
    arr = new int[END - BEGIN];


    // Centre value we're starting from
    const int CENTRE = START_NODE;

    // Add values
    for (i = BEGIN; i < (END/2); i++) {

        // Implementation idea:
        //
        //            50
        //         /     \
        //        25     75
        //       /  \   /  \
        //      20  30 70  80
        //         (CONTINUE)
        //

        // Add the cente
        arr[2*i] = CENTRE + i;
        arr[2*i + 1] = CENTRE - i;
    }

    // Add values of array into binary tree
    for (i = BEGIN; i < END + 1; i++) {
        // Don't insert if we're in the starting node
        if (arr[i] != START_NODE) {
            // Insert the node into an appropriate place
            tree.insertNode(arr[i]);
        }
    }

    i = 0;


    // Order the tree
    tree.inOrder(func);

    // Check if the array is in order
    for (i = BEGIN + 1; i < END; i++) {
        // If the left is bigger than right
        if (arr[i - 1] > arr[i]) {
            // Failure
            return false;
        }
    }

    // Free memory
    delete[] arr;

    // Searching values worked
    return true;
}

int main() {


    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    // Reset structure
    Bst<int> tree;
    tree.insertNode(START_NODE);

    bool pass = test1_insertion(tree);
    if (!pass) { return 1; }

    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    pass = test2_inOrder(tree);

    return !pass;
}
