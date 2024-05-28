#ifndef DATEEXCEPTIONS_H
#define DATEEXCEPTIONS_H

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a date is not correct
     *
     * @class InvalidDate
     *
     */
class InvalidDate {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a day is an invalid day
     *
     * @class InvalidDay
     *
     */
class InvalidDay : public InvalidDate {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a day is an invalid month
     *
     * @class InvalidMonth
     *
     */
class InvalidMonth : public InvalidDate {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

#endif // DATEEXCEPTIONS_H
