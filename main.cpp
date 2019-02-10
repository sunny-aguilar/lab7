/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Menu class description here
*********************************************************************/
#include <iostream>
#include "DynIntQueue.hpp"

int main() {
    DynIntQueue iQueue;

    // enqueue 5 items
    cout << "Enqueuing 5 items...\n";
    for (int k = 1; k < 5; k++) {
        iQueue.enqueue(k*k);
    }

    // dequeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty()) {
        int value;
        iQueue.dequeue(value);
        cout << value << " ";
    }

    return 0;
}