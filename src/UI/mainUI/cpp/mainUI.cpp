#include<iomanip>
#include"../include/mainUI.h"
#include"../../../Controller/branchController/include/branchController.h"
#include<stdlib.h>
#include<ctime>
#include<unistd.h>


void MainUI::mainHeader()
{
  cout<<"\n\t\t\t$***************************************************************************************$"<<endl;
    cout<<"\t\t\t$                                     WELCOME                                           $"<<endl;
    cout<<"\t\t\t$                                       TO                                              $"<<endl;
    cout<<"\t\t\t$                           SAHARA BANK MANAGEMENT SYSTEM                               $"<<endl;
    cout<<"\t\t\t$***************************************************************************************$"<<endl;

time_t now = time(0);
char* dt = ctime(&now);
cout<<"\t\t\t\t\t\t\t"<<dt<<endl;
}

void MainUI::mainMenu()
{

string n;
int k=0;
int l_choice1;
int l_status;
char l_choice;
string h;
do{
system("clear");
mainHeader();
//system("clear");
cout<<"\n\t\t\tHome";
cout<<"\n\n-----------------------------------------Main Menu--------------------------------------------\n\n";
cout<<"\n\t\t\t1.Branch Management\n\t\t\t2.Employee Management\n\t\t\t3.Branch Account Management\n\t\t\t4.Customer Management\n\t\t\t5.ATM Management\n\t\t\t6.Customer Account Management\n\t\t\t7.Customer Services Management\n\t\t\t8.exit";

do{
k=0;
cout<<"\nEnter your choice: ";
cin>>n;
int l_ValidStatus = Validation :: validateChoice(n);
        if(l_ValidStatus == 0)
           {cout<<"\ninvalid choice.. please enter a numeric value\n";
           k=1;}
cout<<"\n";
}while(k);
l_choice1= Utility::convertToInt(n);


switch(l_choice1)
{
 case 1:branchManagement();
        break;
 case 2:employeeManagement();
       
        break;
 case 3:branchAccountManagement();
        break;
 case 4:customerManagement();
        break;
 case 5:ATMManagement();
        break;
 case 6:customerAccountManagement();
        break;
 case 7:customerServiceManagement();       
        break;
 case 8:cout<<"\nYou are exiting successfully\n";
        exit(0);
        break;
 default:cout<<"\ninvalid choice";
        break;
}


}while(1);

}



void MainUI::branchManagement()
{
Bank l_myBank;
BranchController l_myCon;
BranchUI l_myUI;
string n;
int k=0;
int l_status;
int l_back=0;
char l_choice;
int l_choice1;
long int l_branchID;
do{
system("clear");
mainHeader();
cout<<"\nHome/Branch Management";

cout<<"\n\n-----------------------------------------Branch Management--------------------------------------------\n\n";

cout<<"\n\t\t\t1.Add Branch Details\n\t\t\t2.View Branch Details\n\t\t\t3.View all branch details\n\t\t\t4.Deactivate Branch\n\t\t\t5.Update Branch Details\n\t\t\t6.Back\n\t\t\t7.Exit";
do{
k=0;
cout<<"\nEnter your choice: ";
cin>>n;
int l_ValidStatus = Validation :: validateChoice(n);
        if(l_ValidStatus == 0)
          { cout<<"\ninvalid choice.. please enter a numeric value\n";
           k=1;
           }
cout<<"\n";
}while(k);
l_choice1= Utility::convertToInt(n);

switch(l_choice1)
{case 1:
l_branchID = l_myCon.initiateBranchAddition(l_myBank);
//cout<<"\nThe branch id is: "<<l_branchID;
if(l_branchID==1)
cout<<"branch could not be added as the BM ID doesnt exist"<<endl;
else if(l_branchID==0)
cout<<"\nbranch could not be added\n";
else if(l_branchID==2)
cout<<"Branch Manager is already alloted a branch"<<endl;
else
{
cout<<"\nbranch successfully added\n";
cout<<"Branch ID is "<<l_branchID<<endl;
}
break;
case 2:
l_status = l_myCon.initiateViewBranch(l_myBank);

break;
case 3:
l_myCon.initiateViewAllBranches(l_myUI,l_myBank);
break;
case 4:

l_status = l_myCon.initiateDeleteBranch(l_myBank);
if(l_status)
cout<<"\nbranch deactivated\n";
else
cout<<"\nbranch could not be deactivated\n";
break;
case 5:
l_status = l_myCon.initiateUpdateBranch(l_myBank);
if(l_status)
cout<<"\nbranch updated\n";
else
cout<<"\nbranch could not be updated\n";

break;
case 6:l_back = 1; 
       break;
case 7: exit(0);
default: cout<<"\nInvalid choice";
break;
}
if(l_back!=1)
{cout<<"\nDo you want to continue?(y/n): ";
cin>>l_choice;
if(l_choice=='n'||l_choice=='N')
break;
else if(l_choice=='y'||l_choice=='Y')
continue;}
}while(l_back==0);
}


