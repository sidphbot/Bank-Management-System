#include "../include/employeeController.h"
#include "../../../AppClass/employee/include/employee.h"
#include "../../../UI/loginUI/include/loginUI.h"
#include "../../../AppClass/login/include/login.h"
#include "../../../Model/Include/Model.h" 
 

int EmployeeController::initiateAddEmployee(EmployeeUI &p_EmployeeUIobj,Bank &p_Bankobj)
{
   string l_employeeName;
   string l_employeeDOB;
   long int l_empId;
   char l_employeeGender; 
   string l_employeeAddress;
   string l_employeeDesignation;
   int l_employeeStatus;
   l_employeeName=p_EmployeeUIobj.getEmployeeName();
   if(l_employeeName=="2")
   {
      p_EmployeeUIobj.displayMessage("\nYou have exited successfully");
      return 0;
   }
   l_employeeDOB=p_EmployeeUIobj.getEmployeeDOB();
    if(l_employeeDOB=="2")
  {
    p_EmployeeUIobj.displayMessage("\nYou have exited successfully");

    return 0;
   }

   l_employeeGender=p_EmployeeUIobj.getEmployeeGender();
 if(l_employeeGender=='a')
 {  
    p_EmployeeUIobj.displayMessage("\nYou have exited successfully");
    return 0;
   }

   l_employeeAddress=p_EmployeeUIobj.getEmployeeAddress();
 if(l_employeeAddress=="2")
 {
     p_EmployeeUIobj.displayMessage("\nYou have exited successfully");
    return 0;
   }

   l_employeeDesignation=p_EmployeeUIobj.getEmployeeDesignation();
  if(l_employeeDesignation=="2")
  {
     p_EmployeeUIobj.displayMessage("\nYou have exited successfully");
    return 0;
   }

   
   Employee l_tempEmployee;
   l_tempEmployee.setEmployeeName(l_employeeName);
   l_tempEmployee.setEmployeeDOB(l_employeeDOB);
   l_tempEmployee.setEmployeeGender(l_employeeGender);
   l_tempEmployee.setEmployeeAddress(l_employeeAddress);
   l_tempEmployee.setEmployeeDesignation(l_employeeDesignation);


	string l_Seqans1;
	string l_Seqans2;
	string l_password;	
        LoginUI l_LoginUIObj;
	l_Seqans1=l_LoginUIObj.getSeqans1();	
	l_Seqans2=l_LoginUIObj.getSeqans2();
	l_password=l_LoginUIObj.getPassword();
	
	Login l_LoginObj(0,l_Seqans1,l_Seqans2,l_password);

	
   
   string l_choice;
   p_EmployeeUIobj.displayMessage("\nPlease press Y to confirm your registration:");
   //l_choice=p_EmployeeUIobj.confirmAction();
   cin>>l_choice;
   if(l_choice=="Y" || l_choice=="y")
   {
       l_empId=p_Bankobj.addEmployee(l_tempEmployee,l_LoginObj);
       cout<<"Employee ID:"<<l_empId<<endl;
       return 1;
   }
   else return 0;
}

int EmployeeController::initiateViewEmployee(EmployeeUI &p_EmployeeUIobj,Bank &p_Bankobj)
{
   long int l_employeeId;
   l_employeeId=p_EmployeeUIobj.getEmployeeID();
   if(l_employeeId==2)
   {
    return 0;
   }
   if(p_Bankobj.findEmployee(l_employeeId)==0)
   {  
       p_EmployeeUIobj.displayMessage("\nEntered Employee Id doesnot exist. Please enter an existing ID to view the details\n");
       return 0;
   }
   char l_choice;
        Employee l_myEmp=p_Bankobj.viewEmployee(l_employeeId);
        p_EmployeeUIobj.displayDetails(l_myEmp);
        return 1;
   
  
}
   
