#include "MapExceptions.h"

const char* MapKeyNotFound::what() const {
    return "Map Key not found.\n";
}
