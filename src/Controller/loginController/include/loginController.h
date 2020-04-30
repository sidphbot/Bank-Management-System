#ifndef _LOGINCONTROLLER_H_
#define _LOGINCONTROLLER_H_
//#include "../../../UI/Login/include/loginui.h"
//#include "../../../MODEL/include/model.h"

#include<string>
class Logincontroller
{
	public:
	int InitiateLogin();
	void ForgotPassword();
	void ChangePassword();
	void initiateChangeContinue(char);
	void initiateLoginContinue(char);
};
#endif
