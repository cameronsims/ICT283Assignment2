#ifndef YearIO_H
#define YearIO_H

#include "./Year.h"

#include <iostream>

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Year class
     *
     * @param input The istream we are using
     * @param p_year The year class that we are changing
     *
     * @pre input is a valid istream
     *
     */
std::istream & operator >>(std::istream & input, Year& p_Year );

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Year class
     *
     * @param input The ostream we are using to save data into
     * @param p_year The year class that we are saving
     *
     * @pre os is a valid ostream
     *
     */
std::ostream & operator <<(std::ostream & os, const Year& p_Year);

#endif // YearIO_H
