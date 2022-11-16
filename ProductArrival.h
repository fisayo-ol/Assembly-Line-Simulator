#pragma once
#include "Event.h"

class Simulation;
class Parts;

class ProductArrival : public Event{

private:
    Parts *product;
    int firstPart;//time first part arrived

public:
    ProductArrival(int theTime, Simulation *theSim, Parts *prod, int);
    void processEvent();
    virtual ~ProductArrival();
    void print();    
};// class ProductArrival