#ifndef TIMEIO_H
#define TIMEIO_H

#include "./Time.h"
#include <iostream>

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Time class
     *
     * @param input The istream we are using
     * @param p_time The time class that we are changing
     *
     * @pre input is a valid istream
     *
     */
std::istream& operator>>(std::istream& p_is, Time& p_time);

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Time class
     *
     * @param input The istream we are using
     * @param p_time The time class that we are changing
     *
     * @pre os is a valid ostream
     *
     */
std::ostream& operator<<(std::ostream& p_os, const Time& p_time);

#endif // TIMEIO_H
