//
// Created by Arkiserat on 14/02/2022.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <list>
#include "Task.h"
#include "Observer.h"

//creare una classe "interfaccia che tenga
// - numero di task da fare
// - numero di task scaduti
// - numero di task fatti

class ToDoList {
private:
    std::string nome;
    std::list<Task> tasks_to_do;
    std::list<Task> tasks_done;

    Observer* o;

public:
    ToDoList(std::string nome, Observer* o);

    virtual ~ToDoList();

    //parametro task
    void add_task(Task t);
    void modify_task_name(Task t, std::string new_name);
    void modify_task_date(Task t, Date date);
    void toggle_task_done(Task t);
    void delete_task(Task t);
    std::list<Task>::iterator select_task(Task t);

    const std::string &getNome() const;

    const std::list<Task> &getTasksToDo() const;
    const std::list<Task> &getTasksDone() const;
};

#endif //TODOLIST_TODOLIST_H