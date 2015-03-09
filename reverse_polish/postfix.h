/**
* @file infix.h
* @author Daniel Murphy
*/
#ifndef POSTFIX_H
#define POSTFIX_H

#include "stack.h"

//! evaluates the value of a postfix expression
float eval_postfix(char* postfix);

//! computes the binary operations for the eval_postfix function
void compute(string operation, stack<string>& operands);

#endif