#include "../Include/Utility.h"

long Utility::convertToLong (string p_Long)
{
   return atol(p_Long.c_str());
}

double Utility::convertToDouble(string p_Double)
{
   return atof(p_Double.c_str());

}

int Utility::convertToInt(string p_istring)
{
   return (atoi(p_istring.c_str()));
}

long int Utility::convertToLongInt(string p_istring)
{
   return (atol(p_istring.c_str()));
}

char Utility::convertToChar(string p_Input)
{
   char l_chk;
   l_chk=p_Input[0];
   return l_chk;
}

float Utility::convertToFloat(string l_price)
{
string s;
s=l_price;
float d;
d=atof(s.c_str());
return d;
}
