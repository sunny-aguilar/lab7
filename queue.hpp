/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Menu class provides the driver program to
**                      interact with the
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
    Menu menu;
    bool showMenu;
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
    QueueNode *head;
    QueueNode *tail;
};

#endif // LAB7_QUEUE_HPP
