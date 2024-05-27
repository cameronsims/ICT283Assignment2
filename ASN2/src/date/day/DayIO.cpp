#include "./DayIO.h"

#include <sstream>
#include <string>

std::istream & operator >>(std::istream & input, Day& p_day ) {
    // Create temp values to place in
    int day;

    // Get the date in a string, we are getting the cell it relates to
    std::string date;
    input >> date;

    // Convert the cell to string
    day = std::stoi(date);

    // Set the month value
    p_day.setDay(day);

	return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
std::ostream & operator <<(std::ostream & os, const Day& p_day ) {
    // Output day (value)
    os << p_day.getDay();
	return os;
}
