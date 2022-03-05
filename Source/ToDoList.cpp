//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/ToDoList.h"

ToDoList::ToDoList(std::string nome, Observer *o) : nome(nome), o(o){
    // passare this ad un costruttore che richiedeva un parametro per riferimento
    // a ToDoList per costruire un Observer non funzionava, diceva che this non era
    // compatibile con il costruttore di default, non usava il costruttore da me definito
    // che era:
    // Observer(ToDoList* l)
}

ToDoList::~ToDoList() {
    tasks_to_do.clear();
    tasks_done.clear();
}

void ToDoList::add_task(Task t) {
    // richiesta di parametri del nuovo Task
    // al momento è una "simulazione"
    std::string nome = "primo task";
    Date data;

    // The element is constructed in-place by calling allocator_traits::construct
    // with args forwarded.
    tasks_to_do.emplace_back(nome, data);

}

void ToDoList::modify_task_name(Task t, std::string new_name) {
    //gestione lancio eccezione da parte di select_task
    auto it = select_task(t);

    it->setName(new_name);
}

void ToDoList::modify_task_date(Task t, Date date) {
    //gestione lancio eccezione da parte di select_task
    auto it = select_task(t);

    it->setDate(date);
}

void ToDoList::toggle_task_done(Task t) {
    //gestione lancio eccezione da parte di select_task
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
    //gestione lancio eccezione da parte di select_task
    auto it = select_task(t);

    if( !t.isDone() )
        tasks_to_do.erase(it);
    else
        tasks_done.erase(it);
}

std::list<Task>::iterator ToDoList::select_task(Task t) {
    //next: gestione di task non esistente nelle liste e task t passato come null
    //solo lancio eccezione senza gestione?
    if( !t.isDone() ){
        for(auto it = tasks_to_do.begin(); it != tasks_to_do.end(); it++)
            if( it->getName() == t.getName() )
                return it;
    } else {
        for(auto it = tasks_done.begin(); it != tasks_done.end(); it++)
            if( it->getName() == t.getName() )
                return it;
    }
}

const std::list<Task> &ToDoList::getTasksToDo() const {
    return tasks_to_do;
}

const std::list<Task> &ToDoList::getTasksDone() const {
    return tasks_done;
}

const std::string &ToDoList::getNome() const {
    return nome;
}
