#include "Stack.h"

// Виклик базового конструктора
Stack::Stack(int cap) : Deque(cap) {}

// Реалізація методів стеку через успадковані методи базового класу
void Stack::push(int value) {
    pushBack(value);
}

int Stack::pop() {
    return popBack();
}