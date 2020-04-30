#ifndef _CUSTOMER_CONTROLLER_H_
#define _CUSTOMER_CONTROLLER_H_


#include"../../../UI/CustomerAccUI/Include/CustomerUI.h"
#include"../../../Model/Include/Model.h"
#include"../../../AppClass/CustomerAcc/Include/Customer.h"



class CustomerController
{
  public:
  int initViewCustomer(Bank &);

  int initAddCustomer(Bank &);
  int initiateRequestBlockATMCard(Bank &);  
  int initiateViewCustomer(Bank &);
  int initiateUpdateCustomer(Bank &);
  int initiateDeactivateCustomer(Bank &);
  //int initiateBillPayment(Bank &);
  void initiateViewAllCustomer(Bank &);
};

#endif
