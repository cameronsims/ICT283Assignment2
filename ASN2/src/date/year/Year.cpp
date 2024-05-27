#include "Year.h"

Year::Year() : m_year(1) { }

Year::~Year() {}

Year::Year(int p_year) : m_year(1) {
    this->setYear(p_year);
}

int Year::getYear() const {
    return this->m_year;
}

Year& Year::setYear(int p_year) {
    this->m_year = p_year;

    return *this;
}
