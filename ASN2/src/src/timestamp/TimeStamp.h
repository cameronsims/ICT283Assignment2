#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include "../date/Date.h"
#include "../time/Time.h"

   /**
    * @author Cameron Sims
    * @date 05/05/2024
    * @brief A time in a day at a point in a year
    *
    * @class TimeStamp
    *
    */
struct TimeStamp {
        /**
         * @brief Default Constructor to stop compiler from whining
         */
    TimeStamp();

    /// The time of the time stamp
    Time time;

	/// The date of the time stamp
    Date date;
};

#endif // TIMESTAMP_H
