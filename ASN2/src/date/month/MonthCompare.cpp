#include "MonthCompare.h"

bool operator< (const Month& l, const Month& r) {
    return l.getMonth() < r.getMonth();
}

bool operator==(const Month& l, const Month& r) {
    return l.getMonth() == r.getMonth();
}

bool operator> (const Month& l, const Month& r) {
    return l.getMonth() > r.getMonth();
}

