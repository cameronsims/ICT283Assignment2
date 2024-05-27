#ifndef DATEIO_H
#define DATEIO_H

#include "./Date.h"

#include <iostream>

   /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put an istream's values into a Date class
     *
     * @param input The istream we are using
     * @param D The date that will be changed
     *
     * @pre input is a valid istream
     *
     */
std::istream & operator >>(std::istream & input, Date& D );

/**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to put a date's information into an ostream
     *
     * @param os The output source we are printing the data to
     * @param D The date that will be changed
     *
     * @pre input is a valid ostream
     *
     */
std::ostream & operator <<(std::ostream & os, const Date&  D );

#endif // DateIO.h
