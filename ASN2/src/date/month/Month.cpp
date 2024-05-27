#include "Month.h"

Month::Month() : m_month(1) {}

Month::Month(int p_month) : m_month(1) {
    this->setMonth(p_month);
}

Month::~Month() {}

int Month::getMonth() const {
    return this->m_month;
}

Month& Month::setMonth(int p_month) {
    if (p_month < 1 || p_month > 12) {
        throw InvalidMonth();
    }

    this->m_month = p_month;
    return *this;

}
