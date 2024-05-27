//WeatherLogType.h
#ifndef WeatherLogType_H
#define WeatherLogType_H

#include "WeatherRecType.h"
#include "WeatherResults.h"

#include "../date/year/YearCompare.h"
#include "../date/month/MonthCompare.h"

#include "../vector/Vector.h"
#include "../bst/iterative/BST.h"
#include "../stl/Map.h"

//namespace asn2 {
//namespace weather {

        /**
         * @author Cameron Sims
         * @date 14/04/2024
         * @brief Dynamic Array class that holds WeatherRecord
         *
         * @class WeatherLogType
         *
         */
    typedef Map<Year, Map<Month, Vector<asn2::weather::WeatherRecord>>> WeatherLogType;

    /// Sorted by months alone.
    typedef BinarySearchTree<asn2::weather::WeatherResults> WeatherBST;

    /// Has many years, with 12 months, relating to 1 record.
    typedef Map<Year, WeatherBST> WeatherCalender;

    /// Linear Vector for Weather Results
    typedef Vector<asn2::weather::WeatherRecord> WeatherVector;

//}
//}
//typedef Vector<WeatherRecord> WeatherLogType;

#endif // WeatherLogType_H