void MainUI::employeeManagement()
{

Bank l_myBank;
   EmployeeController l_myEmpCon;
   EmployeeUI l_myEmpUI;

   int l_value,l_status,l_value1,l_value2;
   string l_strVal,l_v;
   char l_choice,l_choice1,l_choice3;
   bool l_ch1;
  
 /* outermost do-while loop*/
   do
   {
mainHeader();      
l_myEmpUI.displayEmployeeScreen();
                  fn:cout<<"\n\n\nEnter choice:";
                  cin>>l_strVal;
                  l_ch1=Validation::validateNumber(l_strVal);
                  if(l_ch1==false)
                  {
                      l_myEmpUI.displayMessage("\nPlease enter a number \n");   
                      goto fn;     
                   
                  }
                  l_value1=Utility::convertToInt(l_strVal);
                  switch(l_value1)
                  {
                      case 1:
                             l_status = l_myEmpCon.initiateAddEmployee(l_myEmpUI,l_myBank);
                             if(l_status==1)
                                cout<<"\nEmployee Details added successfully\n";
                             else cout<<"\nEmployee Details cannot be added successfully\n";  
                             break;
                      case 2:l_status=l_myEmpCon.initiateViewEmployee(l_myEmpUI,l_myBank);
                             if(l_status!=1)
                                cout<<"\nEmployee Details cannot be viewed successfully\n";
                             break;
                      case 3:l_status=l_myEmpCon.initiateUpdateEmployee(l_myEmpUI,l_myBank);
                             if(l_status==1)
                                cout<<"\nEmployee Details are updated successfully\n";
                             else cout<<"\nEmployee Details cannot be updated successfully\n";
                             break;
                      case 4:l_status=l_myEmpCon.initiateDeactivateEmployee(l_myEmpUI,l_myBank);
                             if(l_status==1)
                                cout<<"\nEmployee Details are successfully deactivated\n";
                             else cout<<"\nEmplopyee Details cannot be successfully deactivated\n";
                             break;
                     case 5: //l_myBank.dbConnect();
                             l_myEmpCon.initiateViewAllemployees(l_myEmpUI,l_myBank);
                            break;



                       case 6: //l_myBank.dbConnect();
                             l_myEmpCon.initiateViewDeactivatedEmployees(l_myEmpUI,l_myBank);
                            break;





                    case 8:cout<<"\nThank You !!!\n";
                           // l_myBank.disconnect();
                            goto lab;
                    case 7: mainMenu();
                            break;
                                        
                                                           
                     default:cout<<"\nWrong choice entered.Please enter a valid choice\n";
                            break;
                  }
                  cout<<"\nPlease press Y to continue :";
                  cin>>l_choice;
                 }while(l_choice=='Y' || l_choice=='y');
                 lab:cout<<"\n-----------------------------------------------------------------------------------\n";





}

