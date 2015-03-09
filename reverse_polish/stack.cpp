

#include "stack.h"

template <class Object>
stack<Object>::stack(){
    stack_top = NULL;
}

template <class Object>
stack<Object>::~stack(){
    makeEmpty();
}

template <class Object>
bool stack<Object>::isFull() const{
    return false;
}

template <class Object>
bool stack<Object>::isEmpty() const{
    return stack_top == NULL;
}

template <class Object>
void stack<Object>::makeEmpty(){
    while( !isEmpty())
        pop();
}

template <class Object>
void stack<Object>::push( const Object & x ){
    Node* temp = stack_top;
    stack_top = new Node(x);
    stack_top->next = temp;
}

template <class Object>
const Object & stack<Object>::top() const{
    if( isEmpty() ){
        std::cout << "Underflow()" << std::endl;
    }
    return stack_top->element;
}

template <class Object>
void stack<Object>::pop(){
    if( isEmpty()){
        std::cout << "Underflow()" << std::endl;
    }
    else{
        Node *oldTop = stack_top;
        stack_top = stack_top->next;
        delete oldTop;
    }    
}

template <class Object>
Object stack<Object>::topAndPop(){
    Object topItem = top();
    pop();
    return topItem;
}

template <class Object>
const stack<Object> & stack<Object>::
operator=( const stack<Object> & rhs ){
    if( this != &rhs ){
        makeEmpty();
        if( rhs.isEmpty())
            return *this;

        Node *rptr = rhs.stack;
        Node *ptr = new Node( rptr->element );
        stack_top = ptr;

        for( rptr = rptr->next; rptr != NULL; rptr = rptr->next )
            ptr = ptr->next = new Node( rptr->element );
    }
    return *this;
}

template <class Object>
stack<Object>::stack( const stack<Object> & rhs ){

    stack_top = NULL;
    *this = rhs;
}

template <class Object>
int stack<Object>::size(){
    Node* temp = stack_top;
    int counter = 0;
    while(temp != 0){
        temp = temp->next;
        counter += 1;
    }
    return counter;
}