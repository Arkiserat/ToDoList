//
// Created by Arkiserat on 17/02/2022.
//

#include "../Header/Observer.h"

Observer::Observer() = default;

Observer::~Observer() = default;

void Observer::update(Task* t) {
    list->task_done(*t);
}

void Observer::setList(ToDoList *l) {
    this->list = l;
}
