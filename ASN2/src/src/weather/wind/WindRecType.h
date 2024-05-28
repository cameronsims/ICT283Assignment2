#ifndef WindRecord_H
#define WindRecord_H

#include "../../timestamp/TimeStamp.h"

namespace asn2 {
namespace weather {

        /**
         * @author Cameron Sims
         * @date 14/04/2024
         * @brief A record of wind in a specific point in time
         *
         * @class WindRecord
         *
         */
    struct WindRecord {
      public:
        // /// Date that the record was recorded (DD/MM/YYYY)
        // Date d;
        // /// Time of the day that the record was observed (HH:MM)
        // Time t;

            /**
             * @brief To create a struct with nullptr
             */
        WindRecord();

            /**
             * @brief To copy a record
             * @param p_record The record we're copying
             */
        WindRecord(const WindRecord& p_record);

            /**
             * @brief To copy a record
             * @param p_record The record we're copying
             */
        WindRecord& operator= (const WindRecord& p_record);

            /**
             * @brief To set pointers to nullptr
             */
        virtual ~WindRecord();

        /// The date and time that the record was taken
        TimeStamp timestamp;

        /// Ambient Air Temperature of the air (degrees Celcius)
        float* airTemp = nullptr;

        /// Wind speed of the wind
        float* speed = nullptr;
    };

}
}

// WeatherLogType is in "WeatherLogType.h"

#endif // WeatherRecord_H
