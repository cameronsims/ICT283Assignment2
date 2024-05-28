#ifndef TIMEEXCEPTIONS_H
#define TIMEEXCEPTIONS_H

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a time is not valid (under 0:00 or over 23:59)
     *
     * @class InvalidTime
     *
     */
class InvalidTime {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a time is not valid hour is under 0 or over 23
     *
     * @class InvalidHour
     *
     */
class InvalidHour : public InvalidTime {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 03/05/2024
     * @brief Thrown if a time is not valid hour is under 0 or over 59
     *
     * @class InvalidMinute
     *
     */
class InvalidMinute : public InvalidTime {
public:
        /**
		 * @brief Explains to user what went wrong
		 */
    const char* what() const;
};

#endif // TIMEEXCEPTIONS_H
