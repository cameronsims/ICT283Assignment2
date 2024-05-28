#include "./YearIO.h"

#include <sstream>
#include <string>

std::istream & operator >>(std::istream & input, Year& p_year ) {
    // Create temp values to place in
    int year;

    // Get the date in a string, we are getting the cell it relates to
    std::string date;
    input >> date;

    // Convert string to int
    year = std::stoi(date);

    p_year.setYear(year);

	return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
std::ostream & operator <<(std::ostream & os, const Year& p_year ) {
    // Properly output the vals
	os << p_year.getYear();
	return os;
}
