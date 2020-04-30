#include "../Include/BranchAccount.h"


BranchAccount::BranchAccount()
{
   m_branchAccountNo=0;
   m_branchId=0;
   m_branchThreshold=2500000;
   m_currentBalance=0;
   m_Status=0;
}


BranchAccount::BranchAccount(long int p_branchAccountNo,long int p_branchId,double p_branchThreshold,double p_currentBalance,int p_Status)
{
   m_branchAccountNo=p_branchAccountNo;
   m_branchId=p_branchId;
   m_branchThreshold=p_branchThreshold;
   m_currentBalance=p_currentBalance;
    m_Status=p_Status;
}
BranchAccount::~BranchAccount()
{
}

void BranchAccount::setBranchAccountNo(long int p_branchAccountNo)
{

   m_branchAccountNo=p_branchAccountNo;
}

void BranchAccount::setBranchId(long int p_branchId)
{
   m_branchId=p_branchId;

}

void BranchAccount::setBranchThreshold(double p_branchThreshold)
{
   m_branchThreshold=p_branchThreshold;
}

void BranchAccount::setCurrentBalance(double p_currentBalance)
{
   m_currentBalance=p_currentBalance;
}
void BranchAccount::setStatus(int p_Status)
{
   m_Status=p_Status;
}

long int BranchAccount::getBranchAccountNo()
{

   return m_branchAccountNo;
}

long int BranchAccount::getBranchID()
{
   return m_branchId;
}

double BranchAccount::getBranchThreshold()
{
   return m_branchThreshold;
}
  
double BranchAccount::getCurrentBalance()
{
   return m_currentBalance;
}
int BranchAccount::getStatus()
{
   return m_Status;
}
 
