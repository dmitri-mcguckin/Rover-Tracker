#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct stack_entry
{
    int x, y;
    stack_entry * next;
};

class stack
{
    private:
        stack_entry * head;
    public:
        stack();
        ~stack();
        bool isEmpty();
        void push(stack_entry &);
        stack_entry * pop();
        stack_entry * peek();
};

#endif