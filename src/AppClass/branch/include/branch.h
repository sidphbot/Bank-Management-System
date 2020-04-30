#ifndef _BRANCH_H_
#define _BRANCH_H_

#include<iostream>
#include<string>
using namespace std;


class Branch
{
   long int m_branchId;
   string m_branchLoc, m_branchRegion;
   long int m_accountNo;
   long int m_BM;
   int m_bstatus;
   public:
   Branch();
   Branch(long int, string, string, long int, long int);
   Branch(long int, string, string, long int, long int, int);
   ~Branch(){}
   void setBranchLocation(string);
   void setBranchRegion(string);
   void setBranchAccountNo(long int);
   void setBM(long int);
   void setBranchId(long int);
   
   string getBranchLocation();
   string getBranchRegion();
   long int getBranchAccountNo();
   long int getBM();
   long int getBranchId();
};

#endif
