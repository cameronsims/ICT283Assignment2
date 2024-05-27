// main.cpp - Entry of the program
#include "./weather/WeatherConvert.h"
#include "./menu/Menu.h"
#include "./FileParse.h"

int main() {

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    // The way that the new WeatherLogType works is like the following diagram:    //
    //                                                                             //
    // [MAP]            2015-------------2016-------------2017                     //
    // [BST]             6                4                9                       //
    //                 /    \           /    \            /  \                     //
    //                5      7         2      5          7   12                    //
    //                                                                             //
    //                                                                             //
    // We're the year has at most 12 records, all refering to one month.           //
    // This means that we can have a VERY fast insertion / assignment              //
    // operation where the first                                                   //
    //                                                                             //
    // The map has a best case of O(1) with a worse case O(n)                      //
    // The bst has a best case of O(1) with worse case O(log n)                    //
    // Therefore our best case is O(1) with a worse case nlog(m)                   //
    //                                                                             //
    // where n is elements in map and m is elements in bst.                        //
    // We could potentially improve this by using an unordered_map rather          //
    // than a normal map.                                                          //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    // Show Author, done so that we know the program has initiated
    asn2::menu::showAuthor();

    // The wind data that will be modified
    WeatherLogType weather_data;      // (Make the value large so we don't need to resize for a while)

    /////////////////////////////////////////////////////////////
    //                                                         //
    // WE ARE GOING TO READ THE FILES IN THE "data_source.txt" //
    // FILE IN the "data" FILE IN THE ROOT.                    //
    //                                                         //
    // WE WILL BE READING FILE(S) WHICH CONTAIN THE DATA       //
    // READ THE "readme.txt" in "data" for more                //
    //                                                         //
    /////////////////////////////////////////////////////////////

    // The file we are getting the input file(s) from:
    const std::string FILES_LOCATION = "./data/",
                      FILES_MANIFEST = FILES_LOCATION + "data_source.txt",
                      FILES_SAVE = FILES_LOCATION + "WindTempSolar.csv";

    // Loads the files
    asn2::file::load_all(FILES_LOCATION, FILES_MANIFEST, weather_data);

    // Make a Map with a BST
    WeatherCalender calender = asn2::weather::calenderise(weather_data);

    // What do we do with "weather_data???"
    // please refer to the video for documentation reguarding this matter:
    //    https://youtu.be/dyIilW_eBjc
    weather_data = WeatherLogType();

    //////////////////////////////////////////////////////////////
    //                                                          //
    // WE HAVE NOW GOT ALL THE VAUES RECORDED IN "weather_data" //
    // WE ARE NOW ENTERING THE MENU PORTION OF THE PROGRAM      //
    // THERE WILL BE INPUT NEEDED FOR THE USER TO PROGRESS      //
    //                                                          //
    //////////////////////////////////////////////////////////////

    // Loop if we're not exiting the program
    int exit_code = asn2::menu::loop(calender, FILES_SAVE);

    // Return, the program has ended successfully
    return exit_code;
}
