#include "./MonthIO.h"

#include <sstream>
#include <string>

std::istream & operator >>(std::istream & input, Month& p_month ) {
    // Create temp values to place in
    int month;

    // Get the date in a string, we are getting the cell it relates to
    std::string date;
    input >> date;

    // Convert the cell to string
    month = std::stoi(date);

    // Set the month value
    p_month.setMonth(month);

	return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
std::ostream & operator <<(std::ostream & os, const Month& p_month ) {
    // Name of the month
    std::string engMonthName = "UNKNOWN MONTH";
    // Get the month and assign english names
    // We're using this instead of a hashmap as non-valid values
    // would cause an access violation.
    switch (p_month.getMonth()) {
        case 1: { engMonthName = "January";   break; }
        case 2: { engMonthName = "February";  break; }
        case 3: { engMonthName = "March";     break; }
        case 4: { engMonthName = "April";     break; }
        case 5: { engMonthName = "May";       break; }
        case 6: { engMonthName = "June";      break; }
        case 7: { engMonthName = "July";      break; }
        case 8: { engMonthName = "August";    break; }
        case 9: { engMonthName = "September"; break; }
        case 10: { engMonthName = "October";  break; }
        case 11: { engMonthName = "November"; break; }
        case 12: { engMonthName = "December"; break; }
        default: { }
    }
    // Properly output the vals
	os << engMonthName;
	return os;
}
