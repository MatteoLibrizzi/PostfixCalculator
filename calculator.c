#include "stack.h"
#include "calculator.h"
#include "utils.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

static const char* PROMPT = "$> ";
static calculatorFunction* functionMap;
static int* minimumNumberOfOperands;


void initializeMaps() {
    functionMap = (calculatorFunction*)calloc(256,sizeof(calculatorFunction));
    minimumNumberOfOperands = (int*)calloc(256,sizeof(int));/*minimum number associated with each operation*/

    functionMap['p'] = &pCommand;
    functionMap['a'] = &aCommand;
    functionMap['c'] = &cCommand;
    functionMap['r'] = &rCommand;

    functionMap['+'] = &sumOperator;
    functionMap['-'] = &subOperator;
    functionMap['*'] = &mulOperator;
    functionMap['/'] = &divOperator;
    functionMap['^'] = &expOperator;
    functionMap['%'] = &modOperator;
    functionMap['!'] = &facOperator;

    minimumNumberOfOperands['p'] = 1;
    minimumNumberOfOperands['a'] = 0;
    minimumNumberOfOperands['c'] = 0;
    minimumNumberOfOperands['r'] = 2;

    minimumNumberOfOperands['+'] = 2;
    minimumNumberOfOperands['-'] = 2;
    minimumNumberOfOperands['*'] = 2;
    minimumNumberOfOperands['/'] = 2;
    minimumNumberOfOperands['%'] = 2;
    minimumNumberOfOperands['^'] = 2;
    minimumNumberOfOperands['!'] = 1;
}

void maps_quit() {
    free(functionMap);
    free(minimumNumberOfOperands);
}

int hasEnoughOperandsForOperation(CalculatorPtr calculator, char operation) {
    return stack_size(calculator->operands) >= minimumNumberOfOperands[operation];
}

CalculatorPtr calculator_init() {
    initializeMaps();
    StackPtr stack = stack_init();
    CalculatorPtr calculator = (CalculatorPtr)malloc(sizeof(Calculator));
    calculator->operands = stack;
    return calculator;
}

int calculator_input(CalculatorPtr calculator, char* s) {/*handle calculator input, s should have no white spaces in it, they are removed by the use of strtok*/
    char* endptr;
    int n = (int) strtol(s, &endptr, 10);/*only consider it a valid input number if there is nothing but digits*/
    if (*endptr == 0) {
        stack_push(calculator->operands, n);
        return 0;
    } else {
        char c = *s;
        if (isOperand(c) || isCommand(c)) {/*check if it is a valid char*/
            if (hasEnoughOperandsForOperation(calculator,c)) {/*check if the stack has enough operands*/
                calculatorFunction calculatorFunction = functionMap[c];/*get the function to run from the map*/
                return (*calculatorFunction)(calculator);/*run the function*/
            } else {
                fprintf(stderr,"    Not enough operands\n");
                return -1;
            }
        } else {
            fprintf(stderr,"    Invalid input\n");
            return -1;
        }
    }
    fprintf(stderr,"    Invalid input\n");
    return -1;
}
int calculator_quit(CalculatorPtr calculator) {
    stack_quit(calculator->operands);
    maps_quit();
    free(calculator);
    return 0;
}

int calculator_run() {
    CalculatorPtr calculator = calculator_init();
    char *line = readline(PROMPT);
    char* token;
    char* separator = " ";
    while (*line != 'q') {/*only quit when the line only contains 'q'*/
        token = strtok(line, separator);/*removing white spaces and getting the simplest string possible*/
        while (token != NULL) {
            calculator_input(calculator, token);/*call to the handle of the input*/
            token = strtok(NULL, separator);
        }
        line = readline(PROMPT);
    }
    return calculator_quit(calculator);
}