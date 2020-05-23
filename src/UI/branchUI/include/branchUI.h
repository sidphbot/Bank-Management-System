#ifndef _BRANCHUI_H_
#define _BRANCHUI_H_
#include "../../../AppClass/branch/include/branch.h"
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


class BranchUI
{
public: 
void display(string);
string getBranchLocation();
string getBranchRegion();
long int  getBranchID();
long int  getBranchAccountNo();
long int  getBranchBM();
void displayBranch(Branch&);
Branch updateBranch();
void display(vector<Branch>);
};

#endif
