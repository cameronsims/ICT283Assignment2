#include "WindRecType.h"

asn2::weather::WindRecord::WindRecord() : timestamp() {}

asn2::weather::WindRecord::WindRecord(const WindRecord& p_record) : timestamp(p_record.timestamp) {
    // If not null
    if (p_record.speed != nullptr) {
        this->speed = new float((*p_record.speed));
    }
    // if not null
    if (p_record.airTemp != nullptr) {
        this->airTemp = new float((*p_record.speed));
    }
}

asn2::weather::WindRecord& asn2::weather::WindRecord::operator= (const WindRecord& p_record) {
    // Set irreguardless
    this->timestamp = p_record.timestamp;

    // If not null
    if (p_record.speed != nullptr) {
        this->speed = new float((*p_record.speed));
    }
    // if not null
    if (p_record.airTemp != nullptr) {
        this->airTemp = new float((*p_record.speed));
    }
    // Return this
    return (*this);
}

asn2::weather::WindRecord::~WindRecord() {
    // If not nullptr
    if (this->speed != nullptr) {
        // Delete
        delete this->speed;
        // Set to nullptr
        this->speed = nullptr;
    }

    // If not nullptr
    if (this->airTemp != nullptr) {
        // Delete
        delete this->airTemp;
        // Set to nullptr
        this->airTemp = nullptr;
    }
}
