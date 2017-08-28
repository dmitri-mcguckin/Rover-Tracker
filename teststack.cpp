#include <iostream>
#include "stack.h"

using namespace std;

void dumpStack(stack &s)
{
    cout << "Dumping the stack" << endl;
    
    while (!s.isEmpty())
    {
        cout<< "Removing: (" << s.peek()->x << "," << s.peek()->y << ")" << endl;
        s.pop();
    }
}

void pushHelper(stack &s,int x, int y)
{
    stack_entry entry;

    entry.x = x;
    entry.y = y;
    
    cout<< "Adding: (" << x << "," << y << ")" << endl;
    
    s.push(entry);
}

int main()
{
    stack s;
    stack_entry entry;

    pushHelper(s,1,1);
    dumpStack(s);

    pushHelper(s,1,1);
    pushHelper(s,2,2);
    dumpStack(s);

}
