//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/Task.h"

Task::Task(std::string name, Date date, Observer* o) {
    Task::name = name;
    Task::date = date;
    Task::done = false;
    Task::o = o;
}

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

void Task::end() {
    Task::done = true;
    o->update(this);
}

Task::~Task() = default;