
#include "../Include/BranchAccountUI.h"
#include "../../../Validation/Include/Validation.h"
long int  BranchAccountUI::getBranchAccountNo()
{
   int l_Validstatus;
   string l_branchAccountNo;
   do
   {
      //Validation l_temp;
      cin.ignore();
      cout<<"\n Account No:";
      getline(cin,l_branchAccountNo);
     //cin>>l_branchAccountNo;
     //return l_branchAccountNAccountNoa
     if(l_branchAccountNo=="exit")
    {
     return 2;
    }
      int l_Validstatus=Validation::validateLong(l_branchAccountNo);
      if(l_Validstatus==1)
      {  
         //Utility l_tempU;
         return Utility::convertToLong(l_branchAccountNo);
      }
      else
      {
      char l_choice;
      cout<<"Invalid Input. ";/*Do you want to try again [y/n]? ";
      cin>>l_choice;
      if(l_choice=='n'||l_choice=='N')
        return -1;*/
      }
   }while(!l_Validstatus);
}


long int BranchAccountUI::getBranchID()
{
   int l_Validstatus;
   string l_branchID;
   do
   {  
      //Validation l_temp;
      cin.ignore();
      cout<<"\n Branch ID:";
      //cin>>l_branchID;
      // return l_branchID;
      getline(cin,l_branchID);
 if(l_branchID=="exit")
 {
     return 2;
    }

      int l_Validstatus=Validation::validateLong(l_branchID);
      if(l_Validstatus==1)
      {
        // Utility l_tempU;
         return Utility::convertToLong(l_branchID);
      }
      else
      {
      char l_choice;
      cout<<"Invalid Input.";
     /* Do you want to try again [y/n]? ";
      cin>>l_choice;
      if(l_choice=='n'||l_choice=='N')
        return -1;*/
      }
   }while(!l_Validstatus);
}

double BranchAccountUI::getBranchThreshold()

{
   int l_Validstatus;
   string l_branchThreshold;
   do
   {
      //Validation l_temp;
      cin.ignore();
      cout<<"\n Minimum Balance (Rs.):";
      //cin>>l_branchThreshold;
      //return l_branchThreshold;
      getline(cin,l_branchThreshold);
 if(l_branchThreshold=="exit")
{
     return 2;
    }

      l_Validstatus=Validation::validateDouble(l_branchThreshold);
      if(l_Validstatus==1)
      {
         //Utility l_tempU;
         return Utility::convertToDouble(l_branchThreshold);
      }
      else
      {
      char l_choice;
      cout<<"Invalid Input.";/* Do you want to try again [y/n]? ";
      cin>>l_choice;
      if(l_choice=='n'||l_choice=='N')
        return -1;*/
      }
   }while(!l_Validstatus);
}

double BranchAccountUI::getCurrentBalance()

{
   int l_Validstatus;
   string l_currentBalance;
   do
   {
      //Validation l_temp;
      cin.ignore();
      cout<<"\n Initial Balance (Rs.):";
      //cin>>l_currentBalance;
      //return l_currentBalance;
      getline(cin,l_currentBalance);
 if(l_currentBalance=="exit")
{
     return 2;
    }

      int l_Validstatus=Validation::validateDouble(l_currentBalance);
      if(l_Validstatus==1)
      {
         //Utility l_tempU;
         return Utility::convertToDouble(l_currentBalance);
      }
      else
      {
      char l_choice;
      cout<<"Invalid Input.";/* Do you want to try again [y/n]? ";
      cin>>l_choice;
      if(l_choice=='n'||l_choice=='N')
        return -1;*/
      }
   }while(!l_Validstatus);
}

void BranchAccountUI::displayAccountNo(long int p_accountNumber)
{

cout<<"\nBranchAccount has been created successfully.\nThe Account Number of the branch account is "<<p_accountNumber;

}



void BranchAccountUI::display(BranchAccount &p_BranchAccount)
{
cout<<"\nThe branch account details are:\nAccount number : "<<p_BranchAccount.getBranchAccountNo();
cout<<"\nBranch ID : "<<p_BranchAccount.getBranchID();
cout<<"\nMinimum Balance (Rs.): "<<p_BranchAccount.getBranchThreshold();
cout<<"\nInitial balance (Rs.): "<<p_BranchAccount.getCurrentBalance();
}


int BranchAccountUI::displayUpdateOptions()
{
   int l_choice;
   cout<<"\nThe data that you can update are : \n1.Branch ID\n2.Branch account threshold\n3.Current balance.\nEnter the choice that u want to update : ";
   cin>>l_choice;
   cin.ignore();
   return l_choice;
}

