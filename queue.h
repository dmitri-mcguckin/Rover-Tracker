#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

struct queue_entry
{
    int data;
    queue_entry * next;
    queue_entry * prev;
};

class queue
{
    private:
        queue_entry * front;
        queue_entry * back;
    public:
        queue();
        ~queue();
        
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        queue_entry * peakFront();
};

#endif