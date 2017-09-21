#ifndef _PAYROLL_H
#define _PAYROLL_H
#pragma once
#include <string>
#include <sstream>
using namespace std;

string getEmployeeName();
int getEmploymentCategory();
int getTotalHours(int regular_hours, int ot_hours);
int getYearlySalary();
int getOtHours();
double getPayRate();
double getGrossPay(double gross_pay, double ot_pay);
double getSalaryRegularPay(int yearly_salary, double BI_WEEKLY);
double getHourlyRegularPay(int HOURS, double pay_rate);
double getFIT(double gross_pay, double FIT_RATE);
double getOtRate(double pay_rate, double OT_RATE_PERCENT);
double getOtPay(int ot_hours, double ot_rate);
double getFICASSN(double gross_pay, double FICA_SS_RATE);
double getFICAMED(double gross_pay, double FICA_MED_RATE);
double getNetPay(double gross_pay, double fica_med, double fica_ss, double fit);
stringstream stringPayroll(string name, int total_hours, int ot_hours, double pay_rate, double ot_rate, double regular_pay, double ot_pay, double gross_pay, double fica_ss, double fica_med, double fit, double net_pay);
void printPayroll(string output);

#endif
