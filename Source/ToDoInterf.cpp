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

void ToDoInterf::add_task(std::string n) {
    Task t = Task(n);
    tdl->add_task(t);
    update();
}

void ToDoInterf::delete_task(std::string n) {
    Task t = Task(std::move(n));
    std::list<Task>::iterator it;

    try{
        tdl->delete_task(t);
    } catch (std::runtime_error& e){
        t.toggleDone();
        tdl->delete_task(t);
    }

    update();
}

void ToDoInterf::modify_task_name(std::string task, std::string new_name) {
    Task t = Task(task);
    try {
        tdl->modify_task_name(t, new_name);
    } catch (std::runtime_error& e1) {
        try {
            t.toggleDone();
            tdl->modify_task_name(t, new_name);
        } catch (std::runtime_error& e2) {
            std::cout << "shit! No new name for: " << task << std::endl;
        }
    }
}

void ToDoInterf::modify_task_date(std::string task, Date new_date) {
    Task t = Task(task);
    try{
        tdl->modify_task_date(t, new_date);
    } catch (std::runtime_error& e1) {
        try{
            t.toggleDone();
            tdl->modify_task_date(t, new_date);
        } catch (std::runtime_error& e2) {
            std::cout << "shit! No new date for: " << task << std::endl;
        }
    }
    update();
}

void ToDoInterf::toggle_done(std::string task) {
    Task t = Task(task);
    try{
        tdl->toggle_task_done(t);
    } catch (std::runtime_error& e1){
        try {
            t.toggleDone();
            tdl->toggle_task_done(t);
        } catch (std::runtime_error& e2) {
            std::cout << "shit! No toggle on: " << task << std::endl;
        }
    }
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

// printer

void ToDoInterf::print_interface() {
    std::cout << "tot: " << tasks_tot << ", to do: " << tasks_to_do << ", expired: " << tasks_expired << std::endl;
    tdl->print_tasks();
}

