#ifndef TIMESTAMPCOMPARE_H
#define TIMESTAMPCOMPARE_H

#include "TimeStamp.h"

bool operator==(const TimeStamp& p_left, const TimeStamp& p_right);
bool operator!=(const TimeStamp& p_left, const TimeStamp& p_right);

bool operator< (const TimeStamp& p_left, const TimeStamp& p_right);
bool operator> (const TimeStamp& p_left, const TimeStamp& p_right);

bool operator<=(const TimeStamp& p_left, const TimeStamp& p_right);
bool operator>=(const TimeStamp& p_left, const TimeStamp& p_right);

#endif // TIMESTAMPCOMPARE_H
