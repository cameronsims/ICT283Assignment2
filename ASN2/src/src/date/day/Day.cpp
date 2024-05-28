#include "Day.h"

Day::Day() : m_day(1) { }

Day::~Day() {}

Day::Day(int p_day) : m_day(1) {
    this->setDay(p_day);
}

int Day::getDay() const {
    return this->m_day;
}

Day& Day::setDay(int p_day) {
    if (p_day < 1 || p_day > 31) {
        throw InvalidDay();
    }

    this->m_day = p_day;
    return *this;

}
