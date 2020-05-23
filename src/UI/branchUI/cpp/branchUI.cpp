#include "../include/branchUI.h"
#include "../../../AppClass/branch/include/branch.h"
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<iomanip>
using namespace std;

void BranchUI::display(string p_str)
{

cout<<p_str;

}


string BranchUI::getBranchLocation()
{
string l_branchlocation;
do{
cout<<"\n Branch Location:";
cin>>l_branchlocation;
int l_ValidStatus = Validation :: validateString1(l_branchlocation);
  	if(l_ValidStatus == 1)
        {
         if(l_branchlocation=="exit")
         {
          return "2";
         }
         else
        return l_branchlocation;
}
}while(1);
}



string BranchUI::getBranchRegion(){
string l_branchRegion,l_choice;
int l_choice1, k;
do{
k=0;
cout<<"\n Branch Region:\n\t 1.East\n\t2.West\n\t3.north\n\t4.south\n\t5.central\nEnter choice: ";
cin>>l_choice;
if(l_choice=="exit")
return "2";
int l_ValidStatus = Validation :: validateChoice(l_choice);
  	if(l_ValidStatus == 0)
        {
         cout<<"\ninvalid choice.. please enter a numeric value\n";
         k=1;
        }
}while(k);
l_choice1= Utility::convertToInt(l_choice);
switch(l_choice1)
{
case 1: l_branchRegion="east";
        break;
case 2: l_branchRegion="west";
        break;
case 3: l_branchRegion="north";
        break;
case 4: l_branchRegion="south";
        break;
case 5: l_branchRegion="central";
        break;
default:cout<<"\ninvalid region selection\n"; 
        break;
}
return l_branchRegion;

}

long int BranchUI::getBranchID(){
string l_branchID;
do{
cout<<"\n Branch ID:";
cin>>l_branchID;
if(l_branchID=="exit")
return 2;
int l_ValidStatus = Validation :: validateNumber1(l_branchID);
  	if(l_ValidStatus == 1)
      return Utility::convertToLong(l_branchID);
}while(1);

}


long int BranchUI::getBranchAccountNo(){
string l_accountNo;
do{
cout<<"\n Branch AccountNo:";
cin>>l_accountNo;
int l_ValidStatus = Validation :: validateNumber1(l_accountNo);
  	if(l_ValidStatus == 1)
return Utility::convertToLong(l_accountNo);
}while(1);
}

long int BranchUI::getBranchBM(){
string l_branchBM;
do{
cout<<"\n Branch BM:";
cin>>l_branchBM;
if(l_branchBM=="exit")
return 2;
int l_ValidStatus = Validation :: validateNumber1(l_branchBM);
  	if(l_ValidStatus == 1)
return Utility::convertToLong(l_branchBM);
}while(1);
}

void BranchUI::displayBranch(Branch &p_branch)
{
int l_branchID = p_branch.getBranchId();
string l_branchLocation = p_branch.getBranchLocation();
string l_branchRegion = p_branch.getBranchRegion();
int l_branchBM = p_branch.getBM();
int l_branchAccNo = p_branch.getBranchAccountNo();
system("clear");
cout<<"\n------------------------------------------The details are-------------------------------------------\n";
cout<<"\nBranchID: "<<l_branchID;
cout<<"\nBranch location: "<<l_branchLocation;
cout<<"\nBranch region: "<<l_branchRegion;
cout<<"\nBranch Branchmanager: "<<l_branchBM;
if(l_branchAccNo)
cout<<"\nBranch acc no: "<<l_branchAccNo<<"\n";
else
cout<<"\nBranch acc no: "<<"Account not created yet"<<"\n";


}

Branch BranchUI::updateBranch()
{
int l_choice1;
int k=0;
string l_choice, l_region;
Branch l_branch;
cout<<"\n\n-----------------------------------------Update Branch--------------------------------------------\n\n";
cout<<"\n\t\t\t1. Branch Manager(emp no)\n\t\t\t2. Location \n\t\t\t3.exit";
do{
k=0;
cout<<"\nenter your choice: ";
cin>>l_choice;
int l_ValidStatus = Validation :: validateChoice(l_choice);
        if(l_ValidStatus == 0)
	{cout<<"\ninvalid choice.. please enter a numeric value\n";
	 k=1;}
cout<<"\n";
}while(k);
l_choice1= Utility::convertToInt(l_choice);

switch(l_choice1)
{
case 1:
       l_branch.setBM(getBranchBM());
       break;
case 2:
       l_branch.setBranchLocation(getBranchLocation());
       break;
//case 3:l_region= getBranchRegion();
  //     l_branch.setBranchRegion(l_region);
    //   cout<<l_region;
     //  break;
case 3:
       break;
default: 
       cout<<"\nwrong option"; 
       break;
}

return l_branch;

}

void BranchUI::display(vector<Branch> BranchList)
{
   
   system("clear");
   vector<Branch>::iterator BranchIter;
   cout<<"\n\t\t\t\t\t\t\t **************** Branch details **************** \n\n";
   cout<<left<<setw(15)<<setfill(' ')<<"Branch_ID";    
   cout<<left<<setw(30)<<setfill(' ')<<"Branch_Location";    
   cout<<left<<setw(20)<<setfill(' ')<<"Branch_Region";    
   cout<<left<<setw(20)<<setfill(' ')<<"Account_No";    
   cout<<left<<setw(20)<<setfill(' ')<<"BranchManagerId";    
   
   cout<<"\n";
   cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------\n";


   for(BranchIter=BranchList.begin();BranchIter != BranchList.end();BranchIter++)
   {
      cout<<left<<setw(15)<<setfill(' ')<<(*BranchIter).getBranchId();
      cout<<left<<setw(30)<<setfill(' ')<<(*BranchIter).getBranchLocation();
      cout<<left<<setw(20)<<setfill(' ')<<(*BranchIter).getBranchRegion();
      cout<<left<<setw(20)<<setfill(' ')<<(*BranchIter).getBranchAccountNo();
      cout<<left<<setw(20)<<setfill(' ')<<(*BranchIter).getBM();
      
      cout<<"\n";
   }
   cout<<"\n\t\t\t\tPress enter to exit :";
   cin.ignore().get();
   system("clear");
}


