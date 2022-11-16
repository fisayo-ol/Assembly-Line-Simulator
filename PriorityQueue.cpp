#include "PriorityQueue.h"
#include "Node.h"
#include "OrderedItem.h"

PriorityQueue::PriorityQueue() : front(nullptr), back(nullptr), size(0) {}

int PriorityQueue::getSize()
{
    return size;
} //getSize

bool PriorityQueue::isEmpty()
{
    return size == 0;
} //isEmpty

OrderedItem *PriorityQueue::remove()
{
    OrderedItem *theItem = nullptr;
    Node *theNode = front;
    if (front != nullptr)
    {
        theItem = dynamic_cast<OrderedItem *>(front->getItem());
        // if removing the last item.
        if (front == back)
        {
            front = back = nullptr;
        }
        else
        {
            front = front->getNext();
        }
        size--;
        delete (theNode);
    }
    return theItem;
} //remove

OrderedItem *PriorityQueue::getFront()
{
    OrderedItem *theItem = dynamic_cast<OrderedItem *>(front->getItem());
    return theItem;
} //getFront

void PriorityQueue::addItem(OrderedItem *item)
{
    Node *newNode = new Node(item, nullptr);

    // adding to an empty priority queue
    if (front == nullptr || item->compareTo(dynamic_cast<OrderedItem *>(front->getItem())) < 0)
    {
        newNode->setNext(front);
        front = newNode;
    }
    else
    {
        Node *curr = front;
        Node *prev;
        /* Locate the node before the point of insertion
             */
        while (curr->getNext() != nullptr && item->compareTo(dynamic_cast<OrderedItem *>(front->getItem())) >= 0)
        {
            prev = curr;
            curr = curr->getNext();
        }
        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
    }
    size++;
} // add item;