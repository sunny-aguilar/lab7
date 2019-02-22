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
    bool showMenu = true;
    do {
        startMenu();

        showMenu = queueOperations();

    } while ( showMenu );
}

/*********************************************************************
** Description:     function provides a switch statement that performs
**                  queue operations.
*********************************************************************/
bool Queue::queueOperations() {
    switch (validateNumber(1,5)) {
        case 1:
            addValue();
            addBack( validateNumber(1, 2000) );
            cout << endl << endl;
            return true;
        case 2:
            displayFirstNode();
            getFront();
            cout << endl << endl;
            return true;
        case 3:
            removeFirstNode();
            removeFront();
            cout << endl << endl;
            return true;
        case 4:
            displayQueueContents();
            printQueue();
            cout << endl << endl;
            return true;
        case 5:
            return false;
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

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Queue::startMenu() {
    cout << "WELCOME TO MY QUEUE!\n";
    cout << "+--------------------------------------------------+\n";
    cout << "Choose from the following options:\n";
    cout << "1. Enter a value to be added to the back of queue\n";
    cout << "2. Display first node (front) value\n";
    cout << "3. Remove first node (front) value\n";
    cout << "4. Display the queue contents\n";
    cout << "5. Exit\n";
}

/*********************************************************************
** Description:     prompts user to enter a value to add to the back
**                  of the queue
*********************************************************************/
void Queue::addValue() {
    cout << "+--------------------------------------------------+\n";
    cout << "Enter a positive integer:\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays the head node value
*********************************************************************/
void Queue::displayFirstNode() {
    cout << "+--------------------------------------------------+\n";
    cout << "Head Node Value is: ";
}

/*********************************************************************
** Description:     displays to user that head node is being
**                  removed
*********************************************************************/
void Queue::removeFirstNode() {
    cout << "+--------------------------------------------------+\n";
    cout << "Removing the first node\n";
}

/*********************************************************************
** Description:     displays to user the queue contents
*********************************************************************/
void Queue::displayQueueContents() {
    cout << "+--------------------------------------------------+\n";
    cout << "Your queue is: ";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Queue::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}