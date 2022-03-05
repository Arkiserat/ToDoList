//
// Created by Arkiserat on 27/02/2022.
//

#ifndef TODOLIST_TODOINTERF_H
#define TODOLIST_TODOINTERF_H

#include "ToDoList.h"
#include "../Source/ToDoList.cpp"

class ToDoInterf {
private:
    std::list<ToDoList> tdl;
    int tasks_tot, tasks_done, tasks_to_do, tasks_expired, tasks_not_expired;

public:
    ToDoInterf();

    virtual ~ToDoInterf();

    void count_tasks();

    void add_list(ToDoList *l);
    void delete_list(ToDoList *l);

    int getTasksTot() const;

    int getTasksDone() const;

    int getTasksToDo() const;

    int getTasksExpired() const;

    int getTasksNotExpired() const;

};


#endif //TODOLIST_TODOINTERF_H
