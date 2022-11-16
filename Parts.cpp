#include "Parts.h"

Parts::Parts(int partType, int arrivalTime): ListItem(), type(partType), time(arrivalTime){}

int Parts::getType(){
    return type;
}

int Parts::getTime(){
    return time;
}


Parts::~Parts(){}