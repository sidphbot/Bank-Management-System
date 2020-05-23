#ifndef _LOGINUI_H_
#define _LOGINUI_H_
#include<string>
#include<ctime>
//#include"../../../bank/include/bank.h"
using namespace std;
class LoginUI
{


public:
long int getUsername();
string getPassword();
string getSeqans1();
string getSeqans2();
string getNewpassword();
string getConfirmpassword();
char displayContinue();
void setTemplate();
void displayString(string);
int logincount;
LoginUI();
time_t now;

};
#endif
