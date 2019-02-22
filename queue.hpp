/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Queue class implements a circular linked list
**                      where the tail pointer points back to the
**                      front of the list. Node is declared as a
**                      in the queue class declaration.
*********************************************************************/
#ifndef LAB7_QUEUE_HPP
#define LAB7_QUEUE_HPP

#include "menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

class Queue {
public:
    Queue();
    ~Queue();
    void startQueue();
    void queueFlow();
    void queueOperations();
    void addBack(int num);
    void removeFront();
    void getFront();
    void printQueue();
    bool isEmpty();

private:
    // menu object show menu
    Menu menu;
    // QueueNode
    struct QueueNode {
        QueueNode *next;
        QueueNode *prev;
        int val;
        QueueNode(int val, QueueNode *next = nullptr, QueueNode *prev = nullptr) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };
    // data member
    QueueNode *head;
};

#endif // LAB7_QUEUE_HPP