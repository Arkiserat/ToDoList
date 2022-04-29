//
// Created by Arkiserat on 14/02/2022.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <list>
#include "Task.h"


class ToDoList {
private:
    std::list<Task> tasks_to_do;
    std::list<Task> tasks_done;

public:
    ToDoList();

    virtual ~ToDoList();

    // Basic methods
    void add_task(Task t);
    void modify_task_name(Task t, std::string new_name);
    void modify_task_date(Task t, Date date);
    void toggle_task_done(Task t);
    void delete_task(Task t);
    std::list<Task>::iterator select_task(Task t);

    // Counters
    int count_tot();
    int count_done();
    int count_not_done();
    int count_expired();
    int count_not_expired();

    //printer
    void print_tasks() const;
};

#endif //TODOLIST_TODOLIST_H