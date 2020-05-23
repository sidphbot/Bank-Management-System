#ifndef _VALIDATION_H
#define _VALIDATION_H
#include <iostream>
#include <cctype>
#include <string>
#include "../../Utility/Include/Utility.h"
using namespace std;

class Validation
{
   public:
   static int validateDouble (string);
   static int validateLong (string);
   static int validateString(string);
static bool validateNumber(string);
 // static int validateString(string);
  static int  validateName(string);
  static bool validateGender(string);
  static bool validateDate(string);
  static bool validateSize(string,int);
  static bool validateString1(string);
static int validateChoice(string);
static int validateNumber1(string);
static int ValidateNumber(string);
static int ValidateString(string);
static int ValidateBalance(string);
static int ValidateYear(string);
static int ValidateNonSalBalance(string);
static int ValidateDepositAmount(string);
 static bool validateSize1(string,int);
static int ValidateBalance1(string);
static int validateChoice1(string);
};

#endif
