#include "rover.h"

rover::rover()
{
    
}

rover::rover(int x, const int &)
{
    ID = x;
}

rover::~rover()
{

}

void rover::corescan()
{
    printID();
    cout << " scanning." << endl;
    
    results.enqueue(scan.getScandata(positions.peek()->x,positions.peek()->y));
}

void rover::move(int & tX, int & tY)
{
    stack_entry entry;
    
    entry.x = tX;
    entry.y = tY;
    
    printID();
    cout << " moving to location " << entry.x << ", " << entry.y << "." << endl;
    positions.push(entry);
}

void rover::deploy()
{
    printID();
    cout << " deploying..." << endl;
    
    resetCoords();
    
    printID();
    cout << " ready." << endl;
}

void rover::dock()
{
    printID();
    cout << " returning to base." << endl;
    
    while(positions.peek())
    {      
        printID();
                
        if(positions.peek() )
            cout << " moving to location " << positions.peek()->x << ", " << positions.peek()->y << "." << endl;
        
        positions.pop();
    }
    
    printID();
    cout << " at base. Sending results..." << endl;
    
    
    while(results.peakFront() != NULL)
    {
        printID();
        cout << " result: " << results.peakFront()->data << endl;
        results.dequeue();
    }        
    
    
    printID();
    cout << " result transmission complete." << endl;
    
    printID();
    cout << " docked." << endl;
    resetCoords();
}

void rover::resetCoords()
{
    stack_entry base;
    base.x = 0;
    base.y = 0;
    positions.push(base);    
}

void rover::printID()
{
    cout << "Rover (ID " << ID << ")";
}