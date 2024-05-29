#include "FileParse.h"
#include "./weather/WeatherRecType.h"
#include "./timestamp/TimeStamp.h"

#include "./timestamp/TimestampIO.h"
#include "./date/DateIO.h"
#include "./date/month/MonthIO.h"
#include "./time/TimeIO.h"

#include "./menu/Menu.h"
#include "./maths/mathvector.h"

#include <fstream>
#include <sstream>

headerVector asn2::file::load_header(std::istream& p_in) {
    // Header
    headerVector header(4);

    std::string line;               // The line string
    std::getline(p_in, line);       // Read the line

    // The stringstream we're reading from
    std::stringstream ls(line);

    // Loop line
    while (!ls.eof()) {
        // Get cell
        std::string cell;
        std::getline(ls, cell, ',');

        // Make a stringstream to get rid of any whitespace
        std::stringstream ss(cell);
        ss >> cell;

        // Add it
        header.push(cell);
    }

    return header;
}

asn2::file::headerIDMap asn2::file::load_header_map(const headerVector& p_headers) {
    // Create the map
    headerIDMap m;

    //try
        // Assign the header to the map
        for (size_t i = 0; i < p_headers.size(); i++) {
            // The ID we're assigning
            CSVHeaderID id = CSVHeaderID::DEFAULT;

            // if it is a timestamp
            if (p_headers[i] == "WAST") {
                id = CSVHeaderID::TIMESTAMP;
            }

            // if it is a wind speed
            else if (p_headers[i] == "S") {
                id = CSVHeaderID::WIND_SPEED;
            }

            // if it is a ambient air temp
            else if (p_headers[i] == "T") {
                id = CSVHeaderID::AMBIENT_TEMPERATURE;
            }

            // if it is a solar radiation
            else if (p_headers[i] == "SR") {
                id = CSVHeaderID::SOLAR_RADIATION;
            }

            // add the ID
            m[p_headers[i]] = id;
        }
    // catch

    // Return
    return m;
}

bool asn2::file::has_content(const std::string& p_str) {
    /*// The Stringstream we're using to place back in
    std::stringstream ss(p_str);
    // The new string
    std::string str;
    ss >> str;

    // If it is bigger than zero
    return (str.size() > 0);*/
    for (size_t i = 0; i < p_str.size(); i++) {
        if (p_str[i] != ' ') {
            return true;
        }
    }

    return false;
}

int asn2::file::load_cell(std::istream& p_in, CSVHeaderID p_hID, asn2::weather::WeatherRecord& p_record) {
    switch (p_hID) {
        // If the timestamp is what we're looking for
      case CSVHeaderID::TIMESTAMP: {
        // Assign
        Date d;
        Time t;

        // Get Date
        std::string str;
        p_in >> str;
        std::stringstream ss(str);
        ss >> d;

        // Get Time
        p_in >> str;
        ss = std::stringstream(str);
        ss >> t;

        // Assign to the record
        p_record.timestamp.date = d;
        p_record.timestamp.time = t;

        // Set this so that we can actually assign the time
        return 2;
      }

      // If the speed
      case CSVHeaderID::WIND_SPEED: {
        // The speed of the wind
        float wind_speed = 0.0f;
        // Get the speed
        p_in >> wind_speed;
        // If the value is negative
        if (wind_speed < 0) {
            // Tell user
            std::cout << "Error: Negative Wind Speed detected\n";
        }
        // Assign to record
        p_record.speed = new float(wind_speed);
        return 1;
      }

        // If the temperature
      case CSVHeaderID::AMBIENT_TEMPERATURE: {
        // The temperature
        float temp = 0.0f;
        p_in >> temp;
        // if lower than abs zero
        if (temp < -273.15) {
            std::cout << "Error: Temperature lower than absolute zero detected!\n";
        }
        // Assign to record
        p_record.airTemp = new float(temp);
        return 1;
      }

      // If the solar radiations
      case CSVHeaderID::SOLAR_RADIATION: {
        // Get the solar radiation
        int solrad = 0;
        p_in >> solrad;

        // If lower than 0
        if (solrad < 0) {
            std::cout << "Error: Negative Solar Radiation detected!\n";
        }
        // Assign to record
        p_record.solarRad = new int(solrad);
        return 1;
      }

      case CSVHeaderID::DEFAULT:
      default: {
        // Ignore
        return 0;
      }
    }
}

