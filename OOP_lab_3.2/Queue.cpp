#include "Queue.h"

// Виклик базового конструктора
Queue::Queue(int cap) : Deque(cap) {}

// Реалізація методів черги через успадковані методи базового класу
void Queue::enqueue(int value) {
    pushBack(value);
}

int Queue::dequeue() {
    return popFront();
}