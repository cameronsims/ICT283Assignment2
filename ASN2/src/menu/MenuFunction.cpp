#include "MenuFunction.h"
#include "../date/month/MonthIO.h"

Month asn2::menu::MenuFunction::m_month = Month(1);
std::ostream* asn2::menu::MenuFunction::m_os = nullptr;

asn2::menu::MenuFunction::MenuFunction() {

}

void asn2::menu::MenuFunction::setMonth(const Month& p_month) {
    // Set the month (throw is not our responsibility)
    MenuFunction::m_month = Month(p_month.getMonth());
}

void asn2::menu::MenuFunction::setOS(std::ostream& p_os) {
    MenuFunction::m_os = &p_os;
}



// Input 2 lambda:
void asn2::menu::MenuFunction::printAirTemp(const asn2::weather::WeatherResults& result) {
    // The difference
    const int start = MenuFunction::m_month.getMonth(),
              end   = result.month.getMonth(),
              diff  = end - start;

    // If the difference between this month and last month accessed is greater than 1
    if (diff > 1) {
        // Print all the values we missed...
        for (int i = start + 1; i < end; i++) {
            // Print values out
            std::cout << Month(i) << ": No Data\n";
        }
    }

    // Set last accessed month...
    MenuFunction::setMonth( result.month.getMonth() );

    // Print for all values accessed.
    std::cout << result.month << ": " << result.temperature->mean << " degrees C, stdev: " << result.temperature->stdev << "\n";
}

// Input 4 lambda:
void asn2::menu::MenuFunction::printValuesFile(const asn2::weather::WeatherResults& result) {
    // The output stream
    std::ostream& os = *MenuFunction::m_os;

    // Set to file
    os << result.month << ",";

    // If speed is not nullptr
    if (result.speed != nullptr) {
        os << result.speed->mean << "(" << result.speed->stdev << "," << result.speed->mad << ")";
    }
    // Print a comma
    os << ",";

    // If temp is not nullptr
    if (result.temperature != nullptr) {
        os << result.temperature->mean << "(" << result.temperature->stdev << "," << result.temperature->mad << ")";
    }
    // Print solar rad
    os << "," << result.solarRadiation << "\n";
}