void MainUI::customerAccountManagement()
{

Bank l_myBank;
AccountController l_myCon;

AccountUI p_AccountUIObj;

int choice;
int l_status;
int v_status;
int c_status;
int u_status;
char cchoice;

do{
label1:
system("clear");
mainHeader();
cout<<"\nHome/Customer Account Management";
cout<<"\n\n-----------------------------------------Customer Account Management--------------------------------------------\n\n";
cout<< " \t \t \t \t 1. AddAccount" <<endl<<" \t \t \t \t 2. ViewAccount"<<endl << " \t \t \t \t 3. Update Account"<<endl<<" \t \t \t \t 4. Deactivate Account" << endl << " \t \t \t \t 5. Go Back to Main Menu"<<endl<<"\t \t \t \t 6. Exit";
cout<< "\n  \t \t \t Enter your choice:";
cin>>choice;
switch(choice)
{
  case 1:
  l_status = l_myCon.initiateAddCustomerAccount(l_myBank);
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1; 
  else { system("clear");exit(0);}
  // cout<<l_status;
  break;
 
 case 2:
  l_myCon.initiateViewAccountDetails(p_AccountUIObj,l_myBank);  
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1;
  else { system("clear");exit(0);}

  break;

  case 4:
  v_status = l_myCon.initiateDeactivateAccountController(l_myBank);
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1;
  else { system("clear");exit(0);}
  break;
  
  case 3:
  u_status = l_myCon.initiateUpdateCustomerAccount(l_myBank);
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1;
  else { system("clear");exit(0);}
  break;
 
  case 6:
          exit(0); break;
  case 5: mainMenu();
          break;

  default:
        cout<<" \n Invalid option...";
        //cout<<"\n Enter a valid option"; 
        sleep(2);
}
}while(1);




}


void MainUI::ATMManagement()
{
ATMUI l_ATMUI;
Bank l_myBank;
ATMController l_myCon;

ATMUI l_atmUI;
int choice;
int l_status;
int v_status;
int u_status;
int c_status;
int inchoice;
char cchoice;
int achoice;
system("clear");
//menu();
//return 0;
//}


//void menu()
//{
label1:
 do{

  achoice=l_atmUI.displayATMMenu();


//label1:
 
  system("clear");


 
/*cout<<setw(5)<<" *******************************************************";
cout<<setw(75)<<" \n ATM Management \n ";
cout<<setw(5)<<" *******************************************************";
cout<<setw(12)<<endl<< "\n 1. Add ATM" <<endl<<endl<<setw(12)<<"2. View ATM"<<endl<<endl<<setw(12)<<"3. Update ATM"<<endl<<endl<<setw(12)<<"4. Close ATM" <<endl<<endl<<setw(10)<<"5. Exit"<< endl;
cout<<setw(10)<< "\n Enter your choice:";
cin>>choice;*/
 switch(achoice)
 {
  case 1:
  cout<<"\n \t \t ADD ATM DETAILS \n \n";
  l_status = l_myCon.initiateAddATMAccount(l_myBank);
  //cout<<l_status;
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1; 
 // else { system("clear");exit(0);}
   //l_atmUI.displayATMMenu();
//  menu();
  else
  mainMenu();
  break;
 
  case 2:
  cout<<"\n \t \t VIEW DETAILS \n \n";
  v_status = l_myCon.initiateATMController(l_myBank);
  //cout<<v_status;
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
   goto label1;
  else { system("clear");exit(0);}

  // menu();
  
  break;

  case 3:
  do{
  u_status = l_myCon.initiateUpdateATMController(l_myBank);
  cout<<"\n do you wish to continue(y/n)?";
  cin>>cchoice;
  }while(cchoice == 'y' || cchoice == 'Y');
  
  break;
  
  case 4:
  cout<<"\n \t \t CLOSE ATM \n \n";
  c_status = l_myCon.initiateCloseATMController(l_myBank);
 // cout<<c_status;
 cout<<"\n do you wish to continue(y/n)?";
 cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
 goto label1;
  else { exit(0); break;}
   //l_atmUI.displayATMMenu();
  break;
  

 case 5:
 cout<<"\n \t \t GENERATE ATM REPORT \n \n";
 l_myCon.initiateViewAllAtm(l_ATMUI ,l_myBank );
 cout<<"\n do you wish to continue(y/n)?";
 cin>>cchoice;
  if(cchoice == 'y' || cchoice == 'Y')
 goto label1;
  else { exit(0); break;}
   //l_atmUI.displayATMMenu();
  break;



  case 7:exit(0);
         break;
  case 6:mainMenu();
         break;
  default:
        cout<<"\n Invalid Option";
        //inchoice=1;
        cout<<"\n Enter again";
        break; 
  }
 
  

}while(1);
  


}


