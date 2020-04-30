#ifndef _ATMCONTROLLER_H_
#define _ATMCONTROLLER_H_
#include<iostream>
#include<string.h>

#include "../../../UI/ATMUI/Include/ATMUI.h"

#include "../../../Model/Include/Model.h"
using namespace std;
 class ATMController
{
  public:
 int initiateAddATMAccount(Bank &);
 int initiateATMController(Bank &);
 int initiateCloseATMController(Bank &);
 int initiateUpdateATMController(Bank&);
 void initiateViewAllAtm(ATMUI &,Bank &);
 //int findAtmId(long int);
};

#endif

