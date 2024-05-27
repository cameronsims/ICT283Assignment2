#ifndef MONTHCOMPARE_H
#define MONTHCOMPARE_H

#include "Month.h"

bool operator< (const Month& l, const Month& r);
bool operator==(const Month& l, const Month& r);
bool operator> (const Month& l, const Month& r);

#endif // MONTHCOMPARE_H