void MainUI::customerManagement()
{
   CustomerController CustomerControllerObj;
   Bank ModelObj;
  int ch;
  Validation obj;
 int i;
string s_c,h;
Utility u;
bool status;
a:system("clear");
  /*cout<<"\n\t\t\t\t\t\t____________________________";
   cout<<"\n\t\t\t\t\t\t      SAHARA BANK         ";
   cout<<"\n\t\t\t\t\t\t____________________________"<<endl;
  cout<<"\n\t\t\t\t\t\t   Customer management     ";
 cout<<"\n\t\t\t\t\t\t____________________________"<<endl;*/

mainHeader();
cout<<"\nHome/Customer Management";
cout<<"\n\n-----------------------------------------Customer Management--------------------------------------------\n\n";



cout<<"\n\t\t\t\t\t\t1.Add Customer";
  cout<<"\n\t\t\t\t\t\t2.Update Customer Details";
 cout<<"\n\t\t\t\t\t\t3.View Customer Details";
cout<<"\n\t\t\t\t\t\t4.View all";
cout<<"\n\t\t\t\t\t\t5.Deactivate Customer";
cout<<"\n\t\t\t\t\t\t6.Go back to Main Menu";
cout<<"\n\t\t\t\t\t\t7.Exit"<<endl;
cout<<"\n\n\t\t\t\t\t\tEnter a choice:";
 cin>>s_c;
 status=obj.validateNumber(s_c);
      if(status=true)
      {
      ch=u.convertToInt(s_c);
      goto b;
      }
      else
      cout<<"wrong input"<<endl;
      cout<<"Enter a key and press return"<<endl;
      cin>>h;
      goto a;

  b: switch(ch)
{
case 2:
 i = CustomerControllerObj.initiateUpdateCustomer(ModelObj);  
cout<<"\nPress any key to return to previous menu"<<endl;
cin>>h;
 goto a;
case 5:
  CustomerControllerObj.initiateDeactivateCustomer(ModelObj);
cout<<"\nPress any key to return to previous menu"<<endl;
cin>>h;
 goto a;

case 1:
 CustomerControllerObj.initAddCustomer(ModelObj);  
cout<<"\nPress any key to return to previous menu"<<endl;
cin>>h;
 goto a;

case 3:
   CustomerControllerObj.initiateViewCustomer(ModelObj);   
cout<<"\nPress any key to return to previous menu"<<endl;
cin>>h;
 goto a;

case 4: CustomerControllerObj.initiateViewAllCustomer(ModelObj); 
cout<<"\nPress any key to return to previous menu"<<endl;
cin>>h;
 goto a;

case 7: exit(0);
case 6: mainMenu();
default:cout<<"Invalid Choice"<<endl;
        usleep(1000000);
        goto a;
}
}

