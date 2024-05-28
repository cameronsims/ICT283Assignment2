#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H

#include <iostream>
#include "../weather/WeatherResults.h"

namespace asn2 {
namespace menu {

        /**
         * @author Cameron Sims
         * @date 21/05/2024
         * @brief Menu Function is a function which is used to make a function attached to the menu
         *
         * @class MenuFunction
         *
         */
    class MenuFunction {
      public:
            /**
             * @brief Default Constructor
             */
        MenuFunction();

            /**
             * @brief Menu Input 2
             * @param p_result The result of weather to be printed
             */
        static void printAirTemp(const asn2::weather::WeatherResults& p_result);

            /**
             * @brief Menu Input 2
            * @param p_result The result of weather to be printed
            */
        static void printValuesFile(const asn2::weather::WeatherResults& p_result);

            /**
             * @brief Sets the output for the class
             * @param p_month The month wé're looking for
             */
        static void setMonth(const Month& p_month);

            /**
             * @brief Sets the output stream we're using to print into
             * @param p_os The Output stream we're using
             */
        static void setOS(std::ostream& p_os);
      private:

        /// The month we're wanting
        static Month m_month;

        /// The ostream we're using
        static std::ostream* m_os;
    };

}
}

#endif // MENUFUNCTION_H
