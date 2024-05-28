#ifndef FILEPARSE_H
#define FILEPARSE_H

#include "./weather/WeatherLogType.h"

#include <iostream>

/// The header vector
typedef Vector<std::string> headerVector;

namespace asn2 {
namespace file {

    /// This is an enmu which presides over the column we're using
    enum class CSVHeaderID {
        /// This is if we have no idea what the column is
        DEFAULT = 0,

        /// If the column represents date and time (WAST)
        TIMESTAMP = 1,

        /// If the column represents wind speed (S)
        WIND_SPEED = 2,

        /// IF the column represents ambient air temperature (T)
        AMBIENT_TEMPERATURE = 3,

        /// If the column represents solar radiation (SR)
        SOLAR_RADIATION = 4
    };

    /// The map of the header and the ID, like a hashmap
    typedef Map<std::string, CSVHeaderID> headerIDMap;

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load_header
         * @param p_in The istream we're reading the header from
         * @returns Returns a vector representing a column of data...
         */
    headerVector load_header(std::istream& p_in);

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load_header_map
         * @param p_headers The headers we're using to assign a map to
         * @returns Returns a vector representing a column of data...
         */
    headerIDMap load_header_map(const headerVector& p_headers);

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load_line
         * @param p_in The istream we're reading the header from
         * @param p_header The header vector we have represents one column per part
         * @param p_hID The header id we're using
         * @param p_records The records wé're saving to
         *
         * @param p_cs The cell stream we're using
         * @param p_cell The cell we're reading from
         * @param p_record The single record we're using
         */
    void load_line(std::istream& p_in, const headerVector& p_header, const headerIDMap& p_hID, WeatherLogType& p_records, std::string& cell, std::stringstream& cs, asn2::weather::WeatherRecord& p_record);

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load_body
         * @param p_in The istream we're reading the header from
         * @param p_header The header vector we have represents one column per part
         * @param p_hID The header id we're using
         * @param p_records The records wé're saving to
         * @returns Returns a vector representing a column of data...
         */
    void load_body(std::istream& p_in, const headerVector& p_header, const headerIDMap& p_hID, WeatherLogType& p_records);

        /**
         * @author Cameron Sims
         * @date 24/05/2024
         *
         * @fn load_cell
         * @param p_in The istream we're reading the header from
         * @param p_hID The header id we're using
         * @param p_record The records wé're adding infomation into
         * @returns Returns a status, this status is if the program spotted a timestamp(2) or spotted a valid column (1), 0 if none.
         */
    int load_cell(std::istream& p_in, CSVHeaderID p_hID, asn2::weather::WeatherRecord& p_record);

        /**
         * @author Cameron Sims
         * @date 24/05/2024
         *
         * @fn load_cell
         * @param p_str The string that we are using to check
         * @returns True if there is a character in the string
         */
    bool has_content(const std::string& p_str);

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load
         * @param p_file The file we're reading
         * @param p_records The records wé're saving to
         */
    void load(std::istream& p_file, WeatherLogType& p_records);

        /**
         * @author Cameron Sims
         * @date 22/05/2024
         *
         * @fn load_all
         * @param p_location The string dictating where our data file is
         * @param p_manifest The manifest file which holds all our other files
         * @param p_records The records wé're saving to
         */
    void load_all(const std::string& p_location, const std::string& p_manifest, WeatherLogType& p_records);

}
}

#endif // FILEPARSE_H
