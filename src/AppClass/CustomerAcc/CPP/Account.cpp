#include"../Include/Account.h"
#include <iostream>
#include <string>
using namespace std;
 Account::Account()
{
  m_accountno=0;
  m_accounttype=" ";
  m_customerID=0;
  m_balance=0;
   m_BillId=0;
  m_Amount=0;
}

int Account :: m_getAccountStatus()
{
   return m_accountStatus;
}
void Account :: m_setAccountStatus(int p_accountStatus)
{
  m_accountStatus=p_accountStatus;
}

 Account :: Account(long int p_accno,string p_accType,long int p_custID,double p_accountBalance)
{
  m_accountno=p_accno;
  m_accounttype=p_accType;
  m_customerID=p_custID;
  m_balance=p_accountBalance;
}

long int Account::m_getAccountNo()
{
  return m_accountno;
}

void Account::m_setAccountNo(long int p_accountno)
{
  m_accountno=p_accountno;
}

void Account::m_setAccountType(string p_accType)
{
  m_accounttype=p_accType;
}

string Account::m_getAccountType()
{
  return m_accounttype;
}

void Account::m_setCustomerID(long int p_custID)
{
   m_customerID=p_custID;
}

long int Account::m_getCustomerID()
{
  return m_customerID;
}
double Account::m_getBalance()
{
return m_balance;
}
void Account::m_setBalance(double p_balance)
{
m_balance=p_balance;
}
Account::Account(long int p_accountno,string p_accType)
{
 m_accountno=p_accountno;    
 m_accounttype=p_accType;
}

void Account :: m_setAmount(double p_Amount)
{
m_Amount=p_Amount;
}
void Account :: m_setBillId(int p_BillId)
{
m_BillId=p_BillId;
}
double Account :: m_getAmount()
{
return m_Amount;
}
int Account :: m_getBillId()
{
return m_BillId;
}
/*void Account::m_setAccountStatus(int p_status)
{
   m_status=p_status;
}*/

