#include "../Include/ATMController.h"
#include "../../../Model/Include/Model.h"
#include "../../../UI/ATMUI/Include/ATMUI.h"
#include "../../../UI/loginUI/include/loginUI.h"
//#include "../../../include/employeeController.h"
#include "../../../AppClass/employee/include/employee.h"
#include "../../../AppClass/login/include/login.h"

#include<string.h>
#include<iostream>
using namespace std;
 int ATMController::initiateAddATMAccount(Bank &p_DBobj)
 {
     ATMUI l_atmUI;
     //long int l_atmID;
     char l_atmLocation[30];
    double l_atmBalance;
    char l_atmRegion[30];
    double l_atmThreshold;
    char l_atmStatus[9];

    strcpy(l_atmLocation,l_atmUI.getATMLocation().c_str());
   // l_atmID=l_atmUI.getATMID();
    l_atmBalance=l_atmUI.getATMBalance();
    strcpy(l_atmRegion,l_atmUI.getATMRegion().c_str());
   // l_atmThreshold=l_atmUI.getATMThresholdValue();
    //strcpy(l_atmStatus,l_atmUI.getATMstatus().c_str());


     ATM l_tempATM;

     //l_tempATM.m_setAtmid(l_atmID);
     l_tempATM.m_setAtmLoc(l_atmLocation);
     l_tempATM.m_setAtmBalance(l_atmBalance);
     l_tempATM.m_setAtmRegion(l_atmRegion);
    // l_tempATM.m_setAtmThresholdValue(l_atmThreshold);
     //l_tempATM.m_setatmstatus(l_atmStatus);
     int l_status =  p_DBobj.addATMAccount(l_tempATM);
     return l_status;
    
}

  int ATMController::initiateATMController(Bank &p_DBobj)
  {
     ATMUI l_atmUI;
     long int l_atmID;
     //int vchoice=p_DBobj.displayDetails();
    // if(vchoice==1)
     //{
     l_atmID=l_atmUI.getATMID();
     int l_IDstatus=p_DBobj.findAtmId(l_atmID);
    if(l_IDstatus) 
     {
     // ATM l_tempAtm;
      //l_tempAtm.m_setAtmid(l_atmID);
      int l_status=p_DBobj.dbviewATM(l_atmID);
      return l_status;
    } else { cout<<"\n Not Found...";
      return !l_IDstatus;
  }  
 //} 
}
  int ATMController::initiateCloseATMController(Bank &p_DBobj)
  {
     ATMUI l_atmUI;
     long int l_atmID;
     l_atmID=l_atmUI.getATMID();
     int l_IDstatus=p_DBobj.findAtmId(l_atmID);
    if(l_IDstatus)
     {
     ATM l_tempAtm;
     l_tempAtm.m_setAtmid(l_atmID);
     int l_status=p_DBobj.dbcloseATM(l_atmID);
       return l_status;
     } else
       return !l_IDstatus;
   }
   

/*int ATMController::initiateUpdateATMController(Bank &p_DBobj)
{
  ATMUI l_atmUI;
  long int l_atmID;
  char l_atmLocation[10];
  char l_atmRegion[10];
  char l_atmStatus[9];
  l_atmID=l_atmUI.getATMID();
  

 //strcpy(l_atmLocation,l_atmUI.getATMLocation().c_str());
  //strcpy(l_atmRegion,l_atmUI.getATMRegion().c_str());
  //strcpy(l_atmStatus,l_atmUI.getATMstatus().c_str());
  int l_IDstatus=p_DBobj.findAtmId(l_atmID);
  if(l_IDstatus)
  {
    
    ATM l_tempatmobj;
   l_tempatmobj.m_setatmstatus(l_atmStatus);
   l_tempatmobj.m_setAtmLoc(l_atmLocation);
   l_tempatmobj.m_setAtmRegion(l_atmRegion);
   l_tempatmobj.m_setatmstatus(l_atmStatus);
   int l_status=p_DBobj.dbUpdateAtm(l_tempatmobj);
   return l_status;
 } 
 else
  return !l_IDstatus;
} */



int ATMController::initiateUpdateATMController(Bank &p_DBobj)
{
ATMUI l_atmUI;
ATM l_tempatm = l_atmUI.updateAtm();
long int l_atmID = l_tempatm.m_getAtmid();
if(p_DBobj.findAtmId(l_atmID) == 0)
return 0;
int l_status = p_DBobj.dbUpdateAtm(l_tempatm);
return l_status;

}
 
void ATMController::initiateViewAllAtm(ATMUI &p_atmUIObj,Bank &p_BankObj)
{
  vector<ATM> atmList;
  atmList = p_BankObj.ViewAllAtm();
  if(atmList.size()!=0)
      p_atmUIObj.display(atmList);
  else
       cout<<"\n\nRecord not Found........\n";
}  
