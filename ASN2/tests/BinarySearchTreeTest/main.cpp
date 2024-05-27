#include <iostream>

#include "../../src/bst/BinaryNode.h"
#include "../../src/bst/BinaryTree.h"
#include "../../src/bst/Bst.h"

typedef Bst<int> intBst;

// Parameters
constexpr int BEGIN = 0;
constexpr int START_NODE = 50;
constexpr int END = 100;

// Test 1
bool test1_insert(intBst& tree) {
    tree.insertNode(START_NODE);

    // Create a lot of inputs
    for (int i = BEGIN; i < END; i++) {
        try {
            // Add the i to the node
            tree.insertNode(i);
        } catch (const NodeExists& e) {
            // if we found a node which is not the starting node
            if (i != START_NODE)
                // Then we failed
                return false;
        }
    }

    return true;
}

// Test 2
bool test2_search(intBst& tree) {
    // After we've input all the values, check we can find all of them.
    for (int i = BEGIN; i < END; i++) {
        try {
            // Get the index
            tree.searchNode(i);
        } catch (const NodeNotFound& err) {
            return false;
        }
    }

    return true;
}

// Test 3
bool test3_delete(intBst& tree) {
    // Delete the left half of the node network
    tree.deleteNode(BEGIN);

    // Check if any of these values exist...
    // If they do, we failed
    for (int i = BEGIN; i < START_NODE; i++) {
        try {
            // The below should fail
            tree.searchNode(i);
            // if it didn't we failed
            return false;
        } catch (const NodeNotFound& err) {
            // This is the outcome we're expecting and want
        }
    }
    return true;
}


int main() {

    // Create a tree
    Bst<int> tree;

    bool status;

    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 1                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    status = test1_insert(tree);

    // if status is false
    if (!status) {
        return 1;
    }

    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 2                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    status = test2_search(tree);

    // if status is false
    if (!status) {
        return 2;
    }

    ///////////////////////////////////////////////////////////////////
    //                                                               //
    //                             Test 3                            //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

    status = test3_delete(tree);

    // if status is false
    if (!status) {
        return 3;
    }

    return 0;
}
