#include "WeatherRecType.h"

asn2::weather::WeatherRecord::WeatherRecord() {}

asn2::weather::WeatherRecord::WeatherRecord(const asn2::weather::WeatherRecord& p_record) : WindRecord() {
    // Set irreguardless
    this->timestamp = p_record.timestamp;

    // If not null
    if (p_record.speed != nullptr) {
        this->speed = new float((*p_record.speed));
    }
    // if not null
    if (p_record.airTemp != nullptr) {
        this->airTemp = new float((*p_record.airTemp));
    }
    // if not null
    if (p_record.solarRad != nullptr) {
        this->solarRad = new int((*p_record.solarRad));
    }
}

asn2::weather::WeatherRecord& asn2::weather::WeatherRecord::operator= (const asn2::weather::WeatherRecord& p_record) {
    // Set irreguardless
    this->timestamp = p_record.timestamp;

    if (this == &p_record) {
        return *this;
    }

    // If not null
    if (p_record.speed != nullptr) {
        this->speed = new float((*p_record.speed));
    }
    // if not null
    if (p_record.airTemp != nullptr) {
        this->airTemp = new float((*p_record.airTemp));
    }
    // if not null
    if (p_record.solarRad != nullptr) {
        this->solarRad = new int((*p_record.solarRad));
    }

    // Return this
    return (*this);
}

asn2::weather::WeatherRecord::~WeatherRecord() {
    // If not nullptr
    if (this->solarRad != nullptr) {
        // Delete
        delete this->solarRad;
        // Set to nullptr
        this->solarRad = nullptr;
    }
}
