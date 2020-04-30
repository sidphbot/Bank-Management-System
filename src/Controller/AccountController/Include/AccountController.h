#ifndef _ACCOUNTCONTROLLER_H_
#define _ACCOUNTCONTROLLER_H_
#include <iostream>
#include <string>



#include "../../../Model/Include/Model.h"


using namespace std;
class AccountController
{
public:
int initiateUpdateCustomerAccount(Bank&);
void initiateViewAccountDetails1(CustomerUI &,Bank &);
int initiateCashDeposit(Bank &);
int initiateCashWithdrawal(Bank &);
//int initiateBalanceInquiry(Bank &);
//int initiateRequestBlockATMCard(Bank &);
int initiateAddCustomerAccount(Bank &);
int initiateDeactivateAccountController(Bank &);
int initiateAccountStatementGeneration(AccountUI &,Bank &);
int initiateFundTransfer(AccountUI &,Bank &);
long initiateBalanceEnquiry(Bank &);
void initiateViewAccountDetails(AccountUI &,Bank &);
long initiateChequeBookRequest(Bank &);
int initiateBillPayment(Bank &);

};
#endif

