/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Menu class description here
*********************************************************************/
#include "queue.hpp"

/*********************************************************************
** Description:     constructor
*********************************************************************/
Queue::Queue() : showMenu{true} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Queue::~Queue() {}

/*********************************************************************
** Description:     starts queue operations
*********************************************************************/
void Queue::startQueue() {
    queueFlow();
}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Queue::queueFlow() {
    do {
        menu.startMenu();

        queueOperations();
    } while (showMenu);
}

/*********************************************************************
** Description:     function provides a switch statement that performs
**                  queue operations.
*********************************************************************/
void Queue::queueOperations() {

    switch (menu.validateNumber(1,5)) {
        case 1:
            menu.addValue();
            addBack( menu.validateNumber(1, 20000) );
            cout << endl;
            break;
        case 2:
            menu.displayFirstNode();
            getFront();
            cout << endl;
            break;
        case 3:
            menu.removeFirstNode();
            removeFront();
            cout << endl;
            break;
        case 4:
            menu.displayQueueContents();
            printQueue();
            cout << endl;
            break;
        case 5:
            showMenu = false;
            break;
        default:
            cout << "Unable to determine your selection!\n";
    }
}

/*********************************************************************
** Description:     function takes a user-entered int value as a
**                  parameter. A new node is created with the integer
**                  as its value and the node is added to the back of
**                  the queue.
*********************************************************************/
void Queue::addBack(int num) {

}

/*********************************************************************
** Description:     this function removes the front node in the queue
**                  and frees the memory
*********************************************************************/
void Queue::getFront() {}

/*********************************************************************
** Description:     returns the value of the node at the front of the
**                  queue
*********************************************************************/
void Queue::removeFront() {}

/*********************************************************************
** Description:     this function traverses through the queue
**                  starting from the head using the next pointer and
**                  prints the values of each node in the queue.
*********************************************************************/
void Queue::printQueue() {}


bool Queue::isEmpty() {

}