// CLASS: Event
//
// Author: Fisayo Olofin, 7812316

// REMARKS: Parent class all other types event needed in the simulation
//
//-----------------------------------------

#include "Event.h"

Event::Event(int theTime, Simulation *theSim) : eventTime(theTime), sim(theSim) {}


int Event::getTime()
{
	return eventTime;
} //getTime


int Event::compareTo(OrderedItem *other)
{
	Event *otherEvent = dynamic_cast<Event *>(other);
	return eventTime - otherEvent->getTime();
} //compareTo


Event::~Event() {}