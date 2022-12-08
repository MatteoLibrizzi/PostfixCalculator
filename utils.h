#ifndef _operations_
#define _operations_

#include "types.h"

int pCommand(CalculatorPtr c);
int aCommand(CalculatorPtr c);
int cCommand(CalculatorPtr c);
int rCommand(CalculatorPtr c);

int sumOperator(CalculatorPtr c);
int subOperator(CalculatorPtr c);
int mulOperator(CalculatorPtr c);
int divOperator(CalculatorPtr c);
int modOperator(CalculatorPtr c);
int facOperator(CalculatorPtr c);
int expOperator(CalculatorPtr c);

int isOperand(char c);
int isCommand(char c);

#endif