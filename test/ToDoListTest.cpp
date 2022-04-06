//
// Created by Arkiserat on 28/03/2022.
//

#ifndef TODOLIST_TESTTODOLIST_CPP
#define TODOLIST_TESTTODOLIST_CPP

#include "../Header/ToDoList.h"
#include "gtest/gtest.h"

#include <iostream>

class ToDoListTest : public ::testing::Test {
public:
    void SetUp() override{
        t = Task("test");
        t1.add_task(t);
    }
    void TearDown() override{
        delete &t0;
        delete &t1;
    }

    ToDoList t0;
    ToDoList t1;
    Task t;
};

TEST_F(ToDoListTest, IsEmptyInitially){
    EXPECT_EQ(t0.count_tot(), 0);
}

TEST_F(ToDoListTest, AddTaskWorks){
    t0.add_task(t);
    EXPECT_EQ(t0.count_tot(), 1);
    EXPECT_EQ(t0.count_done(), 0);
    EXPECT_EQ(t0.count_not_done(), 1);
}

TEST_F(ToDoListTest, modifyTaskNameWorks){
    t1.modify_task_name(t, "new name");
    t.setName("new name");
    EXPECT_NE(t1.select_task(t), nullptr);
}

TEST_F(ToDoListTest, modifyTaskDateWorks){
    EXPECT_EQ(t1.count_not_expired(), 1);
    EXPECT_EQ(t1.count_expired(), 0);

    Date d = Date(1, 1, 2021);
    t1.modify_task_date(t, d);

    EXPECT_EQ(t1.count_not_expired(), 0);
    EXPECT_EQ(t1.count_expired(), 1);
}

TEST_F(ToDoListTest, toggleTaskDoneWorks){
    EXPECT_EQ(t1.count_not_done(), 1);
    EXPECT_EQ(t1.count_done(), 0);

    t1.toggle_task_done(t);

    EXPECT_EQ(t1.count_not_done(), 0);
    EXPECT_EQ(t1.count_done(), 1);
}

TEST_F(ToDoListTest, deleteTaskWorks){
    ASSERT_EQ(t1.count_tot(), 1);

    t1.delete_task(t);

    EXPECT_EQ(t1.count_tot(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif //TODOLIST_TESTTODOLIST_CPP
