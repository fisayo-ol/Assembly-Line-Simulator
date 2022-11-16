// CLASS: EndAssembly
//
// Author: Fisayo Olofin, 7812316
//
// REMARKS: Event to handle the end of an assembly
//
//-----------------------------------------

#include "EndAssembly.h"
#include "Simulation.h"
#include "ProductArrival.h"
#include "Parts.h"
#include "Queue.h"
#include "StartAssembly.h"

#include <iostream>
using namespace std;

EndAssembly::EndAssembly(int theTime, Simulation *theSim, char loc, int time) : Event(theTime, theSim), location(loc), timeStarted(time)
{
} //Constructor

void EndAssembly::processEvent()
{
    Queue **partsQueue = sim->getPartQueues();
    Queue *productQueue = sim->getProductQueue();

    Event *newEvent; //pointer for new event to be created

    if (location == 'M')
    {

        Parts *newPart = new Parts(2,getTime()); // making a new preassembled part
        Event *newEvent = new ProductArrival(getTime(), sim, newPart, timeStarted);
        sim->addEvent(newEvent);   //add a new product arrival event to eventlist
        sim->setMainStatus(false); // reset status of main station

        //Schedule a startAssebly event if the queues are not empty
        scheduleStart(partsQueue[0], partsQueue[1]);
    }

    else if (location == 'F')
    {
        sim->setFinishingStatus(false); // reset status of finishing station
        sim->finalProduct(getTime()-timeStarted);
        //Schedule a startAssebly event if the queues are empty
        scheduleStart(partsQueue[2], productQueue);
    }
} //processEvent

void EndAssembly::scheduleStart(Queue *queue1, Queue *queue2)
{
    if (!queue1->isEmpty() && !queue2->isEmpty())
    {
        Parts *part1 = dynamic_cast<Parts*>(queue1->dequeue());
        Parts *part2 = dynamic_cast<Parts*>(queue2->dequeue());
        Event *tevent = new StartAssembly(getTime(), sim, location,min(part1->getTime(),part2->getTime()));
        sim->addEvent(tevent);
    }

} //scheduleStart

void EndAssembly::print()
{
    if (location == 'F')
    {
        cout << "Assembly ended at the finishing station at time: " << getTime() << " The first part arrived at time: "<< timeStarted
             << endl;
        cout << "The final product took a time of: " << getTime() - timeStarted << " to assemble\n"
             << endl;
    }
    else if (location == 'M')
    {
        cout << "Assembly ended at the main station at time: " << getTime() << "\n"
             << endl;
    }
} //print


EndAssembly::~EndAssembly() {} //destructor