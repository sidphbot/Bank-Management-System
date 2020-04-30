
#include "../include/branch.h"
#include<string>

Branch::Branch()
{
   m_branchLoc="";
   m_branchRegion="";
   m_accountNo=0;
   m_branchId =0;
   m_BM =0;
   
}

Branch::Branch(long int p_branchId, string p_branchLoc, string p_branchRegion, long int p_accountNo, long int p_BM)
{
   m_BM = p_BM;
   m_branchLoc = p_branchLoc;
   m_branchRegion = p_branchRegion;
   m_accountNo = p_accountNo;
   m_branchId = m_branchId;

}

Branch::Branch(long int p_branchId, string p_branchLoc, string p_branchRegion, long int p_accountNo, long int p_BM, int p_bstatus)
{
   m_BM = p_BM;
   m_branchLoc = p_branchLoc;
   m_branchRegion = p_branchRegion;
   m_accountNo = p_accountNo;
   m_branchId = m_branchId;
   m_bstatus = m_bstatus;
}


void Branch::setBM(long int p_empID)
{
  m_BM = p_empID; 
}

void Branch::setBranchAccountNo(long int p_accNO)
{
  m_accountNo = p_accNO;
}

void Branch::setBranchRegion(string p_branchRegion)
{
  m_branchRegion = p_branchRegion;
}

void Branch::setBranchLocation(string p_branchLoc)
{
  m_branchLoc =  p_branchLoc;
}

void Branch::setBranchId(long int p_branchId)
{
  m_branchId = p_branchId;
}

long int Branch::getBranchId()
{
   return m_branchId;
}

long int Branch::getBM()
{
   return m_BM;
}

long int Branch::getBranchAccountNo()
{
   return m_accountNo;
}

string Branch::getBranchRegion()
{
   return m_branchRegion;
}

string Branch::getBranchLocation()
{
   return m_branchLoc;
}

