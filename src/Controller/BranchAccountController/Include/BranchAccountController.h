
#ifndef _BRANCHACCOUNTCONTROLLER_H_
#define _BRANCHACCOUNTCONTROLLER_H_
#include "../../../AppClass/BranchAccount/Include/BranchAccount.h"
#include "../../../UI/BranchAccountUI/Include/BranchAccountUI.h"
#include "../../../Model/Include/Model.h"
#include <iostream>
using namespace std;

class BranchAccountController
{
   public:
   int initiateBranchAccountAddition(BranchAccountUI&,Bank&);
   int initiateBranchAccountView(BranchAccountUI&,Bank&);
   int initiateBranchAccountUpdation(BranchAccountUI&,Bank&);
   int initiateBranchAccountDeletion(BranchAccountUI&,Bank&);
      void initiateViewAllBranchAccount(BranchAccountUI&,Bank&);
};

#endif