long int BranchAccountUI::getNewBranchId(BranchAccount &p_BranchAccount)
{
   int l_Validstatus;
   string l_branchID;
   //cout<<"\nThe current branch ID is : "<<p_BranchAccount.getBranchID();
   do
   {
      //Validation l_temp;
      cout<<"\nEnter the new branch ID : ";
      //cin>>l_branchID;
      //return l_branchID;
      getline(cin,l_branchID);
 if(l_branchID=="exit")
{
     return 2;
    }

      int l_Validstatus=Validation::validateLong(l_branchID);
        if(l_Validstatus==1)
        {
           //Utility l_tempU;
           return Utility::convertToLong(l_branchID);
        }
        else
        {
        char l_choice;
        cout<<"Invalid Input.";
        /*cout<<"Do you want to try again [y/n]? ";
        cin>>l_choice;
        if(l_choice=='n'||l_choice=='N')
          return -1;*/
        }
   }while(!l_Validstatus);
}
      
double BranchAccountUI::getNewBranchThreshold(BranchAccount &p_BranchAccount)

{
   int l_Validstatus;
   string l_branchThreshold;
   //cout<<"\nThe current branch account threshold value is : "<<p_BranchAccount.getBranchThreshold();
   do
   {
      //Validation l_temp;
      cout<<"\nEnter the new branch minimum balance (Rs.): ";
      //cin>>l_branchThreshold;
      //return l_branchThreshold;
      getline(cin,l_branchThreshold);
 if(l_branchThreshold=="exit")
{
     return 2;
    }

      l_Validstatus=Validation::validateDouble(l_branchThreshold);
      if(l_Validstatus==1)
      {
         //Utility l_tempU;
         return Utility::convertToDouble(l_branchThreshold);
      }
      else
      {
         char l_choice;
         cout<<"Invalid Input.";/* Do you want to try again [y/n]? ";
         cin>>l_choice;
         if(l_choice=='n'||l_choice=='N')
            return -1;*/
      }
   }while(!l_Validstatus);
}
                 
double BranchAccountUI::getNewCurrentBalance(BranchAccount &p_BranchAccount)

{
   int l_Validstatus;
   string l_currentBalance;
   //cout<<"\nThe current balance of the branch account is : "<<p_BranchAccount.getCurrentBalance();
   do
   {
      //Validation l_temp;
      cout<<"\nEnter the new Initial Balance (Rs.): ";
      //cin>>l_currentBalance;
      //return l_currentBalance;
      getline(cin,l_currentBalance);
 if(l_currentBalance=="exit")
{
     return 2;
    }

      int l_Validstatus=Validation::validateDouble(l_currentBalance);
      if(l_Validstatus==1)
      {
         //Utility l_tempU;
         return Utility::convertToDouble(l_currentBalance);
      }
      else
      {
         char l_choice;
         cout<<"Invalid Input.";/* Do you want to try again [y/n]? ";
         cin>>l_choice;
         if(l_choice=='n'||l_choice=='N')
            return -1;*/
      }
   }while(!l_Validstatus);
}
 void BranchAccountUI ::  display(vector<BranchAccount> AccountList)

{
   //system("clear");
   int i=0;
   char l_Next;
   vector<BranchAccount>::iterator ViewList;
   cout<<"\n\t\t\tBranchAccountNo"<<"\t\t"<<"BranchID"<<"\t\t"<<"BranchThreshold"<<"\t\t"<<"CurrentBalance"<<"\t\t"<<"status"<<"\t\t"<<endl;
    cout<<"\n\t\t\t_________________________________________________________________________________________________________\n";
    for (ViewList = AccountList.begin(); ViewList != AccountList.end(); ViewList++)    
    {
      cout<<"\t\t\t"<<(*ViewList).getBranchAccountNo()<<"\t\t\t"<<(*ViewList).getBranchID()<<"\t\t\t"<<(*ViewList).getBranchThreshold()<<"\t\t\t"<<(*ViewList).getCurrentBalance()<<"\t\t\t"<<(*ViewList).getStatus()<<"\t\t\t"<<endl;
      cout<<"\t\t\t----------------------------------------------------------------------------------------------------------\n";
	i++;
	 
      //cout<<"\t\t\t-------------------------------------------------------------------------------------------------------------\n";
         if(i%10==0)
	 {
		cout<<"Enter 'n' for next page or any other key to go back: "<<endl;
		cin>>l_Next;
		if(l_Next=='n'||l_Next=='N')
		{
			system("clear");
			//displayHeader();
   			cout<<"\n\t\t\tBranchAccountNo"<<"\t\t"<<"BranchID"<<"\t\t"<<"BranchThreshold"<<"\t\t"<<"CurrentBalance"<<"\t\t"<<"status"<<"\t\t"<<endl;
                        cout<<"\n\t\t\t_________________________________________________________________________________________________________\n";
			continue;
		}	
		else
		break;
   	 }
    }
}




