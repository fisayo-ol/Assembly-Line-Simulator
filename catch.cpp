#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PriorityQueue.h"
#include "PartArrival.h"
#include "Parts.h"


TEST_CASE("Test the PriorityQueue and Parts class"){

    SECTION("1"){
        PriorityQueue *queue1 = new PriorityQueue();
        queue1->addItem(new PartArrival(1,nullptr,nullptr));
        queue1->addItem(new PartArrival(2,nullptr,nullptr));
        queue1->addItem(new PartArrival(3,nullptr,nullptr));
        queue1->addItem(new PartArrival(4,nullptr,nullptr));

        REQUIRE(queue1->getSize()==4);
    }

    SECTION("2"){
        Parts *part1 = new Parts(2,200);

        REQUIRE(part1->getTime()==200);
        REQUIRE(part1->getType()==2); 
    }  
}




