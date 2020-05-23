
#ifndef _BRANCHACCOUNTMODEL_H_
#define _BRANCHACCOUNTMODEL_H_
#include<iostream>
//#include<sqlca.h>
#include"../../AppClass/BranchAccount/Include/BranchAccount.h"
//#include"../../Controller/BranchAccountController/Include/BranchAccountController.h"
#include"../../UI/BranchAccountUI/Include/BranchAccountUI.h"
using namespace std;

class BranchAccountModel
{
public:
long int addBranchAccount(BranchAccount &);
int findBranchAccount(long int);
void dbConnect();
void disconnect();
int deleteBranchAccount(long int);
BranchAccount viewBranchAccount(long int );
int updateBranchID(BranchAccount &);
int updateBranchThreshold(BranchAccount &);
int updateCurrentBalance(BranchAccount &);

};

#endif
