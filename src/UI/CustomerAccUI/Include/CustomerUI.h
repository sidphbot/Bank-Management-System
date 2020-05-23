
#ifndef _CUSTOMERUI_H_
#define _CUSTOMERUI_H_
#include<string>
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
#include "../../../AppClass/CustomerAcc/Include/Customer.h"
#include<vector>
using namespace std;

class CustomerUI
{
   public:
 	string getCustomerAddress();
string getCustomerName();
int getCustomerAge();
char getCustomerGender();
string getCustomerAtmStatus();
long int getCustomerID();
long int getCustomerId();
void displayview(long int,string ,string ,string ,string ); 
int displayUpdateScreen();
void displayDetails(long int, char*, int, char*); 
void displayDeactivateScreen();
//int displayBillScreen();
//int getBillId();
//int getBillAmount();
string getCustomerdob();
void displayviewall(vector<Customer>);
//void display(vector<Agent>);

};

#endif
