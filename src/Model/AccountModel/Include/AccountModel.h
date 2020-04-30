
#ifndef _BANK_H_
#define _BANK_H_
#include "../../../AppClass/CustomerAcc/Include/Customer.h"
#include "../../../AppClass/CustomerAcc/Include/Account.h"
#include "../../../UI/CustomerAccUI/Include/AccountUI.h"
#include<iostream>
#include<string.h>
//#include</usr/include/oracle/11.2/client64/sqlca.h>
using namespace std;
class Bank
{ 
   public:
 int addCustomerAccount(Customer &,Account &);
 int findCustomerID(long int);
 int dbcloseAccount(long int);
 int findAccountNo(long int);
 void dbConnect();
 void disconnect();
 int accountStatementGeneration(long int);
 int dbCashDeposit(Account& , double);
 int dbCashWithdrawal(Account& , double);
  int dbViewCustomer(Customer &);
  int dbRequestBlockATMCard(Customer &);
};

#endif
