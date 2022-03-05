//
// Created by Arkiserat on 17/02/2022.
//

#include "../Header/Observer.h"

Observer::Observer(ToDoInterf *i) : interf(i) {}

Observer::~Observer() = default;

void Observer::update() {
    interf->count_tasks();
}
