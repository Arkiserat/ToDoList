//
// Created by Arkiserat on 14/02/2022.
//

#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H

#include <stdexcept>
#include <ctime>

class Date
{
private:
    int day, month, year;
public:
    Date();
    Date(int day, int month, int year);
    ~Date();

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setDate(Date d);

    bool operator<=(const Date &date) const;
    bool operator<(const Date &date) const;
};

#endif //TODOLIST_DATE_H