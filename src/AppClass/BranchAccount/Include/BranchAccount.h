#ifndef  _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <iostream>
using namespace std;

class BranchAccount
{
   long int m_branchAccountNo;
   long int m_branchId;
   double m_branchThreshold;
   double m_currentBalance;
   int m_Status;

   public:
   BranchAccount();
   BranchAccount(long int,long int,double,double,int);
   ~BranchAccount();

   void setBranchAccountNo(long int);
   void setBranchId(long);
   void setBranchThreshold(double);
   void setCurrentBalance(double);
     void setStatus(int);

   long int getBranchAccountNo();
   long int getBranchID();
   double getBranchThreshold();
   double getCurrentBalance();
     int getStatus();

};

#endif
