#ifndef DAY_H
#define DAY_H

#include "../DateExceptions.h"

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Day class is designed to maintain a day of a month
     *
     * @class Day
     *
     */
class Day {
  public:
		/**
		 * @brief Create the day class
		 */
    Day();

        /**
         * @brief To destruct the day class
         * This is done to make the compiler stop whining
         */
    virtual ~Day();

		/**
		 * @brief Create the day class
		 * @param p_day Day (must be between 1-31)
		 * @throw Throws InvalidDay if invalid number
		 */
    Day(int p_day);

		/**
		 * @brief Get the day
		 * @returns The day that the class contains
		 */
    int getDay() const;

		/**
		 * @brief Change the day
		 * @param p_day Day (must be between 1-31)
		 * @returns Returns "this" class
		 * @throw Throws InvalidDay if invalid number
		 */
    virtual Day& setDay(int p_day);

  private:
		/**
		 * @brief To catalogue day
		 */
    int m_day;
};

#endif // DAY_H
