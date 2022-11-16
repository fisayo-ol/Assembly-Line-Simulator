// CLASS: StartAssembly
//
// Author: Fisayo Olofin, 7812316
//
// REMARKS: Event to handle when a station needs to assemble parts
//
//-----------------------------------------

#include "StartAssembly.h"
#include "Simulation.h"
#include "EndAssembly.h"
#include "Parts.h"

#include <iostream>
using namespace std;

StartAssembly::StartAssembly(int theTime, Simulation *theSim, char loc, int time) : Event(theTime, theSim), location(loc), timeStarted(time)
{
}

void StartAssembly::processEvent()
{
    Event *newEvent;
    int currTime = sim->getSimulationTime();
    int processTime;
    if (location == 'M')
    {
        sim->setMainStatus(true);
        processTime = sim->getMainTime();
        newEvent = new EndAssembly(currTime + processTime, sim, location, timeStarted);
    }

    else if (location == 'F')
    {
        sim->setFinishingStatus(true);
        processTime = sim->getFinishingTime();
        newEvent = new EndAssembly(currTime + processTime, sim, location, timeStarted);
    }

    sim->addEvent(newEvent);
    ;
} //processEvent

void StartAssembly::print()
{

    if (location == 'F')
    {
        cout << "Assembly started at the finishing station at time unit: " << getTime() << "\n"
             << endl;
    }
    else if (location == 'M')
    {
        cout << "Assembly started at the main station at time unit: " << getTime() << "\n"
             << endl;
    }
} //print


StartAssembly::~StartAssembly() {}