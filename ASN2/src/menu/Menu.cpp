// Menu.cpp - The implementation of the Menu

#include "./Menu.h"
#include "./MenuFunction.h"

#include "../FileParse.h"

#include "../date/DateIO.h"
#include "../date/month/MonthIO.h"
#include "../date/year/YearIO.h"

#include "../maths/mathvector.h"

#include "../weather/WeatherResults.h"
#include "../weather/WeatherResultsCompare.h"

#include <iostream>
#include <fstream>
#include <sstream>

void asn2::menu::showAuthor() {
    // Show at the top who wrote the program
    // We are writing this here because we want it to be hard coded
    std::cout << "##################################\n"
              << "#          Cameron Sims          #\n"
              << "#           (34829454)           #\n"
              << "#      ICT283: Assignment 2      #\n"
              << "##################################\n"
              << "\n";
}

int asn2::menu::loop(WeatherCalender& p_records, const std::string& p_SAVELOC) {
    // This is the fstream we're going to use
    std::ofstream out;

    // Set default value
    int option = -1;

    while (option != 5) {
        // Show menu
        asn2::menu::showOptions();

        // Get input
        option = asn2::menu::getOption();

        // Open file if option is 4
        if (option == 4) {
            // Where we're going to save the data to
            // The file we are saving to
            out.open(p_SAVELOC, std::ofstream::out);

            // If the ostream doesn't work
            if (!out.good()) {
                std::cout << "Error: File \"" << p_SAVELOC << "\" is not a valid file location OR is read-only!\n";
                return -1;
            }
        }

        // Decide what to do via function
        asn2::menu::execute(p_records, out, option);

        // If option 4 was called, refresh the ostream
        if (option == 4) {
            // Close, to save to file
            out.close();
        }
    }

    return 0;
}

void asn2::menu::showOptions() {
    std::cout << "\n1. Get Average/SD of Wind Speeds throughout a month.\n"
              << "2. Get the Ambient Wind Temperature for each month of a year.\n"
              << "3. Get Pearson Corrolation Co-efficent, between two elements\n"
              << "4. Get average windspeed (SD, MAD), average ambient temperature (SD, MAD) total solar radiation. [Placed in \"WindTempSolar.csv\"]\n"
              << "5. Exit the Program\n";
}

int asn2::menu::getOption() {
    // Ask for input
    std::cout << "\nSelect Option: ";

    // Temp value
    int opt;

    // Try get option
    try {
        // We want a string because god knows what the user inputs
        std::string optionStr;

        // Get console input
        std::cin >> optionStr;

        // Then cast it to int
        opt = std::stoi(optionStr);
    }
    // If we put in a large value
    catch (const std::out_of_range& err) {
        // Tell error continue
        std::cout << "Over/Underflow, please pick a smaller number\n";
        // Recurse
        return asn2::menu::getOption();
    }
    // If not a valid option then recurse function
    catch (const std::invalid_argument& err) {
        // Tell error continue
        std::cout << "Bad Input, please retry your input.\n";
        // Recurse
        return asn2::menu::getOption();
    }

    // This thing here is to get rid of the new line character
    // which is left after calling std::cin
    std::cin.get();

    // If the input isn't between 1-5, return invalid number
    if (opt < 1 || opt > 5) {
        return -1;
    }

    // Otherwise return option
    return opt;
}

Date asn2::menu::getCalenderMonth() {
    // The value we are returning
    Date date;

    // Ask for input
    std::cout << "Input month/year: MM/YYYY: ";

    try {
        // Get input
        std::string input;
        std::cin >> input;

        // Add a dummy number at the start
        input = "01/" + input;

        // Set the date 01/MM/YYYY
        std::stringstream ss(input);
        ss >> date;

        // Ensure the day is 1 just to avoid any weirdness
        date.setDay(1);
    }
    // if the value is invalid
    catch (InvalidDate err) {
         // Tell user of invalid input
        std::cout << "Invalid format for month/year was input.\n";
        // Return a strange day so that the user knows they fucked up
        return Date(2, 1, -2000);
    }
    catch (const std::invalid_argument& err) {
        // Tell user of invalid input
        std::cout << "Invalid format for month/year was input.\n";
        // Return a strange day so that the user knows they fucked up
        return Date(2, 1, -2000);
    }
    // if we run into an integer overflow error
    catch (const std::out_of_range& err) {
        // Tell user of invalid input
        std::cout << "Invalid input, please pick a number smaller/bigger.\n";
        // Return a strange day so that the user knows they fucked up
        return Date(2, 1, -2000);
    }

    return date;
}

