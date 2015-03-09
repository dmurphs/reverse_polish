#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

template <class Object>
class stack{
    public:
        stack();
        stack(const stack & rhs);
        ~stack();

        bool isEmpty() const;
        bool isFull() const;
        const Object & top() const;

        void makeEmpty();
        void pop();
        void push( const Object & x);
        Object topAndPop();

        const stack & operator=( const stack & rhs );

        int size();

    private:
        struct Node{
            Object element;
            Node *next;

            Node(const Object & theElement, Node * n = NULL){
                element = theElement;
                next = n;
            }
        };
        Node* stack_top;
};

#endif