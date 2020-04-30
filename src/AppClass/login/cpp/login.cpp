#include "../include/login.h"
Login :: Login ()
{
   m_username =0;
   m_password ="";
   m_seqans1="";
   m_seqans2="";
   m_newpassword="";
   m_confirmpassword="";
}
Login :: Login (long int p_name,string p_seqans1,string p_seqans2,string p_newpassword)
{
   m_username=p_name;
   m_seqans1=p_seqans1;
   m_seqans2=p_seqans2;
   m_newpassword=p_newpassword;  
  
}
Login :: Login (long int p_name,string p_password)
{
   m_username=p_name;
   m_password=p_password;
   
}
Login :: ~Login()
{
 
}

void Login :: setUsername(long int p_name) { m_username=p_name; }
void Login :: setPassword(string p_password) { m_password= p_password; }
void Login :: setSeqans1(string p_seqans1) { m_seqans1=p_seqans1; }
void Login :: setSeqans2(string p_seqans2) { m_seqans2=p_seqans2; }
void Login :: setNewpassword(string p_newpassword) { m_newpassword=p_newpassword; }
void Login :: setConfirmpassword(string p_confirmpassword) { m_confirmpassword=p_confirmpassword; }

long int Login :: getUsername() { return m_username; }
string Login :: getPassword() { return m_password; }
string Login :: getSeqans1() { return m_seqans1; }
string Login :: getSeqans2() { return m_seqans2; }
string Login :: getNewpassword() { return m_newpassword; }
string Login :: getConfirmpassword() { return m_confirmpassword; }
