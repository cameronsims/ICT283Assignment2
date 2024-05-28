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
     * @class VectorOverride
     * @brief A child class of a Vector, which default constructor calls a bigger size to optimise the program
     */
template<class T>
class VectorOverride : public Vector<T> {
public:
    /**
     * @brief Default Constructor
     */
    VectorOverride();
};

template<class T>
VectorOverride<T>::VectorOverride() : Vector<T>(31*24*60) {}



/// Linear Vector for Weather Results
typedef VectorOverride<asn2::weather::WeatherRecord> WeatherVector;



    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Dynamic Array class that holds WeatherRecord
     *
     * @class WeatherLogType
     *
     */
typedef Map<Year, Map<Month, WeatherVector>> WeatherLogType;



/// Sorted by months alone.
typedef BinarySearchTree<asn2::weather::WeatherResults> WeatherBST;




/// Has many years, with 12 months, relating to 1 record.
typedef Map<Year, WeatherBST> WeatherCalender;

//}
//}
//typedef Vector<WeatherRecord> WeatherLogType;

#endif // WeatherLogType_H
