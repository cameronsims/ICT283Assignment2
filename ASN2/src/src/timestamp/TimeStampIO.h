#ifndef TIMESTAMPIO_H
#define TIMESTAMPIO_H

#include "TimeStamp.h"

#include <iostream>

    /**
     * @author Cameron Sims
     * @date 25/05/2024
     * @brief Used to input timestamp
     *
     * @param p_is The istream we are using
     * @param p_timestamp The timestamp we're outpitting into
     *
     * @pre input is a valid istream
     *
     */
std::istream& operator>>(std::istream& p_is, TimeStamp& p_timestamp);

    /**
     * @author Cameron Sims
     * @date 25/05/2024
     * @brief Used to output a timestamp
     *
     * @param p_os The ostream we are using to output
     * @param p_timestamp The timestamp we're outpitting into
     *
     * @pre os is a valid ostream
     *
     */
std::ostream& operator<<(std::ostream& p_os, const TimeStamp& p_timestamp);

#endif // TIMESTAMPIO_H
