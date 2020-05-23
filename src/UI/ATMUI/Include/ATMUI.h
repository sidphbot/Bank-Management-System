#ifndef _ATMUI_H_
#define _ATMUI_H_
#include<string.h>
#include<iostream>
#include<vector>
#include"../../../AppClass/ATM/Include/ATM.h"
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
using namespace std;

class ATMUI
{
public:
long int getATMID();
string getATMLocation();
double getATMBalance();
string getATMRegion();
string getATMstatus();
//double getATMThresholdValue();
int displayUpdateMenu();
ATM updateAtm();
int displayATMMenu();
char getChoice();
void displayAll(long int,string,double,string,string);
void displayCustNotFound();
void displayMsg();
void displayUpdate();
void displayDeactivate();
void displayRMsg();
void displayAddMsg();
void displayFailMsg();
void display(vector<ATM>);
};

#endif
