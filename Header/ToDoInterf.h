//
// Created by Arkiserat on 27/02/2022.
//

#ifndef TODOLIST_TODOINTERF_H
#define TODOLIST_TODOINTERF_H

#include "ToDoList.h"

class ToDoInterf{
private:
    ToDoList *tdl;
    int tasks_tot, tasks_done, tasks_to_do, tasks_expired, tasks_not_expired;

public:
    ToDoInterf();
    virtual ~ToDoInterf();

    // main methods
    void add_task(std::string n);
    void delete_task(std::string n);

    void modify_task_name(std::string task, std::string new_name);
    void modify_task_date(std::string task, Date new_date);
    void toggle_done(std::string task);

    void update();

    // Getters

    int getTasksTot() const;
    int getTasksDone() const;
    int getTasksToDo() const;
    int getTasksExpired() const;
    int getTasksNotExpired() const;

    // printer
    void print_interface();

};

#endif //TODOLIST_TODOINTERF_H
