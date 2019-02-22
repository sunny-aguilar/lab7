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
Queue::Queue() : head{nullptr} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Queue::~Queue() {
    QueueNode *nodePtr = head;
    do {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    } while (nodePtr != nullptr && nodePtr != head);
}

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
    } while ( menu.getMenuControl() );
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
            menu.setMenuControl(false);
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
        head->prev = head;
        head->next = head;
    }
    else {
        // create a new node
        QueueNode *newNode = new QueueNode(num);
        // get the head node
        QueueNode *headNode = head;
        // new node next pointer point to head node
        newNode->next = headNode;
        // get node behind head node
        QueueNode *oldBack = head->prev;
        // new node prev pointer point to node behind head
        newNode->prev = oldBack;
        // node behind head next point to new node
        oldBack->next = newNode;
        // connect head node previous to new node
        head->prev = newNode;
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
** Description:     removes the head node of the queue, if it exist
**                  otherwise it prompts user that there are no nodes
**                  to be removed.
*********************************************************************/
void Queue::removeFront() {
    // if node is empty, do not remove anything
    // else update head pointer and delete node
    if ( isEmpty() ) {
        cout << "There are no nodes in the queue\n";
    }
    else {
        // assign new head node and assign it the next node from head
        QueueNode *oldHead = head;
        QueueNode *newHead = nullptr;
        newHead = head->next;

        // if the next node is not the head node i.e., there is
        // only one node, then connect the last node to the new node
        // and connect the new node ->prev to the last node
        if (newHead != oldHead) {
            // connect new head node to last node
            newHead->prev = oldHead->prev;

            // connect last node to the new head node
            QueueNode *last = head->prev;
            last->next = newHead;

            // point head pointer to the new head
            head = newHead;
        }
        else {
            // if only one node, remove it
            head = nullptr;
        }
        delete oldHead;
    }
}

/*********************************************************************
** Description:     this function traverses through the queue
**                  starting from the head using the next pointer and
**                  prints the values of each node in the queue. The
**                  user is alerted if no nodes exist however, if 1
**                  or more nodes exist, then the list is traversed
**                  until it reaches the head node.
*********************************************************************/
void Queue::printQueue() {
    bool ref = true;
    QueueNode *temp = head;

    if (isEmpty()) {
        cout << "The queue is empty!\n";
        return;
    }
    else {
        while (ref) {
            cout << temp->val << " ";
            temp = temp->next;
            if (temp == head) {
                ref = false;
            }
        }
    }
}

/*********************************************************************
** Description:     this function checks if the queue is empty and if
**                  it is, then it returns true otherwise it returns
**                  false
*********************************************************************/
bool Queue::isEmpty() {
    if (!head) { return true; }
    else { return false; }
}