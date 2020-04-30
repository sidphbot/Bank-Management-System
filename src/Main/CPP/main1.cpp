#include<iostream>
#include<string>
#include"../../Controller/AccountController/Include/AccountController.h"
#include"../../Controller/BranchAccountController/Include/BranchAccountController.h"
/*#include"../../AppClass/BranchAccount/Include/BranchAccount.h"
#include"../../UI/BranchAccountUI/Include/BranchAccountUI.h"
#include"../../Model/Include/Model.h"
//#include"../../Model/AccountModel/Include/AccountModel.h"
#include"../../UI/CustomerAccUI/Include/AccountUI.h"
*/
int main()
{
char l_choice;
int l_value,l_valueStatus;
BranchAccountController l_BACon;
BranchAccountUI l_BAUI;
AccountController l_accountController;
Bank l_accountModel;
AccountUI l_accountUI;


MAIN:


cout<<"\n\n\n          SAHARA BANKING SYSTEM \n\n";
do
{
cout<<"\nMAIN MENU:\n";
cout<<"\n1.Bank management\n2.Branch account management\n3.ATM management\n4.Employee management\n5.Customer management\n6.Account management\n7.Customer service management\n8.Exit.\n\nEnter your choice : ";
cin>>l_value;
switch(l_value)
{
    case 2:goto BA;
           break;
    default:cout<<"\nThe module is under construction.\nPlease select another choice.\n";
            break;           
    case 7:goto CSM;
           break;
    case 8:cout<<"\nThank You. Have a nice day.\n\n\n";
           exit(0);
}
cout<<"\n\nDo you want to continue ? ";
cin>>l_choice;
}while(l_choice=='Y' || l_choice=='y'); 
if(l_choice=='n' || l_choice=='N')
{
cout<<"\nThank You. Have a nice day.\n\n\n";
exit(0);
}


CSM:


cout<<"\n\n\n       CUSTOMER SERVICE MANAGEMENT \n\n";
do
{
cout<<"\nMENU:\n";
cout<<"\n1.Fund transfer";
cout<<"\n2.Account statement";
cout<<"\n3.Bill payment";
cout<<"\n4.Cash deposit";
cout<<"\n5.Cash withdrawal";
cout<<"\n6.Block ATM";
cout<<"\n7.Balance enquiry";
cout<<"\n8.Cheque book request";
cout<<"\n9.Return to main menu\n10.Exit.\n\nEnter your choice : ";
cin>>l_value;
switch(l_value)
{
case 1:goto FUND;
case 2:l_valueStatus=l_accountController.initiateAccountStatementGeneration(l_accountUI,l_accountModel);
       break;
case 4:l_valueStatus = l_accountController.initiateCashDeposit(l_accountModel);
        if(l_valueStatus==1)
        {
         cout<<"\nDeposited successfully."<<endl;
         //cout<<"Do you want to continue[y/n]: ";
         //cin>>k;
        }      
else
        {
        cout<<"\nDeposit unsuccessful."<<endl;
        goto CSM;
        }
       break;
case 5 : l_valueStatus = l_accountController.initiateCashWithdrawal(l_accountModel);
       if(l_valueStatus==1)
       {
       cout<<"\nWithdrawed successfully."<<endl;
       //cout<<"\nDo you want to continue[y/n]: "<<endl;
       //cin>>k;
       } 
      else
       {
        cout<<"\nWithdraw unsuccessful"<<endl;
        goto CSM;
       }
       break;
/*case 6:l_valueStatus = l_accountController.initiateBlockATMCard(l_accountModel);
       if(l_valueStatus==1)                   
       //cout<<"Do you want to continue[y/n]: ";
       //cin>>k;
       cout<<"\nRequest generated and ATM Card is Blocked"<<"\n";
       else
       {
       cout<<"\nAttempt to block ATM card was unsuccessful. Please try again.\n";  
       goto CSM;
       }
       break;*/
case 7:system("clear");
       l_accountUI.displayheader();
            cout<<"Main Menu/Customer Services/Balance Enquiry"<<endl;
            cout<<"type 'exit' if you want to stop the process at any point"<<endl;            
            cout<<"________________________________"<<endl;
            cout<<"BALANCE ENQUIRY MENU"<<endl;
            l_accountController.initiateBalanceEnquiry(l_accountModel);
            cout<<"\nenter a key to continue......"<<endl;
            char h;
            cin>>h;
            goto CSM;
case 8:system("clear");
       l_accountUI.displayheader();
             cout<<"Main Menu/Customer Services/Cheque Book Request"<<endl;
             cout<<"type 'exit' if you want to stop the process at any point"<<endl;
             cout<<"________________________________"<<endl;
             cout<<"CHEQUE BOOK REQUEST MENU"<<endl;
             l_accountController.initiateChequeBookRequest(l_accountModel);
             cout<<"\nenter a key to continue......"<<endl;
             cin>>h;
             goto CSM; 

default:cout<<"\nThe module is under construction.\nPlease select another choice.\n";
case 9:goto MAIN;
       break;
case 10:cout<<"\nThank You. Have a nice day.\n\n\n";
              exit(0);
}
cout<<"\n\nDo you want to continue ? ";
cin>>l_choice;
}while(l_choice=='Y' || l_choice=='y');
if(l_choice=='n' || l_choice=='N')
{
cout<<"\nThank You. Have a nice day.\n\n\n";
exit(0);
}



BA:



l_accountModel.dbConnect();
//l_BAUI.displayScreen();
cout<<"\n\n\n       BRANCH ACCOUNT MANAGEMENT \n\n";
do
{  
   cout<<"\nMENU:\n";
   cout<<"\n1.Add branch account\n2.View branch account\n3.Update branch Account\n4.Deactivate branch Account\n5.Return to main menu\n6.Exit.\n\nEnter your choice : ";
   cin>>l_value;
   cin.ignore();
      switch(l_value)
      {
   
       case 1: l_valueStatus = l_BACon.initiateBranchAccountAddition(l_BAUI,l_accountModel);
               //cout<<l_valueStatus;
               break;
       case 2:l_valueStatus=l_BACon.initiateBranchAccountView(l_BAUI,l_accountModel);
               //cout<<l_valueStatus;
               break;
       case 3:l_valueStatus=l_BACon.initiateBranchAccountUpdation(l_BAUI,l_accountModel);
               //cout<<l_valueStatus;
               break;

       case 4:l_valueStatus=l_BACon.initiateBranchAccountDeletion(l_BAUI,l_accountModel);
               //cout<<l_valueStatus;
               break;
       case 5:goto MAIN;break;
       case 6:cout<<"\nThank You. Have a nice day.\n\n\n";
              exit(0);
       default: cout<<"\nwrong choice entered\n";
      }
   cout<<"\n\nDo you want to continue ? ";
   cin>>l_choice;
}while(l_choice=='Y' || l_choice=='y');
cout<<"\nThank You. Have a nice day.\n\n\n";
l_accountModel.disconnect();
return 0;

FUND:


int l_status;
   cout<<"\n_______________________________________________";
   cout<<"\n\n\n             FUND TRANSFER \n\n";
   cout<<"\n_______________________________________________";
   cout<<"\n\nEnter the details for fund transfer\n";
   l_status=l_accountController.initiateFundTransfer(l_accountUI,l_accountModel);
   if(l_status==1)
     l_accountUI.displayMessage("\nFund was transfered successfully.\n");
   else l_accountUI.displayMessage("\nFund transfer failed\n");
   //l_myUI.displayMessage("\n\nTHANK YOU !!!\n");
   //l_myUI.displayMessage("Have a nice day !!!\n");
   cout<<"\n_____________________________________________________________________________________________________________\n";
 cout<<"\n\nDo you want to continue ? ";
   cin>>l_choice;
if(l_choice=='Y' || l_choice=='y')
     goto CSM;
cout<<"\nThank You. Have a nice day.\n\n\n";
l_accountModel.disconnect();
return 0;

}


