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
Queue::Queue() : showMenu{true}, head{nullptr}, tail{nullptr} {}

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
            cout << endl << endl;
            break;
        case 2:
            menu.displayFirstNode();
            getFront();
            cout << endl << endl;
            break;
        case 3:
            menu.removeFirstNode();
            removeFront();
            cout << endl << endl;
            break;
        case 4:
            menu.displayQueueContents();
            printQueue();
            cout << endl << endl;
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
    if (head == nullptr) {
        head = new QueueNode(num);
        tail = head;
    }
    else {
        tail->next = new QueueNode(num);
        tail = tail->next;
    }
}

/*********************************************************************
** Description:     this function removes the front node in the queue
**                  and frees the memory
*********************************************************************/
void Queue::getFront() {
    if (head == nullptr) {
        cout << "The queue is empty\n";
    }
    else {
        cout << head->val << endl;
    }
}

/*********************************************************************
** Description:     returns the value of the node at the front of the
**                  queue
*********************************************************************/
void Queue::removeFront() {
    // create temp node
    QueueNode *temp = nullptr;

    // if node is empty, do not remove anything
    // else update head pointer and delete node
    if ( isEmpty() ) {
        cout << "There are no nodes in the queue\n";
    }
    else {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/*********************************************************************
** Description:     this function traverses through the queue
**                  starting from the head using the next pointer and
**                  prints the values of each node in the queue.
*********************************************************************/
void Queue::printQueue() {
    QueueNode *temp = head;

    if (isEmpty()) {
        cout << "The queue is empty\n";
    }
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

/*********************************************************************
** Description:     this function checks if the que is empty and if
**                  it is, then it returns true otherwise it returns
**                  false
*********************************************************************/
bool Queue::isEmpty() {
    if (head == nullptr) { return true; }
    else { return false; }
}