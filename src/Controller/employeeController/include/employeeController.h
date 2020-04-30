#ifndef _EMPLOYEE_CONTROLLER_H_
#define _EMPLOYEE_CONTROLLER_H_

#include "../../../UI/employeeUI/include/employeeUI.h"
#include "../../../Model/Include/Model.h"
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class EmployeeController
{
   public:
   int initiateAddEmployee(EmployeeUI &,Bank &);
   int initiateViewEmployee(EmployeeUI &,Bank &);
   int initiateUpdateEmployee(EmployeeUI &,Bank &);
   int initiateDeactivateEmployee(EmployeeUI &,Bank &);
   void initiateViewAllemployees(EmployeeUI &,Bank &);




   void initiateViewDeactivatedEmployees(EmployeeUI &,Bank &);


};

#endif  
