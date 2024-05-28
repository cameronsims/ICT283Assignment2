#ifndef MONTH_H
#define MONTH_H

#include "../DateExceptions.h"

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to index a month of a year, must be between 1-12
     *
     * @class Month
     *
     */
class Month {
  public:
		/**
		 * @brief Create the date class
		 */
    Month();

        /**
         * @brief To destruct the month class
         * This is done to make the compiler stop whining
         */
    virtual ~Month();

		/**
		 *
		 * @param p_month Month (must be between 1-12)
		 * @throw Throws InvalidMonth if invalid number
		 */
    Month(int p_month);

		/**
		 * @brief Get the month
		 * @returns Month that the class is encapsulating
		 */
    int getMonth() const;

		/**
		 * @param p_month Month must be between (1-12)
		 * @returns Returns "this" class
		 * @throw Throws InvalidMonth if invalid number
		 */
    Month& setMonth(int p_month);

  private:
		/**
		 * @author Cameron Sims
		 * @date 18/03/2024
		 * @brief To catalogue month
		 */
    int m_month;
};

#endif // MONTH_H