void MainUI::branchAccountManagement()
{

string l;
char l_choice;
int l_value,l_valueStatus;
BranchAccountController l_BACon;
BranchAccountUI l_BAUI;
AccountController l_accountController;
Bank l_accountModel;
AccountUI l_accountUI;
CustomerController CustomerControllerObj;
   Bank ModelObj;
  int ch;
  Validation obj;
 int i;
string s_c,h;
Utility u;
bool status;
int k;

BA:

do{
system("clear");

l_accountModel.dbConnect();

mainHeader();
cout<<"\n\n\t\t\t-----------------------------------------Branch Account Management--------------------------------------------\n\n";

cout<<"\nHome/Branch Account Management";
do{
   cout<<"\n\t\t\t--------------------------------------------MENU------------------------------\n";
   cout<<"\n\t\t\t\t\t\t1.Add branch account\n\t\t\t\t\t\t2.View branch account\n\t\t\t\t\t\t3.Update branch Account\n\t\t\t\t\t\t4.Deactivate branch Account\n\t\t\t\t\t\t5.View all Branch Account \n\t\t\t\t\t\t6.Go back to the Main Menu\n\t\t\t\t\t\t7.Exit.\n\n\tEnter your choice : ";
   cin>>l;
  int l_ValidStatus = Validation :: validateChoice(l);
 if(l_ValidStatus == 0)
           {cout<<"\ninvalid choice.. please enter a numeric value\n";
           k=1;}
cout<<"\n";
}while(k==1);
l_value= Utility::convertToInt(l);

   cin.ignore();
      switch(l_value)
      {

       case 1: l_valueStatus = l_BACon.initiateBranchAccountAddition(l_BAUI,l_accountModel);
               
               break;
       case 2:l_valueStatus=l_BACon.initiateBranchAccountView(l_BAUI,l_accountModel);
               
               break;
       case 3:l_valueStatus=l_BACon.initiateBranchAccountUpdation(l_BAUI,l_accountModel);
               
               break;

       case 4:l_valueStatus=l_BACon.initiateBranchAccountDeletion(l_BAUI,l_accountModel);
               
               break;
       case 5:l_BACon.initiateViewAllBranchAccount(l_BAUI,l_accountModel);

                break;
       //case 5:goto MAIN;break;
       case 7:cout<<"\nThank You. Have a nice day.\n\n\n";
              exit(0);
       case 6:mainMenu();
       default: cout<<"\nwrong choice entered\n";
      }
   cout<<"\n\nDo you want to continue ? ";
   cin>>l_choice;
}while(l_choice=='Y' || l_choice=='y');
cout<<"\nThank You. Have a nice day.\n\n\n";
l_accountModel.disconnect();
//return 0;
             
}



