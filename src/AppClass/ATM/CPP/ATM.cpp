#include "../Include/ATM.h"
#include<string.h>
#include<iostream>
 
using namespace std;

ATM::ATM()
{
   m_atmThresholdValue=0;
   m_atmBalance=0;
   m_atmLoc="";
   m_atmId=0;
   m_atmRegion="";
   m_atmstatus="";
}



ATM::ATM(long int p_atmId,string p_atmLoc,double p_atmBalance,string p_atmRegion,double p_atmThresholdValue,string p_atmstatus)
{
    m_atmId=p_atmId;
    m_atmLoc=p_atmLoc;
    m_atmBalance=p_atmBalance;
    m_atmRegion=p_atmRegion;
    m_atmThresholdValue=p_atmThresholdValue;
    m_atmstatus=p_atmstatus;

}



void ATM::m_setAtmThresholdValue(double p_atmThresholdValue)
{
    m_atmThresholdValue=p_atmThresholdValue;
}
double ATM::m_getAtmThresholdValue()
{
    return m_atmThresholdValue;
} 


void ATM::m_setAtmBalance(double p_atmBalance)
{
    m_atmBalance=p_atmBalance;
}
double ATM::m_getAtmBalance()
{				
    return m_atmBalance;
}
void ATM::m_setatmstatus(string p_atmstatus)
{
    m_atmstatus=p_atmstatus;
}
string ATM::m_getatmstatus()
{
  return m_atmstatus;
}
void ATM::m_setAtmLoc(string p_atmLoc)
{
   m_atmLoc=p_atmLoc;
}
string ATM::m_getAtmLoc()
{
    return m_atmLoc;
}
long int ATM:: m_getAtmid()
{
   return m_atmId;
}
void ATM::m_setAtmid(long int p_atmid)
{
   m_atmId=p_atmid;
}
void ATM::m_setAtmRegion(string p_atmRegion)
{
  m_atmRegion=p_atmRegion;
}
string ATM::m_getAtmRegion()
{
   return m_atmRegion;
}
