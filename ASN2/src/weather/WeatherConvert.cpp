// WeatherConvert.cpp
#include "./WeatherConvert.h"
#include "../maths/mathvector.h"

#include "./WeatherRecTypeCompare.h"
#include "./WeatherResultsCompare.h"


//Vector<WeatherResults> weather_pack(const WeatherRecType* p_records, size_t p_size) {
//    // The results of various months
//    WeatherResults results;
//   return results;
//}

// The purpose of the following comments is no longer needed as the code has been deprecated...
// However I feel it is an important message to keep for the younger generations.
//
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C
// I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C I HATE C

void asn2::weather::read_month(const Map<Month, Vector<WeatherRecord>> p_map, WeatherCalender& p_calender, const Year& p_year) {
    // For all months
    for (MapIteratorConst<const Month, Vector<WeatherRecord>> it = p_map.begin(); it != p_map.end(); it++) {
        // The vector we're reading
        const Vector<WeatherRecord>& recs = it->second;
        // Compile the vector
        WeatherResults result = asn2::weather::consolidate(recs);
        try {
            p_calender[ p_year.getYear() ].insertNode(result);
        } catch (const NodeExists& err) {
            // Ignore, this should never be called but we can never be too sure.
        }
    }
}

WeatherCalender asn2::weather::calenderise(const WeatherLogType& p_records) {

    // The calender we're using...
    WeatherCalender calender;

    // Result structure
    WeatherResults result;

    // This is used to optimise the code for the pearson's segment
    size_t amountOfYears = 1;

    // Loop ALL years in the record
    try {
        for (MapIteratorConst<const Year, Map<Month, Vector<WeatherRecord>>> yit = p_records.begin(); yit != p_records.end(); yit++) {
            // We now need to iterate all months over all years...
            const Year& y = yit->first;

            // This is the second map we are iterating
            const Map<Month, Vector<WeatherRecord>>& mp = yit->second;

            // For all months
            read_month(mp, calender, y);
            // increment the amount of years
            amountOfYears++;
        }
    } catch (const VectorOutOfRange& e) {
        // Don't do anything, there is no value for month
    }

    // Now that we've compiled everything...
    const size_t MAX_SIZE = 24*60*31*amountOfYears;

    for (int i = 0; i < 12; i++) {
        // We want to refresh memory every loop
        Vector<float> speeds(MAX_SIZE);
        Vector<float> temps (MAX_SIZE);
        Vector<float> solrad(MAX_SIZE);

        // For all years
        for (auto yit = p_records.begin(); yit != p_records.end(); yit++) {
            // Catch if not in year
            try {
                // Test if we have the record in file
                const Vector<WeatherRecord>& records = (yit->second)[Month(i + 1)];

                // If it does (should be thrown otherwise)
                for (size_t j = 0; j < records.size(); j++) {
                    // Add this to our vectors
                    const asn2::weather::WeatherRecord& rec = records[j];

                    // If speed exists
                    if (rec.speed != nullptr) {
                        speeds.push( (*rec.speed) );
                    }

                    // If air temp exists
                    if (rec.airTemp != nullptr) {
                        temps.push( (*rec.airTemp) );
                    }

                    // If solar radiation exists
                    if (rec.solarRad != nullptr) {
                        solrad.push( (float)(*rec.solarRad) );
                    }
                }
            }
            // If no month was detected
            catch (const MapKeyNotFound& err) {
                // Don't do anything, mistakes can happen without bugging user
            }
        }

        // After the checks, start adding
        WeatherResults::pcc_st[i] = asn2::math::pearsonCorrolation(speeds, temps );
        WeatherResults::pcc_sr[i] = asn2::math::pearsonCorrolation(speeds, solrad);
        WeatherResults::pcc_tr[i] = asn2::math::pearsonCorrolation(temps,  solrad);
    }


    // Return the results
    return calender;
}

asn2::weather::WeatherResults asn2::weather::consolidate(const WeatherVector& p_records) {
    // Then consolodate all prior records
    WeatherResults result;

    // The amount of elements
    const size_t n = p_records.size();

    // The elements of the class we want
    Vector<float> speeds(n);
    Vector<float> temper(n);
    float solarRads = 0.0f;

    // For all the records
    for (size_t i = 0; i < n; i++) {
        // Add to all
        const asn2::weather::WeatherRecord& record = p_records[i];

        // If the record has a speed recorded...
        if (record.speed != nullptr) {
            speeds.push(         (*record.speed)    );
        }

        // If the record has an air temperature recorded...
        if (record.airTemp != nullptr) {
            temper.push(         (*record.airTemp)  );
        }

        // If the record has a solar rad detected
        if (record.solarRad != nullptr) {
            // If not at least 100
            if ((*record.solarRad) >= 100) {
                solarRads += (float)(*record.solarRad);
            }
        }
    }

    // If vector is bigger than size
    if (n > 0) {
        // Get elemetns into result
        result.month = p_records[0].timestamp.date.getMonth();
        result.solarRadiation = ((solarRads / 6.0f) / 1000.0f);

        // If we recorded speeds
        if (speeds.size() > 0) {
            result.speed = new WeatherResultStat;
            // Convert to km/h
            result.speed->mean  = asn2::math::mean                 (speeds) * (3.6f);
            result.speed->stdev = asn2::math::standardDeviation    (speeds);
            result.speed->mad   = asn2::math::meanAbsoluteDeviation(speeds);
        }

        // If we recorded temperature
        if (temper.size() > 0) {
            result.temperature = new WeatherResultStat;
            result.temperature->mean   = asn2::math::mean                 (temper);
            result.temperature->stdev  = asn2::math::standardDeviation    (temper);
            result.temperature->mad    = asn2::math::meanAbsoluteDeviation(temper);
        }
    }

    return result;
}