void MainUI::customerServiceManagement()
{
 char l_choice;
int l_value,l_valueStatus;
BranchAccountController l_BACon;
BranchAccountUI l_BAUI;
AccountController l_accountController;
Bank l_accountModel;
AccountUI l_accountUI;
CustomerController CustomerControllerObj;
   Bank ModelObj;
  int ch;
  Validation obj;
 int i,k;
string s_c,h,l_n;
Utility u;
bool status;


CSM:
system("clear");
do
{
//cout<<"\n\n\n       CUSTOMER SERVICE MANAGEMENT \n\n";
 //cout<<"\n\t\t\t\t\t\t____________________________"<<endl;
 mainHeader();


cout<<"\n\t\t\tHome/Customer Service  Management";
cout<<"\n\n\t\t\t-----------------------------------------Customer Service Management--------------------------------------------\n\n";

cout<<"\n\t\t\t\t\t\t\tMENU:\n";
cout<<"\n\t\t\t\t\t\t1.Fund transfer";
cout<<"\n\t\t\t\t\t\t2.Account statement";
cout<<"\n\t\t\t\t\t\t3.Bill payment";
cout<<"\n\t\t\t\t\t\t4.Cash deposit";
cout<<"\n\t\t\t\t\t\t5.Cash withdrawal";
cout<<"\n\t\t\t\t\t\t6.Block ATM";
cout<<"\n\t\t\t\t\t\t7.Balance enquiry";
cout<<"\n\t\t\t\t\t\t8.Cheque book request";
cout<<"\n\t\t\t\t\t\t9.Go back to the Main Menu";
cout<<"\n\t\t\t\t\t\t10.Exit.\n\nEnter your choice : ";
//cin.ignore();
//string n;
do
{
k=0;
//cout<<"\nEnter your choice: ";
cin>>l_n;
int l_ValidStatus = Validation :: validateChoice(l_n);
        if(l_ValidStatus == 0)
           {cout<<"\ninvalid choice.. please enter a numeric value\n";
           k=1;}
cout<<"\n";
}while(k);
l_value= Utility::convertToInt(l_n);

//cin>>l_value;
switch(l_value)
{
case 1:goto FUND;
case 2:l_valueStatus=l_accountController.initiateAccountStatementGeneration(l_accountUI,l_accountModel);
       break;
case 3:l_valueStatus=l_accountController.initiateBillPayment(l_accountModel);
       break;
case 4:
system("clear");
cout<<"\n\t\t\t\t\t\t CASH DEPOSIT";
 cout<<"\n\t\t\t\t\t\t____________________________"<<endl;
l_valueStatus = l_accountController.initiateCashDeposit(l_accountModel);
        if(l_valueStatus==1)
        {
         cout<<"\nDeposited successfully."<<endl;
         
        }
         else if(l_valueStatus==2)
         {
          break;
         }
else
        {
        cout<<"\nDeposit unsuccessful."<<endl;
       // goto CSM;
        }
        cout<<"Enter a key to continue"<<endl;
       cin>>h;
       goto CSM;
       break;
case 5 :system("clear");
cout<<"\n\t\t\t\t\t\t CASH WITHDRAW";
 cout<<"\n\t\t\t\t\t\t____________________________"<<endl;
 l_valueStatus = l_accountController.initiateCashWithdrawal(l_accountModel);
 if(l_valueStatus==1)
       {
       cout<<"\nWithdrawed successfully."<<endl;
       
       }
      else
       {
        cout<<"\nWithdraw unsuccessful"<<endl;
       // goto CSM;
       }
        cout<<"Enter a key to continue"<<endl;
       cin>>h;
       goto CSM;
       break;
case 6:system("clear");
cout<<"\n\t\t\t\t\t\t BLOCK ATM";
cout<<"\n\t\t\t\t\t\t____________________________"<<endl;

l_valueStatus = CustomerControllerObj.initiateRequestBlockATMCard(l_accountModel);
       if(l_valueStatus==1)
       {
             cout<<"\nRequest generated and ATM Card is Blocked"<<"\n";
       }
       else
       {
       cout<<"\nAttempt to block ATM card was unsuccessful. Please try again.\n";
       //cout<<"Enter a key to continue"<<endl; 
      // cin>>h;
       //goto CSM;
       }
        cout<<"Enter a key to continue"<<endl;
       cin>>h;
       goto CSM;
       break;
case 7:system("clear");
       l_accountUI.displayheader();
            cout<<"Main Menu/Customer Services/Balance Enquiry"<<endl;
            cout<<"type 'exit' if you want to stop the process at any point"<<endl;
            cout<<"________________________________"<<endl;
            cout<<"BALANCE ENQUIRY MENU"<<endl;
            l_accountController.initiateBalanceEnquiry(l_accountModel);
            cout<<"\nenter a key to continue......"<<endl;
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
//case 9:goto MAIN;
       //break;
case 9: mainMenu();
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

FUND:

system("clear");

int l_status;
   cout<<"\n_______________________________________________";
   cout<<"\n\n\n             FUND TRANSFER \n\n";
   cout<<"\n_______________________________________________";
   cout<<"\n\nEnter the details for fund transfer\n";
   l_status=l_accountController.initiateFundTransfer(l_accountUI,l_accountModel);
   if(l_status==1)
     l_accountUI.displayMessage("\nFund was transfered successfully.\n");
   else l_accountUI.displayMessage("\nFund transfer failed\n");
      cout<<"\n_____________________________________________________________________________________________________________\n";
 cout<<"\n\nDo you want to continue ? ";
   cin>>l_choice;
if(l_choice=='Y' || l_choice=='y')
     goto CSM;
cout<<"\nThank You. Have a nice day.\n\n\n";
l_accountModel.disconnect();
//return 0;

}
