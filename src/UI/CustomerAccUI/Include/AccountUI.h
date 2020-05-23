#ifndef _ACCOUNTUI_H_
#define _ACCOUNTUI_H_
#include "../../../AppClass/CustomerAcc/Include/Account.h"
#include"../../../Validation/Include/Validation.h"
#include"../../../Utility/Include/Utility.h"
#include<string>
#include<vector>
#include "../../../Model/Include/Model.h"
using namespace std;
class AccountUI
{
   public:
         void displayfind(long int ,char[],char[] ,char[] ,char[] ,double); 
        void displayAccount(char[],char[],double ,char[]);
        void displayfixed(char[],int ,char[] ,double ,char[]);
        int getMaturityPeriod();
	long int getAccountNo();
	string getAccounttype();
	double getAccountBalance();
        double getDepositAmount();
        int  getDepositYears();
        double getBalance();
        double getSalariedBalance();
        double getNonSalBalance();
        int displayAccountTypeMenu();
        int displaySavingsMenu();
        double getAmount();
        void displayTransaction(long int,long int,string,string,double);
        char displayConfirmAction();
        void displayMessage(string);
        void displayTransactionHeader();
 void displayRequest(long,long,char*,long);
  int getNumberOfCheques();
 void displayDetails(int,long int,char*,char*,char*,int);
 int displayAccountlist2(long int);
 void displayNoRecords();
 void displayRequestGenerated();
 void displayheader();
void displayUpdate();
        void displayDeactivate();
        void displayAction();
        void displayExists();
        void displayInvalid();
string getAccountStatus();
void displayAccountlist(vector<Account>);
 char displayRecord(long int,char *,long int,double,int); 
void displayBillWater(long int,int,double,long int);   
   void displayBillElec(long int,int,double,long int);
   void displayBillPhone(long int,int,double,long int);
int getBillId();
   float getBillAmount();
   int getBillScreen();
};

#endif
