#include "../Include/AccountController.h"
#include "../../../AppClass/CustomerAcc/Include/Account.h"
#include "../../../AppClass/CustomerAcc/Include/Customer.h"
#include "../../../UI/CustomerAccUI/Include/AccountUI.h"
#include "../../../UI/CustomerAccUI/Include/CustomerUI.h"
#include <iostream>
#include <string.h>
using namespace std;
/*void AccountController::initiateViewAccountDetails1(CustomerUI &l_CustUI,Bank &p_BankObj)
{
 long int l_customerID=l_CustUI.getCustomerId();
 AccountUI val;
 val.displayAccountlist2(l_customerID);
}*/

long AccountController:: initiateChequeBookRequest(Bank &obj)
{
 obj.dbConnect();
 CustomerUI l_CustUI;
 AccountUI val;
 long int l_customerID=l_CustUI.getCustomerId();
 if(l_customerID==0)
 {
  val.displayMessage("Maximum number of attempts is 3.please try again.");
  return 0;
 }
 else if(l_customerID==2)
 {
  return 0;
 }
 else
 { 
  int i=val.displayAccountlist2(l_customerID);
 obj.disconnect();
  
if(i!=0)
  {
   long int l_accountno;
   AccountUI l_UI;
    obj.dbConnect();

   l_accountno=l_UI.getAccountNo();
   if(l_accountno==0)
   {
    val.displayMessage("Maximum number of attempts is 3.please try again.");
    return 0;
   }
   else if(l_accountno==2)
   {
   return 0;
   }
   else
   {
   int l_Cheques;
   
   obj.dbInitiateChequeBookRequest(l_accountno,l_customerID);
   }
   obj.disconnect();
  }
 } 
}


int AccountController::initiateAccountStatementGeneration(AccountUI &p_accountUI,Bank &p_accountModel)
{
long int l_accountno;
l_accountno=p_accountUI.getAccountNo();
p_accountModel.dbConnect();
int  l_AccountnoStatus=p_accountModel.findAccountNo(l_accountno);
if(l_AccountnoStatus==1)
{
int l_status=p_accountModel.accountStatementGeneration(l_accountno);
p_accountModel.disconnect();
return l_status;
}
}

int AccountController::initiateCashDeposit(Bank &p_DBobj)
{
AccountUI l_UI;
Account l_tempAccount;
long int l_accountno;
char ch;
int l_AccountnoStatus;
do
{
l_accountno=l_UI.getAccountNo();
l_AccountnoStatus=p_DBobj.findAccountno(l_accountno);
cout<<"\n\n press Y/y to continue, press any other key to go back ";
cin>>ch;
}while(ch!='y' && ch!='Y');
//cout<<"status is "<<l_AccountnoStatus;
if(l_AccountnoStatus==1 || l_AccountnoStatus==2)
{
double l_amount;
l_amount=l_UI.getAmount();
l_tempAccount.m_setAccountNo(l_accountno);
int l_status=p_DBobj.dbCashDeposit(l_tempAccount,l_amount);
return l_status;
}
else if(l_AccountnoStatus==3)
{
double l_amount=0;
l_tempAccount.m_setAccountNo(l_accountno);
int l_status=p_DBobj.dbCashDeposit(l_tempAccount,l_amount);
return l_status;
}
else
{
cout<<"account doesnot exists";
return 0;
}
}

int AccountController::initiateCashWithdrawal(Bank &p_DBobj)
{
AccountUI l_UI;
Account l_tempAccount;
char ch;
int l_AccountnoStatus;
long int l_accountno;
do
{
l_accountno=l_UI.getAccountNo();
if(l_accountno==0)
{
return 2;
}
l_AccountnoStatus=p_DBobj.findAccountno(l_accountno);
cout<<"\n\n press Y/y to continue, press any other key to go back ";
cin>>ch;
}while(ch!='y' && ch!='Y');
if(l_AccountnoStatus==1 || l_AccountnoStatus==2)
{
double l_amount;
l_amount=l_UI.getAmount();
l_tempAccount.m_setAccountNo(l_accountno);
int l_status=p_DBobj.dbCashWithdrawal(l_tempAccount,l_amount);
//cout<<"\n"<<l_status;
return l_status;
}
else if(l_AccountnoStatus==3)
{
l_tempAccount.m_setAccountNo(l_accountno);
int l_status=p_DBobj.dbfixedCashWithdrawal(l_tempAccount);
return l_status;
}
else
{
cout<<"account doesnot exists";
return 0;
}
}



 

