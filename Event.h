#pragma once
#include "OrderedItem.h"


class Simulation;

/**** Event abstract interface */
class Event: public OrderedItem {
private:
        int eventTime; // time of the event.
protected: 
        Simulation *sim; // simulation event is a part of.
public:
        Event(int theTime, Simulation* sim);
        virtual void processEvent() = 0; // polymorphic method for events. 
        virtual void print() = 0; // polymorphic method for events.
        virtual ~Event();
        int getTime(); 
        int compareTo(OrderedItem *other); // you must implement this. 
};// class Event
