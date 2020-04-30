CC=g++
CFLAGS=-c -Wno-deprecated

all:Build/Management
Build/Management:Build/Account.o Build/Customer.o Build/ATM.o Build/BranchAccount.o Build/branch.o Build/login.o Build/employee.o Build/CustomerUI.o Build/AccountUI.o Build/BranchAccountUI.o Build/ATMUI.o Build/branchUI.o Build/loginUI.o Build/employeeUI.o Build/mainUI.o Build/Model.o Build/BranchAccountController.o Build/branchController.o Build/loginController.o  Build/ATMController.o Build/employeeController.o Build/AccountController.o Build/CustomerController.o Build/Validation.o Build/Utility.o  Build/main.o 
	$(CC) Build/*.o -o Build/Management -L /opt/oracle/clinet64/instantclient_19_5 -lclntsh

Build/Account.o:AppClass/CustomerAcc/CPP/Account.cpp
	$(CC) $(CFLAGS) AppClass/CustomerAcc/CPP/Account.cpp -o Build/Account.o

Build/Customer.o:AppClass/CustomerAcc/CPP/Customer.cpp
	$(CC) $(CFLAGS) AppClass/CustomerAcc/CPP/Customer.cpp -o Build/Customer.o

Build/ATM.o:AppClass/ATM/CPP/ATM.cpp
	$(CC) $(CFLAGS) AppClass/ATM/CPP/ATM.cpp -o Build/ATM.o

Build/branch.o:AppClass/branch/cpp/branch.cpp
	$(CC) $(CFLAGS) AppClass/branch/cpp/branch.cpp -o Build/branch.o

Build/login.o:AppClass/login/cpp/login.cpp
	$(CC) $(CFLAGS) AppClass/login/cpp/login.cpp -o Build/login.o

Build/employee.o:AppClass/employee/cpp/employee.cpp
	$(CC) $(CFLAGS) AppClass/employee/cpp/employee.cpp -o Build/employee.o

Build/BranchAccount.o:AppClass/BranchAccount/CPP/BranchAccount.cpp
	$(CC) $(CFLAGS) AppClass/BranchAccount/CPP/BranchAccount.cpp -o Build/BranchAccount.o

Build/CustomerUI.o:UI/CustomerAccUI/CPP/CustomerUI.cpp
	$(CC) $(CFLAGS) UI/CustomerAccUI/CPP/CustomerUI.cpp -o Build/CustomerUI.o

Build/AccountUI.o:UI/CustomerAccUI/CPP/AccountUI.cpp
	$(CC) $(CFLAGS) UI/CustomerAccUI/CPP/AccountUI.cpp -o Build/AccountUI.o

Build/BranchAccountUI.o:UI/BranchAccountUI/CPP/BranchAccountUI.cpp
	$(CC) $(CFLAGS) UI/BranchAccountUI/CPP/BranchAccountUI.cpp -o Build/BranchAccountUI.o

Build/ATMUI.o:UI/ATMUI/CPP/ATMUI.cpp
	$(CC) $(CFLAGS) UI/ATMUI/CPP/ATMUI.cpp -o Build/ATMUI.o

Build/branchUI.o:UI/branchUI/cpp/branchUI.cpp
	$(CC) $(CFLAGS) UI/branchUI/cpp/branchUI.cpp -o Build/branchUI.o

Build/loginUI.o:UI/loginUI/cpp/loginUI.cpp
	$(CC) $(CFLAGS) UI/loginUI/cpp/loginUI.cpp -o Build/loginUI.o

Build/employeeUI.o:UI/employeeUI/cpp/employeeUI.cpp
	$(CC) $(CFLAGS) UI/employeeUI/cpp/employeeUI.cpp -o Build/employeeUI.o

Build/mainUI.o:UI/mainUI/cpp/mainUI.cpp UI/mainUI/include/mainUI.h
	$(CC) $(CFLAGS) UI/mainUI/cpp/mainUI.cpp -o Build/mainUI.o

Build/Model.o:Model/PC/Model.pc Model/PC/Model.cpp Model/Include/Model.h
	proc code=cpp cpp_suffix=cpp parse=none Model/PC/Model.pc
	$(CC) $(CFLAGS) Model/PC/Model.cpp -o Build/Model.o

Build/BranchAccountController.o:Controller/BranchAccountController/CPP/BranchAccountController.cpp
	$(CC) $(CFLAGS) Controller/BranchAccountController/CPP/BranchAccountController.cpp -o Build/BranchAccountController.o

Build/ATMController.o:Controller/ATMController/CPP/ATMController.cpp
	$(CC) $(CFLAGS) Controller/ATMController/CPP/ATMController.cpp -o Build/ATMController.o

Build/AccountController.o:Controller/AccountController/CPP/AccountController.cpp
	$(CC) $(CFLAGS) Controller/AccountController/CPP/AccountController.cpp -o Build/AccountController.o

Build/CustomerController.o:Controller/CustomerController/CPP/CustomerController.cpp
	$(CC) $(CFLAGS) Controller/CustomerController/CPP/CustomerController.cpp -o Build/CustomerController.o

Build/branchController.o:Controller/branchController/cpp/branchController.cpp Controller/branchController/include/branchController.h
	$(CC) $(CFLAGS) Controller/branchController/cpp/branchController.cpp -o Build/branchController.o

Build/loginController.o:Controller/loginController/cpp/loginController.cpp
	$(CC) $(CFLAGS) Controller/loginController/cpp/loginController.cpp -o Build/loginController.o

Build/employeeController.o:Controller/employeeController/cpp/employeeController.cpp Controller/employeeController/include/employeeController.h
	$(CC) $(CFLAGS) Controller/employeeController/cpp/employeeController.cpp -o Build/employeeController.o

Build/Validation.o:Validation/CPP/Validation.cpp
	$(CC) $(CFLAGS) Validation/CPP/Validation.cpp -o Build/Validation.o

Build/Utility.o:Utility/CPP/Utility.cpp
	$(CC) $(CFLAGS) Utility/CPP/Utility.cpp -o Build/Utility.o

Build/main.o:Main/CPP/main.cpp
	$(CC) $(CFLAGS) Main/CPP/main.cpp -o Build/main.o

clean:
	rm -f Build/*.o Build/Management
