//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/Date.h"

Date::Date() {
    std::time_t now = std::time(0);
    std::tm *lt = std::localtime(&now);

    year = 1900 + lt->tm_year;
    month = 1 + lt->tm_mon;
    day = lt->tm_mday;
}

Date::Date(int day, int month, int year){
    if(!isOk(day, month, year))
        throw e;
    else{
        Date::day = day;
        Date::month = month;
        Date::year = year;
    }
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

void Date::setDay(int day){
    if(!isOk(day, this->month, this->year))
        throw e;
    else
        Date::day = day;
}

void Date::setMonth(int month) {
    if(! isOk(this->day, month, this->year))
        throw e;
    else
        Date::month = month;
}

void Date::setYear(int year) {
    if(! isOk(this->day, this->month, year)){
        throw e;
    } else {
        Date::year = year;
    }
}

void Date::setDate(const Date& d) {
    this->setYear(d.getYear());
    this->setMonth(d.getMonth());
    this->setDay(d.getDay());
}

bool Date::operator<=(const Date &date) const{
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

bool Date::operator<(const Date &date) const{
    if (this->year < date.getYear())
        return true;
    else
        if (this->year == date.getYear()) {
            if (this->month < date.getMonth())
                return true;
            else
                if (this->month == date.getMonth()){
                    if (this->day < date.getDay())
                        return true;
                }
        }
    return false;
}

bool Date::isOk(int d, int m, int y) const{
    if(y < 1900 || y > 2100)
        return false;

    if(m < 1 || m > 12)
        return false;

    if(d <= 0)
        return false;
    else {
        //if february
        if (m == 2) {
            //if year is bissexstile
            if (y % 4 == 0) {
                if (d > 29)
                    return false;
            } else {
                if (d > 28)
                    return false;
            }
        } else{
            //if month have 31 days
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                if (d > 31)
                    return false;
            }
            else{
                //if month have not 31 days
                if(m == 4 || m == 6 || m == 9 || m == 11){
                    if(d > 30)
                        return false;
                }
            }
        }
    }
    return true;
}