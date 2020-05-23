
 #include "../Include/AccountUI.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include <vector>
using namespace std;
#include<string.h>
#include<unistd.h>
 
/*long int AccountUI::getAccountNo(){
long int l_accountno;
cout<<"\n Account No:";
cin>>l_accountno;
return l_accountno;
}
string  AccountUI::getAccounttype(){
string l_accounttype;
 cout<<"\n Account Type:";
 cin>>l_accounttype;
 return  l_accounttype;
}
double AccountUI::getAccountBalance()
{
double l_accountBalance;
cout<<"Balance :";
cin>>l_accountBalance;
return l_accountBalance; 
}

char AccountUI::displayRecord(long int p_accno,char *p_acctype,long int p_custid,double p_accbalance,int p_status)
{
  long int l_accno;
  char *l_acctype;
  long int l_custid;
  double l_accbalance;
  int l_status;
  l_accno=p_accno;
  strcpy(l_acctype,p_acctype);
  l_custid=p_custid;
  l_accbalance=p_accbalance;
  l_status=p_status;
  
  cout<<"\n ACCOUNTNUMBER"<<setw(20)<<"ACCOUNTTYPE"<<setw(20)<<"CUSTOMERID"<<setw(20)<<"BALANCE"<<setw(20)<<"STATUS \n";
  cout<<"\n ------------------------------------------------------------------------------------------------------------ \n \n";
  cout<<l_accno<<setw(20)<<l_acctype<<setw(15)<< l_custid<<setw(15)<<l_accbalance<<setw(15)<<l_status;

  cout<<"\n Do you want to update status(y/n)?:";
  char choice;
  cin>>choice;
  return choice;
} 

double AccountUI :: getDepositAmount(){
 long int l_depositAmount;
 cout<<"\n Enter FD Amount:";
 cin>>l_depositAmount;
 return l_depositAmount;
}

int AccountUI :: getDepositYears(){
 long int l_depositYears;
 cout<<"\n Enter period(in years):";
 cin>>l_depositYears;
 return l_depositYears;
}

double AccountUI :: getBalance(){
 long int l_balance;
 cout<<"\n Enter Balance:";
 cin>>l_balance;
 return l_balance;
}

double AccountUI :: getSalariedBalance(){
 long int l_salminBalance;
 cout<<"\n Enter Minimum Balance:";
 cin>>l_salminBalance;
 return l_salminBalance;
}

double AccountUI :: getNonSalBalance(){
 long int l_nonsalminBalance;
 cout<<"\n Enter Minimum Balance:";
 cin>>l_nonsalminBalance;
 return l_nonsalminBalance;
}

int AccountUI :: displaySavingsMenu(){
 int choice;
 cout<<"\n SAVINGS MENU"<<endl;
 cout<<"1. Salaried Account"<<endl<<"2. Non Salaried Account"<<endl;
 cout<<"\n Enter your choice:"<<endl;
 cin>>choice;
 return choice;
}
*/
/*
long int  CustomerUI::getCustomerID(){
   string l_customerID; 
   int l_Validstatus;
   do{  
   cout<<"\n Customer ID:";
   cin>>l_customerID;
   l_Validstatus=Validation::ValidateNumber(l_customerID);
   if(l_Validstatus==1)
   return Utility :: convertToLongint(l_customerID);
   else 
   cout<<"\n Invalid ID.. \n Enter again";
  }while(l_Validstatus==0); 
 }

string CustomerUI::getCustomerName(){
 string l_customerName; 
 int l_Validstatus;
 do{
  cin.ignore();
  cout<<"\n Name:";
// cin>>l_customerName;
//  cin.ignore();
  getline(cin,l_customerName); 
l_Validstatus=Validation::ValidateString(l_customerName);
 if(l_Validstatus==1)
 return l_customerName;
 else
  cout<<"\n Enter valid name";
 }while(l_Validstatus==0);
}


*/
long int AccountUI::getAccountNo(){
 int i=0;
  bool status;
   string c_accountno;
  //  validate val;
    // utility u;
    cout<<"\nnote:Maximum number of attempts is 3\n"<<endl;
     cin.ignore(1000,'\n');
      for(int i=0;i<3;i++)
       {
         cout<<"\n\t\t\tEnter your 6 digit Account Number:";
           getline(cin,c_accountno);
             if(c_accountno=="exit")
               {
                  return 2;
                    }
 
                      status=Validation::validateNumber(c_accountno);
                        if(status== true)
                          {
                             return Utility::convertToLong(c_accountno);
                               }
                                 else
                                   cout<<"Invalid input"<<endl;
 
                                  }
                                     return 0;
                                    

}
string  AccountUI::getAccounttype(){
 string l_accounttype;
 int l_Validstatus;
 do{
  cin.ignore();
  cout<<"\n Account Type:";
// cin>>l_accounttype;
 
  //cin.ignore();
  getline(cin,l_accounttype);
l_Validstatus=Validation::ValidateString(l_accounttype);
 if(l_Validstatus==1)
  return  l_accounttype;
  else
  cout<<"\n Enter valid type";
 }while(l_Validstatus==0);
}
double AccountUI::getAccountBalance()
{
 int l_Validstatus;
 string l_accountBalance;
  do{
  cout<<"Balance :";
  cin>>l_accountBalance;
  l_Validstatus=Validation::ValidateBalance(l_accountBalance);
  if(l_Validstatus==1)
   return  Utility::convertToDouble( l_accountBalance); 
  else
  cout<<"\n Enter valid input";
 }while(l_Validstatus==0);
}

