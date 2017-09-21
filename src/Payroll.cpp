#include "Payroll.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
//#include <sstream>

using namespace std;

string getEmployeeName()
{
	string name;
	string first_name;
	string last_name;
	cout << "Enter employee's first and last name: ";
	cin >> first_name >> last_name;
	name = first_name + " " + last_name;
	return name;
}

int getEmploymentCategory()
{
	string category;
	int category_choice;
	cout << "Enter employment category (salary or hourly): ";
	cin >> category;

	while (!(category == "salary" || category == "hourly"))
	{
		cout << "ERROR: Please enter salary or hourly: ";
		cin >> category;
	}

	if (category == "salary")
	{
		category_choice = 1;
	}
	else
	{
		category_choice = 2;
	}

	return category_choice;
}

int getYearlySalary()
{
	int yearly_salary;

	cout << "Enter yearly salary: ";
	cin >> yearly_salary;

	while (yearly_salary < 20000 || yearly_salary > 100000)
	{
		cout << "ERROR: Please enter salary between $20,000 and $100,000: ";
		cin >> yearly_salary;
	}

	return yearly_salary;
}

int getOtHours()
{
	int ot_hours;

	cout << "Enter overtime hours worked: ";
	cin >> ot_hours;

	while (ot_hours < 0 || ot_hours > 60)
	{
		cout << "ERROR: Please enter overtime hours betwee 0-60: ";
		cin >> ot_hours;
	}

	return ot_hours;
}
double getPayRate()
{
	double pay_rate;

	cout << "Enter regular pay rate: ";
	cin >> pay_rate;

	while (pay_rate < 0 || pay_rate > 50)
	{
		cout << "ERROR: Please enter regular pay rate between $0 and $50: ";
		cin >> pay_rate;
	}
	return pay_rate;
}

double getSalaryRegularPay(int yearly_salary, double BI_WEEKLY)
{
	return yearly_salary / BI_WEEKLY;
}
double getHourlyRegularPay(int HOURS, double pay_rate)
{
	return HOURS * pay_rate;
}

double getOtRate(double pay_rate, double OT_RATE_PERCENT)
{
	return pay_rate * OT_RATE_PERCENT;
}
double getOtPay(int ot_hours, double ot_rate)
{
	return ot_hours * ot_rate;
}

double getGrossPay(double regular_pay, double ot_pay)
{
	return regular_pay + ot_pay;
}

double getFIT(double gross_pay, double FIT_RATE)
{
	return gross_pay * FIT_RATE;
}

double getFICASSN(double gross_pay, double FICA_SS_RATE)
{
	return gross_pay * FICA_SS_RATE;
}
double getFICAMED(double gross_pay, double FICA_MED_RATE)
{
	return gross_pay * FICA_MED_RATE;
}
double getNetPay(double gross_pay, double fica_med, double fica_ss, double fit)
{
	return gross_pay - (fica_med + fica_ss + fit);
}

int getTotalHours(int regular_hours, int ot_hours)
{
	return regular_hours + ot_hours;
}
//getNetPay uses the functions getGrossPay, getFIT, getFICASSN, getFICAMED
/*stringstream stringPayroll(string name, int total_hours, int ot_hours, double pay_rate, double ot_rate, double regular_pay, double ot_pay, double gross_pay, double fica_ss, double fica_med, double fit, double net_pay)
{
	stringstream ss;
	//format headers with tab spacing and values formatted for columns with 2 decimal places
	ss << fixed << showpoint << setprecision(2)
		<< left << name
		<< right << setw(12) << total_hours
		<< right << setw(12) << ot_hours
		<< right << setw(13) << pay_rate
		<< right << setw(11) << ot_rate
		<< right << setw(20) << regular_pay
		<< right << setw(11) << ot_pay
		<< right << setw(19) << gross_pay
		<< right << setw(15) << fica_ss
		<< right << setw(16) << fica_med
		<< right << setw(12) << fit
		<< right << setw(11) << net_pay
		<< endl;
	return ss;

} */
void printPayroll(string output)
{
	cout << "\nName \t\tHours \t OT Hours \t Rate \t OT Rate \t Regular Pay \t OT Pay \t Gross Pay \t FICA SSN \t FICA Med \t FIT \t Net Pay" << endl;
	cout << output << endl;
}
