//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/ToDoList.h"

ToDoList::ToDoList() = default;

ToDoList::~ToDoList() {
    tasks_to_do.clear();
    tasks_done.clear();
}

// Basic methods

void ToDoList::add_task(Task t) {
    if(t.isDone()){
        tasks_done.push_back(t);
    } else {
        tasks_to_do.push_back(t);
    }
}

void ToDoList::modify_task_name(Task t, std::string new_name) {
    auto it = select_task(t);

    it->setName(new_name);
}

void ToDoList::modify_task_date(Task t, Date date) {
    auto it = select_task(t);

    it->setDate(date);
}

void ToDoList::toggle_task_done(Task t) {
    auto it = select_task(t);

    it->toggleDone();

    if( it->isDone() ){
        tasks_done.push_back(*it);
        tasks_to_do.erase(it);
    } else {
        tasks_to_do.push_back(*it);
        tasks_done.erase(it);
    }
}

void ToDoList::delete_task(Task t) {
    auto it = select_task(t);

    if (! it->isDone())
        tasks_to_do.erase(it);
    else
        tasks_done.erase(it);
}

std::list<Task>::iterator ToDoList::select_task(Task t) {
    std::list<Task>::iterator it;

    if( !t.isDone() ){
        for(it = tasks_to_do.begin(); it != tasks_to_do.end(); it++)
            if( it->getName() == t.getName() )
                break;
    } else {
        for(it = tasks_done.begin(); it != tasks_done.end(); it++)
            if( it->getName() == t.getName() )
                break;
    }

    if(it != tasks_done.end() && it != tasks_to_do.end()) {
        return it;
    } else {
        throw std::runtime_error("not found");
    }
}

// Counters

int ToDoList::count_tot() {
    return int( tasks_to_do.size() + tasks_done.size() );
}

int ToDoList::count_done() {
    return int( tasks_done.size() );
}

int ToDoList::count_not_done() {
    return int( tasks_to_do.size() );
}

int ToDoList::count_expired() {
    Date today = Date();
    int c = 0;

    for(auto it = tasks_to_do.begin(); it != tasks_to_do.end(); it++){
        if(it->getDate() < today)
            c++;
    }
    return c;
}

int ToDoList::count_not_expired() {
    Date today = Date();
    int c = 0;

    for(auto it = tasks_to_do.begin(); it != tasks_to_do.end(); it++){
        if(today <= it->getDate())
            c++;
    }
    return c;
}

void ToDoList::print_tasks() {
    for(auto it = tasks_to_do.begin(); it != tasks_to_do.end(); it++){
        it->printTask();
    }
    for(auto it = tasks_done.begin(); it != tasks_done.end(); it++) {
        it->printTask();
    }
}
