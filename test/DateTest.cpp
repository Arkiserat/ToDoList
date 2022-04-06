//
// Created by lorenzo on 29/03/2022.
//

#ifndef TODOLIST_TESTDATE_CPP
#define TODOLIST_TESTDATE_CPP

#include "../Header/Date.h"
#include "gtest/gtest.h"

class DateTest : public ::testing::Test {
public:
    void SetUp() override {
        now = std::time(0);
        lt = std::localtime(&now);

        t = Date();
    }

    void TearDown() override {
        delete &t;
        delete &now;
        delete lt;
    }

    Date t;
    std::time_t now;
    std::tm *lt;
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

TEST_F(DateTest, defaultConstructorWorks){

    int y = 1900 + lt->tm_year;
    int m = 1 + lt->tm_mon;
    int d = lt->tm_mday;

    EXPECT_EQ(t.getYear(), y);
    EXPECT_EQ(t.getMonth(), m);
    EXPECT_EQ(t.getDay(), d);
}

TEST_F(DateTest, setYearWorks) {
    EXPECT_THROW(t.setYear(0), std::out_of_range);
    EXPECT_THROW(t.setYear(999999), std::out_of_range);
    EXPECT_NO_THROW(t.setYear(2025));
}

TEST_F(DateTest, setMonthWorks) {
    EXPECT_THROW(t.setMonth(0), std::out_of_range);
    EXPECT_THROW(t.setMonth(13), std::out_of_range);
    EXPECT_NO_THROW(t.setMonth(2));
}

TEST_F(DateTest, setDayWorks) {
    EXPECT_THROW(t.setDay(0), std::out_of_range);
    EXPECT_THROW(t.setDay(33), std::out_of_range);
    EXPECT_NO_THROW(t.setDay(12));

    t.setMonth(2);
    EXPECT_THROW(t.setDay(30), std::out_of_range);
    t.setYear(2020);
    EXPECT_NO_THROW(t.setDay(29));
    t.setMonth(6);
    EXPECT_THROW(t.setDay(31), std::out_of_range);
    t.setMonth(3);
    EXPECT_NO_THROW(t.setDay(31));
}

TEST_F(DateTest, minEqOperatorWorks) {
    Date today = Date(5, 4, 2022);
    Date yesterday = Date(4, 4, 2022);

    EXPECT_EQ(yesterday <= today, true);
    EXPECT_EQ(today <= yesterday, false);

    yesterday.setDate(today);
    EXPECT_EQ(yesterday <= today, true);
    EXPECT_EQ(today <= yesterday, true);
}

TEST_F(DateTest, minOperatorWorks) {
    Date today = Date(5, 4, 2022);
    Date yesterday = Date(4, 4, 2022);

    EXPECT_EQ(yesterday < today, true);
    EXPECT_EQ(today < yesterday, false);

    yesterday.setDate(today);
    EXPECT_EQ(yesterday < today, false);
    EXPECT_EQ(today < yesterday, false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif //TODOLIST_TESTDATE_CPP