int AccountController::initiateFundTransfer(AccountUI &p_UIobj,Bank &p_DBobj)
{

              
long int l_creditAccountNo,l_debitAccountNo;
    double l_amount,l_bal;
    int l_status1;
    Account p_myAccount;
    l_debitAccountNo=p_UIobj.getAccountNo();
   if(l_debitAccountNo==0)
   {
   return 0;
    }
     
    if(p_DBobj.findAccountno(l_debitAccountNo)==0)
    {
       p_UIobj.displayMessage("\nAccount does not exist\n");
       return 0;
    }
    else if(p_DBobj.findAccountno(l_creditAccountNo)==3)
         {
             p_UIobj.displayMessage("\nFund cannot be withdrawn from a fixed deposit\n");
           return 0;
         }

    p_myAccount.m_setAccountNo(l_debitAccountNo);
    l_amount=p_UIobj.getAmount();
    char l_val;
    l_creditAccountNo=p_UIobj.getAccountNo();
    if(p_DBobj.findAccountno1(l_creditAccountNo)==0)
    {
         p_UIobj.displayMessage("\nAccount does not exist\n");
           return 0;
    }
    else if(p_DBobj.findAccountno1(l_creditAccountNo)==3)
         {
             p_UIobj.displayMessage("\nFund cannot be transfered to a fixed deposit\n");
           return 0;
         }
    l_val=p_UIobj.displayConfirmAction();
    if(l_val=='n' || l_val=='N')
       return 0;
    int l_status=p_DBobj.dbCashWithdrawal(p_myAccount,l_amount);
    if(l_status==1)
    {
        p_myAccount.m_setAccountNo(l_creditAccountNo);
        l_status1=p_DBobj.dbFundCashDeposit(p_myAccount,l_amount);
        return l_status1;
     }
     else {
             return l_status;
          }


}
long AccountController::initiateBalanceEnquiry(Bank &p_DBobj) 
{
 AccountUI val;
 p_DBobj.dbConnect();
 CustomerUI l_CustUI;
 long int l_customerID=l_CustUI.getCustomerId();
 if(l_customerID==0)
 { 
  val.displayMessage("Maximum number of attempts is 3.please try again.");
  return 0;
 }
 else if(l_customerID==2)
 {
 cout<<"1"<<endl;
 return 0;
 }
 else if(l_customerID==1)
{
 return 0;
 }
 else
 {
  int i=val.displayAccountlist2(l_customerID);
  p_DBobj.disconnect();
  if(i!=0)
  {
   string c_accountno;
   long int l_accountno;
   l_accountno=val.getAccountNo();
   if(l_accountno==0)
   {
    val.displayMessage("Maximum number of attempts is 3.please try again.");
    return 0;
   }
   else if(l_accountno==2)
   {
   return 0;
   }
   else
   p_DBobj.dbConnect();
   p_DBobj.dbGetAccountBalance(l_accountno,l_customerID);
   p_DBobj.disconnect();
  }
 }
}


void AccountController::initiateViewAccountDetails1(CustomerUI &l_CustUI,Bank &p_BankObj)
{
 long int l_customerID=l_CustUI.getCustomerId();
 AccountUI val;
 val.displayAccountlist2(l_customerID);
}

/*long AccountController:: initiateChequeBookRequest(Bank &obj)
{
 obj.dbConnect();
 CustomerUI l_CustUI;
 AccountUI val;
 long int l_customerID=l_CustUI.getCustomerId();
 if(l_customerID==0)
 {
  val.displayMessage("Maximum number of attempts is 3.please try again.");
  return 0;
 }
 else if(l_customerID==2)
 {
  return 0;
 }
 else
 { 
  int i=val.displayAccountlist(l_customerID);
  {
   long int l_accountno;
   AccountUI l_UI;
   l_accountno=l_UI.getAccountNo();
   if(l_accountno==0)
   {
    val.displayMessage("Maximum number of attempts is 3.please try again.");
    return 0;
   }
   else if(l_accountno==2)
   {
   return 0;
   }
   else
   obj.dbInitiateChequeBookRequest(l_accountno,l_customerID);
   obj.disconnect();
  }
 } 
}
*/

 int AccountController::initiateAddCustomerAccount(Bank &p_DBobj)
 {
     CustomerUI l_CustUI; 
     AccountUI l_AccUI;
     long int l_customerID;
     char l_AccountType[20];
     double l_accountBalance;
     l_customerID=l_CustUI.getCustomerID();
    //strcpy(l_AccountType,l_AccUI.getAccounttype().c_str());
    
    //l_customerID=l_CustUI.getCustomerID();
   // l_accountBalance=l_AccUI.getAccountBalance();

    int l_IDstatus = p_DBobj.findCustomerID(l_customerID);
    
    if(l_IDstatus)
   { 
     Account l_tempCustAccount;
     Customer l_tempCustomer;
     //l_tempCustAccount.m_setAccountType(l_AccountType);
     //l_tempCustAccount.setCustomerId(l_customerID);
      l_tempCustomer.setCustomerId(l_customerID);
    //l_tempCustAccount.m_setAccountBalance(l_accountBalance);
     int l_status =  p_DBobj.addCustomerAccount( l_tempCustomer,l_tempCustAccount);
     return l_status;
    }
    else
     {
       cout<<"\n Customer ID not found...";
       return !l_IDstatus;
     }
}


 int AccountController::initiateDeactivateAccountController(Bank &p_DBobj)
  {
     AccountUI l_AccUI;
     long int l_accountno;
     l_accountno= l_AccUI.getAccountNo();
 int l_IDstatus = p_DBobj.findAccountNo(l_accountno);
    
    if(l_IDstatus)
   { 
     int l_status =  p_DBobj.dbcloseAccount(l_accountno); 
       return l_status;
     }
     else
      return !l_IDstatus;
 }

 int AccountController::initiateUpdateCustomerAccount(Bank &p_DBobj)
{
   AccountUI l_AccUI;
   long int l_accountno;
   char l_stat[9];
   l_accountno=l_AccUI.getAccountNo();
  int l_status=p_DBobj.findAccountNo(l_accountno);
  if(l_status==0)
  {
   cout<<"\n Account Number doesn't exist";
   return 0;
  }
 // strcpy(l_stat,l_AccUI.getAccountStatus().c_str());
  Account l_account;
  l_account.m_setAccountNo(l_accountno);
 // l_account.m_setAccountStatus(l_stat);
int l_status1=p_DBobj.updateAccount(l_account);
  return l_status1;
}

