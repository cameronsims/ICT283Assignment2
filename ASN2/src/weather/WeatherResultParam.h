// WeatherResultParam.h

namespace asn2 {
namespace weather {

       /**
        * @author Cameron Sims
        * @date 19/05/2024
        *
        * @class WeatherResultStat
        * @brief Used to accord to a parameter to a stats calc
        */
    struct WeatherResultStat {
        /// The mean of the stat
        float mean;

        /// The standard deviation of the stat
        float stdev;

        /// The mean absolute deviation of the stat
        float mad;
};

}}
