#include "../Include/Validation.h"
#include <iostream>
using namespace std;
#define DATE (Utility::convertToInt(p_Input.substr(0,2)))
#define MONTH (Utility::convertToInt(p_Input.substr(3,2)))
#define YEAR (Utility::convertToInt(p_Input.substr(6,4)))

int Validation :: ValidateNumber(string p_InputNumber)
{
        

      if(p_InputNumber.length()!=6)
       {return 0;}

      for (int i=0; i < p_InputNumber.length(); i++)
      { 
         if (!(isdigit(p_InputNumber[i])) && isspace(p_InputNumber[i]))
         {  
             return 0;
        }    
      }
     return 1;

}

int Validation :: ValidateString(string p_InputString)
{
 if (p_InputString.length() >0 && p_InputString.length() <= 30)
   {
      for (int i=0; i < p_InputString.length(); i++)
         if (!isalpha(p_InputString[i]) && !isspace(p_InputString[i]))
          {
            return 0;
          }
    return 1;
   }
   else
      return 0;

}


int Validation :: ValidateBalance(string p_InputNumber)
{
       for (int i=0; i < p_InputNumber.length(); i++)
       {
          if (!(isdigit(p_InputNumber[i])) && isspace(p_InputNumber[i]))
         {
            return 0;
         } 
      }
      if((p_InputNumber.length()>=0) && (p_InputNumber.length()<=14))
        {
           return 1;
        }
         else
         return 0;
      }


int Validation :: ValidateYear(string p_InputNumber)
{
   
  if(p_InputNumber.length()==1)
  {
   for(int i=0;i<p_InputNumber.length();i++)
   {
   // if(p_InputNumber[i]==1 || p_InputNumber[i]==3 || p_InputNumber[i]==5)
      
     if((atoi(p_InputNumber.c_str())==1) || (atoi(p_InputNumber.c_str())==3) || (atoi(p_InputNumber.c_str())==5))
     return 1;
   else 
     return 0;
  }
 }else 
   return 0;
}



int Validation :: ValidateNonSalBalance(string p_InputNumber)
{
   for (int i=0; i < p_InputNumber.length(); i++)
     { if (!(isdigit(p_InputNumber[i])))

         {
          return 0;
         }      
     }
     string amt1="5000";
             
       //if((strcmp(p_InputNumber,amt1)==0) || (strcmp(p_InputNumber,"10000")==0))
        
    if((atoi(p_InputNumber.c_str())>=5000) || (atoi(p_InputNumber.c_str()) >= 10000))
        return 1;
       else
        return 0;
}

int Validation :: ValidateDepositAmount(string p_InputNumber)
{
   for (int i=0; i < p_InputNumber.length(); i++)
     { 
      if (!(isdigit(p_InputNumber[i])))

         {
          return 0;
         }
     }

    if(atoi(p_InputNumber.c_str())>=10000)
      return 1;
     else
       return 0;
}

int Validation::validateDouble(string p_d)
{
    int i;
   if(p_d.length()==1 && !isdigit(p_d[0]))
   {
        cout<<"\nPlease enter atleast one number.\n";
        return 0;
    }
   else if(p_d.length()>12)
       {
          cout<<"\nPlease enter a price with a maximum of 8 digits and 2 decimal values.\n";
           return 0;
       }
      else
         {
             for(i=0;i<8&&p_d[i]!='\0';i++)
             {
                if(p_d[i]=='.')
                {
                       break;
                }
                else if(i==p_d.length())
                          return 1;
                      else if(!isdigit(p_d[i]))
                            {
                                  cout<<"\nPlease enter only numbers.\n";
                                  return 0;
                              }

              }                
              if(i<p_d.length())
              {
                    ++i;
                    for(i;i<=i+2&&p_d[i]!='\0';i++)
                     {
                           if(!isdigit(p_d[i]))
                           {
                               cout<<"\nPlease enter only numbers.\n";
                               return 0;
                            }
                            else if(p_d[i]=='.')
                                 {
                                            cout<<"\nEnter a value with only one decimal point('.').\n";
                                            return 0;
                                 }
                     }
              }
           }
    if(i!=p_d.length())
    {
            cout<<"\nPlease enter a price with a maximum of 8 digits and 2 decimal values.\n";
            return 0;
    }
    else
        return 1;

}

