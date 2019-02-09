//
// Created by Sandro on 2/9/2019.
//
#include "DynIntQueue.hpp"

DynIntQueue::DynIntQueue() {
    front = nullptr;
}

DynIntQueue::~DynIntQueue() {
    QueueNode *garbage = front;
    while (garbage != nullptr) {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

void DynIntQueue::enqueue(int num) {
    if (isEmpty()) {
        front = new QueueNode(num);
        rear = front;
    }
    else {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

void DynIntQueue::dequeue(int &num) {
    QueueNode *temp = nullptr;
    if (isEmpty()) {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool DynIntQueue::isEmpty() const {
    if (front == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void DynIntQueue::clear() {
    int value;

    while (!isEmpty()) {
        dequeue(value);
    }
}