//
// Created by Arkiserat on 17/02/2022.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H

#include "ToDoList.h"
#include "Task.h"
#include "ToDoInterf.h"

class Observer {
private:
    ToDoInterf* interf;

public:
    Observer(ToDoInterf* i);

    virtual ~Observer();

    void update();

};


#endif //TODOLIST_OBSERVER_H
