#include "../Include/ATMUI.h"
#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include"../../../AppClass/ATM/Include/ATM.h"
#include <iomanip>

long int  ATMUI::getATMID(){

  string l_ATMID;
   int l_Validstatus;
  do{
  cin.ignore();
  cout<<"\n ATM ID:";
  //cin>>l_ATMID;
  getline(cin,l_ATMID);
   l_Validstatus=Validation::ValidateNumber(l_ATMID);
  if(l_Validstatus==1)
  return Utility::convertToLong(l_ATMID);
  else
   cout<<"\n Invalid input... Enter valid input..";
 // return l_ATMID;
   }while(l_Validstatus==0);
   }
  
 string ATMUI::getATMLocation()
{
      int l_Validstatus;
        string l_ATMlocation;
          do{
            cin.ignore();
            cout<<"\n Location:";
            getline(cin,l_ATMlocation);
             // cin>>l_ATMlocation;
                 l_Validstatus=Validation::ValidateString(l_ATMlocation);
                   if(l_Validstatus==1)
                     return l_ATMlocation;
                       else
                          cout<<"\n Invalid input... Enter valid input..";
                           }while(l_Validstatus==0);
                           }
  
  double ATMUI::getATMBalance()
{
  int l_Validstatus;
  string l_ATMbalance;
  do{
      cin.ignore();
      cout<<"\n Balance:";
      getline(cin,l_ATMbalance);
//      cin>>l_ATMbalance;
      l_Validstatus=Validation::ValidateBalance1(l_ATMbalance);
      if(l_Validstatus==1)
      return Utility::convertToDouble(l_ATMbalance);
  else
      cout<<"\n Invalid input... Enter valid input..";
    }while(l_Validstatus==0);
    //return l_ATMbalance;
}
    
string ATMUI::getATMRegion(){
   int l_Validstatus;
  string l_ATMRegion;
  l1:
  cin.ignore();
  cout<<"\n Region:";
  getline(cin,l_ATMRegion);
  //cin>>l_ATMRegion;
  l_Validstatus=Validation::ValidateString(l_ATMRegion);
  if((l_Validstatus==1) && (l_ATMRegion=="west" || l_ATMRegion=="east" || l_ATMRegion=="north" || l_ATMRegion=="south"))
  return l_ATMRegion;
  else
  cout<<"\n Invalid input... Enter valid input.."; goto l1;
}

string ATMUI::getATMstatus(){
   int l_Validstatus;
  string l_ATMstatus;
  do{
  cin.ignore();
  cout<<"\n Status:";
  getline(cin,l_ATMstatus);
 // cin>>l_ATMstatus;
  l_Validstatus=Validation::ValidateString(l_ATMstatus);
  if(l_Validstatus==1)
   return l_ATMstatus;
  else
   cout<<"\n Invalid input... Enter valid input..";
 }while(l_Validstatus==0);

}

/*double ATMUI::getATMThresholdValue(){
   int l_Validstatus;
  string l_ATMThreshold;
   do{
   cout<<"\n Threshold Value:";
   cin>>l_ATMThreshold;
   l_Validstatus=Validation::ValidateThreshold(l_ATMThreshold);
    if(l_Validstatus==1)
    return Utility :: convertToDouble(l_ATMThreshold);
    else
     cout<<"\n Invalid input... Enter valid input..";
  }while(l_Validstatus==0);
}*/

int ATMUI::displayUpdateMenu(){
  int choice;
  cout<<"\n 1. Location"<<endl<<"2. Region"<<endl<<"3. Status"<<endl;
  cin>>choice;
  return choice;
}

