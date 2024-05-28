// Menu.h - Prototype functions for the menu interface
#ifndef MENU_H
#define MENU_H

#include "../weather/WeatherLogType.h"
#include "../date/Date.h"

#include "../weather/WeatherConvert.h"       // WeatherCalender

#include <iostream>

namespace asn2 {
namespace menu {

        /**
         * @author Cameron Sims
         * @date 14/04/2024
         * @brief Prints author / author's details on the screen
         *
         */
    void showAuthor();

        /**
         * @author Cameron Sims
         * @date 11/04/2024
         * @brief Loops the menu
         * @param p_records The records we're printing
         * @param p_SAVELOC The save location
         * @returns The exit code
         */
    int loop(WeatherCalender& p_records, const std::string& p_SAVELOC);

        /**
         * @author Cameron Sims
         * @date 11/04/2024
         * @brief Prints menu on the screen
         *
         */
    void showOptions();

        /**
         * @author Cameron Sims
         * @date 11/04/2024
         * @brief Gets option that was selected
         * @return Returns the number value (-1) if invalid
         *
         */
    int getOption();

        /**
         * @author Cameron Sims
         * @date 13/04/2024
         * @brief Gets a month/year from user
         * @return Returns a date that the user input (the day of the date will be 2 if there was an error)
         *
         */
    Date getCalenderMonth();

        /**
         * @author Cameron Sims
         * @date 18/05/2024
         * @brief Gets a month from user
         * @return Returns a Month of the year
         *
         */
    Month getMonth();

        /**
         * @author Cameron Sims
         * @date 13/04/2024
         * @brief Gets a year from user
         * @return Returns a Date that the user input (the day will be 2 if there was an error and the month will be 12)
         *
         */
    Date getCalenderYear();

        /**
         * @author Cameron Sims
         * @date 13/04/2024
         * @brief This is the command loop, this function will run until the user inputs a number to stop the function from looping
         *
         * @param p_records The records we are searching through
         * @param p_saveLocation The location we are saving the data into
         * @param p_option The option we wish to execute
         *
         */
    void execute(const WeatherCalender& p_records, std::ostream& p_saveLocation, int p_option);

    //    /**
    //     * @author Cameron Sims
    //     * @date 17/04/2024
    //     * @brief Shows where an error is
    //     *
    //     * @param p_os The ostream we are printing to
    //     * @param p_line The line that we got an error in
    //     * @param p_column The column that the error was occured
    //     *
    //     */
    //void show_error(std::ostream& p_os, const std::string& p_line, int p_column);

}
}

#endif // H