int EmployeeController::initiateUpdateEmployee(EmployeeUI &p_EmployeeUIobj,Bank &p_Bankobj)
{
   long int l_employeeId;
   int l_status,l_choice;
   Employee p_myEmp;
   
   l_employeeId=p_EmployeeUIobj.getEmployeeID();
   if(l_employeeId==2)
   {
    return 0;
   }
   if(p_Bankobj.findEmployee(l_employeeId)==0)
   {
     p_EmployeeUIobj.displayMessage("\nEntered Employee Id doesnot exist. Please enter an existing ID to update the details\n");
     return 0;
   }
   l_choice=p_EmployeeUIobj.displayUpdateScreen();
   switch(l_choice)
   {
       case 1:l_status=p_Bankobj.updateEmployeeName(l_employeeId);
              if(l_status==1)
              {
                p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
                p_EmployeeUIobj.displayDetails(p_myEmp);
              }
              return l_status;
              break;
       case 2:l_status=p_Bankobj.updateEmployeeAddress(l_employeeId);
              if(l_status==1)
              {
                p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
                p_EmployeeUIobj.displayDetails(p_myEmp);
              }
              return l_status;
              break;
       case 3:l_status=p_Bankobj.updateEmployeeDesignation(l_employeeId);
              if(l_status==1)
              {
                p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
                p_EmployeeUIobj.displayDetails(p_myEmp);
              }
              return l_status;
              break;
    /*   case 4:l_status=p_Bankobj.updateEmployeeGender(l_employeeId);
              if(l_status==1)
              {
                p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
                p_EmployeeUIobj.displayDetails(p_myEmp);
              }
              return l_status;
              break;
         case 5:l_status=p_Bankobj.updateEmployeeDOB(l_employeeId);
              if(l_status==1)
              {
                p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
                p_EmployeeUIobj.displayDetails(p_myEmp);
              }
              return l_status;
              break;
*/
       case 4:cout<<"You have successfully exited\n";
              exit(0);
       
       default:cout<<"Wrong choice entered\n";
               break;
   }
   
}


int EmployeeController::initiateDeactivateEmployee(EmployeeUI &p_EmployeeUIobj,Bank &p_Bankobj)
{
   long int l_employeeId;
   string l_choice;
   Employee p_myEmp;
   
   l_employeeId=p_EmployeeUIobj.getEmployeeID();
   if(l_employeeId==2)
   {
    return 0;
   }
   if(p_Bankobj.findEmployee(l_employeeId)==0)
   {
      p_EmployeeUIobj.displayMessage("\nEntered Employee Id doesnot exist. Please enter an existing ID to deactivate\n");
      return 0;
   }
   p_myEmp=p_Bankobj.viewEmployee(l_employeeId);
   p_EmployeeUIobj.displayDetails(p_myEmp);
   p_EmployeeUIobj.displayMessage("\nPlease press Y to confirm deactivation of employee details:");
  // l_choice=p_EmployeeUIobj.confirmAction();
  cin>>l_choice;

   if(l_choice=="Y" || l_choice=="y")
   {
       int l_status=p_Bankobj.deactivateEmployee(l_employeeId);
       return l_status;
   }
   else //p_EmployeeUIobj.displayScreen();
            return 0;
}


void EmployeeController::initiateViewAllemployees(EmployeeUI &p_employeeUIObj,Bank &p_BankObj)
{
  vector<Employee> employeeList;
  employeeList = p_BankObj.ViewAllemployees();
  if(employeeList.size()!=0)
      p_employeeUIObj.display(employeeList);
  else
       p_employeeUIObj.displayMessage("\n\nRecord not Found........\n");
}









void EmployeeController::initiateViewDeactivatedEmployees(EmployeeUI &p_employeeUIObj,Bank &p_BankObj)
{
  vector<Employee> DeactivatedEmployeeList;
  DeactivatedEmployeeList = p_BankObj.ViewDeactivatedEmployees();
  if(DeactivatedEmployeeList.size()!=0)
      p_employeeUIObj.display(DeactivatedEmployeeList);
  else
       p_employeeUIObj.displayMessage("\n\nRecord not Found........\n");
}







    


