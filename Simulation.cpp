// CLASS: Simulation
//
// Author: Fisayo Olofin, 7812316
//
// REMARKS: Runs the simulation to 
//
//-----------------------------------------


#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "PartArrival.h"
#include "ProductArrival.h"
#include "StartAssembly.h"
#include "EndAssembly.h"
#include "Parts.h"

#include <fstream>
#include <iostream>
using namespace std;

Simulation::Simulation() : mainBusy(false), finishingBusy(false), simulationTime(0), count(0), totalTime(0)
{
    partQueues = new Queue *[3];
    partQueues[0] = new Queue; // Queue to store parts P0
    partQueues[1] = new Queue; // Queue to store parts P1
    partQueues[2] = new Queue; // Queue to store parts P2

    productQueue = new Queue; // Queue to store partially assemble products

    eventList = new PriorityQueue; //Priority Queue of events
}

void Simulation::runSimulation(char *fileName)
{
    ifile.open(fileName);
    ifile >> mainAssemblyTime >> finishingAssemblyTime; //Assigning Assembly times
    bool flag = false;

    //First part arrives
    getNextArrival();

    while (!eventList->isEmpty())
    {

        int oldpos = ifile.tellg();
        string line;
        int nextTime;
        if (getline(ifile, line, ' '))
        {
            nextTime = stoi(line);
        }
        else
        {
            nextTime = -1;
        }
        ifile.seekg(oldpos);

        if (nextTime != -1)
        {
            Event *nextEvent1 = dynamic_cast<Event *>(eventList->getFront());

            if ( nextTime < nextEvent1->getTime())
            {
                
                getNextArrival();
                
            }
        }

        Event *nextEvent = dynamic_cast<Event *>(eventList->remove());
        simulationTime = nextEvent->getTime();
        nextEvent->processEvent();
        nextEvent->print();
        
        delete nextEvent;

        

        if (eventList->isEmpty())
        {
            getNextArrival();
        }

    }

    ifile.close();
}

void Simulation::printSummary()
{
    cout << "There are " <<  partQueues[0]->getSize() << " parts of the initial " << partQueues[0]->getSize() + count <<" left in the P0 parts queue\n"  << endl;
    cout << "There are " <<  partQueues[1]->getSize() << " parts of the initial " << partQueues[1]->getSize() + count <<" left in the P1 parts queue\n"  << endl;
    cout << "There are " <<  partQueues[2]->getSize() << " parts of the initial " << partQueues[2]->getSize() + count <<" left in the P2 parts queue\n"  << endl;
    cout << "There are " <<  productQueue->getSize() << " parts of the initial " << productQueue->getSize() + count <<" left in the pre-assembled parts queue\n"  << endl;

    cout << "A total of " <<  count << " products were assembled"  << endl;
    cout << "The Total assembly time is " <<  totalTime  << endl;
    cout << "The Average assembly time is " <<  totalTime/count  << endl;
}

void Simulation::getNextArrival()
{   
    int i;
    int j;
    if (ifile >> i >> j)
    {
        Parts *newPart = new Parts(j,i);
        addEvent(new PartArrival(i, this, newPart));
    }
}

// getters and setters

bool Simulation::isMainBusy()
{
    return mainBusy;
} //is the main station busy?

bool Simulation::isFinishingBusy()
{
    return finishingBusy;
} //is the finisihing station busy?

void Simulation::setMainStatus(bool flag)
{
    mainBusy = flag;
} //set status for the main station

void Simulation::setFinishingStatus(bool flag)
{
    finishingBusy = flag;
} //set status for the finishing station

Queue **Simulation::getPartQueues()
{
    return partQueues;
} //returns the array of partsQueues

Queue *Simulation::getProductQueue()
{
    return productQueue;
} //returns the array of partsQueues

int Simulation::getSimulationTime()
{
    return simulationTime;
}

void Simulation::setSimulationTime(int time)
{
    simulationTime = time;
}

int Simulation::getMainTime()
{
    return mainAssemblyTime;
}

int Simulation::getFinishingTime()
{
    return finishingAssemblyTime;
}

void Simulation::addEvent(Event *newEvent)
{
    eventList->addItem(newEvent);
}

void Simulation::finalProduct(int assemblyTime)
{
    count++;
    totalTime+= assemblyTime;
}