double AccountUI :: getDepositAmount(){
  int l_Validstatus;
  string l_depositAmount;
 do{
  cout<<"\n Enter FD Amount:";
  cin>>l_depositAmount;
  l_Validstatus=Validation::ValidateDepositAmount(l_depositAmount);
  if(l_Validstatus==1)
 return  Utility::convertToDouble(l_depositAmount);
  else
  cout<<"\n Enter valid amount";
 }while(l_Validstatus==0);
}

int AccountUI :: getDepositYears(){
 int l_Validstatus;
 string l_depositYears;
 do{
 cout<<"\n Enter period(in years):";
 cin>>l_depositYears;
  l_Validstatus=Validation::ValidateYear(l_depositYears);
  if(l_Validstatus==1)
 return  Utility::convertToInt(l_depositYears);
  else
   cout<<"\n Invalid year.. FD years available are 1,3 and 5 only..\n Enter again...";
 }while(l_Validstatus==0);
}

double AccountUI :: getBalance(){
 int l_Validstatus;
  string l_balance;
 do{
 cout<<"\n Enter Balance:";
 cin>>l_balance;
  l_Validstatus=Validation::ValidateBalance(l_balance);
  if(l_Validstatus==1)
  return Utility::convertToDouble(l_balance);
  else
  cout<<"\n Enter valid amount";
 }while(l_Validstatus==0);
}

double AccountUI :: getSalariedBalance(){
 string l_salminBalance;
int l_Validstatus;
do{
 cout<<"\n Enter Minimum Balance:";
 cin>>l_salminBalance;
  l_Validstatus=Validation::ValidateBalance(l_salminBalance);
  if(l_Validstatus==1)
 return  Utility::convertToDouble( l_salminBalance);
  else
  cout<<"\n Enter valid amount";
 }while(l_Validstatus==0);
}

double AccountUI :: getNonSalBalance(){
 string l_nonsalminBalance;
int l_Validstatus;
 do{
 cout<<"\n Enter Minimum Balance:";
 cin>>l_nonsalminBalance;
  l_Validstatus=Validation::ValidateNonSalBalance(l_nonsalminBalance);
  if(l_Validstatus==1)
 return  Utility :: convertToDouble( l_nonsalminBalance);
  else
  cout<<"\n Enter valid amount..\n  Amount should be minimum of 5000 or 10000";
 }while(l_Validstatus==0);
}

