//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/Task.h"
#include <iostream>

Task::Task(std::string name) {
    Task::name = name;
    Task::date = Date();
    Task::done = false;
}

Task::~Task() = default;

bool Task::isDone() const {
    return done;
}

const std::string &Task::getName() const {
    return name;
}

const Date &Task::getDate() const {
    return date;
}

void Task::setName(const std::string &name) {
    Task::name = name;
}

void Task::setDate(const Date &date) {
    Task::date = date;
}

void Task::toggleDone() {
    if(done)
        Task::done = false;
    else
        Task::done = true;
}

void Task::printTask() const {
    if(done)
        std::cout << " _ " << name << " " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
    else
        std::cout << " X " << name << " " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
}