ATM ATMUI::updateAtm()
{
int l_choice;
ATM l_atm;
int upchoice;
char lchoice;
l_atm.m_setAtmid(getATMID());
do{
system("clear");
cout<<"\nUpdate Menu\n";
cout<<"\n1. Location \n2. Region \n3. Status \n4. Exit";
cout<<"\n Enter your choice:";
cin>>l_choice;
switch(l_choice)
{
case 1:
       l_atm.m_setAtmLoc(getATMLocation());
       break;
case 2:
       l_atm.m_setAtmRegion(getATMRegion());
       break;
case 3:
       l_atm.m_setatmstatus(getATMstatus());
       break;
case 4:
       exit(0); break;
default:
       cout<<"Invalid Choice... \n";
       cout<<"Enter Again"; upchoice=1;
       break;
 }

}while(upchoice==1);
return l_atm;

                      }

char ATMUI::getChoice()
{
char cchoice;
cout<<"\n Do you wish to continue(y/n)?";
cin>>cchoice;
return cchoice;
}

int ATMUI::displayATMMenu()
{
 int choice;
 system("clear");
 cout<<" *******************************************************";
 cout<<" \n \t \t \tATM Management \n ";
 cout<<" *******************************************************";
 cout<<"\n\n1. Add ATM" <<endl<<"2. View ATM"<<endl<<"3. Update ATM"<<endl<<"4. Close ATM" <<endl<<"5. Generate Atm Report"<<endl<<"6. Exit"<< endl;
 cout<< "\n Enter your choice:";
 cin>>choice;
 return choice;
}

void ATMUI :: displayAll(long int p_atmid,string p_atmlocation,double p_atmbalance,string p_atmregion,string p_atmstatus)
{
 long int l_atmid=p_atmid;
 string l_atmlocation=p_atmlocation;
 double l_atmbalance=p_atmbalance;
 string l_atmregion=p_atmregion;
 string l_atmstatus=p_atmstatus;
 cout<<"\n ATMID\t ATMLocation\t \t \t ATMBALANCE\t \t ATMREGION\t \t ATMSTATUS \n \n";
 cout<<l_atmid<<"\t"<< l_atmlocation<<l_atmbalance <<"\t"<<l_atmregion<< l_atmstatus<<"\n";
}



void ATMUI :: displayCustNotFound()
  {
    cout<<"\n Customer ID not found...";
  }

 void ATMUI :: displayMsg()
{
   cout<<"\n ATM already Deactivated...";
}
void ATMUI :: displayUpdate()
{
  cout<<"\n Updated Successfully";
}

void ATMUI :: displayDeactivate()
{
  cout<<"\n Deactivated Successfully...\n";
}
void ATMUI :: displayRMsg()
{
   cout<<"\n Record has already been Deactivated...";
}
void ATMUI :: displayAddMsg()
 {
   cout<<"\n Details added Successfully...";
}

void ATMUI :: displayFailMsg()
{
 cout<<"Failed to add details...";
}

/*void ATMUI:: display(vector<ATM> atmList)
{
    int i=0;
    char l_Next;
    system("clear");
    vector<ATM>::iterator atmIter;
    cout<<"\n\n*********************************ATM Details**************************************** \n\n";
    cout<<"ATM_ID"<<"\t\t"<<" ATM_LOCATION"<<"      \t\t\t"<<"BALANCE"<<"\t\t\t"<<"REGION"<<"\t\t\t\t"<<"THRESHOLD_VALUE"<<"\t\t\t\t"<<"STATUS"<<endl;
    cout<<"\n_______________________________________________________________________________________________________________________________________________________\n";
    for (atmIter = atmList.begin(); atmIter != atmList.end(); atmIter++)
    {
       cout<<(*atmIter).m_getAtmid()<<" \t\t"<<(*atmIter).m_getAtmLoc()<<(*atmIter).m_getAtmBalance()<<"\t\t "<<(*atmIter).m_getAtmRegion()<<""<<(*atmIter).m_getAtmThresholdValue()<<"   \t\t\t\t"<<(*atmIter).m_getatmstatus()<<endl;
       i++;
	 
	 cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
         if(i%10==0)
	 {
		cout<<"Enter 'n' for next page or any other key to go back: "<<endl;
		cin>>l_Next;
		if(l_Next=='n'||l_Next=='N')
		{
			system("clear");
			//displayHeader();
   			cout<<"ATM_ID"<<"\t\t"<<" ATM_LOCATION"<<"      \t\t"<<"BALANCE"<<"\t\t\t"<<"REGION"<<"\t\t\t\t"<<"THRESHOLD_VALUE"<<"\t\t\t\t"<<"STATUS"<<endl;
  			cout<<"\n________________________________________________________________________________________________________________________________________________\n";
			continue;
		}	
		else
		break;
   	 }
    }
        //displayMessage("\nPress enter to exit :");
        //cin.ignore().get();
       // system("clear");
}

*/


