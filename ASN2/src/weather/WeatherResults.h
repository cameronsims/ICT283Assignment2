#ifndef WEATHERRESULTS_H
#define WEATHERRESULTS_H

#include "./WeatherResultParam.h"

#include "../date/month/Month.h"

#define ASN2_WEATHERRECORDS_PEARSON_SIZE 12

namespace asn2 {
namespace weather {

        /**
         * @author Cameron Sims
         * @date 17/05/2024
         *
         * @class WeatherResults
         */
    struct WeatherResults {
            /**
             * @brief Default constructor
             */
        WeatherResults();

            /**
             * @brief Used to copy
             * @param p_result Another result to copy from
             */
        WeatherResults(const WeatherResults& p_result);

            /**
             * @brief Used to assign
             * @param p_result Another result to copy from
             * @return Returns a reference to itself
             */
        WeatherResults& operator= (const WeatherResults& p_result);

            /**
             * @brief Used to kill not nullptr values
             */
        ~WeatherResults();

        /// The month the record was observed
        Month month;

        ///////////////////////
        //       Speed       //
        //        km/h       //
        ///////////////////////

        /// The speed of a weather result
        WeatherResultStat* speed = nullptr;

        ///////////////////////
        //  Ambient Air Temp //
        //       deg C       //
        ///////////////////////

        /// The temperature mean
        WeatherResultStat* temperature = nullptr;

        ///////////////////////
        //  Total Solar Rads //
        //      kWh/m^2      //
        ///////////////////////

        /// Total Solar Radiation
        float solarRadiation;

        ///////////////////////
        //  Pearson Corrol.  //
        //      0<=b<=1      //
        //  Where: y = bx+c  //
        ///////////////////////

        /// Speed - Temperature
        static float pcc_st[ASN2_WEATHERRECORDS_PEARSON_SIZE];

        /// Speed - Radiation
        static float pcc_sr[ASN2_WEATHERRECORDS_PEARSON_SIZE];

        /// Temp. - Radiation
        static float pcc_tr[ASN2_WEATHERRECORDS_PEARSON_SIZE];
    };

}
}

#endif // WEATHERRESULTS_H
