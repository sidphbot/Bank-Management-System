#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

 
#include<iostream>
#include<string>
using namespace std;
 
class Customer
{
   long int m_AccountNo;
   long int m_CustomerId;
   string m_CustomerName;
   int m_CustomerAge;
   char m_CustomerGender;
   string m_CustomerAddress;
   string m_CustomerAtmStatus;
   //int m_BillId;
   string m_dob;
   //int m_Amount;
   string m_AccountType;
   double m_Balance;
   public:
   Customer();
   Customer(long int,string,string,char,string,string);
   Customer(string,string,char,string,string);
   Customer(int,int, long int);  
 
   Customer(long );
   ~Customer(){}
   void setCustomerName(string);
   void setCustomerAge(int);
   void setCustomerGender(char);
   void setCustomerAddress(string);
   void setCustomerId(long);
   void setCustomerAtmStatus(string);
   //void setCustomerBillId(int);
   //void setCustomerAmount(int);
   void setCustomerdob(string);
   
    
   
   string getCustomerdob(); 
   string getCustomerName();
   int getCustomerAge();
   char getCustomerGender();
   string getCustomerAddress();
   string getCustomerAtmStatus();
   long getCustomerId();
   //int getCustomerBillId();
   //int getCustomerAmount();
};


#endif

