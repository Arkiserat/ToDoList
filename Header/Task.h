//
// Created by Arkiserat on 14/02/2022.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <string>
#include "Date.h"

class Task
{
private:
    bool done;
    std::string name;
    Date date;

public:
    Task(std::string name);

    ~Task();

    bool isDone() const;
    const std::string &getName() const;
    const Date &getDate() const;

    void setName(const std::string &name);
    void setDate(const Date &date);
    void toggleDone();

    void printTask() const;

};

#endif //TODOL