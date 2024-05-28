#ifndef YEAR_H
#define YEAR_H

    /**
     * @author Cameron Sims
     * @date 14/04/2024
     * @brief Used to index a year in time
     *
     * @class Year
     *
     */
class Year {
  public:
		/**
		 * @brief Create the date class
		 */
    Year();

        /**
         * @brief To destruct the year class
         * This is done to make the compiler stop whining
         */
    virtual ~Year();

		/**
		 * @brief Create the date class
		 * @param p_year Year
		 */
    Year(int p_year);

		/**
		 * @brief Get the year
		 * @returns Year that the class is encapsulating
		 */
    int getYear() const;

		/**
		 * @param p_year the year
		 * @returns Returns "this" class
		 * @throws "int" if not in bounds
		 */
    Year& setYear(int p_year);

  private:
		/**
		 * @author Cameron Sims
		 * @date 18/03/2024
		 * @brief To catalogue year
		 */
    int m_year;
};

#endif // YEAR_H
