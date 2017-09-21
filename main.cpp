/*
1) Prompts user for employee name and employee category (salary or hourly)
2) Prompts hourly employees for hours worked and prompts for yearly salary when salaried employee
3) Prompts hourly employees for a pay rate.
4) Calculates regular gross salary
For salaried employees assume a bi-weekly pay
5) Calculates overtime hours and pay for hourly employees
Assume 40 hour work week and weekly pay
Salary employees don't qualify for OT pay
6) Calculates federal income tax(FIT) deduction at a flat rate of 15%
7) Calculate FICA SS tax at 6.2% and FICA medicare at 1.45% deductions
8) Calculates net pay
9) Displays the pay check to screen
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Payroll.h"
//#include <sstream>

using namespace std;

int main()
{
	//stringstream ss;
	string output;

	string name,
		category;

	double pay_rate = 0.00,
		ot_rate = 0.00,
		yearly_salary,
		regular_pay = 0.0,
		gross_pay,
		overtime_hours,
		ot_pay = 0.00,
		net_pay,
		fit,
		fica_ss,
		fica_med;

	int total_hours,
		ot_hours = 0,
		category_choice;

	const double FIT_RATE = 0.15,
		FICA_SS_RATE = 0.062,
		FICA_MED_RATE = 0.0145,
		OT_RATE_PERCENT = 1.5;

	const int BI_WEEKLY = 26,
		HOURS = 40;

	enum category_choices { salary = 1, hourly = 2 };

	for (int counter = 1; counter <= 3; counter++)
	{
		//prompt for name and category
		name = getEmployeeName();
		cout << endl;

		category_choice = getEmploymentCategory();
		cout << endl;

		//decision structure based on employee category (salary vs hourly)
		switch (category_choice)
		{
		case salary: yearly_salary = getYearlySalary();
			regular_pay = getSalaryRegularPay(yearly_salary, BI_WEEKLY);
			break;
		case hourly:
			ot_hours = getOtHours();
			pay_rate = getPayRate();
			ot_rate = getOtRate(pay_rate, OT_RATE_PERCENT);
			ot_pay = getOtPay(ot_hours, ot_rate);
			regular_pay = getHourlyRegularPay(HOURS, pay_rate);
			break;
		}

		//calculate gross pay, federal taxes, total hours worked, and net pay
		gross_pay = getGrossPay(regular_pay, ot_pay);
		fit = getFIT(gross_pay, FIT_RATE);
		fica_med = getFICAMED(gross_pay, FICA_MED_RATE);
		fica_ss = getFICASSN(gross_pay, FICA_SS_RATE);
		total_hours = getTotalHours(HOURS, ot_hours);
		net_pay = getNetPay(gross_pay, fica_med, fica_ss, fit);

		//format headers with tab spacing and values formatted for columns with 2 decimal places
		//ss = stringPayroll(name, total_hours, ot_hours, pay_rate, ot_rate, regular_pay, ot_pay, gross_pay, fica_ss, fica_med, fit, net_pay);
		//cout << endl;
		//output += ss.str();

	}

	printPayroll(output);

	return 0;
}
