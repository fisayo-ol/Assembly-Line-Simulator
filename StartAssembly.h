#pragma once
#include "Event.h"

class Simulation;
class Parts;

class StartAssembly : public Event{

private:
    char location; //where the assembly is taking place 0-main, 1-Finisihing.

    //parts being assembled
    int timeStarted;
public:
    StartAssembly(int theTime, Simulation *theSim, char loc, int time);
    void processEvent();
    ~StartAssembly();
    void print();    
};// class StartAssembly