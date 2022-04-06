//
// Created by lorenzo on 01/04/2022.
//

#ifndef TODOLIST_TESTTODOINTERF_H
#define TODOLIST_TESTTODOINTERF_H

#include "../Header/ToDoInterf.h"
#include "gtest/gtest.h"

class ToDoInterfTest : public ::testing::Test {
public:
    void SetUp() override {
        tdi0 = ToDoInterf();
        tdi1 = ToDoInterf();
        t = Task("test");
        tdi1.add_task(t);
    }

    void TearDown() override {
        delete &t;
        delete &tdi0;
        delete &tdi1;
    }

    ToDoInterf tdi0, tdi1;
    Task t;
};

TEST_F(ToDoInterfTest, addTaskWorks) {
    EXPECT_EQ(tdi0.getTasksTot(), 0);
    tdi0.add_task(t);
    EXPECT_EQ(tdi0.getTasksTot(), 1);
}

TEST_F(ToDoInterfTest, deleteTaskWorks){
    ASSERT_EQ(tdi1.getTasksTot(), 1);
    tdi1.delete_task(t);
    EXPECT_EQ(tdi1.getTasksTot(), 0);
}


#endif //TODOLIST_TESTTODOINTERF_H