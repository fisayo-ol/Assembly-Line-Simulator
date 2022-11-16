#pragma once
#include "ListItem.h"

class Parts: public ListItem{
    private:
        int type;
        int time;
    public:
        Parts(int partType, int arrivalTime);
        int getType();
        int getTime();
        ~Parts();
};// class Parts