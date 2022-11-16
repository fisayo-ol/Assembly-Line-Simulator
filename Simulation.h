#pragma once
#include <fstream>
using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you. 
class PartArrival;

class Simulation {
private:
        ifstream ifile; // input file to read.
        int simulationTime; // what is the current time of the simulation?
        PriorityQueue *eventList; // priority queue of Events.
        Queue* productQueue; // queue of partially assembled products (for finishing station).
        Queue** partQueues; // *array* of queues of parts for the stations.
        int  mainAssemblyTime; //  how long does the main station take?
        int  finishingAssemblyTime; //  how long does the main station take?
	bool mainBusy; // is the main station busy?
	bool finishingBusy; // is the finishing station busy?
        int count;
        int totalTime;// Time needed to calculate the average

public:
        Simulation();

	// you need methods to manipulate product and part queues.
	// [add them here.]
        
        int getSimulationTime();
        void setSimulationTime(int time);

        // main method for driving the simulation
        void runSimulation(char *fileName);

	// add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
        void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);

        //getters and setter for station queues and events priority queue
        Queue** getPartQueues();
        Queue* getProductQueue();

        int getMainTime();
        int getFinishingTime();

        void printSummary();

        void finalProduct(int);

};// class Simulation
