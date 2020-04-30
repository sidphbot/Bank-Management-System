#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

 
#include<iostream>
#include<string>
using namespace std;
 

class Account
{
 int m_accountStatus;
   long int m_accountno;
   string m_accounttype;
   long int m_customerID;
   double m_balance;
  double m_Amount; 
  int m_BillId;
 int  m_status;

   
public:
   Account();
void m_setAccountStatus(int);
   ~Account(){}
   Account(long int,string);
   Account(long int,string,long int,double);
   long int m_getAccountNo();
   void m_setAccountNo(long int);
   void m_setAccountType(string);
   string m_getAccountType();
   void m_setCustomerID(long int);
   long int m_getCustomerID();
  void  m_setBalance(double);
   double m_getBalance();
  int m_getAccountStatus();

double  m_getAmount();
void m_setAmount(double);
int m_getBillId();
void m_setBillId(int);
 //void m_setAccountStatus(int);
};

#endif

