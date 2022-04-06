//
// Created by lorenzo on 29/03/2022.
//

#ifndef TODOLIST_TESTDATE_CPP
#define TODOLIST_TESTDATE_CPP

#include "../Header/Date.h"
#include "gtest/gtest.h"

class DateTest : public ::testing::Test {
public:
    void test_default_constructor();

    void test_setDay();
    void test_setMonth();
    void test_setYear();
    void test_operator_me();
    void test_operator_m();
};

/*
 * EXPECT_THROW(statement,exception_type)
 * ASSERT_THROW(statement,exception_type)
 * Verifies that statement throws an exception of type exception_type.
 *
 * EXPECT_ANY_THROW(statement)
 * ASSERT_ANY_THROW(statement)
 * Verifies that statement throws an exception of any type.
 *
 * EXPECT_NO_THROW(statement)
 * ASSERT_NO_THROW(statement)
 * Verifies that statement does not throw any exception.
 */


#endif //TODOLIST_TESTDATE_CPP
