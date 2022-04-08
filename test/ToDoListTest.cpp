//
// Created by Arkiserat on 28/03/2022.
//

#ifndef TODOLIST_TESTTODOLIST_CPP
#define TODOLIST_TESTTODOLIST_CPP

#include "../Header/ToDoList.h"
#include "gtest/gtest.h"

#include <iostream>

class ToDoListTest : public ::testing::Test {
protected:
    void SetUp() override{
        t0 = new ToDoList();
        t1 = new ToDoList();

        t = Task("test");
        t1->add_task(t);
    }
    void TearDown() override{
        delete t0;
        delete t1;
    }

    ToDoList *t0;
    ToDoList *t1;
    Task t;
};

TEST_F(ToDoListTest, IsEmptyInitially){
    EXPECT_EQ(t0->count_tot(), 0);
}

TEST_F(ToDoListTest, AddTaskWorks){
    t0->add_task(t);
    EXPECT_EQ(t0->count_tot(), 1);
    EXPECT_EQ(t0->count_done(), 0);
    EXPECT_EQ(t0->count_not_done(), 1);

    t.setName("another test");
    t0->add_task(t);
    EXPECT_EQ(t0->count_tot(), 2);
    EXPECT_EQ(t0->count_done(), 0);
    EXPECT_EQ(t0->count_not_done(), 2);

    t.setName("beautiful test");
    t.toggleDone();
    t0->add_task(t);
    EXPECT_EQ(t0->count_tot(), 3);
    EXPECT_EQ(t0->count_done(), 1);
    EXPECT_EQ(t0->count_not_done(), 2);
}

TEST_F(ToDoListTest, modifyTaskNameWorks){
    t1->modify_task_name(t, "new name");
    EXPECT_THROW(t1->select_task(t), std::runtime_error);

    t.setName("new name");
    std::list<Task>::iterator it;
    EXPECT_NO_THROW(it = t1->select_task(t));
    EXPECT_EQ(it->getName(), t.getName());
}

TEST_F(ToDoListTest, modifyTaskDateWorks){
    EXPECT_EQ(t1->count_not_expired(), 1);
    EXPECT_EQ(t1->count_expired(), 0);

    Date d = Date(1, 1, 2021);

    EXPECT_NO_THROW(t1->modify_task_date(t, d));

    EXPECT_EQ(t1->count_not_expired(), 0);
    EXPECT_EQ(t1->count_expired(), 1);
}

TEST_F(ToDoListTest, toggleTaskDoneWorks){
    EXPECT_EQ(t1->count_not_done(), 1);
    EXPECT_EQ(t1->count_done(), 0);

    t1->toggle_task_done(t);

    EXPECT_EQ(t1->count_not_done(), 0);
    EXPECT_EQ(t1->count_done(), 1);
}

TEST_F(ToDoListTest, deleteTaskWorks){
    ASSERT_EQ(t1->count_tot(), 1);

    Task newT = Task("failing delete test");
    EXPECT_THROW(t1->delete_task(newT), std::runtime_error);
    EXPECT_EQ(t1->count_tot(), 1);

    EXPECT_NO_THROW(t1->delete_task(t));
    EXPECT_EQ(t1->count_tot(), 0);
}

#endif //TODOLIST_TESTTODOLIST_CPP
