#ifndef YEARCOMPARE_H
#define YEARCOMPARE_H

#include "Year.h"

bool operator< (const Year& l, const Year& r);
bool operator==(const Year& l, const Year& r);
bool operator> (const Year& l, const Year& r);

#endif // YEARCOMPARE_H
