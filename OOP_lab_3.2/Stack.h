#pragma once
#include "Deque.h"

// Стек (LIFO) на базі черги з двома кінцями
class Stack : public Deque {
public:
    // Конструктор
    Stack(int cap = 10);

    // Специфічні методи стеку
    void push(int value);
    int pop();
};