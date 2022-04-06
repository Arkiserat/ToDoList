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
        tdi1.add_task("test");
    }

    void TearDown() override {
        delete &tdi0;
        delete &tdi1;
    }

    ToDoInterf tdi0, tdi1;
};

TEST_F(ToDoInterfTest, addTaskWorks) {
    EXPECT_EQ(tdi0.getTasksTot(), 0);
    tdi0.add_task("test");
    EXPECT_EQ(tdi0.getTasksTot(), 1);
}

TEST_F(ToDoInterfTest, deleteTaskWorks){
    ASSERT_EQ(tdi1.getTasksTot(), 1);
    tdi1.delete_task("test");
    EXPECT_EQ(tdi1.getTasksTot(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif //TODOLIST_TESTTODOINTERF_H