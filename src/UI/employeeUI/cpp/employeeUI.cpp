#include "../include/employeeUI.h"
#include "../../../Utility/Include/Utility.h"
#include "../../../Validation/Include/Validation.h"
#include<stdlib.h>

long int EmployeeUI::getEmployeeID()
{  
   string l_empID;
   long int l_employeeId;
   bool l_val,l_val1;
   cin.ignore(1000,'\n');
   lab:cout<<"\n Enter Employee ID:";
   getline(cin,l_empID);
   if(l_empID=="exit")
   {
    return 2;
   }
   l_val=Validation::validateNumber(l_empID);
   if(l_val==true)
   {
      l_val1=Validation::validateSize(l_empID,6);
      if(l_val1==false)
      {
          cout<<"\nPlease enter the ID within 6 digits\n";
          goto lab;
      }
   }
   else
      {
          cout<<"Please enter only numbers\n";
          goto lab;
      }
   l_employeeId=Utility::convertToLongInt(l_empID);
   return l_employeeId;
}

string EmployeeUI::getEmployeeAddress()
{
    string l_employeeAddress;
    cin.ignore(1000,'\n');
    cout<<"\n Enter Address:";
    getline(cin,l_employeeAddress);
    if(l_employeeAddress=="exit")
  {
   return "2";
  }
    return l_employeeAddress;
 
}

string EmployeeUI::getEmployeeName()
{
    string l_employeeName;
    bool l_val,l_val1;
    cin.ignore(1000,'\n');
    lab:cout<<"\n Enter Name:";
    getline(cin,l_employeeName);
    if(l_employeeName=="exit")
    {
     return "2";
    }
    l_val=Validation::validateString(l_employeeName);
    if(l_val==false)
    {  
        displayMessage("\nPlease enter only alphabets\n");;
        goto lab;
    }
    l_val1=Validation::validateSize(l_employeeName,32);
    if(l_val1==false)
    {
        displayMessage("\nPlease enter your name within 32 characters\n");
        goto lab;
    }     
    return l_employeeName;
    
}

string EmployeeUI::getEmployeeDOB()
{
    string l_employeeDOB;
    cin.ignore(1000,'\n');
    bool l_val;
    lab:cout<<"\n Enter Date Of Birth(dd-mm-yyyy):";
    getline(cin,l_employeeDOB);
    if(l_employeeDOB=="exit")
    {
     return "2";
    }
    l_val=Validation::validateDate(l_employeeDOB);
    if(l_val==false)
    {
        displayMessage("\nPlease enter your date as per the given format\n"); 
        goto lab;
    }
   
    return l_employeeDOB;
    
}

char EmployeeUI::getEmployeeGender()
{
    string l_employeeGender;
    char l_empGen;
    bool l_val;
    cin.ignore(1000,'\n');
    lab:cout<<"\n Enter Gender [M/m-Male and F/f-Female]:";
    getline(cin,l_employeeGender);
    if(l_employeeGender=="exit")
    {
     return 'a';
    }
    l_val=Validation::validateGender(l_employeeGender);
    if(l_val==false)
    {
        displayMessage("\nPlease enter M/m for Male or F/f for Female\n");
        goto lab;
    }
    l_empGen=Utility::convertToChar(l_employeeGender);
    return l_empGen;
    
}

string EmployeeUI::getEmployeeDesignation()
{
     string l_employeeDesignation,l_choice;
     cin.ignore(1000,'\n');
     bool l_val;
     lab:cout<<"\n Designation:\n";
     cout<<"1.General Manager\n";
     cout<<"2.Regional Manager\n";
     cout<<"3.Branch Manager\n";
     cout<<"4.Clerk/Accountant\n";
     cout<<"Enter your choice:";
     getline(cin,l_choice);
     if(l_choice=="exit")
     {
      return "2";
     }
     l_val=Validation::validateNumber(l_choice);
     if(l_val==false)
     {
          displayMessage("\nPlease enter a number\n");
          goto lab;
     }
     int l_ch=Utility::convertToInt(l_choice);
     switch(l_ch)
     {
         case 1:l_employeeDesignation="General Manager";
                break;
         case 2:l_employeeDesignation="Regional Manager";
                break;
         case 3:l_employeeDesignation="Branch Manager";
                break;
         case 4:l_employeeDesignation="Clerk/Accountant";
                break;
        default:cout<<"Invalid choice.\nPlease enter a valid choice\n";
                goto lab;
     }
       
     return l_employeeDesignation;
     
}


