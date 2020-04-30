#include "../include/employee.h"
#include<iostream>
#include<string.h>
using namespace std;
Employee::Employee()
{
   m_employeeId=0;
   m_employeeName="";
   m_employeeDOB="";
   m_employeeGender=' ';
   m_employeeAddress="";
   m_employeeDesignation="";
   m_employeeStatus=1;
}

Employee::Employee(long int p_employeeId,string p_employeeName,string p_employeeDOB,char p_employeeGender,string p_employeeAddress,string p_employeeDesignation, int p_employeeStatus=1)
{
   m_employeeId=p_employeeId;
   m_employeeName=p_employeeName;
   m_employeeDOB=p_employeeDOB;
   m_employeeGender=p_employeeGender;
   m_employeeAddress=p_employeeAddress;
   m_employeeDesignation=p_employeeDesignation;
   m_employeeStatus=p_employeeStatus;
}


/*Employee::Employee(long int p_employeeId,char p_employeeName[30],char p_employeeDOB[20],char p_employeeGender,char p_employeeAddress[30],char p_employeeDesignation[30], int p_employeeStatus=1)
{
   m_employeeId=p_employeeId;
   strcpy(m_employeeName,p_employeeName);
   strcpy(m_employeeDOB,p_employeeDOB);
   m_employeeGender=p_employeeGender;
   strcpy(m_employeeAddress,p_employeeAddress);
   strcpy(m_employeeDesignation,p_employeeDesignation);
   m_employeeStatus=p_employeeStatus;
}*/


void Employee::setEmployeeName(string p_employeeName)
{
    m_employeeName=p_employeeName;
}

void Employee::setEmployeeDOB(string p_employeeDOB)
{
    m_employeeDOB=p_employeeDOB;
}

void Employee::setEmployeeGender(char p_employeeGender)
{
    m_employeeGender=p_employeeGender;
}

void Employee::setEmployeeAddress(string p_employeeAddress)
{
   m_employeeAddress=p_employeeAddress;
}

void Employee::setEmployeeDesignation(string p_employeeDesignation)
{
   m_employeeDesignation=p_employeeDesignation;
}


void Employee::setEmployeeId(long int p_employeeId)
{
   m_employeeId=p_employeeId;
}

void Employee::setEmployeeStatus(int p_employeeStatus)
{
   m_employeeStatus=p_employeeStatus;
}

string Employee::getEmployeeName()
{
   return m_employeeName;
}


string Employee::getEmployeeDOB()
{
   return m_employeeDOB;
}

char Employee::getEmployeeGender()
{
   return m_employeeGender;
}


string Employee::getEmployeeAddress()
{
   return m_employeeAddress;
}


string Employee::getEmployeeDesignation()
{
   return m_employeeDesignation;
}


long int Employee::getEmployeeId()
{
   return m_employeeId;
}


int Employee::getEmployeeStatus()
{
   return m_employeeStatus;
}



