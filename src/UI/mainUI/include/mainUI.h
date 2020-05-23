#ifndef _MAINUI_H_
#define _MAINUI_H_

#include<iostream>
#include<string>
#include<stdlib.h>

#include"../../../AppClass/branch/include/branch.h"
#include"../../../Model/Include/Model.h"
#include"../../../Controller/branchController/include/branchController.h"
#include"../../../UI/branchUI/include/branchUI.h"
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
#include"../../../Controller/employeeController/include/employeeController.h"
#include"../../../UI/employeeUI/include/employeeUI.h"
#include"../../../AppClass/employee/include/employee.h"
#include"../../../Controller/CustomerController/Include/CustomerController.h"
#include"../../../Controller/AccountController/Include/AccountController.h"
#include"../../../Controller/BranchAccountController/Include/BranchAccountController.h"
#include"../../../AppClass/BranchAccount/Include/BranchAccount.h"
 #include"../../../UI/BranchAccountUI/Include/BranchAccountUI.h"
// #include"../../../Model/Include/Model.h"
//#include"../../Model/AccountModel/Include/AccountModel.h"
#include"../../../UI/CustomerAccUI/Include/AccountUI.h"
#include "../../../AppClass/ATM/Include/ATM.h"
#include "../../../AppClass/CustomerAcc/Include/Account.h"
#include "../../../AppClass/CustomerAcc/Include/Customer.h"
//#include "../../../../atmaccount/Model/CustomerAccount/Include/Bank.h"
//#include "../../../Controller/AccountController/Include/AccountController.h"
#include "../../../UI/ATMUI/Include/ATMUI.h"
#include "../../../Controller/ATMController/Include/ATMController.h"
//#include "../../../Controller/CustomerController/Include/CustomerController.h"
#include "../../../UI/CustomerAccUI/Include/CustomerUI.h"
//#include "../../../../customer/Model/Include/Bank.h"
//#include "../../../../customer/Validation/customer/Include/Validation.h"
//#include "../../../../customer/Utility/customer/Include/Utility.h"



using namespace std;


class MainUI
{
public:
void mainMenu();
void branchManagement();
void employeeManagement();
void mainHeader();
void customerAccountManagement();
void ATMManagement();
void customerManagement();
void customerServiceManagement();
void branchAccountManagement();


};

#endif