void EmployeeUI::displayHeading()
{
    cout<<"\n\t\t\t$***************************************************************************************$"<<endl;
    cout<<"\t\t\t$                                     WELCOME                                           $"<<endl;
    cout<<"\t\t\t$                                       TO                                              $"<<endl;
    cout<<"\t\t\t$                           SAHARA BANK MANAGEMENT SYSTEM                               $"<<endl;
    cout<<"\t\t\t$***************************************************************************************$"<<endl;
}


void EmployeeUI::displayScreen()
{   
    system("clear");
    displayHeading();
    cout<<"\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t                              1.Bank Management\n";
    cout<<"\t\t\t                              2.Employee Management\n";
    cout<<"\t\t\t                              3.Customer Management\n";
    cout<<"\t\t\t                              4.Account management\n";
    cout<<"\t\t\t                              5.Branch Account Management\n";
    cout<<"\t\t\t                              6.ATM Management\n";
    cout<<"\t\t\t                              7.Customer Services management\n";
    cout<<"\t\t\t                              8.Exit\n";
}

void EmployeeUI::displayEmployeeScreen()
{   
    system("clear");
    displayHeading();
    cout<<"\n\t\t\t**************************WELCOME TO EMPLOYEE MANAGEMENT**************************\n"; 
     cout<<"\n\n\t\t\tHome/Employee Management\n";
     cout<<"\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout<<"\t\t\t                                1.Add Employee\n";
    cout<<"\t\t\t                                2.View Employee\n";
    cout<<"\t\t\t                                3.Update Employee\n";
    cout<<"\t\t\t                                4.Deactivate Employee\n";
    cout<<"\t\t\t                                5.View All Employee details\n";
    cout<<"\t\t\t                                6.View Deactivated Employee details\n";
    cout<<"\t\t\t                                7.Go Back to Main Menu\n";
    cout<<"\t\t\t                                8.Exit\n"; 
}


void EmployeeUI::displayCustomerServiceScreen()
{
   system("clear");
   displayHeading();
   cout<<"\n\t\t\t**********************WELCOME TO CUSTOMER SERVICE MANAGEMENT**************************\n";
   cout<<"\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
   cout<<"\t\t\t                                  1.Fund Transfer\n";
   cout<<"\t\t\t                                  2.Bill Payment\n";
   cout<<"\t\t\t                                  3.Cash Deposit\n";
   cout<<"\t\t\t                                  4.Cash Withdrawal\n";
   cout<<"\t\t\t                                  5.Balance Enquiry\n";
   cout<<"\t\t\t                                  6.Request for Cheque Book\n";
   cout<<"\t\t\t                                  7.Block ATM\n";
   cout<<"\t\t\t                                  8.Account Statement\n";
   cout<<"\t\t\t                                  9.Go Back to Main Menu\n";
   cout<<"\t\t\t                                  10.Exit\n";
}


void EmployeeUI::displayDetails(Employee &p_empobj)
{
    cout<<"\n\t\t\tThe details of the employee are:\n";
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|Employee Id : |"<<p_empobj.getEmployeeId()<<"                |"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|Name        : |"<<p_empobj.getEmployeeName()<<"              |\n"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|DOB         : |"<<p_empobj.getEmployeeDOB()<<"               |\n"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|Gender      : |"<<p_empobj.getEmployeeGender()<<"            |\n"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|Address     : |"<<p_empobj.getEmployeeAddress()<<"           |\n"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";
    cout<<"\t\t\t\t|Designation : |"<<p_empobj.getEmployeeDesignation()<<"       |\n"<<endl;
    cout<<"\t\t\t\t|-------------------------------------------------------------|\n";

}


