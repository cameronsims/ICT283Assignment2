#include "BinaryTreeExceptions.h"

const char* NodeError::what() const {
    return "Node Error!";
}

const char* NodeExists::what() const {
    return "Node Exists!";
}

const char* NodeNotFound::what() const {
    return "Node Not Found!";
}

const char* NodeCantDelete::what() const {
    return "Can't delete root node.";
}
