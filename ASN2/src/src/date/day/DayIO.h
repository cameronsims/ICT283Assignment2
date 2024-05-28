#ifndef DAYIO_H
#define DAYIO_H

#include "./Day.h"

#include <iostream>

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Day class
     *
     * @param input The istream we are using
     * @param p_day The day class that we are changing
     *
     * @pre input is a valid istream
     *
     */
std::istream & operator >>(std::istream & input, Day& p_day );

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put a Day's information into a Day
     *
     * @param os The istream we are using
     * @param p_day The day class that we are changing
     *
     * @pre os is a valid ostream
     *
     */
std::ostream & operator <<(std::ostream & os, const Day& p_day);

#endif // DAYIO_H
