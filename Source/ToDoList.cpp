//
// Created by Arkiserat on 14/02/2022.
//

#include "../Header/ToDoList.h"

ToDoList::ToDoList(){
    // passare this ad un costruttore che richiedeva un parametro per riferimento
    // a ToDoList per costruire un Observer non funzionava, diceva che this non era
    // compatibile con il costruttore di default, non usava il costruttore da me definito
    // che era:
    // Observer(ToDoList* l)
    Observer n_observer = Observer();
    n_observer.setList(this);
    ToDoList::o = n_observer;
}

ToDoList::~ToDoList() {
    tasks.clear();
}

void ToDoList::new_task() {
    // richiesta di parametri del nuovo Task
    // al momento è una "simulazione"
    std::string nome = "primo task";
    Date data = Date(1, 1, 2022);

    // The element is constructed in-place by calling allocator_traits::construct
    // with args forwarded.
    tasks.emplace_back(nome, data, &o);

}

void ToDoList::task_done(Task t) {
    for(auto it = tasks.begin(); it != tasks.end(); it++)
        if(it->getName() == t.getName()){
            tasks.erase(it);
            break;
        }
}

Task* ToDoList::select_task(int selected) {
    // se condizione non soddisfatta tirare eccezione o elaborare l'input?
    if(selected >= 0 && selected < tasks.size()) {
        auto it = tasks.begin();

        for (int i = 0; i < selected; i++)
            it++;

        return &(*it);
    }

}