#ifndef WeatherRecordCOMPARE_H
#define WeatherRecordCOMPARE_H

#include "WeatherRecType.h"

bool operator==(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);
bool operator!=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);

bool operator< (const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);
bool operator> (const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);

bool operator<=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);
bool operator>=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right);

#endif // WeatherRecordCOMPARE_H
