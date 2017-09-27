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
TEST(payrollTests, test_get_salary_regular_pay_50k_bi_weekly){
    EXPECT_EQ(3846.153846153846, getSalaryRegularPay(100000,26));
}
TEST(payrollTests, test_get_net_pay_if_gross_5000_fmed_100_fssn_200_fit_300){
    EXPECT_EQ(530, getNetPay(1000,150,20,300));
}
TEST(payrollTests, test_get_net_pay_if_gross_5000_fmed_100_fssn_200_fit_300){
    EXPECT_EQ(4400, getNetPay(5000,100,200,300));
}
