#include "../Include/BranchAccountController.h"
//#include "../../../Model/Include/Model.h"
//#include "../../../UI/BranchAccountUI/Include/BranchAccountUI.h"

int BranchAccountController::initiateBranchAccountAddition(BranchAccountUI &p_UI,Bank &p_db)
{
   long int l_branchId;
   double l_branchThreshold;
   double l_currentBalance;
   l_branchId=p_UI.getBranchID();
   if(l_branchId==2)
   {
    return 0;
   }
   //cout<<"b id = "<<l_branchId;
   l_branchThreshold=p_UI.getBranchThreshold();
   if(l_branchThreshold==2)
   {
    return 0;
   }
   l_currentBalance=p_UI.getCurrentBalance();
   if(l_currentBalance==2)
 {
    return 0;
   }

   BranchAccount l_tempBranchAccount;
   l_tempBranchAccount.setBranchId(l_branchId);
   l_tempBranchAccount.setBranchThreshold( l_branchThreshold);
   l_tempBranchAccount.setCurrentBalance( l_currentBalance);
   long int l_branchAccountNumber =p_db.addBranchAccount(l_tempBranchAccount);
   p_UI.displayAccountNo(l_branchAccountNumber);
   return 1;
}

int BranchAccountController::initiateBranchAccountView(BranchAccountUI &p_UI,Bank &p_db)
{
long int l_branchAccountNumber = p_UI.getBranchAccountNo();
   if(l_branchAccountNumber==2)
 {
    return 0;
   }


if(p_db.findBranchAccount(l_branchAccountNumber) == 0)
{
cout<<"Account not found";
return 0;
}
BranchAccount l_tempBranchAccount = p_db.viewBranchAccount(l_branchAccountNumber);
cout<<l_tempBranchAccount.getBranchAccountNo();
p_UI.display(l_tempBranchAccount);
return 1; 

}


int BranchAccountController::initiateBranchAccountUpdation(BranchAccountUI &p_UI,Bank &p_db)
{
  int l_status;
  long int l_branchId;
   double l_branchThreshold;
   double l_currentBalance;
  long int l_branchAccountNumber;
  l_branchAccountNumber=p_UI.getBranchAccountNo();
   if(l_branchAccountNumber==2)
 {
    return 0;
   }


  if(p_db.findBranchAccount(l_branchAccountNumber) ==0)
  {
     cout<<"Account not found";
     return 0;
  } 
  BranchAccount l_tempBranchAccount=p_db.viewBranchAccount(l_branchAccountNumber);
  int l_choice=p_UI.displayUpdateOptions();
  BranchAccount l_tempBranchAccount1;  
  switch(l_choice)
  {
    case 1:l_branchId=p_UI.getNewBranchId(l_tempBranchAccount);
           l_tempBranchAccount.setBranchId(l_branchId);
           l_status=p_db.updateBranchID(l_tempBranchAccount);
           l_tempBranchAccount1 = p_db.viewBranchAccount(l_branchAccountNumber);
           p_UI.display(l_tempBranchAccount1);
           return l_status;
   case 2:l_branchThreshold=p_UI.getNewBranchThreshold(l_tempBranchAccount);
           l_tempBranchAccount.setBranchThreshold(l_branchThreshold);
           l_status=p_db.updateBranchThreshold(l_tempBranchAccount);
           l_tempBranchAccount1 = p_db.viewBranchAccount(l_branchAccountNumber);
           p_UI.display(l_tempBranchAccount1);
           return l_status;
  case 3:l_currentBalance=p_UI.getNewCurrentBalance(l_tempBranchAccount);
           l_tempBranchAccount.setCurrentBalance(l_currentBalance);
           l_status=p_db.updateCurrentBalance(l_tempBranchAccount);
           l_tempBranchAccount1 = p_db.viewBranchAccount(l_branchAccountNumber);
           p_UI.display(l_tempBranchAccount1);
           return l_status;    

  }
return 0;
}



int BranchAccountController::initiateBranchAccountDeletion(BranchAccountUI &p_UI,Bank &p_db)
{
long int l_branchAccountNumber = p_UI.getBranchAccountNo();   
   if(l_branchAccountNumber==2)
 {
    return 0;
   }


if(p_db.findBranchAccount(l_branchAccountNumber) == 0)
return 0;
int l_status = p_db.deleteBranchAccount(l_branchAccountNumber);
return l_status;

}

  void BranchAccountController::initiateViewAllBranchAccount(BranchAccountUI &p_UI,Bank &p_db)
{
  vector<BranchAccount> ViewList;
  ViewList = p_db.ViewAllBranchAccount();
  if(ViewList.size()!=0)
     p_UI .display(ViewList);
  else
      cout<<"\n\nRecord not Found........";
}    

