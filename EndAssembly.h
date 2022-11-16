#pragma once
#include "Event.h"


class Simulation;
class Queue;

class EndAssembly : public Event{

private:
    char location; //What station is being processed M-Main, F-Finishing
    int timeStarted;//time the first part arrived
public:
    EndAssembly(int theTime, Simulation *theSim, char loc, int time);
    void processEvent();
    void scheduleStart(Queue *queue1, Queue *queue2);
    ~EndAssembly();
    void print();    
};// class EndAssembly