string AccountUI :: getAccountStatus(){
  string l_status;
int l_Validstatus;
 do{
   cin.ignore();
  cout<<"\n Enter Status to update:";
 //  cin>>l_status;
 // cin.ignore();
  getline(cin,l_status);  
 l_Validstatus=Validation::ValidateString(l_status);
   if(l_Validstatus==1)
   return l_status;
   else
  cout<<"\n Enter valid input";
 }while(l_Validstatus==0);
}  

int AccountUI :: displaySavingsMenu(){
 int choice;
int l_Validstatus;
 cout<<"\n \t \t  \t ------------- SAVINGS MENU --------------"<<endl;
 cout<<" \t \t \t 1. Salaried Account"<<endl<<"\t \t \t 2. Non Salaried Account"<<endl<<"\t \t \t 3. Exit"<<endl;
 cout<<"\n Enter your choice:";
 cin>>choice;
 return choice;
}

int AccountUI :: displayAccountTypeMenu()
{
int mchoice;
system("clear");
cout<<"\n \t \t \t--------------  Account Type ------------- \n \n";
cout<<" \t \t \t 1.savings Account"<<endl;
cout<<" \t \t \t 2.current Account"<<endl;
cout<<" \t \t \t 3.Fixed Deposit Account"<<endl;
cout<<" \t \t \t 4.Exit"<<endl;
cout<<" \t \t Enter choice:";
cin>>mchoice;
return mchoice;
}


void AccountUI::displayAccountlist(vector<Account> accountlist)
{
   system("clear");

   AccountUI obj;
      cout<<"\n \t \t \t \t ACCOUNT DETAILS \n \n \n";
      cout<<"\n\tAccountNumber"<<setw(15)<<"AccountType"<<setw(15)<<"CustomerID"<<setw(20)<<"AccountBalance"<<setw(20)<<"status"<<endl;
   cout<<"\n\t________________________________________________________________________________________\n";
    for (int ViewList=0; ViewList<accountlist.size(); ViewList++)
    {
cout<<"\t"<<accountlist[ViewList].m_getAccountNo()<<"\t \t "<<accountlist[ViewList].m_getAccountType()<<"\t"<<accountlist[ViewList].m_getCustomerID()<<"\t \t"<< accountlist[ViewList].m_getBalance()<<"\t \t"<<accountlist[ViewList].m_getAccountStatus()<<endl;
cout<<"\t_______________________________________________________________________________________\n";

    }

}



char AccountUI::displayRecord(long int p_accno,char *p_acctype,long int p_custid,double p_accbalance,int p_status)
{
  long int l_accno;
  char *l_acctype;
  long int l_custid;
  double l_accbalance;
  int l_status;
  l_accno=p_accno;
  strcpy(l_acctype,p_acctype);
  l_custid=p_custid;
  l_accbalance=p_accbalance;
  l_status=p_status;
  
  cout<<"\n ACCOUNTNUMBER"<<setw(20)<<"ACCOUNTTYPE"<<setw(20)<<"CUSTOMERID"<<setw(20)<<"BALANCE"<<setw(20)<<"STATUS \n";
  cout<<"\n ------------------------------------------------------------------------------------------------------------ \n \n";
  cout<<l_accno<<setw(20)<<l_acctype<<setw(25)<< l_custid<<setw(20)<<l_accbalance<<setw(20)<<l_status;

  cout<<"\n Do you want to update status(y/n)?:";
  char choice;
  cin>>choice;
  return choice;
} 

void AccountUI :: displayUpdate()
{
  cout<<"\n Updated Successfully...";
}

void AccountUI :: displayDeactivate()
{
 cout<<"\n Deactivated Successfully...";
}
void AccountUI :: displayAction()
{
  cout<<"\n Action Successfull...";
}
void AccountUI :: displayExists()
{
  cout<<"\n Account already exists...";
}
void AccountUI :: displayInvalid()
{
  cout<<"\n Invalid input...";
}


