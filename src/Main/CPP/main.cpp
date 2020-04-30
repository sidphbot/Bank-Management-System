#include<iostream>
#include<string>
#include"../../Model/Include/Model.h"
#include"../../UI/loginUI/include/loginUI.h"
#include"../../UI/mainUI/include/mainUI.h"
#include <csignal>
using namespace std;
void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   exit(signum);  
}

int main()
{

signal(SIGINT, signalHandler);
Bank l_myBank;

l_myBank.dbConnect();
LoginUI l_lUI;
l_lUI.setTemplate();

l_myBank.disconnect();
return 0;
}
