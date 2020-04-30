#ifndef _LOGIN_H_
#define _LOGIN_H_
#include<string>
using namespace std;
class Login
{ 
  public:
    long int m_username;
    string m_password;
    string m_seqans1;
    string m_seqans2;
    string m_newpassword;
    string m_confirmpassword;
    Login();
     Login(long int,string);
    Login(long int,string,string,string);
   ~Login();
    void setUsername(long int);
    void setPassword(string);
    void setSeqans1(string);
    void setSeqans2(string);
    void setNewpassword(string);
    void setConfirmpassword(string);
    long int getUsername();
    string getPassword();
    string getSeqans1();
    string getSeqans2();
    string getNewpassword();
    string getConfirmpassword();
};
#endif


