//! File: infix.cpp
//! @Author: Daniel Murphy

#include "stack.cpp"
#include "stack.h"
#include "infix.h"

using namespace std;

void infix2postfix(char* infix, char* postfix){
    stack<char> operators;
    char symbol;
    int i = 0;
    int j = 0;

    while(infix[i]){    
        symbol = infix[i];

        if(symbol && (symbol == '^' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '(' || symbol == ')')){
            if(symbol == '-' && infix[i + 1] != ' '){
                while(symbol != ' '){
                    postfix[j++] = symbol;
                    i += 1;
                    if(!infix[i]){
                        break;
                    }
                    symbol = infix[i];
                }
                continue;
            }
            else if(operators.isEmpty() || operators.top() == '('){
                operators.push(symbol);
            }
            else if(symbol == '('){
                operators.push(symbol);
            }
            else if(symbol == ')'){
                while(operators.top() != '('){
                    postfix[j++] = ' ';
                    postfix[j++] = operators.topAndPop();
                }
                operators.pop();
            }
            else if(precedence(symbol) > precedence(operators.top())){
                operators.push(symbol);
            }
            else if(precedence(symbol) == precedence(operators.top())){
                if(symbol == '^'){
                    operators.push(symbol);
                }
                else{
                    postfix[j++] = operators.topAndPop();
                    operators.push(symbol);
                }
            }
            else if(precedence(symbol) < precedence(operators.top())){
                while((operators.isEmpty() != 1) && precedence(symbol) < precedence(operators.top())){
                    postfix[j++] = operators.topAndPop();
                    postfix[j++] = ' '; 
                };
                if(operators.isEmpty() == 1){
                    operators.push(symbol);
                }
                else if(precedence(symbol) > precedence(operators.top())){
                    operators.push(symbol);
                }
                else if(precedence(symbol) == precedence(operators.top())){
                    if(symbol == '^'){
                        operators.push(symbol);
                    }
                    else{
                        postfix[j++] = operators.topAndPop();
                        operators.push(symbol);
                    }
                }
                else{
                    operators.push(symbol);
                }
            };
        }
        else{
            postfix[j++] = symbol;
        }
        i++;
    };
    while(operators.isEmpty() != 1){
        postfix[j++] = ' ';
        postfix[j++] = operators.topAndPop();
    };
};

//! checks the precedence of a character symbol
int precedence(char symbol){
    int priority;
    if(symbol == '^'){
        priority = 4;
    }
    else if(symbol == '*' || symbol == '/'){
        priority = 3;
    }
    else if(symbol == '+'){
        priority = 2;
    }
    else{
        priority = 1;
    }
    return priority;
}