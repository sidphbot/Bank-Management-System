#include<iostream>
#include<stdlib.h>
#include"../include/loginUI.h"
#include"../../../Controller/loginController/include/loginController.h"
#include<string>
#include<unistd.h>		//for getpass
#include "../../../Validation/Include/Validation.h"
#include "../../../Utility/Include/Utility.h"
#include<ctime>
using namespace std;
LoginUI :: LoginUI()
{
	logincount=1;
	now = time(NULL);
}

long int LoginUI::getUsername()
{
	string l_username;
do{
	cout<<"\nUser name:";
	cin>>l_username;
        if(l_username=="exit")
        return 2;
	//int l_ValidStatus = Validation :: validateNumber1(l_username);
  	int l_ValidStatus = 1;
	if(l_ValidStatus == 1)
	return Utility::convertToLong(l_username);
}while(1);
}


string LoginUI::getPassword()
{
	string  l_password;
	l_password = getpass("Password:");
	bool l_ValidStatus = Validation :: validateString1(l_password);
	if(l_ValidStatus == true)
	   return l_password;
}

string LoginUI::getSeqans1()
{
	string l_seqans1;
do{
	cout<<"\nWhat is the name of your hometown:";
	cin>>l_seqans1;
	int l_ValidStatus = Validation :: validateString1(l_seqans1);
  	if(l_ValidStatus == 1)
	return l_seqans1;
}while(1);
}

string LoginUI::getSeqans2()
{
	string l_seqans2;
do{
	cout<<"\nWhat is your mother's maiden name:";
	cin>>l_seqans2;
	int l_ValidStatus = Validation :: validateString1(l_seqans2);
  	if(l_ValidStatus == 1)
	return l_seqans2;
}while(1);
}
string LoginUI::getNewpassword()
{
	string l_newpassword;

	cout<<"\nEnter a new password";
	cin>>l_newpassword;
        int l_ValidStatus = Validation :: validateString1(l_newpassword);
  	if(l_ValidStatus == true)
	return l_newpassword;
}

string LoginUI::getConfirmpassword()
{
	string l_confirmpassword;
	l_confirmpassword = getpass("\nConfirm Password:  ");
	//bool l_ValidStatus = Validation :: validateName(l_username);
  	//if(l_ValidStatus == true)
	return l_confirmpassword;

}


void LoginUI::setTemplate(void)
{
	  int choice, l_status, k;
          string l_choice;
	  Logincontroller lc;	
	  time_t now = time(0);
          char* dt = ctime(&now);
          system("clear");
          cout<<"\n\n\t\t---------------------------------- Welcome To Sahara Bank -------------------------------------------\n\n";
          cout<<"\t\t\t\t\t\t  "<<dt<<endl; 
          cout<<"\n\n\t\t   ------------------------------------------Login Menu--------------------------------------------\n\n";
          cout<<"\n\t\t\t1.Login\n\n\t\t\t2.ForgotPassword\n\n\t\t\t3.Change Password\n\n\t\t\t4.Exit";
         
	  do{
          k=0;
          cout<<"\t\t\t\nenter your choice: ";
          cin>>l_choice;
          int l_ValidStatus = Validation :: validateChoice(l_choice);
          if(l_ValidStatus == 0)
          {cout<<"\ninvalid choice.. please enter a numeric value\n";
           k=1;}
          cout<<"\n";
          }while(k);
          choice= Utility::convertToInt(l_choice);


	 
          switch(choice)
          {
          case 1:
		
                 l_status=lc.InitiateLogin();
                 if(!l_status)
		{
			time_t next=time(NULL);
			double seconds=difftime(next,now);
		 	logincount++;
			//cout<<"\nseconds"<<seconds;
			//sleep(1);
		 	if(logincount<4 || seconds>=60 )
			{
			//cout<<logincount<<" logincount"<<endl;
			//sleep(2);	
                 	setTemplate();
			}
		
			else
			{
			cout<<"You have entered wrong credentials three times. Please try again after some time";
			cout<<"\n\t\tThank you";
			sleep(1);
			setTemplate();
			}
		}
                 break;
          
	  case 2:
		lc.ForgotPassword();
		break;
	  case 3:
		 system("clear");
		 lc.ChangePassword();
		 break;
	  case 4:
	         cout<<"\n\t\tThank you.Visit Again\n";
                 exit(0);
    	  default:
	  	cout<<"\n\t\t\tInvalID choice.Please try again\n";
		setTemplate();
	  }
}


void LoginUI::displayString(string p_string)
{
	cout<<p_string<<endl;
}


char LoginUI::displayContinue()
{	
	char l_choice;
	cout<<"\n\t\t\tDo you want to continue?\n\t\t\tPress y to continue or n for previous menu or any other key for exit:";
	cin>>l_choice;
	return l_choice;
}
