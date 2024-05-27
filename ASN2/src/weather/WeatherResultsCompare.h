#ifndef WEATHERRESULTCOMPARE_H
#define WEATHERRESULTCOMPARE_H

#include "WeatherResults.h"

bool operator< (const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r);

bool operator==(const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r);

bool operator> (const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r);


#endif // WEATHERRESULTCOMPARE_H
