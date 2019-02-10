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
    void startQueue();
    void queueFlow();

private:
    Menu menu;

};

#endif // LAB7_QUEUE_HPP
