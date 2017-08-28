#include "stack.h"

stack::stack()
{
    head = NULL;
}

stack::~stack()
{
    delete head;
}

bool stack::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void stack::push(stack_entry & entry)
{
    if(head == NULL)
    {
        head = new stack_entry;
        head->x = entry.x;
        head->y = entry.y;
        head->next = NULL;    
    }
    else
    {
        stack_entry * temp = new stack_entry;
        temp->x = entry.x;
        temp->y = entry.y;
        temp->next = head;
        head = temp;
        temp = NULL;
    }
}

stack_entry * stack::pop()
{
    if(head)
    {
        stack_entry * temp = head;
        head = head->next;
        
        temp->next = NULL;
        
        delete temp;
        temp = NULL;
    }
    
    return head;
}

stack_entry * stack::peek()
{
    return head;
}