int Validation :: ValidateBalance1(string p_InputNumber)
{
       for (int i=0; i < p_InputNumber.length(); i++)
     { if (!(isdigit(p_InputNumber[i])))

         {

             return 0;
        }       }

           if((p_InputNumber.length()>=6) && (p_InputNumber.length()<=14))
            {
                  return 1;
             }
         else
         return 0;
      }




int Validation::validateLong(string p_Long)
{
int l_length=p_Long.length();
    if((l_length<1) || (l_length>=7))
    {
        return 0;
    }
    if (p_Long.find_first_not_of("0123456789") != string::npos)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Validation :: validateString(string p_InputString)
{
   
 if (p_InputString.length() >=0 && p_InputString.length() <= 30)
   {
      for (int i=0; i < p_InputString.length(); i++)
         if (!isalpha(p_InputString[i]) && !isspace(p_InputString[i]))
          {
            return 0;
          }
    return 1;
   }
   else
      return 0;

}

bool Validation :: validateNumber(string p_Input)
{
   for (int i=0; i < p_Input.length(); i++)
      if (!isdigit(p_Input[i]) || isspace(p_Input[i]))
      return false;
      return true;
}

bool Validation :: validateSize(string p_Input,int p_MaxSize)
{
   if (p_Input.length() > p_MaxSize)
   return false;
   else
   return true;
}

bool Validation :: validateSize1(string p_Input,int p_MaxSize)
{
   if (p_Input.length() != p_MaxSize)
   return false;
   else
   return true;
}



int Validation :: validateName(string p_InputString)
{
 if (p_InputString.length() >=0 && p_InputString.length() <= 30)
{
 for (int i=0; i < p_InputString.length(); i++)
if (!isalpha(p_InputString[i])&& !isspace(p_InputString[i]))
{
cout<<"\nPlease enter only alphabets(For example: Sam,Jack..)";
return 0;
 }
 return 1;
 }
else
 return 0;
}

bool Validation :: validateDate(string p_Input)
{
   string dateTemplate= "##-##-####";
   if (p_Input.length()==dateTemplate.length())
   {
      for (int i=0; i < p_Input.length(); i++)
      {
         switch (dateTemplate[i])
         {
            case '#':
               if (!isdigit(p_Input[i]))
                  return false;
               break;
            default:
               if (p_Input[i] != dateTemplate[i])
                  return false;
               break;
         }
      }



   if ((MONTH>0 && MONTH<13) && (DATE>0 && DATE<=31))
   {
      switch(MONTH)
         {
            case 4:
            case 6:
            case 9:
            case 11:
               if (DATE<=30)
                  return true;
               else
                  return false;
               break;
            case 2:
               if (YEAR%400==0 || (YEAR%100!=0 && YEAR%4==0))
               {
                  if (DATE<=29)
                     return true;
                  else
                     return false;
               }
               else
               {
                  if(DATE<=28)
                    return true;
                  else 
                    return false;
               }
               break;
            default:
               if (DATE<=31)
                  return true;
               else
                  return false;
               break;
         }
      }
      else
      {
         return false;
      }
   }
   else
      return false;
  
 

    
}

bool Validation::validateGender(string p_Input)
{
      if(p_Input=="m" || p_Input=="M" || p_Input=="f" || p_Input=="F" || p_Input=="NA" || p_Input=="na")
           return true;
          return false; 
}


bool Validation :: validateString1(string p_Input)
{

   for (int i=0; i < p_Input.length(); i++)
      if (!isalpha(p_Input[i]) && !isspace(p_Input[i]))
      return false;
      return true;

}

int Validation :: validateNumber1(string p_InputNumber)
{
        

      if(p_InputNumber.length()!=6)
       {return 0;}

      for (int i=0; i < p_InputNumber.length(); i++)
     { if (!(isdigit(p_InputNumber[i])) && isspace(p_InputNumber[i]))

         {  

             return 0;
        }       }

     return 1;

}
int Validation :: validateChoice(string p_InputNumber)
{



      for (int i=0; i < p_InputNumber.length(); i++)
     { if (!(isdigit(p_InputNumber[i]))&& isspace(p_InputNumber[i]))


         {

             return 0;
        }       }

     return 1;

}

int Validation :: validateChoice1(string p_InputAction)
{
     for (int i=0; i < p_InputAction.length(); i++)
     {
         if (!(isalpha(p_InputAction[i])) && isspace(p_InputAction[i]))
            return 0;
     }
     return 1;
}

