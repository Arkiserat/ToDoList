//
// Created by Arkiserat on 17/02/2022.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H

class ToDoList;

class Observer {

public:
    Observer();

    virtual ~Observer();

    virtual void update() = 0;

};


#endif //TODOLIST_OBSERVER_H