void ATMUI:: display(vector<ATM> atmList)
{
   int b=0;
   int count=0,page=0;
   string stopper;

   cout<<"\n\n";

    vector<ATM>::iterator atmIter;
     
    cout<<left<<setw(14)<<setfill(' ')<<"ATM ID";
    cout<<left<<setw(25)<<setfill(' ')<<"Location";    
    cout<<left<<setw(28)<<setfill(' ')<<"Balance(in Rupees)";    
    cout<<left<<setw(25)<<setfill(' ')<<"Region";
    cout<<left<<setw(31)<<setfill(' ')<<"Threshold Value(in Rupees)";    
    cout<<left<<setw(20)<<setfill(' ')<<"Status";    
        
    
    cout<<"\n"; 
   
    for(int x=0;x<=150;x++)
   {
       cout<<"_";
   }
        cout<<"\n";
    for (atmIter = atmList.begin(); atmIter != atmList.end(); atmIter++)
    
    {
       cout<<left<<setw(14)<<setfill(' ')<<(*atmIter).m_getAtmid();
       cout<<left<<setw(2)<<setfill(' ')<<(*atmIter).m_getAtmLoc();
       cout<<left<<setw(17)<<setfill(' ')<<(*atmIter).m_getAtmBalance(); 
       cout<<left<<setw(10)<<setfill(' ')<<(*atmIter).m_getAtmRegion();
       cout<<left<<setw(16)<<setfill(' ')<<(*atmIter).m_getAtmThresholdValue();
       cout<<left<<setw(14)<<setfill(' ')<<(*atmIter).m_getatmstatus();
     
      
       cout<<"\n";
 
       for(int y=0;y<=150;y++)
   {
       cout<<"_";
   }
        cout<<"\n";


   b++;
   if(b%7==0)
  {  
    page++; 
    count=page;
    cout<<"\n"; 
    cout<<"\t\t";
    cout<<left<<setw(7)<<setfill(' ')<<"Page Number :"<<page;
    cout<<"\t\t\t\t";
    cout<<left<<setw(7)<<setfill(' ')<<"Enter a key to view next page:" ;
    cin>>stopper; 
    cout<<"\n";  
    system("clear");
    cout<<"\n\n";
    cout<<left<<setw(14)<<setfill(' ')<<"ATM ID";
    cout<<left<<setw(25)<<setfill(' ')<<"Location";    
    cout<<left<<setw(28)<<setfill(' ')<<"Balance(in Rupees)";    
    cout<<left<<setw(25)<<setfill(' ')<<"Region";
    cout<<left<<setw(31)<<setfill(' ')<<"Threshold Value(in Rupees)";    
    cout<<left<<setw(20)<<setfill(' ')<<"Status";    
            
           
        
    
    cout<<"\n"; 
   
    for(int x=0;x<=150;x++)
   {
       cout<<"_";
   }
        cout<<"\n";

   continue;

   } 
} 
        count++;
        cout<<"\n";
        cout<<left<<setw(7)<<setfill(' ')<<"Page Number :"<<count;
        cout<<"\n\n\t\t\t\tPress Enter To Exit :";
        cin.ignore().get();
        system("clear");
}

