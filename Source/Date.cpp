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
    setYear(year);
    setMonth(month);
    setDay(day);
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
    bool ok = true;
    int m = this->month;

    if(day <= 0)
        ok = false;
    else {
        //if february
        if (m == 2) {
            //if year is bissexstile
            if (this->year % 4 == 0) {
                if (day > 29)
                    ok = false;
            } else {
                if (day > 28)
                    ok = false;
            }
        } else{
            //if month have 31 days
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                if (day > 31)
                    ok = false;
            }
            else{
                //if month have not 31 days
                if(m == 4 || m == 6 || m == 9 || m == 11){
                    if(day > 30)
                        ok = false;
                }
            }
        }
    }
    if(!ok)
        throw std::out_of_range("wrong day");
    else
        Date::day = day;
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12)
        throw std::out_of_range("wrong month");
    else
        Date::month = month;
}

void Date::setYear(int year) {
    if(year < 1900 || year > 2100) {
        throw std::out_of_range("Wrong year"); // segmentation fault
    }else {
        Date::year = year;
    }
}

void Date::setDate(Date d) {
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