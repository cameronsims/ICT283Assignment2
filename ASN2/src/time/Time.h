// Time.h - Defines Time class
#ifndef TIME_H
#define TIME_H

#include "TimeExceptions.h"

   /**
    * @author Cameron Sims
    * @date 14/04/2024
    * @brief A time in a day
    *
    * @class Time
    *
    */
class Time {
  public:
		/**
		* @brief To construct the class with no arguments
		*/
	Time();

		/**
		* @brief To construct the class with arguments
		* @param p_hour The hour in time
		* @param p_minutes The seconds in time
		* @throw Throws InvalidTime if invalid number(s)
		*/
	Time(int p_hour, int p_minutes);

		/**
		* @brief To get the time
		*/
	int getHour() const;

		/**
		* @brief To change the hour
		* @param p_hour To change the hour to
		* @returns "This" class
		* @throw Throws InvalidHour if invalid number
		*/
	Time& setHour(int p_hour);

		/**
		* @brief To get the seconds
		* @returns The minutes that the class is encapsulating
		*/
	int getMinutes() const;

		/**
		* @brief To change the hour
		* @param p_hour To change the seconds to
		* @returns "This" class
		* @throw Throws InvalidMinute if invalid number
		*/
	Time& setMinutes(int p_minutes);

  private:
	/// The first two digits (HH:SS)
    int m_hour;

	/// The second two digits (HH:SS)
    int m_minutes;
};

#endif // TIME_H
