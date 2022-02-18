//
// Created by Arkiserat on 14/02/2022.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <list>
#include "Task.h"
#include "Observer.h"

class ToDoList
{
private:
    std::list<Task::Task> tasks;
    Observer::Observer o;

public:
    ToDoList();

    virtual ~ToDoList();

    void new_task();

    void task_done(Task::Task t);

    Task* select_task(int selected);
};

#endif //TODOLIST_TODOLIST_H