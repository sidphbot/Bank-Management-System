
#ifndef _ATM_H_
#define _ATM_H_


#include<iostream>
#include<string.h>
using namespace std;


class ATM
{
   double m_atmThresholdValue;
   double m_atmBalance;
   string m_atmLoc; 
   long int m_atmId;
   string m_atmRegion;
   string m_atmstatus;
   public:
   ATM();
   ATM(long int,string,double,string,double,string);
   ~ATM(){}
   void m_setAtmThresholdValue(double);
   void m_setAtmBalance(double);
   void m_setAtmLoc(string);
   long int m_getAtmid();
   void m_setAtmid(long int);
   double m_getAtmThresholdValue();
   double m_getAtmBalance();
   string m_getAtmLoc();
   string m_getatmstatus();
   void m_setatmstatus(string);
   void m_setAtmRegion(string);
   string m_getAtmRegion();

};
#endif
