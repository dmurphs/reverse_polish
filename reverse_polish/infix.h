/**
* @file infix.h
* @author Daniel Murphy
*/
#ifndef INFIX_H
#define INFIX_H

#include "stack.h"

//! assigns precedence to operators
int precedence(char x);

//! converts infix expression to postfix expression.
void infix2postfix(char* infix, char* postfix);

#endif