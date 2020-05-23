
#ifndef  _BANKACCOUNTUI_H_
#define _BANKACCOUNTUI_H_
#include "../../../AppClass/BranchAccount/Include/BranchAccount.h"
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
#include <iostream>
#include<vector>
using namespace std;

class BranchAccountUI
{
   public:
   long getBranchAccountNo();
   long getBranchID();
   double getBranchThreshold();
   double getCurrentBalance();
   void display(BranchAccount &);
   void displayAccountNo(long int);
   int displayUpdateOptions();
   long int getNewBranchId(BranchAccount &);
   double getNewBranchThreshold(BranchAccount &);
   double getNewCurrentBalance(BranchAccount &);
     void display(vector<BranchAccount>);
};

#endif
