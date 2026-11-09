#pragma once
#include "Deque.h"

// Звичайна черга (FIFO) на базі черги з двома кінцями
class Queue : public Deque {
public:
    // Конструктор
    Queue(int cap = 10);

    // Специфічні методи черги
    void enqueue(int value);
    int dequeue();
};