//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/Date.h"
#include <ctime>

Date::Date() {
    std::time_t now = std::time(0);
    std::tm *lt = std::localtime(&now);

    year = 1900 + lt->tm_year;
    month = 1 + lt->tm_mon;
    day = lt->tm_mday;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    //next: gestione di date sbagliate
}

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

bool Date::operator<=(Date &date) const{
    if (this->year < date.getYear())
        return true;
    else
        if (this->year == date.getYear()) {
            if (this->month < date.getMonth())
                return true;
            else
                if (this->month == date.getMonth()){
                    if (this->day <= date.getDay())
                        return true;
                }
        }
    return false;
}
