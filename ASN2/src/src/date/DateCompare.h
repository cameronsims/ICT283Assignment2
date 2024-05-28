#ifndef DATECOMPARE_H
#define DATECOMPARE_H

#include "Date.h"

bool operator==(const Date& p_left, const Date& p_right);
bool operator!=(const Date& p_left, const Date& p_right);

bool operator< (const Date& p_left, const Date& p_right);
bool operator> (const Date& p_left, const Date& p_right);

bool operator<=(const Date& p_left, const Date& p_right);
bool operator>=(const Date& p_left, const Date& p_right);

#endif // DATECOMPARE_H
