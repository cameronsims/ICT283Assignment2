#ifndef DATE_H
#define DATE_H

#include "./day/Day.h"
#include "./month/Month.h"
#include "./year/Year.h"

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Date class that indexes a day in a year
     *
     * @class Date, has a Day/Month and Year
     *
     */
class Date : public Day, public Month, public Year {
  public:
		/**
		* @brief Create the date class
		*/
    Date();

        /**
         * @brief Destructor
         */
    virtual ~Date();

		/**
		* @brief Create the date class
		* @throw Throws InvalidDate if invalid number
		* @param p_day Day (must be between 1-31)
		* @param p_month Month (must be between 1-12)
		* @param p_year Year
		*
		*/
    Date(int p_day, int p_month, int p_year);

        /**
		 * @brief Change the day
		 * @param p_day Day that we want to change it to
		 * @throw Throws InvalidDay if invalid number
		 *
		 */
    Date& setDay(int p_day);

        /**
		 * @brief Change the month
		 * @param p_month Month that we want to change to
		 * @throw Throws InvalidMonth if invalid number
		 *
		 */
    Date& setMonth(int p_month);

        /**
		 * @brief Change the year
		 * @param p_year Year that we want to change to
		 * @throw InvalidDate if invalid year combination
		 */
    Date& setYear(int p_year);

  private:

        /**
         * @brief This checks if the combination of day, month and year is valid
         * @param p_day Is the day of the new date
         * @param p_month Is the month of the new date
         * @param p_year Is the year of the new date
         * @returns A boolean value representing if the date is valid
         */
    static bool m_isValid(int p_day, int p_month, int p_year);

        /**
		 * @brief THIS CONSTRUCTOR SHOULD NOT UNDER ANY CIRCUMSTANCES BE CALLED
		 * @param This int is here so that none of the parent classes' constructors are called
		 */
    Date(int);
};

#endif // DATE_H
