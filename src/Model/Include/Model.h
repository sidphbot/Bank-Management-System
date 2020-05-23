#ifndef _MODEL_H_
#define _MODEL_H_
#include "../../AppClass/branch/include/branch.h"
#include "../../AppClass/login/include/login.h"
#include "../../AppClass/employee/include/employee.h"
#include "../../AppClass/ATM/Include/ATM.h"
#include "../../AppClass/CustomerAcc/Include/Customer.h"
#include "../../AppClass/CustomerAcc/Include/Account.h"
#include "../../UI/CustomerAccUI/Include/AccountUI.h"
#include"../../AppClass/BranchAccount/Include/BranchAccount.h"
#include"../../UI/BranchAccountUI/Include/BranchAccountUI.h"
#include"../../UI/CustomerAccUI/Include/CustomerUI.h"
#include "../../UI/employeeUI/include/employeeUI.h"
#include "../../UI/ATMUI/Include/ATMUI.h"
//#include "../../UI/mainUI/include/mainUI.h"
#include<iostream>
#include<string.h>
#include<vector>
//#include</usr/include/oracle/11.2/client64/sqlca.h>
using namespace std;
class Bank
{ 
   public:
long int addBranch(Branch&);
int findBranch(long int);
Branch viewBranch(long int); 
int deleteBranch(long int);
int updateBranch(Branch&);
vector<Branch> ViewAllBranches();
int checklogin(Login&);
int changepassword(Login&);
int changepassword2(Login &);
int dbUpdateAtm(ATM &);
//int updateAccount(Account &);
//Branch viewBranch(long int);
//employee management
  long int addEmployee(Employee &, Login &);
  Employee viewEmployee(long int);
  int findEmployee(long int);
  int updateEmployeeName(long int);
  int updateEmployeeAddress(long int);
  int updateEmployeeDesignation(long int);
//  int updateEmployeeGender(long int);
//  int updateEmployeeDOB(long int);
  int deactivateEmployee(long int);
  vector<Employee> ViewAllemployees();




  //int reactivateEmployee(long int);
  vector<Employee> ViewDeactivatedEmployees();






  vector<ATM> ViewAllAtm();

 int addATMAccount(ATM &);
    int dbviewATM(long int);
    int dbcloseATM(long int);
    int findAtmId(long int);
    void dbConnect();
    double displayBalance(long int);
    void disconnect();
 int addCustomerAccount(Customer &,Account &);
 int findCustomerID(long int);
 int dbcloseAccount(long int);
 int findAccountNo(long int);
 int accountStatementGeneration(long int);
int dbFundCashDeposit(Account &,double); 
int dbCashDeposit(Account &,double);
 int dbCashWithdrawal(Account &,double);
  int dbViewCustomer(Customer &);
  int dbRequestBlockATMCard(Customer &);
long int addBranchAccount(BranchAccount &);
int findBranchAccount(long int);
int deleteBranchAccount(long int);
BranchAccount viewBranchAccount(long int );
int updateBranchID(BranchAccount &);
int updateBranchThreshold(BranchAccount &);
int updateCurrentBalance(BranchAccount &);
int dbfixedCashWithdrawal(Account&);
int  findAccountno(long int);
int  findAccountno1(long int);
int dbGetAccountBalance(long int,long int);
int dbInitiateChequeBookRequest(long int,long int);
vector<Account> dbViewAccount(long int);
 int dbAddCustomer(Customer &);
int findCustomerID1(long int);
  //int dbViewCustomer(Customer &);
  int updateCustomerName1(long int);
  int updateCustomerdob(long int);
  int updateCustomerGender(long int);
  int updateCustomerAddress(long int);
  int DeactivateCustomer(long int);
  int dbBillPaymentElectricity(Account &);
  int dbBillPaymentPhone(Account &);
  int dbBillPaymentWater(Account &);
  vector<Customer> ViewAllCustomer();
int dbCashDeposit1(Account &,double);
 int dbCashWithdrawal1(Account &,double);

  int updateAccount(Account &);
   vector<BranchAccount> ViewAllBranchAccount();



};

#endif
