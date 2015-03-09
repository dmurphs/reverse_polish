/**
* @file main.cpp
* @author Daniel Murphy
*/

#include <iostream>
#include <cstdlib>
#include "postfix.h"
#include "infix.h"

//! Formats user input so it can be read by the program.
void format_input(string input, string &output);

int main(void){
	while(1){
		int choice;
		cout << "Select 1 to enter an expression or 0 to quit: " << endl;
		cin >> choice;
		cin.clear();
		while(cin.fail()){
			cout << "invalid, try again" << endl;
			cin.clear();
			cin >> choice;
			cin.clear();
		}

		cin.ignore(1000, '\n');

		if(choice == 1){
			string in, out, expression;
			cout << "Enter an expression: ";
			getline(cin, in);
			format_input(in, expression);
			out.resize(expression.length() * 100);

			char *infix = &expression[0];
			char *postfix = &out[0];
			cout << "\nFixed: " << infix << endl;

			infix2postfix(infix, postfix);
	
			cout << "\nPostfix: " <<  out << endl;
			cout << "gets here" << endl;
			double x = eval_postfix(postfix);
			cout << "Evaluated Postfix: " << x << endl;
		}
			
		else{
			break;
		}	


	return 0;
	}	

};

void format_input(string input, string &output){
	for(unsigned int i = 0; i < input.length(); i++){
		if(input[i] != ' '){
            if(input[i] == '^' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '+'){
				output.push_back(' ');
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == '-'){
				if((i != 0) && (*output.rbegin() != '^' && *output.rbegin() != '(' && *output.rbegin() != ' ' && *output.rbegin() != '*' && *output.rbegin() != '/' && *output.rbegin() != '/' && *output.rbegin() != '%' && *output.rbegin() != '+' && *output.rbegin() != '-')){
					output.push_back(' ');
					output.push_back(input[i]);
					output.push_back(' ');
				}
				else{
					output.push_back(input[i]);
				}	
			}
			else if(input[i] == '('){
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == ')'){
				output.push_back(' ');
				output.push_back(input[i]);
			}
			else{
				output.push_back(input[i]);
			}
		}
	}
}