/*int AccountUI :: displayAccountTypeMenu()
{
int mchoice;
cout<<"\n Account Type";
cout<<"\n1.savings"<<endl;
cout<<"\n2.current"<<endl;
cout<<"\n3.fixed"<<endl;
cout<<"enter choice:  "<<endl;
}
*/

double AccountUI::getAmount()
{
A:cin.ignore(1000,'\n');
string l_amount;
double l_amt;
cout<<"\n Enter Amount:";
getline(cin,l_amount);
int l_status=Validation::validateDouble(l_amount);
if(l_status==1)
{
    l_amt=Utility::convertToDouble(l_amount);
    return l_amt;
}
else goto A;
}

char AccountUI::displayConfirmAction()
{
    char l_val;
    cout<<"Confirm your Action:";
    cin>>l_val;
    return l_val;
}

void AccountUI::displayMessage(string p_str)
{
    cout<<p_str;
}

int AccountUI :: getMaturityPeriod()
{
int ch;
cout<<"select a choice from the available macturity period list:";
cout<<"\n 1. 1year";
cout<<"\n 2. 3year";
cout<<"\n 3. 5year \n";
cin>>ch;
return ch;
}
void AccountUI::displayfind(long int CustomerID,char Name[21],char DOB[12],char Address[31],char Accounttype[11],double balance)
{
long int l_CustomerID;
char l_Name[21];
char l_DOB[12];
char l_Address[31];
double l_balance;
char l_Accounttype[11];
l_CustomerID=CustomerID;
strcpy(l_Name,Name);
strcpy(l_DOB,DOB);
strcpy(l_Address,Address);
strcpy(l_Accounttype,Accounttype);
l_balance=balance;
cout<<"\n\t\t\t Customer Account Details\n";
cout<<" _____________________________________________________________________________________________________________________";
cout<<"\n| CUSTOMER ID | NAME             | DATE OF BIRTH   | ADDRESS           | ACCOUNT TYPE         |BALANCE              |";
cout<<"\n ___________________________________________________________________________________________________________________";
cout<<"\n|"<<l_CustomerID<<"  |"<<l_Name<<"   |"<<l_DOB<<"   |"<<l_Address<<"    |"<<l_Accounttype<<"  |"<<l_balance<<"    |";
}


void AccountUI::displayAccount(char Accounttype[11],char type[10],double Balance,char date[20])
{
char l_Accounttype[11];
double l_Balance;
char l_date[20];
char l_type[10];
strcpy(l_Accounttype,Accounttype);
strcpy(l_type,type);
l_Balance=Balance;
strcpy(l_date,date);
cout<<"\n\t\t\t Transaction Details\n";
cout<<" ________________________________________________________________________________ ";
cout<<"\n| ACCOUNT TYPE   | TRANSACTION TYPE  | TRANSACTION DATE   | BALANCE            |";
cout<<"\n ______________________________________________________________________________";
cout<<"\n|"<<l_Accounttype<<" |"<<l_type<<" |"<<l_date<<" |"<<l_Balance<<"     |";
sleep(1);
}

void AccountUI::displayfixed(char type[10],int period,char date[20],double balance,char tdate[20])
{
char l_type[10];
int l_period;
char l_date[21];
char l_tdate[21];
double l_balance;
l_period=period;
strcpy(l_type,type);
strcpy(l_date,date);
strcpy(l_tdate,tdate);
l_balance=balance;
cout<<"\n\t\t\t Transaction Details\n";
cout<<" _____________________________________________________________________________________";
cout<<"\n| TRANSACTION TYPE | MACTURITY PERIOD | FD OPENING DATE | BALANCE | TRANACTION DATE |";
cout<<"\n ___________________________________________________________________________________";
cout<<"\n|"<<l_type<<"      |"<<l_period<<"    |"<<l_date<<"     |"<<l_balance<<"   |"<<l_tdate<<"|";
}

void AccountUI::displayTransactionHeader()
{
cout<<" ________________________________________________________________________";
cout<<"\n| TRANSACTION ID | ACCOUNT NO | TRANSACTION DATE | ACCOUNT TYPE | AMOUNT |";
cout<<"\n ________________________________________________________________________";
}
void AccountUI::displayTransaction(long int l_transactionID,long int l_accountno, string l_transactiondate,string l_type,double l_amount)

