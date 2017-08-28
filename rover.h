#ifndef ROVER_H
#define ROVER_H

#include <iostream>
#include "stack.h"
#include "queue.h"
#include "scandata.h"

using namespace std;

class rover
{
    private:
        int ID;    
        stack positions;
        queue results;
        scandata scan;
        
    public:
        rover();
        rover(int, const int &);
        ~rover();
        
        void corescan();
        void move(int &, int &);
        void deploy();
        void dock();
        void resetCoords();
        void printID();
};

#endif