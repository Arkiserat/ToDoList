//
// Created by Arkiserat on 27/02/2022.
//

#include "../Header/ToDoInterf.h"

#include <iostream>

ToDoInterf::ToDoInterf() {
    tasks_tot = 0;
    tasks_to_do = 0;
    tasks_done = 0;
    tasks_expired = 0;
    tasks_not_expired = 0;
}

ToDoInterf::~ToDoInterf() {
    tdl.clear();
}

void ToDoInterf::add_list(ToDoList l) {
    tdl.push_back(l);
    count_tasks();
}

void ToDoInterf::delete_list(ToDoList *l) {
    for(auto it = tdl.begin(); it != tdl.end(); it++){
        if(it->getNome() == l->getNome()){
            tdl.erase(it);
            break;
        }
    }
    count_tasks();
}

void ToDoInterf::count_tasks() {
    tasks_tot = 0;
    tasks_done = 0;
    tasks_to_do = 0;
    tasks_expired = 0;
    tasks_not_expired = 0;
    Date *today = new Date();

    for(auto it = tdl.begin(); it != tdl.end(); it++){
        std::list<Task> nd = it->getTasksToDo();
        std::list<Task> d = it->getTasksDone();
        tasks_to_do += nd.size();
        tasks_done += d.size();
        tasks_tot += tasks_to_do + tasks_done;

        for (auto ind = nd.begin(); ind != nd.end(); ind++){
            if (ind->getDate() <= *today)
                tasks_not_expired++;
            else
                tasks_expired++;
        }
        for (auto id = d.begin(); id != d.end(); id++){
            if (id->getDate() <= *today)
                tasks_not_expired++;
            else
                tasks_expired++;
        }
    }
}

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

