#include "WeatherResults.h"

float asn2::weather::WeatherResults::pcc_st[ASN2_WEATHERRECORDS_PEARSON_SIZE] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

    // Speed - Radiation
float asn2::weather::WeatherResults::pcc_sr[ASN2_WEATHERRECORDS_PEARSON_SIZE] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

    // Temp. - Radiation
float asn2::weather::WeatherResults::pcc_tr[ASN2_WEATHERRECORDS_PEARSON_SIZE] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

asn2::weather::WeatherResults::WeatherResults() : month(1), solarRadiation(0.0f) {
    this->speed = nullptr;
    this->temperature = nullptr;
}

asn2::weather::WeatherResults::WeatherResults(const WeatherResults& p_result) : month(p_result.month), solarRadiation(p_result.solarRadiation) {
    this->speed = nullptr;
    this->temperature = nullptr;

    // Copy over
    if (p_result.speed != nullptr) {
        this->speed = new WeatherResultStat();

        // Copy params
        this->speed->mean =  p_result.speed->mean;
        this->speed->stdev = p_result.speed->stdev;
        this->speed->mad =   p_result.speed->mad;
    }

    if (p_result.temperature != nullptr) {
        this->temperature = new WeatherResultStat();

        // Copy params
        this->temperature->mean =  p_result.temperature->mean;
        this->temperature->stdev = p_result.temperature->stdev;
        this->temperature->mad =   p_result.temperature->mad;
    }
}

asn2::weather::WeatherResults& asn2::weather::WeatherResults::operator= (const asn2::weather::WeatherResults& p_result) {
    // Check if it is the same
    if (this == &p_result) {
        return *this;
    }

    // Set date
    this->month = p_result.month;
    this->solarRadiation = p_result.solarRadiation;
    this->speed = nullptr;
    this->temperature = nullptr;

    // Copy over
    if (p_result.speed != nullptr) {
        this->speed = new WeatherResultStat();

        // Copy params
        this->speed->mean =  p_result.speed->mean;
        this->speed->stdev = p_result.speed->stdev;
        this->speed->mad =   p_result.speed->mad;
    }

    if (p_result.temperature != nullptr) {
        this->temperature = new WeatherResultStat();

        // Copy params
        this->temperature->mean =  p_result.temperature->mean;
        this->temperature->stdev = p_result.temperature->stdev;
        this->temperature->mad =   p_result.temperature->mad;
    }

    return (*this);
}

asn2::weather::WeatherResults::~WeatherResults() {
    // If windspeed isn't nullptr
    if (this->speed != nullptr) {
        // Delete it
        delete this->speed;
        // Continue with your day
        this->speed = nullptr;
    }

    // If temperature isn't nullptr
    if (this->temperature != nullptr) {
        // Delete it
        delete this->temperature;
        // Continue with your day
        this->temperature = nullptr;
    }
}
