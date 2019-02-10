/*********************************************************************
** Program name: 		LAB 7 - Linked List
** Author: 				Sandro Aguilar
** Date: 				02/20/2019
** Description:         Menu class description here
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
    void addBack();
    void removeFront();
    void getFront();
    void printQueue();

private:
    Menu menu;
    bool showMenu;

};

#endif // LAB7_QUEUE_HPP
