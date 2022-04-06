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

    void update();

    // Getters

    int getTasksTot() const;
    int getTasksDone() const;
    int getTasksToDo() const;
    int getTasksExpired() const;
    int getTasksNotExpired() const;

};


#endif //TODOLIST_TODOINTERF_H
