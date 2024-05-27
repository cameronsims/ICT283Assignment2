#include "./Time.h"

Time::Time() : m_hour(0), m_minutes(0) {

}

Time::Time(int p_hour, int p_minutes) : m_hour(0), m_minutes(0)  {
    this->setHour(p_hour);
    this->setMinutes(p_minutes);
}

int Time::getHour() const {
    return this->m_hour;
}

Time& Time::setHour(int p_hour) {
    if (p_hour < 0 || p_hour > 23) {
        // Invalid time, throw error
        throw InvalidHour();
    }


    this->m_hour = p_hour;
    return *this;
}

int Time::getMinutes() const {
    return this->m_minutes;
}

Time& Time::setMinutes(int p_minutes) {
    if (p_minutes < 0 || p_minutes > 59) {
        // Invalid time, throw error
        throw InvalidMinute();
    }


    this->m_minutes = p_minutes;
    return *this;
}