Month asn2::menu::getMonth() {
    // The value we are returning
    Month month;

    // Ask for input
    std::cout << "Input month: MM: ";

    try {
        // Get input
        std::string input;
        std::cin >> input;

        // Set the date 01/MM/YYYY
        std::stringstream ss(input);
        ss >> month;
    }
    // if the value is in an invalid format
    catch (const std::invalid_argument& err) {
        // Tell user of invalid input
        std::cout << "Invalid format for month/year was input.\n";
        // Return a strange day so that the user knows they fucked up
        return Month(1);
    }
    // if we run into an integer overflow error
    catch (const std::out_of_range& err) {
        // Tell user of invalid input
        std::cout << "Invalid input, please pick a number smaller/bigger.\n";
        // Return a strange day so that the user knows they fucked up
        return Month(1);
    }

    return month;
}

Date asn2::menu::getCalenderYear() {
    // The value we are returning
    Date y;

    // Ask for input
    try {
        std::cout << "Input year (YYYY): ";
        std::cin >> (Year&)y;
        // Make sure we'll get no errors
        y.setDay(1);
        y.setMonth(1);
    }
    // if the value is invalid
    catch (const std::invalid_argument& err) {
        // Tell user of invalid input
        std::cout << "Invalid format for year was input.\n";
        // Return a strange day so that the user knows they fucked up
        return Date(2, 12, -2000);
    }
    // if we run into an integer overflow error
    catch (const std::out_of_range& err) {
        // Tell user of invalid input
        std::cout << "Invalid input, please pick a number smaller/bigger.\n";
        // Return a strange day so that the user knows they fucked up
        return Date(2, 12, -2000);
    }

    // Return year
    return y;
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Moved to MenuFunction.cpp

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void asn2::menu::execute(const WeatherCalender& p_records, std::ostream& p_saveLocation, int p_option) {
    // Set default value
    // Decide what to do via switch-case
    switch (p_option) {
      // If the value is not valid
      default: {
        std::cout << "Error: Command not recognised\n";
        break;
      }

      // If we are getting the average/sd of wind speed
      case 1: {
        // Get month & year
        Date date = asn2::menu::getCalenderMonth();

        // Get the result using the key below
        asn2::weather::WeatherResults temp;
        temp.month = date.getMonth();

        std::cout << Month(date.getMonth()) << " " << Year(date.getYear()) << ": ";

        // Search using key
        try {
            asn2::weather::WeatherResults result = p_records[ date.getYear() ].searchNode(temp);

            // Print month & year
            if (result.speed != nullptr) {
                std::cout << "\nAverage speed: " << result.speed->mean << "km/h"
                          << "\nSample stdev:  " << result.speed->stdev << "\n";
            } else {
                std::cout << "No Data\n";
            }
        } catch (const NodeNotFound& err) {
            std::cout << "No Data\n";
        } catch (const MapKeyNotFound& err) {
            std::cout << "No Data\n";
        }

        break;
      }

      // If we are getting the ambient air temperature
      case 2: {
        // Get year
        Date date = asn2::menu::getCalenderYear();

        // Create a menu function object
        MenuFunction mfunc;

        // Print all months from the year
        std::cout << date.getYear() << "\n";

        // Create month to look for
        mfunc.setMonth(Month(1));

        // Do that.
        try {
            p_records[date.getYear()].inOrder(mfunc.printAirTemp);
        } catch (const MapKeyNotFound& err) {
            // Tell user
            std::cout << "Error: Year not found.\n";
        }

        break;
      }

      // Print pearsons' for certain months over all years
      case 3: {
        try {
            // Get month
            Month month = asn2::menu::getMonth();

            // Print for all years one month.
            std::cout << "S_T: " << asn2::weather::WeatherResults::pcc_st[ month.getMonth() - 1 ] << "\n"
                      << "S_R: " << asn2::weather::WeatherResults::pcc_sr[ month.getMonth() - 1 ] << "\n"
                      << "T_R: " << asn2::weather::WeatherResults::pcc_tr[ month.getMonth() - 1 ] << "\n";
        } catch (const InvalidDate& err) {
            // Tell user of invalid input
            std::cout << "Invalid format for month/year was input.\n";
        }

        break;
      }

      // Do all three, and compress it into a file
      case 4: {
        // Get year
        Year year = asn2::menu::getCalenderYear();

        MenuFunction mfunc;
        mfunc.setOS(p_saveLocation);

        // Print for all months:
        p_saveLocation << year.getYear() << "\n";

        try {
            // Month, Mean(STDEV, MAD),...,TotalSolarRad(kW/h)
            p_records[ year.getYear() ].inOrder(mfunc.printValuesFile);
        }
        // Catch if not in map
        catch (const MapKeyNotFound& err) {
            std::cout << "Error: Year not found.\n";
        }

        break;
      }

      // Close the program
      case 5: {
        std::cout << "Exiting Program...\n";
        break;
      }
    }
}

/*void asn2::menu::show_error(std::ostream& p_os, const std::string& p_line, int p_column) {
    // Print the line
    p_os << p_line << "\n";

    // Show the error
    for (int i = 0; i < p_column; i++) {
        // Print up until the error
        p_os << " ";
    }

    // show the point and print a new line
    p_os << "^\n";
}*/
