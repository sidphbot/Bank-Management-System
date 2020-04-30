#include"../include/branchController.h"
#include"../../../AppClass/branch/include/branch.h"
#include"../../../UI/branchUI/include/branchUI.h" 
//#include"../../../bank/include/bank.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


long int BranchController::initiateBranchAddition(Bank &db)

{
BranchUI l_UI;
string l_branchLocation;
string l_branchRegion;
system("clear");
l_UI.display("\n--------------------------------------branch initiation menu---------------------------------------------\n");
long int l_branchBM = l_UI.getBranchBM();
if(l_branchBM==2)
return 0;
l_branchLocation = l_UI.getBranchLocation();
if(l_branchLocation=="2")
return 0;
l_branchRegion = l_UI.getBranchRegion();
if(l_branchRegion=="2")
return 0;
Branch l_tempBranch;
l_tempBranch.setBranchLocation(l_branchLocation);
l_tempBranch.setBranchRegion(l_branchRegion);
l_tempBranch.setBM(l_branchBM);
long int l_status = db.addBranch(l_tempBranch);




return l_status;
}

int BranchController::initiateViewBranch(Bank &db)
{
BranchUI l_UI;
long int l_branchID = l_UI.getBranchID();
if(l_branchID==2)
{
return 0;
}
if(db.findBranch(l_branchID) == 0)
{l_UI.display("\nBranch not found\n");
return 0;}
Branch l_tempBranch = db.viewBranch(l_branchID);
l_tempBranch.setBranchId(l_branchID);
l_UI.displayBranch(l_tempBranch);
return 1; 

}


int BranchController::initiateDeleteBranch(Bank &db)
{
BranchUI l_UI;
long int l_branchID = l_UI.getBranchID();
if(l_branchID==2)
{
return 0;
}
if(db.findBranch(l_branchID) == 0)
{l_UI.display("\nBranch not found\n");
return 0;}
int l_status = db.deleteBranch(l_branchID);
return l_status;

}


int BranchController::initiateUpdateBranch(Bank &db)
{
BranchUI l_UI;
long int l_branchID = l_UI.getBranchID();
if(l_branchID==2)
{
return 0;
}
if(db.findBranch(l_branchID) == 0)
{l_UI.display("\nBranch not found\n");
return 0;}
Branch l_tempBranch = db.viewBranch(l_branchID);
l_tempBranch.setBranchId(l_branchID);
l_UI.displayBranch(l_tempBranch);
l_UI.display("\n");
l_tempBranch = l_UI.updateBranch();
l_tempBranch.setBranchId(l_branchID);
int l_status = db.updateBranch(l_tempBranch);
return l_status;


}

void BranchController::initiateViewAllBranches(BranchUI &p_BranchUIObj,Bank &p_BankObj)
{
  vector<Branch> BranchList;
  BranchList = p_BankObj.ViewAllBranches();
  if(BranchList.size()!=0)
      p_BranchUIObj.display(BranchList);
  else
       cout<<"\n\nRecord not Found........\n";
}    



























