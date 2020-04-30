#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include<iostream>
#include<string>
using namespace std;

class Employee
{
   long int m_employeeId;
   string m_employeeName;
   string m_employeeDOB;
   char m_employeeGender;
   string m_employeeAddress;
   string m_employeeDesignation;
   int m_employeeStatus;
   /*char m_employeeName[30];
   char m_employeeDOB[20];
   char m_employeeAddress[30];
   char m_employeeDesignation[30];*/
   public:
   Employee();
   Employee(long int,string,string,char,string,string,int);
   //Employee(long int,char[30],char[20],char,char[30],char[30],int);
   ~Employee(){}
   void setEmployeeName(string);
   void setEmployeeDOB(string);
   void setEmployeeGender(char);
   void setEmployeeAddress(string);
   void setEmployeeId(long int);
   void setEmployeeStatus(int);
   void setEmployeeDesignation(string);
   string getEmployeeName();
   string getEmployeeDOB();
   char getEmployeeGender();
   string getEmployeeAddress();
   string getEmployeeDesignation();
   long int getEmployeeId();
   int getEmployeeStatus();
};


#endif
