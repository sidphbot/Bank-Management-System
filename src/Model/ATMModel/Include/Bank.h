#ifndef _BANK_H_
#define _BANK_H_
#include "../../../AppClass/ATM/Include/ATM.h"
#include<iostream>
#include<string.h>
/*#include</usr/include/oracle/11.2/client64/sqlca.h>*/
using namespace std;
class Bank
{
   public:
    int addATMAccount(ATM &);
    int dbviewATM(long int);
    int dbcloseATM(long int);
    int findAtmId(long int);
    void dbConnect();
    void disconnect();
};

#endif
