//
// Created by Arkiserat on 27/02/2022.
//

#include "../Header/ToDoInterf.h"

#include <iostream>

// Constructor and Destroyer

ToDoInterf::ToDoInterf() {
    tdl = new ToDoList();
    tasks_tot = 0;
    tasks_to_do = 0;
    tasks_done = 0;
    tasks_expired = 0;
    tasks_not_expired = 0;
}

ToDoInterf::~ToDoInterf() {
    delete tdl;
}

// main methods

void ToDoInterf::add_task(Task t) {
    tdl->add_task(t);
    update();
}

void ToDoInterf::delete_task(Task t) {
    tdl->delete_task(t);
    update();
}

void ToDoInterf::update() {
    tasks_tot = tdl->count_tot();
    tasks_done = tdl->count_done();
    tasks_to_do = tdl->count_not_done();
    tasks_expired = tdl->count_expired();
    tasks_not_expired = tdl->count_not_expired();
}

// Getter

int ToDoInterf::getTasksTot() const {
    return tasks_tot;
}

int ToDoInterf::getTasksDone() const {
    return tasks_done;
}

int ToDoInterf::getTasksToDo() const {
    return tasks_to_do;
}

int ToDoInterf::getTasksExpired() const {
    return tasks_expired;
}

int ToDoInterf::getTasksNotExpired() const {
    return tasks_not_expired;
}

