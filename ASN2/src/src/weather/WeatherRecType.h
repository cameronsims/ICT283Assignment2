#ifndef WeatherRecord_H
#define WeatherRecord_H

#include "./wind/WindRecType.h"

namespace asn2 {
namespace weather {

        /**
         * @author Cameron Sims
         * @date 14/04/2024
         * @brief A record of wind in a specific point in time
         *
         * @class WeatherRecord
         *
         */
    struct WeatherRecord : public WindRecord {
        // Inheirts a few from WindRecord.

            /**
             * @brief To create a struct with nullptr
             */
        WeatherRecord();

            /**
             * @brief To copy a record
             * @param p_record The record we're copying
             */
        WeatherRecord(const WeatherRecord& p_record);

            /**
             * @brief To copy a record
             * @param p_record The record we're copying
             */
        WeatherRecord& operator= (const WeatherRecord& p_record);

            /**
             * @brief To set pointers to nullptr
             */
         virtual ~WeatherRecord();

        /// Radiation that the sun gave (W/m^2) [Watts per square meter]
        int* solarRad = nullptr;
    };
}
}

// WeatherLogType is in "WeatherLogType.h"

#endif // WeatherRecord_H
