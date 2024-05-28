#ifndef MONTHIO_H
#define MONTHIO_H

#include "./Month.h"

#include <iostream>

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Month class
     *
     * @param input The istream we are using
     * @param p_month The month class that we are changing
     *
     * @pre input is a valid istream
     *
     */
std::istream & operator >>(std::istream & input, Month& p_month );

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Month class
     *
     * @param os The ostream we are saving values into
     * @param p_month The month we are printing
     *
     * @pre os is a valid ostream
     *
     */
std::ostream & operator <<(std::ostream & os, const Month& p_month);

#endif // MONTHIO_H
