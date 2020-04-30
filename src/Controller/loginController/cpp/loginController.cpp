#include"../include/loginController.h"
#include"../../../UI/loginUI/include/loginUI.h"
#include<string>
#include<iostream>
#include<ctime>
#include"../../../Model/Include/Model.h"
#include"../../../UI/mainUI/include/mainUI.h"
#include<unistd.h>
#include<string>
using namespace std;


int Logincontroller::InitiateLogin()
{	
	LoginUI p_LoginUIObj;
	Bank p_ModelObj;
	long int l_Username;
        string l_Password;
        
	
	l_Username=p_LoginUIObj.getUsername();
        if(l_Username==2)
         return 0;
	l_Password=p_LoginUIObj.getPassword();
         if(l_Password=="exit")
         return 0;
	
	Login l_LoginObj(l_Username,l_Password);

	int l_InsertStatus=p_ModelObj.checklogin(l_LoginObj);
	if(l_InsertStatus==1)
	{
		cout<<"Login success"<<endl;
		sleep(1);
		MainUI l_mainUI;
		l_mainUI.mainMenu();
	/*
	if(l_Username=="superuser")
           {
		cout<<"Administrator logged in!!";
            	
           }
	else
	   {
		
			
	   }
        */
        return 1;
	}
	else
	{
	cout<<"Unable to connect"<<endl;
	cout<<"Invalid username or password"<<endl;
	sleep(1);
        return 0;
	}
	
}
void Logincontroller::ForgotPassword()
{
	LoginUI p_LoginUIObj;
	Bank p_ModelObj;
	long int l_Username;
	string l_Seqans1;
	string l_Seqans2;
	string l_Newpassword;	
        int l_loginstatus;
	l_Username=p_LoginUIObj.getUsername();
	l_Seqans1=p_LoginUIObj.getSeqans1();	
	l_Seqans2=p_LoginUIObj.getSeqans2();
	l_Newpassword=p_LoginUIObj.getNewpassword();
	
	Login l_LoginObj(l_Username,l_Seqans1,l_Seqans2,l_Newpassword);

	
	int l_InsertStatus=p_ModelObj.changepassword(l_LoginObj);
	if(l_InsertStatus==1)
	{
	   cout<<"\nPassword changed successfully"<<endl;
	   do{   cout<<"Enter the login credentials\n";
                 l_loginstatus=InitiateLogin();
             }while(!l_loginstatus);
	}
	else
	{
	cout<<"\nInvalid username or security answer"<<endl;
	   //do{l_loginstatus=InitiateLogin();}while(!l_loginstatus);
	   ForgotPassword();
	}
}


void Logincontroller::ChangePassword()
{
	LoginUI p_LoginUIObj;
	Bank p_ModelObj;
	Login l_LoginObj;
	long int l_Username;
	string l_Newpassword;
	char l_choice;	

	l_LoginObj.setUsername(p_LoginUIObj.getUsername());
	l_LoginObj.setPassword(p_LoginUIObj.getPassword());	
	l_LoginObj.setNewpassword(p_LoginUIObj.getNewpassword());
	l_LoginObj.setConfirmpassword(p_LoginUIObj.getConfirmpassword());

	if(l_LoginObj.getNewpassword()==l_LoginObj.getConfirmpassword())
	{
		int l_InsertStatus=p_ModelObj.changepassword2(l_LoginObj);
		if(l_InsertStatus==0)
		{
	   		p_LoginUIObj.displayString("\n\t\t\tPassword changed successfully");
	   		l_choice=p_LoginUIObj.displayContinue();
			initiateLoginContinue(l_choice);
		}
		else
		{
			p_LoginUIObj.displayString("\n\t\t\tInvalid username or password");
			l_choice=p_LoginUIObj.displayContinue();
			initiateChangeContinue(l_choice);
		}
	}
	else
	{
		p_LoginUIObj.displayString("\n\t\t\tNew Password and Confirm Password do not match!!");
		l_choice=p_LoginUIObj.displayContinue();
        	initiateChangeContinue(l_choice);
	}
}


void Logincontroller::initiateChangeContinue(char p_choice)
{
	LoginUI p_LoginUIObj;
	if((p_choice=='y')||(p_choice=='Y'))
			{
				cin.clear();
				ChangePassword();
			}
			else if((p_choice=='n')||(p_choice=='N'))
			{	
				cin.clear();
				p_LoginUIObj.setTemplate();
			}
			else
			{
				
				for(int i=5;i>=0;i--)
				{
					cout<<"\t\t\tThe application will exit in: " <<i<<"s  ";
					cout << '\r';
					cout.flush();
					sleep(1);
				}
				cin.clear();
				system("clear");
				exit(0);
			}
}
void Logincontroller::initiateLoginContinue(char p_choice)
{
	LoginUI p_LoginUIObj;
	if((p_choice=='y')||(p_choice=='Y'))
			{
				cin.clear();
				InitiateLogin();
			}
			else if((p_choice=='n')||(p_choice=='N'))
			{	
				cin.clear();
				p_LoginUIObj.setTemplate();
			}
			else
			{
				for(int i=5;i>=0;i--)
				{
					cout<<"\t\t\tThe application will exit in: " <<i<<"s  ";
					cout << '\r';
					cout.flush();
					sleep(1);
				}
				cin.clear();
				system("clear");
				exit(0);
			}
}