int EmployeeUI::displayUpdateScreen()
{
   int l_choice1,k;
   string l_choice;
   cout<<"\n\t\t\tEnter the field to be updated:\n";
   cout<<"\t\t\t1.Employee Name\n";
   cout<<"\t\t\t2.Employee Address\n";
   cout<<"\t\t\t3.Employee Designation\n";
   cout<<"\t\t\t4.Exit\n";
    do{
      k=0;
      getline(cin,l_choice);
       int l_ValidStatus = Validation :: validateChoice(l_choice);
        if(l_ValidStatus == 0)
        {
           cout<<"\nInvalid choice... please enter a numeric value\n";
           k=1;
        }
       cout<<"\n";
      }while(k);
      l_choice1= Utility::convertToInt(l_choice);

   return l_choice1;
}


char EmployeeUI::confirmAction()
{
 
   string l_ch;
   char l_conf;
   cin.ignore();
   getline(cin,l_ch);
   int l_s=Validation::validateChoice1(l_ch);
   if(l_s==1)
   {
      l_conf=Utility::convertToChar(l_ch);
      return l_conf;
  }
  else return ' ';
}

void EmployeeUI::displayMessage(string p_message)
{
    cout<<p_message;
}

void EmployeeUI:: display(vector<Employee> employeeList)
{
    system("clear");
    vector<Employee>::iterator employeeIter;
    displayMessage("*********************************Employee Details**************************************** \n\n");
    cout<<"Employee_ID"<<"\t\t"<<"Employee_NAME"<<"      \t"<<"Employee_DOB"<<"\t\t"<<"Employee_Gender"<<"\t\t"<<"Employee_Address"<<"\t\t"<<"Employee_Designation"<<endl;
    for (employeeIter = employeeList.begin(); employeeIter != employeeList.end(); employeeIter++)
    {
       cout<<(*employeeIter).getEmployeeId()<<"\t\t\t"<<(*employeeIter).getEmployeeName()<<(*employeeIter).getEmployeeDOB()<<"\t"<<(*employeeIter).getEmployeeGender()<<"\t\t"<<(*employeeIter).getEmployeeAddress()<<"\t"<<(*employeeIter).getEmployeeDesignation()<<endl;
    }
        //displayMessage("\nPress enter to exit :");
        //cin.ignore().get();
       // system("clear");
}









void display(vector<Employee> DeactivatedEmployeeList)
{
    system("clear");
    vector<Employee>::iterator DeactivatedEmployeeIter;
    //displayMessage("*********************************Employee Details**************************************** \n\n");
    cout<<"*******************************Deactivated Employee Details*************************************\n\n";
    cout<<"Employee_ID"<<"\t\t"<<"Employee_NAME"<<"      \t"<<"Employee_DOB"<<"\t\t"<<"Employee_Gender"<<"\t\t"<<"Employee_Address"<<"\t\t"<<"Employee_Designation"<<endl;
    for (DeactivatedEmployeeIter = DeactivatedEmployeeList.begin(); DeactivatedEmployeeIter != DeactivatedEmployeeList.end(); DeactivatedEmployeeIter++)
    {
       cout<<(*DeactivatedEmployeeIter).getEmployeeId()<<"\t\t\t"<<(*DeactivatedEmployeeIter).getEmployeeName()<<(*DeactivatedEmployeeIter).getEmployeeDOB()<<"\t"<<(*DeactivatedEmployeeIter).getEmployeeGender()<<"\t\t"<<(*DeactivatedEmployeeIter).getEmployeeAddress()<<"\t"<<(*DeactivatedEmployeeIter).getEmployeeDesignation()<<endl;
    }
        
}









