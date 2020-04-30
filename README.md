# Bank-Management-System
A bank management system with infrastructure management along with account and service management written purely in C++/Pro*c

# Specifications
The customer can register and login to view the CLI user dashboard with options to make a suitable request according to his authorization level, the general options available are: Branch Management, Employee Management, Branch Account Management, Customer Management, ATM Management, Customer Account Management, Customer Services Management. In branch management the customer can perform the following operation: Add Branch Details, View Branch Details, View all branch details, Deactivate Branch, Update Branch Details.
Similar to this in Branch Account management the customer may perform the following operations: Add branch account, View branch account, Update branch Account, De-activate branch Account, View all Branch Account.
A branch manager may handle all the operations relative to the branch such as managing branch accounts, creating new accounts and modifying the existing ones. He/ she an also edit the user profile and their passwords. The manager can also view the customer details and perform similar operations on the customers of their specific branch where as a regional manager may perform the. Same operations for customers of all the branch in their region. The manager has the features to perform these operations on the customers of their branch: Add Customer, Update Customer Details, View Customer Details, View all, Deactivate Customer. Deactivate customer can be used only with that level of authorization in cases where deactivating an account is a must. 
Similar to this the manager has a feature to manage the ATMs relative to him and he/ she may perform the following operations on an ATM. Add ATM, View ATM, Update ATM, Close ATM, generate ATM Report.
The features like Customer Account Management can be used to perform the following operations in the banking system: 
Add Account, View Account, Update Account, Deactivate Account and , Customer Services Management may be used to perform the following operations : Fund transfer, Account statement, Bill payment, Cash deposit, Cash withdrawal, Block ATM, Balance enquiry, Cheque book request. 

# Usage
This application is used by Employees of a bank, the employees may access the following features:
Branch Management
Employee Management
Branch Account Management
Customer Management
ATM Management
Customer Account Management
Customer Services Management

# Features
F-01	Login
F-02	Change Password
F-03	Forgot Password
F-04	Add branch
F-05	Update branch
F-06	deactivate branch
F-07	view all branch
F-08	view branch
F-09	Add employee
F-10 	Update employee
F-11 	deactivate employee
F-12 	view all employee
F-13 	view employee
F-14 	Add customer
F-15 	Update customer
F-16 	deactivate customer
F-17 	view all customer
F-18 	view customer
F-19 	Add ATM
F-20 	Update ATM
F-21 	deactivate ATM
F-22 	view all ATM	
F-23 	view ATM
F-24 	Add customer account
F-25 	Update customer account
F-26 	deactivate customer account
F-27 	view all customer account
F-28 	view customer account
F-29 	Add branch account
F-30 	Update branch account
F-31 	deactivate branch account
F-32 	view all branch account
F-33 	view branch account
F-34 	Fund Transfer
F-35 	Bill Payment
F-36 	Account Statement
F-37 	Block ATM
F-38 	Chequebook request
F-39 	Balance enquiry 

# Data	
D-01	Employee data
D-02	Transaction data
D-03	Accounts data
D-04    Bank Infrastructure data


# Software requirements
OS: Linux 
Back end: C++ runtime with Oracle Instant Client with Pro*C compiler
Editor: Visual studio
Database: Oracle 11g

# design diagrams

please look into teh design folder
(Note: not all use case diagrams, activity diagrams and sequence diagrams are present)

# steps to run

- create schema as follows:

user: BMS
pass: abc123
SID: XE
 
create tables and sequences according to db_specs.txt in design folder to load up the database architecture (entity-relationship-diagram also present in design folder)


- unzip application src folder in [your_app_directory]

- run "make" command in [your_app_directory]     // if pro*c fails to compile change makefile for shared library location according to oracle installation

- run it

> cd [your_app_directory]/Build
> ./Management

[then its just CLI]
