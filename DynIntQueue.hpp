/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Menu class description here
*********************************************************************/
#ifndef LAB7_DYNINTQUEUE_HPP
#define LAB7_DYNINTQUEUE_HPP

#include <iostream>
using std::endl;
using std::cout;

class DynIntQueue {
private:
    struct QueueNode {
        int value;
        QueueNode *next;
        QueueNode(int value1, QueueNode *next1 = nullptr) {
            value = value1;
            next = next1;
        }
    };
    // These track the front and rea of the queue
    QueueNode *front;
    QueueNode *rear;

public:
    // Constructor and Destructor
    DynIntQueue();
    ~DynIntQueue();

    // member functions
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    void clear();
};

#endif //LAB7_DYNINTQUEUE_HPP
