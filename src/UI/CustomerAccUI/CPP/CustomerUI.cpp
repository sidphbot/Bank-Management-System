#include "../Include/CustomerUI.h"
#include<iostream>
using namespace std;
#include<string>

/*void AgentUI :: display(vector<Agent> AgentList1)
{
  vector<Agent>::iterator ViewAgent;
  cout<<"\n\t------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n\tAgentId\tAgentName\tAgentAddress\tAgentAge\tAgentGender\tAgentContact\tAgentMailId\tAgentSalary\tAgentStatus"<<endl;
  cout<<"\n\t------------------------------------------------------------------------------------------------------------------------------------------\n"<<endl;
  for (ViewAgent = AgentList1.begin(); ViewAgent!= AgentList1.end(); ViewAgent++)
  {
   cout<<"\t"<<(*ViewAgent).getAgentID()<<"\t"<<(*ViewAgent).getAgentName()<<"\t"<<(*ViewAgent).getAgentAddress()<<"\t"<<(*ViewAgent).getAgentAge()<<"\t"<<(*ViewAgent).getAgentGender()<<"\t"<<(*ViewAgent).getAgentContact()<<"\t"<<(*ViewAgent).getAgentMailID()<<"\t"<<(*ViewAgent).getAgentSalary()<<"\t"<<(*ViewAgent).getAgentStatus()<<endl;
   cout<<"\t-------------------------------------------------------------------------------------------------------------------------------------------\n"<<endl;
  }
}*/

long int  CustomerUI::getCustomerID(){
   string l_customerID;
   int l_Validstatus;
   do{
   cout<<"\n Customer ID:";
   cin>>l_customerID;
   if(l_customerID=="exit")
{
return 2;
}

   l_Validstatus=Validation::ValidateNumber(l_customerID);
   if(l_Validstatus==1)
   return Utility :: convertToLongInt(l_customerID);
   else
   cout<<"\n Invalid ID.. \n Enter again";
  }while(l_Validstatus==0);
 }

string CustomerUI::getCustomerName(){
 string l_customerName;
 int l_Validstatus;
 
  cin.ignore(1000,'\n');
 a:cout<<"\nEnter Name:";
  
   getline(cin,l_customerName);
if(l_customerName=="exit")
{
return "2";
}

   l_Validstatus=Validation::ValidateString(l_customerName);
    if(l_Validstatus==1)
     return l_customerName;
      else
        cout<<"\nName must be in alphabets(for eg: akash gundlapally)";
        goto a;
         }


void CustomerUI:: displayviewall(vector<Customer> employeeList)
{
    system("clear");
    int i;
   cout<<"\n\t\t\t\t\t\t\t***CUSTOMER DETAILS*** \n\n";
   cout<<"\n_____________________________________________________________________________________________________________________________";
    cout<<"\nCustomer_ID"<<"\t"<<"Customer_NAME"<<"\t\t    "<<"Customer_DOB"<<"\t"<<"Gender"<<"\t"<<"Customer_Address"<<"\t\t\t"<<"ATMStatus"<<endl;
   cout<<"\n_____________________________________________________________________________________________________________________________";
 
  // for (employeeIter = employeeList.begin(); employeeIter != employeeList.end(); employeeIter++)
 for(i=0;i<employeeList.size();i++)
    {
	    
     cout<<"\n"<<employeeList[i].getCustomerId()<<"\t\t"<<employeeList[i].getCustomerName()<<employeeList[i].getCustomerdob()<<employeeList[i].getCustomerGender()<<"\t"<<employeeList[i].getCustomerAddress()<<"\t\t"<<employeeList[i].getCustomerAtmStatus();
  cout<<"\n------------------------------------------------------------------------------------------------------------------------------";    
//   cout<<(*employeeIter).getCustomerId()<<"\t\t"<<(*employeeIter).getCustomerName()<<(*employeeIter).getCustomerdob()<<"\t\t"<<(*employeeIter).getCustomerGender()<<"\t\t"<<(*employeeIter).getCustomerAddress()<<"\t\t"<<(*employeeIter).getCustomerAtmStatus()<<endl;
    }
      
 

//        cin.ignore().get();
       // system("clear");
        }


void  CustomerUI::displayview(long int p_CustomerId,string p_Name,string p_dob,string p_Address, string h_AtmStatus)
{
cout<<"\n\n              CUSTOMER DETAILS";
cout<<"\n\t----------------------------------";
 cout<<"\n\n\tCUSTOMERID      : "<<p_CustomerId;
cout<<"\n\n\tName            : "<<p_Name;
cout<<"\n\n\tDate of birth   : "<<p_dob;
cout<<"\n\n\tAddress         : "<<p_Address;
cout<<"\n\n\tAtm Status      : "<<h_AtmStatus;
cout<<"\n\t-----------------------------------";
//cout<<"\nEnter Y to deactivate this account : ";

}


