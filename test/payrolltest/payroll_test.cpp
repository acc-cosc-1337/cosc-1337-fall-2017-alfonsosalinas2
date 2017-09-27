#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTests, test_get_regular_pay_if_hours_40_pay_rate_25){
    EXPECT_EQ(1000, getHourlyRegularPay(40,25));
}
TEST(payrollTests, test_get_regular_pay_if_hours_50_pay_rate_20){
    EXPECT_EQ(1000, getHourlyRegularPay(50,20));
}
TEST(payrollTests, test_get_salary_regular_pay_50k_bi_weekly){
    EXPECT_EQ(1923.076923076923, getSalaryRegularPay(50000,26));
}
TEST(payrollTests, test_get_hourly_regular_pay_40_pay_rate_20){
    EXPECT_EQ(800, getHourlyRegularPay(40,20));
}
