#ifndef _UTILITY_H
#define _UTILITY_H
#include <iostream>
#include <stdlib.h>
using namespace std;


class Utility
{
public:
//long convertToLong(string );

static long int convertToLong(string);
static double convertToDouble(string);
static int convertToInt(string);
static long int convertToLongInt(string);
static char convertToChar(string);
static float convertToFloat(string);
};

#endif
