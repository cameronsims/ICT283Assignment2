#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <iostream>

#include "../vector/Vector.h"

#include <cmath>

namespace asn2 {
namespace math {

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn coeff
         * @tparam T The type we're using
         * @brief The coefficent variable
         * @returns The co-efficent of how related the two vectors are
         *
         * @param p_vectorX The first vector we're using
         * @param p_vectorY The second vector we're using
         */
    template<typename T>
    T coeff(const Vector<T>& p_vectorX, const Vector<T>& p_vectorY);

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn mean
         * @tparam T The type we're using
         * @brief The mean of all variables
         * @returns The mean of the vector elements
         *
         * @param p_vector The vector we're using to get the mean
         */
    template<typename T>
    T mean(const Vector<T>& p_vector);

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn variance
         * @tparam T The type we're using
         * @brief The variance of all variables
         * @returns The variance of the vector elements
         *
         * @param p_vector The vector we're getting the variance of
         */
    template<typename T>
    T variance(const Vector<T>& p_vector);

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn standardDeviation
         * @tparam T The type we're using
         * @brief The standard deviation of all variables
         * @returns The standard deviation of the vector elements
         *
         * @param p_vector The vector we're getting the standard deviation, squareroot of the variance
         */
    template<typename T>
    T standardDeviation(const Vector<T>& p_vector);

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn pearsonCorrolation
         * @tparam T The type we're using
         * @brief The pearson corrolation of all variables
         * @returns The pearson corrolation of the vector elements
         *
         * @param p_vectorX The first vector we're using
         * @param p_vectorY The second vector we're using
         */
    template<typename T>
    T pearsonCorrolation(const Vector<T>& p_vectorX, const Vector<T>& p_vectorY);

        /**
         * @author Cameron Sims
         * @date 05/05/2024
         *
         * @fn meanAbsoluteDeviation
         * @tparam T The type we're using
         * @brief The mean absolute deviation of all variables
         * @returns The mean absolute deviation of the vector elements
         *
         * @param p_vectorX The vector we're using
         */
    template<typename T>
    T meanAbsoluteDeviation(const Vector<T>& p_vector);

}
}








// Implementation

template<typename T>
T asn2::math::coeff(const Vector<T>& p_vectorX, const Vector<T>& p_vectorY) {
    // Sample size
    size_t n = (p_vectorX.size() < p_vectorY.size()) ? p_vectorX.size() : p_vectorY.size();

    // Mean of X
    const T meanX = mean(p_vectorX);

    // Mean of Y
    const T meanY = mean(p_vectorY);

    // The sum we're returning
    T sum = T();

    // n sigma i = 1
    for (size_t i = 0; i < n; i++) {
        // (x[i] - xMean) * (y[i] - yMean)
        sum += (p_vectorX[i] - meanX)*(p_vectorY[i] - meanY);
    }

    // Return the sum of the co-efficents
    return sum;
}

template<typename T>
T asn2::math::mean(const Vector<T>& p_vector) {
    // The size of the vector
    const size_t n = p_vector.size();

    // Create the type
    T sum = T();

    // For all the values
    for (size_t i = 0; i < n; i++) {
        // Add "this" to the temp values
        sum += p_vector[i];
    }

    // Determine the mean and return
    return (sum / n);
}

template<typename T>
T asn2::math::variance(const Vector<T>& p_vector) {
    // get the size
    const size_t n = p_vector.size();

    // loop for n values, where i starts at first index
    T sum = coeff(p_vector, p_vector);

    // sqrt(sum/(size-1))
    return sum / (n - 1);  // Sum will ALWAYS be positive so we don't need to check
}

template<typename T>
T asn2::math::standardDeviation(const Vector<T>& p_vector) {
    // sqrt(sum/(size-1))
    return sqrt( variance(p_vector) );  // Sum will ALWAYS be positive so we don't need to check
}

template<typename T>
T asn2::math::pearsonCorrolation(const Vector<T>& p_vectorX, const Vector<T>& p_vectorY) {

    // The mean of x & y
    //const T meanX = mean(p_vectorX),
    //        meanY = mean(p_vectorY);

    // The sum
    T sum = coeff(p_vectorX, p_vectorY);

    // Bottom half of the equation

    // The left hand side
    T leftDenom = coeff(p_vectorX, p_vectorX);

    // The right hand side
    T rightDenom = coeff(p_vectorY, p_vectorY);

    return sum / sqrt( leftDenom*rightDenom );
}

template<typename T>
T asn2::math::meanAbsoluteDeviation(const Vector<T>& p_vector) {
    // The mean
    const T mu = mean(p_vector);

    // The size
    const size_t n = p_vector.size();

    // The total we're going to divide by n
    T total = T();

    // Make a temp to get x[i] - mu and then absolute it
    T toAbs;

    // Make a loop
    for (size_t i = 0; i < n; i++) {
        // For this element
        toAbs = (p_vector[i] - mu);

        // If it toAbs is negative, make it negative
        if (toAbs < 0) {
            // The absolute
            toAbs = 0 - toAbs;
        }

        // Add
        total = total + toAbs;
    }
    return (total) / n;
}

#endif // MATHVECTOR_H