string CustomerUI::getCustomerAddress()
{
string l_customerAddress;
cin.ignore(1000,'\n');
a:cout<<"\nEnter Address : ";
getline(cin,l_customerAddress);
int p=l_customerAddress.length();
if(p<=30)
{
if(l_customerAddress=="exit")
{
return "2";
}
int p=l_customerAddress.length();
if(p==0)
{
cout<<"Address field cannot be blank"<<endl;
goto a;
}
return l_customerAddress;
}
else
{
cout<<"\n Address is too long";
goto a;
}
}



int CustomerUI::getCustomerAge()
{
//int l_validstatus;
//string l_customerAge;
int l_customerAge;
//l_validstatus = 0;
// do
//{
cout<<"\nEnter Age : ";
cin>>l_customerAge;
//l_validstatus=Validation::validateNumber(l_customerAge);
//cout<<l_validstatus;
//}while(l_validstatus == 0);
//return Utility :: convertToInt(l_customerAge);
return l_customerAge;
}


char CustomerUI::getCustomerGender()
{
string l_employeeGender;
    char l_empGen;
    bool l_val;
    lab:cout<<"\nEnter Gender(M/F):";
    cin>>l_employeeGender;
if(l_employeeGender=="exit")
{
return 'a';
}

    l_val=Validation::validateGender(l_employeeGender);
    if(l_val==false)
    {
        cout<<"Please Enter M or F (NA if not applicable)\n";
        goto lab;
    }
    l_empGen=Utility::convertToChar(l_employeeGender);
    return l_empGen;
/*char l_customerGender;
//int l_validstatus; 
//l_validstatus = 0;
//do
//{

cout<<"\nEnter Gender : ";
cin>>l_customerGender;
//l_validstatus=Validation:: Gender(l_customerGender);
//}while(l_validstatus == 0);
return l_customerGender;*/

}


/*string CustomerUI::getCustomerAtmStatus()
{
//int l_validstatus;
//l_validstatus = 0;
string l_customerATMStatus;
//do
//{
cout<<"\nCustomer ATM Status:";
cin>>l_customerATMStatus;
//l_validstatus=Validation::validateString(l_customerATMStatus);
//}while(l_validstatus == 0);
return l_customerATMStatus;
}*/

long int CustomerUI::getCustomerId()
{
 bool status;
 string l_customerID;
 //validate val;
 //utility u;
 for(int i=0;i<3;i++)
 {
  cout<<"\n\t\t\tEnter your 6 digit customer ID:";
  cin>>l_customerID;
  if(l_customerID=="exit")
  {
  return 2;
  }
  status=Validation::validateNumber(l_customerID);
  if(status== true)
  {
    return Utility::convertToLong(l_customerID);
  }
  else
  {
  cout<<"\n invalid customer id\n";
 

  }
 }
 return 0;


}

int CustomerUI::displayUpdateScreen()
{
   string l_choice;
bool status;
   cout<<"\n\t\tUpdate Menu";
   cout<<"\n\t\t___________________________________\n";
   cout<<"\t\t1.Update customer name\n";
   cout<<"\t\t2.Update customer gender\n";
   cout<<"\t\t3.Update customer date of birth \n";
   cout<<"\t\t4.Update customer address\n";
   
   a: cout<<"\nEnter the field to be updated : ";
   cin>>l_choice;
status=Validation::validateNumber(l_choice);
if(status==true)
{
   return  Utility::convertToInt(l_choice);
}
else 
{
cout<<"\nInvalid Choice";

goto a;
}
}



void CustomerUI::displayDetails(long int p_id, char p_name[30], int p_Age, char p_address[30])
{
    cout<<"The details of the employee are:\n";
    cout<<"Employee Id:"<<p_id<<endl;
    cout<<"Name:"<<p_name<<endl;
    cout<<"Age:"<<p_Age<<endl;
   // cout<<"Gender:"<<p_empobj.getEmployeeGender()<<endl;
    cout<<"Address:"<<p_address<<endl;
   // cout<<"Designation:"<<p_empobj.getEmployeeDesignation()<<endl;
}
void CustomerUI::displayDeactivateScreen()
{
cout<<"\nplease enter the customer id to deactivate:\n";
}
/*
int CustomerUI::displayBillScreen()
{
int l_choice;
cout<<"\nEnter a choice";
cout<<"\n1.Electricity bill";
cout<<"\n2.Phone bill";
cout<<"\n3.Water bill\n";
cin>>l_choice;
return l_choice;
}
int CustomerUI:: getBillId()
{
long int l_BillId;
cout<<"\nenter a bill id:";
cin>>l_BillId;
return l_BillId;
}
int CustomerUI:: getBillAmount()
{
int l_Amount;
cout<<"\nenter amount:";
cin>>l_Amount;
return l_Amount;
*/
string CustomerUI:: getCustomerdob()
{
string l_employeeDOB;
    bool l_val;
    lab:cout<<"\nEnter Customer DOB(dd-mm-yyyy):";
    cin>>l_employeeDOB;
if(l_employeeDOB=="exit")
{
return "2";
}

    l_val=Validation::validateDate(l_employeeDOB);
    if(l_val==false)
    {
        cout<<"\nEnter date in appropriate format(for example 30-08-2014)\n";
        goto lab;
    }
    return l_employeeDOB;
}



