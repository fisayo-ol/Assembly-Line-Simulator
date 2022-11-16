#pragma once
#include "Event.h"

class Simulation;
class Parts;

class PartArrival : public Event{

private:
    Parts *typeOfPart; //what kind of part arrived
    char location;

public:
    PartArrival(int theTime, Simulation *theSim, Parts *part);
    void processEvent();
    void processMain();
    void processFinishing();
    virtual ~PartArrival();
    void print();    
};// class PartArrival