{
//cout<<"\nIn UI..\n";
cout<<"\n|"<<l_transactionID<<"          |"<<l_accountno<<"      |"<<l_transactiondate<<"|"<<l_type<<"    |"<<l_amount<<"|";
}




void AccountUI::displayDetails(int l_id,long int l_accountnum, char l_type[30], char l_dates[30],char l_type1[11], int l_Amount)
{
 cout<<"\t\t\tCHEQUE BOOK REQUEST-Summary"<<endl;
 cout<<"\t\t\t___________________________"<<endl;
 cout<<"\t\t\tRequest ID:"<<l_id<<endl;
 cout<<"\t\t\tAccount Number:"<<l_accountnum<<endl;
 cout<<"\t\t\tRequest Type:"<<l_type<<endl;
 cout<<"\t\t\tRequest raised on "<<l_dates<<endl;
 cout<<"\t\t\tRs."<<l_Amount<<" deducted from your "<<l_type1<<"account bearing number "<<l_accountnum<<endl;
}

void AccountUI::displayRequest(long h_acc,long h_bal,char h_type[20],long h_customerid)
{
 cout<<"\n\t\t\tACCOUNT BALANCE-Summary"<<endl;
 cout<<"\t\t\t___________________________"<<endl;
 //cout<<"Account Number:"<<h_acc<<endl;
 cout<<"\t\t\tAccount Balance:"<<h_bal<<endl;
 cout<<"\t\t\tAccount Type:"<<h_type<<endl;
 cout<<"\t\t\tCustomer ID "<<h_customerid<<endl;
}

int AccountUI::getNumberOfCheques()
{
 int l_Choice;
 int l_Cheques;
 cout<<"\t\t\tCHEQUE BOOK TYPES"<<endl;
 cout<<"\t\t\t1. 50 page cheque book - Rs.50"<<endl;
 cout<<"\t\t\t2. 100 page cheque book - Rs.100"<<endl;
 cout<<"\t\t\tSelect your choice: ";
 
 while(true)
 {
   cin>>l_Choice;
   switch(l_Choice)
   {
     case 1: l_Cheques=50;
		break;
     case 2: l_Cheques=100;
		break;
     default: cout<<"\t\t\tInvalid Choice! Try Again: ";
	 	continue;
   }
   break;
 }
 return l_Cheques;
}
 
int AccountUI::displayAccountlist2(long int l_customerID)
{
 vector<Account> accountlist;
 Bank obj;
 accountlist=obj.dbViewAccount(l_customerID);
 if(accountlist.size()==0)
 {
  cout<<"no records"<<endl;
  return 0;
 }
 else
 {
  cout<<"\n\t\t\tAccount Number"<<setw(20)<<"AccountType"<<endl;
  for(int i=0;i<accountlist.size();i++)
  {
   cout<<"\t\t\t______________________________"<<endl;
   cout<<"\t\t\t"<<accountlist[i].m_getAccountNo()<<"\t\t\t"<<setw(20)<<accountlist[i].m_getAccountType()<<endl;
  }
 }

}

void AccountUI::displayNoRecords()
{
 cout<<"\n\t\t\tNo records Found"<<endl;
}
void AccountUI::displayRequestGenerated()
{
 cout<<"\n\t\t\tRequest Already Generated"<<endl;
}
void AccountUI::displayheader()
{
 cout<<"\t\t\t\t\t\t\t\t___________________________________"<<endl;
 cout<<"\t\t\t\t\t\t\t\t           SAHARA BANK"<<endl;
 time_t now = time(0);
 char* dt = ctime(&now);
 cout<<"\t\t\t\t\t\t\t\t\t"<<dt<<endl;

}


