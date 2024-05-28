#include "VectorExceptions.h"

const char* VectorError::what() const {
    return "Vector Error";
}

const char* VectorOutOfRange::what() const {
    return "Vector Out of Range";
}
