#ifndef TIMECOMPARE_H
#define TIMECOMPARE_H

#include "./Time.h"


bool operator==(const Time& p_left, const Time& p_right);
bool operator!=(const Time& p_left, const Time& p_right);

bool operator< (const Time& p_left, const Time& p_right);
bool operator> (const Time& p_left, const Time& p_right);

bool operator<=(const Time& p_left, const Time& p_right);
bool operator>=(const Time& p_left, const Time& p_right);


#endif // TIMECOMPARE_H