int AccountUI :: getBillId()
{
string BillId;
lab:cout<<"\nEnter Bill Id:";
cin>>BillId;
bool l_val,l_val1; 
l_val=Validation::validateNumber(BillId);
if(l_val==true)
{

l_val1=Validation::validateSize(BillId,4);
 if(l_val1==false)
{
cout<<"\nPlease Enter an four digit bill ID(for example:1111)\n"; goto lab;
}
}
else 
{
cout<<"\nPlease Enter an existing four digit bill ID(for example:1111)\n";
 goto lab;
}

return (Utility::convertToInt(BillId));

}

float AccountUI::getBillAmount()
{
string BillAmount;
bool l_validStatus;

lab:
cout<<"\nEnter the Bill Amount:";
cin>>BillAmount;
 l_validStatus = Validation :: validateNumber(BillAmount);
if(l_validStatus==true)
return Utility :: convertToFloat(BillAmount);
else 
{cout<<"Enter the proper bill amount(for example:1000)";
goto lab; 
}

}


int AccountUI::getBillScreen()
{
string l_choice;
bool l_val;

lab:
system ("clear");
cout<<"\n\t\t\t\t\t\t      SAHARA BANK         ";
cout<<"\n\t\t\t\t\t\t____________________________"<<endl;
 cout<<"\n\t\t\t\t\t\t      BILL PAYMENT";
cout<<"\n\t\t\t\t\t\t____________________________"<<endl;

cout<<"\n\t\t\t\t\t\t1.Pay Water Bill";
cout<<"\n\t\t\t\t\t\t2.Pay Electricity Bill";
cout<<"\n\t\t\t\t\t\t3.Pay Phone Bill";
cout<<"\n\t\t\t\t\t\t4.Exit";
cout<<"\n\t\t\tEnter a Choice(1-4) : "; 
cin>>l_choice;
l_val=Validation::validateNumber(l_choice);
if(l_val==true)
{
return (Utility::convertToInt(l_choice));
}
else 
{
cout<<"\nEnter a valid choice";
goto lab;
}
}

void AccountUI::displayBillWater(long int p_Accountno,int p_billId,double p_Amount,long int p_refId)
{
cout<<"\n\n\t              SAHARA BANK";
cout<<"\n\t___________________________________";              
cout<<"\n\n\t              BILL RECEIPT";
cout<<"\n\t------------------------------------";
cout<<"\n\n\tAccountNo          : "<<p_Accountno;
cout<<"\n\n\tBillID             : "<<p_billId;
cout<<"\n\n\tAmount paid(Rs)    : "<<p_Amount;
cout<<"\n\n\tBill Type          :  Electricity Bill";
cout<<"\n\n\tBill Reference ID  : "<<p_refId;
cout<<"\n\t------------------------------------";

}

void AccountUI::displayBillElec(long int p_Accountno,int p_billId,double p_Amount,long int p_refId)
{
cout<<"\n\n\tSAHARA BANK";
cout<<"\n\t_________________________________";
cout<<"\n\n\tBILL RECEIPT";
cout<<"\n\t--------------------------------";
cout<<"\n\n\tAccountNo          : "<<p_Accountno;
cout<<"\n\n\tBillID             : "<<p_billId;
cout<<"\n\n\tAmount paid(Rs)    : "<<p_Amount;
cout<<"\n\n\tBill Type          : Water Bill";
cout<<"\n\n\tBill Reference ID  : "<<p_refId;
cout<<"\n\t---------------------------------";

}
void AccountUI::displayBillPhone(long int p_Accountno,int p_billId,double p_Amount,long int p_refId)
{
cout<<"\n\n              SAHARA BANK";
cout<<"\n___________________________________";
cout<<"\n\n              BILL RECEIPT";
cout<<"\n\t------------------------------------";
cout<<"\n\n\tAccountNo          : "<<p_Accountno;
cout<<"\n\n\tBillID             : "<<p_billId;
cout<<"\n\n\tAmount paid(Rs)    : "<<p_Amount;
cout<<"\n\n\tBill Type          : Phone Bill";
cout<<"\n\n\tBill Reference ID  : "<<p_refId;
cout<<"\n\t------------------------------------";

}


