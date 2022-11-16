// CLASS: ProductArrival
//
// Author: Fisayo Olofin, 7812316
//
// REMARKS: Event to handle the when a pre-assembled product arrives at the finishing station
//
//-----------------------------------------

#include "ProductArrival.h"
#include "Simulation.h"
#include "Queue.h"
#include "Parts.h"
#include "StartAssembly.h"

#include <iostream>
using namespace std;

ProductArrival::ProductArrival(int theTime, Simulation *theSim, Parts *prod, int ttime) : Event(theTime, theSim), product(prod), firstPart(ttime)
{
}

void ProductArrival::processEvent()
{
    Queue *partQueue = sim->getPartQueues()[2];   //Queue conataining part P2
    Queue *productQueue = sim->getProductQueue(); //Queue conataining this product
    if (sim->isFinishingBusy() || partQueue->isEmpty())
    {
        productQueue->enqueue(product);
    }
    else
    {
        Parts *part2 = dynamic_cast<Parts *>(partQueue->dequeue());
        Event *newEvent = new StartAssembly(getTime(), sim, 'F',std::min(part2->getTime(),firstPart));
        sim->addEvent(newEvent);
    }
}  //processEvent

void ProductArrival::print()
{
    cout << "Pre-assmebled part arrives at the finishing station from the main station at time: " << getTime() << endl;
}  //print

ProductArrival::~ProductArrival() {}