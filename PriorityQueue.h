#pragma once

class Node;
class OrderedItem;

class PriorityQueue{
private:
        Node *front; //front of priority Queue
        Node *back; //back of priority Queue
        int size; //size of priority Queue
public:    
        PriorityQueue();
        int getSize(); //Number of elements in the priority Queue
        bool isEmpty(); //Is the Priority Queue empty
        void addItem(OrderedItem *item); // add item to the priority queue
        OrderedItem *getFront(); //look at first item in the priority queue
        OrderedItem *remove(); // remove item with the highest priority
        ~PriorityQueue();
}; //class PriorityQueue