#ifndef _EMPLOYEEUI_H_
#define _EMPLOYEEUI_H_

#include "../../../AppClass/employee/include/employee.h"
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class EmployeeUI
{
   public: 
   long int getEmployeeID();
   string getEmployeeName();
   string getEmployeeDOB();
   char getEmployeeGender();
   string getEmployeeAddress();
   string getEmployeeDesignation();
   int getEmployeeStatus();
   void displayScreen();
   void displayDetails(Employee &);
   int displayUpdateScreen();
   void displayMessage(string);
   char confirmAction();
   void displayEmployeeScreen();
   void displayCustomerServiceScreen();
   void display(vector<Employee>);
   void fund();
   void displayHeading();


   
};

#endif
