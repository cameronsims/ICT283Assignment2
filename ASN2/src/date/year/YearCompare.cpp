#include "YearCompare.h"

bool operator< (const Year& l, const Year& r) {
    return l.getYear() < r.getYear();
}

bool operator==(const Year& l, const Year& r) {
    return l.getYear() == r.getYear();
}

bool operator> (const Year& l, const Year& r) {
    return l.getYear() > r.getYear();
}

