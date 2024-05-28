#include "./DateIO.h"

#include "./day/DayIO.h"
#include "./month/MonthIO.h"
#include "./year/YearIO.h"

#include <sstream>
#include <string>

std::istream & operator >>(std::istream & input, Date & D ) {
    // Make a throwaway string to ignore
    std::string temp;

    // Get formatted value
    std::getline(input, temp, '/');

    // Get first date, used for stringstream
    std::stringstream ss(temp);

    // Cast the date to all it's parent classes
    ss >> (Day&)D;

    // Get next value
    std::getline(input, temp, '/');

    // Get second part (Month)
    ss = std::stringstream(temp);

    ss >> (Month&)D;

    // Get next value
    std::getline(input, temp);

    // Get second part (Month)
    ss = std::stringstream(temp);

    ss >> (Year&)D;

	return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
std::ostream & operator <<(std::ostream & os, const Date & D ) {
    // Cast to day, month and year
	os << (const Day&)D << " "
	   << (const Month&)D << " "
       << (const Year&)D;
	return os;
}
