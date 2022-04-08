//
// Created by lorenzo on 29/03/2022.
//

#ifndef TODOLIST_TESTTASK_CPP
#define TODOLIST_TESTTASK_CPP

#include "../Header/Task.h"
#include "gtest/gtest.h"

class TaskTest : public ::testing::Test {
protected:
    void SetUp() override{
        t = Task("test");
    }

    void TearDown() override {
    }

    Task t;
};

TEST_F(TaskTest, costructorWorks){
    EXPECT_EQ(t.getName(), "test");
}

TEST_F(TaskTest, toggleDoneWorks){
    EXPECT_EQ(t.isDone(), false);
    t.toggleDone();
    EXPECT_EQ(t.isDone(), true);
}

#endif //TODOLIST_TESTTASK_CPP
