
#include "../Include/Customer.h"
#include<string>
#include<iostream>
using namespace std;


Customer::Customer()
{
   m_CustomerId=0;
   m_CustomerName=" ";
   m_CustomerAge=0;
   m_CustomerGender=' ';
   m_CustomerAddress=" ";
   m_CustomerAtmStatus=" ";
   //m_BillId=0;
   //m_Amount=0;
    m_dob=" ";
}

Customer::Customer(long int p_CustomerId, string p_CustomerName , string p_dob , char p_CustomerGender , string p_CustomerAddress , string p_CustomerAtmStatus)
{
m_CustomerId=p_CustomerId;
m_CustomerName=p_CustomerName;
m_dob=p_dob;
m_CustomerGender=p_CustomerGender;
m_CustomerAddress=p_CustomerAddress;
m_CustomerAtmStatus=p_CustomerAtmStatus;
}

Customer::Customer(string p_CustomerName,string p_dob,char p_CustomerGender,string p_CustomerAddress,string p_CustomerAtmStatus)
{
   
   m_CustomerName=p_CustomerName;
   m_dob=p_dob;
   m_CustomerGender=p_CustomerGender;
   m_CustomerAddress=p_CustomerAddress;
   m_CustomerAtmStatus=p_CustomerAtmStatus;
}
/*Customer::Customer(int p_BillId, int p_Amount, long int p_CustomerId)
{
m_CustomerId=p_CustomerId;
m_BillId=p_BillId;
m_Amount=p_Amount;
}*/

Customer::Customer(long p_CustomerID)
{
m_CustomerId=p_CustomerID;
}
void Customer :: setCustomerdob(string p_dob)
{
m_dob=p_dob;
}
/*void Customer :: setCustomerBillId(int p_BillId)
{
m_BillId=p_BillId;
}
void Customer :: setCustomerAmount(int p_Amount)
{
m_Amount=p_Amount;
}
int Customer:: getCustomerBillId()
{
return m_BillId;  
}
int Customer:: getCustomerAmount()
{
return m_Amount;
}*/
string Customer:: getCustomerdob()
{
return m_dob;
}
void Customer::setCustomerName(string p_CustomerName)
{
   m_CustomerName=p_CustomerName;
}

void Customer::setCustomerAge(int p_CustomerAge)
{
    m_CustomerAge=p_CustomerAge;
}

void Customer::setCustomerGender(char p_CustomerGender)
{
    m_CustomerGender=p_CustomerGender;
}

void Customer::setCustomerAddress(string p_CustomerAddress)
{
   m_CustomerAddress=p_CustomerAddress;
}

void Customer::setCustomerAtmStatus(string p_CustomerAtmStatus)
{
   m_CustomerAtmStatus=p_CustomerAtmStatus;
}


void Customer::setCustomerId(long p_Id)
{
m_CustomerId=p_Id;
}
string Customer::getCustomerName()
{
   return m_CustomerName;
}


int Customer::getCustomerAge()
{
   return m_CustomerAge;
}

char Customer::getCustomerGender()
{
   return m_CustomerGender;
}


string Customer::getCustomerAddress()
{
   return m_CustomerAddress;
}


string Customer::getCustomerAtmStatus()
{
   return m_CustomerAtmStatus;
}

long Customer::getCustomerId()
{
   return m_CustomerId;
}


