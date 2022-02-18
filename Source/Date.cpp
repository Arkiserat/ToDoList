//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/Date.h"

Date::Date() = default;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::~Date() = default;

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    Date::day = day;
}

void Date::setMonth(int month) {
    Date::month = month;
}

void Date::setYear(int year) {
    Date::year = year;
}
