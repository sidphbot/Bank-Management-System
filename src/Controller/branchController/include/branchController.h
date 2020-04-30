
#ifndef _BRANCHCONTROLLER_H_
#define _BRANCHCONTROLLER_H_

#include<iostream>
#include<string>

#include"../../../Model/Include/Model.h"
#include"../../../UI/branchUI/include/branchUI.h"
using namespace std;


class BranchController
{
  public:

long int initiateBranchAddition(Bank&);
int initiateViewBranch(Bank&);
int initiateDeleteBranch(Bank&);
int initiateUpdateBranch(Bank&);
void initiateViewAllBranches(BranchUI &,Bank &);


};

#endif
