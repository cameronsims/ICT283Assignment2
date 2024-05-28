// WeatherConvert.h
#ifndef WEATHERCONVERT_H
#define WEATHERCONVERT_H

// Some Data Structures
#include "../stl/Map.h"
#include "../vector/Vector.h"
#include "../bst/iterative/BST.h"

// Original Struct
#include "./WeatherRecType.h"
#include "./WeatherLogType.h"
#include "./WeatherResults.h"

// /**
// * @author Cameron Sims
// * @date 17/05/2024
// *
// * @fn weather_pack
// * @brief Optimise so that it represents numerous types of it's self. (Mean, STDEV, sPCC, MAD)
// *
// * @param p_records The records we're going to be "packing"
// * @returns The results of the records that under go various mathematical operations, will be a vector of 12 size
// */
//Vector<WeatherResults> weather_pack(const WeatherRecord* p_records, size_t p_size);

namespace asn2 {
namespace weather {

        /**
         * @author Cameron Sims
         * @date 17/05/2024
         *
         * @fn read_month
         * @param p_map The year map we're reading
         * @param p_calender The calendar we're reading
         * @param p_year The we're reading from
         */
    void read_month(const Map<Month, WeatherVector>& p_map, WeatherCalender& p_calender, const Year& p_year);

        /**
        * @author Cameron Sims
        * @date 17/05/2024
        *
        * @fn calenderise
        * @brief Optimise so that one month represents one record
        * @param p_records The records we're going to be "calenderising"
        * @returns WeatherCalender of all the previous records
        */
    WeatherCalender calenderise(const WeatherLogType& p_records);

        /**
        * @author Cameron Sims
        * @date 18/05/2024
        *
        * @fn consolidate
        * @brief Set a vector filled of several parts and set it to one results
        * @param p_records The records we're going to be "calenderising"
        * @returns WeatherResults which is a consolidated amount of several
        */
    WeatherResults consolidate(const WeatherVector& p_records);

        /**
        * @author Cameron Sims
        * @date 28/05/2024
        *
        * @fn merge
        * @param p_result The result we're merging into
        * @param p_month The month the result was taken on
        * @param p_speeds A vector containing speeds
        * @param p_temper A vector containing temperatures
        * @param p_solarRads Solar Radiations
        * @brief Uses the stats routines and merges it into the vector
        */
    void merge(WeatherResults& p_result, const Month& p_month, const Vector<float>& p_speeds, const Vector<float>& p_temper, float p_solarRads);

}
}

#endif // WEATHERCONVERT_H
