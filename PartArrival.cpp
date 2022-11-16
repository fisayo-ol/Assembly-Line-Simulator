// CLASS: PartArrival
//
// Author: Fisayo Olofin, 7812316
//
// REMARKS: Event to handle the when a part arrives at a station
//
//-----------------------------------------

#include "PartArrival.h"
#include "Simulation.h"
#include "Queue.h"
#include "Parts.h"
#include "StartAssembly.h"

#include <iostream>
using namespace std;

PartArrival::PartArrival(int theTime, Simulation *theSim, Parts *part) : Event(theTime, theSim), typeOfPart(part)
{
}

void PartArrival::processEvent()
{
    if (typeOfPart->getType() == 0 || typeOfPart->getType() == 1)
    {
        processMain();
    }
    else if (typeOfPart->getType() == 2)
    {
        processFinishing();
    }
} //processEvent

void PartArrival::processMain()
{
    location = 'M';
    Queue *partQueue = sim->getPartQueues()[typeOfPart->getType()];              //Queue containing this part
    Queue *partQueue2 = sim->getPartQueues()[((typeOfPart->getType() + 1) % 2)]; //contains adjacent parts
    if (sim->isMainBusy() || partQueue2->isEmpty())
    {
        partQueue->enqueue(typeOfPart);
    }
    else
    {
        Parts *part2 = dynamic_cast<Parts*>(partQueue2->dequeue());
        Event *newEvent = new StartAssembly(getTime(), sim, location,std::min(part2->getTime(),typeOfPart->getTime()));
        sim->addEvent(newEvent);
    }
} //processMain

void PartArrival::processFinishing()
{
    location = 'F';
    Queue *partQueue = sim->getPartQueues()[typeOfPart->getType()]; //Queue conataining this part
    Queue *productQueue = sim->getProductQueue();                   //contains adjacent parts
    if (sim->isFinishingBusy() || productQueue->isEmpty())
    {
        partQueue->enqueue(typeOfPart);
    }
    else
    {
        Parts *part2 = dynamic_cast<Parts*>(productQueue->dequeue());
        Event *newEvent = new StartAssembly(getTime(), sim, location,std::min(part2->getTime(),typeOfPart->getTime()));
        sim->addEvent(newEvent);
    }
} //processFinishing

void PartArrival::print()
{
    if (location == 'F')
    {
        cout << "Part P" << typeOfPart->getType() << " arrives to the finishing station at time: " << getTime() << endl;
    }
    else if (location == 'M')
    {
        cout << "Part P" << typeOfPart->getType() << " arrives to the main station at time: " << getTime() << endl;
    }
} //print

PartArrival::~PartArrival() {}