void asn2::file::load_line(std::istream& p_in, const headerVector& p_header, const headerIDMap& p_hID, WeatherLogType& p_records, std::string& p_cell, std::stringstream& p_cs, asn2::weather::WeatherRecord& p_record) {
    // The column we're at
    size_t i = 0;

    // Boolean to detect if we got a date
    bool hasTime = false;

    // While we're not at the end of the line
    while (!p_in.eof()) {
        // Get a cell
        std::getline(p_in, p_cell, ',');

        // Check if there is anything in the cellstream

        // If there is an invalid value
        if (has_content(p_cell) && p_cell != "NA") {
            // Create a cellstream
            p_cs = std::stringstream(p_cell);

            // Do a switch case statement and a try-catch
            try {
                if (load_cell(p_cs, p_hID[p_header[i]], p_record) == 2) {
                    hasTime = true;
                }
            }
            // If we have exceeded the vector size
            catch (const VectorError& e) {
                // Don't do anything, we don't care about an extra comma
            }
            // If we have exceeded the vector size
            catch (const VectorOutOfRange& e) {
                // Don't do anything, we don't care about an extra comma

            }
            // If invalid date
            catch (const InvalidDate& e) {
                std::cout << "Error: Invalid Date Detected!\n";
            }
            // If invalid time
            catch (const InvalidTime& e) {
                std::cout << "Error: Invalid Time Detected!\n";
            }
            // If there was a wrong value input
            catch (const std::invalid_argument& e) {
                std::cout << "Error: Unexpected token.\n";
            }
            // If there was an overflow
            catch (const std::out_of_range& e) {
                std::cout << "Error: Integer Under/Overflow\n";
            }
            // If there was any other issue
            catch (const std::exception& e) {
                std::cout << "Error: Unexpected error has occured.\n";
            }
        }

        // Next column
        i++;

        // Check if there is any more values, if not return
        if (i >= p_header.size()) {
            break;
        }
    }

    // Assign into map IF we have a date/time
    if (hasTime) {
        // Assign to map
        Date& date = p_record.timestamp.date;
        p_records[ date.getYear() ][ date.getMonth() ].push(p_record);
    }
}

void asn2::file::load_body(std::istream& p_in, const headerVector& p_header, const headerIDMap& p_hID, WeatherLogType& p_records) {
    // For every single line...
    std::string line;
    std::stringstream ls;

    asn2::weather::WeatherRecord record;
    std::string cell;
    std::stringstream cs;

    // Keep reading the file
    while (!p_in.eof()) {
        // Get a line in the istream
        std::getline(p_in, line);

        // If line has content
        if (line.size() > 0) {
            // From the line, create stringstream to parse as a file line
            ls = std::stringstream(line);

            // Reset the record
            record = asn2::weather::WeatherRecord();

            // Parse
            asn2::file::load_line(ls, p_header, p_hID, p_records, cell, cs, record);
        }
    }
}

void asn2::file::load(std::istream& p_file, WeatherLogType& p_records) {
    // Read header
    headerVector header = asn2::file::load_header(p_file);
    if (header.size() == 0) {
        std::cout << "Error: No Header Line!\n";
        return;
    }

    // Assign header to map
    headerIDMap IDMap = asn2::file::load_header_map(header);
    bool exists = false;
    for (auto it = IDMap.begin(); it != IDMap.end(); it++) {
        // If it not default
        if (it->second != CSVHeaderID::DEFAULT) {
            exists = true;
            break;
        }
    }

    if (exists) {
        // Read the file line by line
        asn2::file::load_body(p_file, header, IDMap, p_records);
    }
}

void asn2::file::load_all(const std::string& p_location, const std::string& p_manifest, WeatherLogType& p_records) {
    // Open the manifest file
    std::ifstream manifest(p_manifest);

    // If the file isn't a good stream
    if (!manifest.good()) {
        // Tell user that manifest doesn't exist
        std::cout << "Error: File Manifest \"" << p_manifest << "\" cannot be accessed.\n";
        // Return
        return;
    }

    // Read the header from the file...
    while (!manifest.eof()) {
        // Get line
        std::string line;
        std::getline(manifest, line);

        // if the line hasn't got anything
        if (line == "") {
            // Continue for loop
            continue;
        }

        // Create a new file
        std::ifstream file(p_location + line);

        // If the file doesn't get anything
        if (!file.good()) {
            // Tell error
            std::cout << "Error: No file \"" << p_location << line << "\" was found.\n\n";
            continue;
        }

        // If it exists...
        std::cout << "Reading file: \"" << p_location << line << "\"\n";

        // Read file line by line
        asn2::file::load(file, p_records);

        // Tell user we finished
        std::cout << "File \"" << p_location << line << "\" has been read.\n\n";
    }
}