void AccountController::initiateViewAccountDetails(AccountUI &p_AccountUIObj, Bank &p_BankObj)
{
  CustomerUI l_CustUI;
long int l_customerID=l_CustUI.getCustomerID();
  vector<Account> AccountList;
  
  AccountList=p_BankObj.dbViewAccount(l_customerID);
  if(AccountList.size()!=0)
  p_AccountUIObj.displayAccountlist(AccountList);
  else
  cout<<"No records found";
}


int AccountController::initiateBillPayment(Bank &p_DBobj)
{
    AccountUI p_UIobj;
    int l_BillId;
    long int l_creditAccountNo,l_debitAccountNo;
    double l_amount;
    Account p_myAccount;
   int l_status1,i,l_ch;

 
     
     int l_chioce = p_UIobj.getBillScreen();
    switch(l_chioce)
        {
    case 1:{
          l_debitAccountNo=p_UIobj.getAccountNo();
       

    if(p_DBobj.findAccountNo(l_debitAccountNo)==0)
      { cout<<"\nThis account number does not exist";
       return 0;
      }
     l_amount=p_UIobj.getBillAmount();
     l_BillId=p_UIobj.getBillId();
                          
      Account myAccount1;
       myAccount1.m_setAccountNo(l_debitAccountNo);
        myAccount1.m_setBillId(l_BillId);
        myAccount1.m_setAmount(l_amount);


     l_ch=p_DBobj.dbCashWithdrawal(myAccount1,l_amount);
  

        l_creditAccountNo=100090;
        
        p_myAccount.m_setAccountNo(l_creditAccountNo);
          i=p_DBobj.dbCashDeposit(myAccount1,l_amount);
         
        if(i==1)
         {
       l_status1= p_DBobj.dbBillPaymentElectricity(myAccount1);
         return l_status1;
         }
         return i;}
   case 2: {
          l_debitAccountNo=p_UIobj.getAccountNo();


    if(p_DBobj.findAccountNo(l_debitAccountNo)==0)
        { cout<<"\nThis account number does not exist";
       return 0;
      }


     l_amount=p_UIobj.getBillAmount();
     l_BillId=p_UIobj.getBillId();

      Account  myAccount2;
   myAccount2.m_setAccountNo(l_debitAccountNo);
        myAccount2.m_setBillId(l_BillId);
        myAccount2.m_setAmount(l_amount);



     l_ch=p_DBobj.dbCashWithdrawal(myAccount2,l_amount);


        l_creditAccountNo=100091;

        p_myAccount.m_setAccountNo(l_creditAccountNo);
          i=p_DBobj.dbCashDeposit(myAccount2,l_amount);

        if(i==1)
         {
       l_status1= p_DBobj.dbBillPaymentWater(myAccount2);
         return l_status1;
         }
         return i;
 
     }
      case 3: {
          l_debitAccountNo=p_UIobj.getAccountNo();


    if(p_DBobj.findAccountNo(l_debitAccountNo)==0)
      { cout<<"\nThis account number does not exist";
       return 0;
      }
     l_amount=p_UIobj.getBillAmount();
     l_BillId=p_UIobj.getBillId();

      Account myAccount3;
  myAccount3.m_setAccountNo(l_debitAccountNo);
        myAccount3.m_setBillId(l_BillId);
        myAccount3.m_setAmount(l_amount);



     l_ch=p_DBobj.dbCashWithdrawal(myAccount3,l_amount);


        l_creditAccountNo=100092;

        p_myAccount.m_setAccountNo(l_creditAccountNo);
          i=p_DBobj.dbCashDeposit(myAccount3,l_amount);

        if(i==1)
         {
       l_status1= p_DBobj.dbBillPaymentPhone(myAccount3);
         return l_status1;
         }
         return i;
}
case 4:exit(0); break;
default :
cout<<"\nEnter a valid choice";

}
}
    
