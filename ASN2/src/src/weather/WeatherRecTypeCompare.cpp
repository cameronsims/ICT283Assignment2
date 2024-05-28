#include "WeatherRecTypeCompare.h"

#include "../timestamp/TimeStampCompare.h"

bool operator==(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    // Return true if both time and date are the same
    return (p_left.timestamp == p_right.timestamp);
}

bool operator!=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    return !( p_left == p_right );
}

bool operator< (const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    return p_left.timestamp < p_right.timestamp;
}

bool operator> (const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    return p_left.timestamp > p_right.timestamp;
}

bool operator<=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    return !( p_left > p_right );
}

bool operator>=(const asn2::weather::WeatherRecord& p_left, const asn2::weather::WeatherRecord& p_right) {
    return !( p_left < p_right);
}
