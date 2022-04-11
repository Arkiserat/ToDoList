
#include "Header/ToDoInterf.h"
#include <cstdlib>

int main() {
    srand(time(nullptr));

    ToDoInterf face = ToDoInterf();
    std::string task_name;
    Date expired = Date(1, 1, 2022);

    for(int i = 0; i < 10; i++){
        task_name = "number";
        task_name += std::to_string(i);
        face.add_task(task_name);
        if(rand()%2 == 1){
            face.modify_task_date(task_name, expired);
            if(rand()%2 == 1) {
                face.toggle_done(task_name);
            }
        }
    }

    face.print_interface();

    return 0;
}
