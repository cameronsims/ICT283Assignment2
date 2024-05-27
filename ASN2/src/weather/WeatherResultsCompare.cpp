#include "WeatherResultsCompare.h"

bool operator< (const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r) {
    return l.month.getMonth() <  r.month.getMonth();
}

bool operator==(const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r) {
    return l.month.getMonth() == r.month.getMonth();
}

bool operator> (const asn2::weather::WeatherResults& l, const asn2::weather::WeatherResults& r) {
    return l.month.getMonth() >  r.month.getMonth();
}
