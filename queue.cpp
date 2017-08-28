#include "queue.h"

queue::queue()
{
    front = NULL;
    back = NULL;
}

queue::~queue()
{

}

bool queue::isEmpty()
{
    if(front)
    {
        return true;
    }
    else
    {
        return false;
    }        
}

void queue::enqueue(int x)
{        
    if(front == NULL)
    {
        front = new queue_entry;
        front->data = x;
        front->next = NULL;
        front->prev = NULL;
        back = front;
    }
    else
    {
        queue_entry * temp = new queue_entry;
        temp->data = x;
        temp->next = NULL;
        temp->prev = back;
        back->next = temp;
        back = temp;
        temp = NULL;
    }
}

int queue::dequeue()
{
    if(front)
    {
        queue_entry * temp = front;
        if(front == back)
            back = NULL;
        front = front->next;
        if(front)
            front->prev = NULL;
                
        temp->prev = NULL;
        delete temp;
        temp = NULL;
    }
}

queue_entry * queue::peakFront()
{
    return front;
}