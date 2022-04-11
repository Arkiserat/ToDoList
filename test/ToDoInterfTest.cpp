//
// Created by lorenzo on 01/04/2022.
//

#ifndef TODOLIST_TESTTODOINTERF_H
#define TODOLIST_TESTTODOINTERF_H

#include "../Header/ToDoInterf.h"
#include "gtest/gtest.h"

class ToDoInterfTest : public ::testing::Test {
protected:
    void SetUp() override {
        tdi0 = new ToDoInterf();
        tdi1 = new ToDoInterf();
        tdi1->add_task("test");
    }

    void TearDown() override {
        delete tdi0;
        delete tdi1;
    }

    ToDoInterf *tdi0, *tdi1;
};

TEST_F(ToDoInterfTest, addTaskWorks) {
    EXPECT_EQ(tdi0->getTasksTot(), 0);

    tdi0->add_task("test");
    EXPECT_EQ(tdi0->getTasksTot(), 1);

    tdi0->add_task("another test");
    EXPECT_EQ(tdi0->getTasksTot(), 2);
}

TEST_F(ToDoInterfTest, deleteTaskWorks){
    ASSERT_EQ(tdi1->getTasksTot(), 1);

    EXPECT_THROW(tdi1->delete_task("another test"), std::runtime_error);
    EXPECT_EQ(tdi1->getTasksTot(), 1);

    EXPECT_NO_THROW(tdi1->delete_task("test"));
    EXPECT_EQ(tdi1->getTasksTot(), 0);
}

TEST_F(ToDoInterfTest, DoesModifyDate) {
    Date nd = Date(1, 1, 2022);

    EXPECT_EQ(tdi1->getTasksExpired(), 0);
    tdi1->modify_task_date("test", nd);
    EXPECT_EQ(tdi1->getTasksExpired(), 1);

    tdi1->add_task("new test");

    EXPECT_EQ(tdi1->getTasksExpired(), 1);
    tdi1->modify_task_date("new test", nd);
    EXPECT_EQ(tdi1->getTasksExpired(), 2);
}

TEST_F(ToDoInterfTest, DoesToggle) {
    EXPECT_EQ(tdi1->getTasksDone(), 0);
    tdi1->toggle_done("test");
    EXPECT_EQ(tdi1->getTasksDone(), 1);

    tdi1->add_task("new test");

    EXPECT_EQ(tdi1->getTasksDone(), 1);
    tdi1->toggle_done("new test");
    EXPECT_EQ(tdi1->getTasksDone(), 2);
}

#endif //TODOLIST_TESTTODOINTERF_H