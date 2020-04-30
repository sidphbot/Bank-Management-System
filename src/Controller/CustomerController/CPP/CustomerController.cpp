#include<iostream>
#include<string.h>
#include "../Include/CustomerController.h"
#include<stdlib.h>
using namespace std;

int CustomerController :: initAddCustomer(Bank &p_DBObj)
{
CustomerUI l_UI;
string l_dob;
string l_CustomerName;
char l_CustomerGender;
string l_CustomerAddress;
string l_AtmStatus;
//l_CustomerAge=l_UI.getCustomerAge();
l_CustomerName=l_UI.getCustomerName();
if(l_CustomerName=="2")
{
return 0;
}
l_dob=l_UI.getCustomerdob();
if(l_dob=="2")
{
return 0;
}
l_CustomerGender=l_UI.getCustomerGender();
if(l_CustomerGender=='a')
{
return 0;
}

l_CustomerAddress=l_UI.getCustomerAddress();
if(l_CustomerAddress=="2")
{
return 0;
}

//l_AtmStatus=l_UI.getCustomerAtmStatus();
Customer l_tempCustomer(l_CustomerName,l_dob,l_CustomerGender,l_CustomerAddress,l_AtmStatus);


p_DBObj.dbAddCustomer(l_tempCustomer);
return 0;
}


int CustomerController :: initiateRequestBlockATMCard(Bank &p_DBObj)
{
CustomerUI l_UI;
long int l_CustomerID;
int l_CustomerStatus;
int l_status;
char ch;
do
{
l_CustomerID=l_UI.getCustomerId();
l_CustomerStatus=p_DBObj.findCustomerID(l_CustomerID);
cout<<"\n\n press Y/y to continue, press any other key to go back ";
cin>>ch;
}while(ch!='y' && ch!='Y');

if(l_CustomerStatus==1)
{
Customer l_tempCustomer;
l_tempCustomer.setCustomerId(l_CustomerID);
l_status=p_DBObj.dbRequestBlockATMCard(l_tempCustomer);
return l_status;
}
else
{
cout<<"\n No such Customer exists";
return 0;
}
}



int CustomerController :: initiateUpdateCustomer(Bank &p_dbObj)
{ 
  CustomerUI p_UIobj;
  long int l_CustomerId;
   int l_status,l_choice;
   Customer p_Customer;
   l_CustomerId=p_UIobj.getCustomerId();
   if(l_CustomerId==2)
   {
   return 0;
   }
   if(p_dbObj.findCustomerID1(l_CustomerId)==0)
 { cout<<"\nThis customer id is not associated with Sahara bank";    
  return 0;
}  
else
{ 
l_choice=p_UIobj.displayUpdateScreen();
    switch(l_choice)
{ 
 case 1: 

l_status= p_dbObj.updateCustomerName1(l_CustomerId);
return l_status;
break;


 case 3:
l_status= p_dbObj.updateCustomerdob(l_CustomerId);
return l_status;
break;

case 2:
l_status= p_dbObj.updateCustomerGender(l_CustomerId);
return l_status;
break;
case 4: 
l_status= p_dbObj.updateCustomerAddress(l_CustomerId);
return l_status;
break;
}
}
}
int CustomerController :: initiateDeactivateCustomer(Bank &p_dbObj)
{
CustomerUI p_UIobj;
  long int l_CustomerId;
   int l_status,l_choice;
   Customer p_Customer;
  
  l_CustomerId=p_UIobj.getCustomerId();
   if(l_CustomerId==2)
   {
   return 0;
   }

   if(p_dbObj.findCustomerID1(l_CustomerId)==0)
    {
cout<<"\nThis customer id is not associated with Sahara bank";
 return 0;}
 
   p_dbObj.DeactivateCustomer(l_CustomerId);
    return 0;
}


int CustomerController :: initiateViewCustomer(Bank &p_DBObj)
{
CustomerUI l_UI;
long int l_CustomerID;
l_CustomerID=l_UI.getCustomerId();
   if(l_CustomerID==2)
   {
   return 0;
   }

int l_CustomerStatus=p_DBObj.findCustomerID1(l_CustomerID);
if(l_CustomerStatus==1)
{
Customer l_tempCustomer;
l_tempCustomer.setCustomerId(l_CustomerID);
int l_status=p_DBObj.dbViewCustomer(l_tempCustomer);
return l_status;
}
else
{
cout<<"no such customer id exists";
return 0;
}
Customer l_tempCustomer;
l_tempCustomer.setCustomerId(l_CustomerID);
p_DBObj.dbViewCustomer(l_tempCustomer);

return 0;
}

 void CustomerController::initiateViewAllCustomer(Bank &p_bankObj)
{
  CustomerUI p_employeeUIObj;
  vector<Customer> employeeList;
  employeeList = p_bankObj.ViewAllCustomer();
  if(employeeList.size()!=0)
      p_employeeUIObj.displayviewall(employeeList);
  else
       cout<<"\n\nRecords not Found........\n";
}    
