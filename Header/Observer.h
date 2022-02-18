//
// Created by Arkiserat on 17/02/2022.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H

#include "ToDoList.h"
#include "Task.h"

class Observer {
private:
    ToDoList* list;

public:
    Observer();

    virtual ~Observer();

    void update(Task* t);

    void setList(ToDoList *l);
};


#endif //TODOLIST_OBSERVER_H
