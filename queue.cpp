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
Queue::Queue() {}

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
            break;
        case 2:
            menu.displayFirstNode();
            break;
        case 3:
            menu.removeFirstNode();
            break;
        case 4:
            menu.displayQueueContents();
            break;
        case 5:
            showMenu = false;
            break;
        default:
            cout << "Unable to determine your selection!\n";
    }
}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Queue::addBack() {}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Queue::removeFront() {}


void Queue::getFront() {}


void Queue::printQueue() {}