#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Deque {
private:
    int* data;      
    int capacity;
    int size;
    int front;
    int rear;

public:
    // Конструктор з параметром за замовчуванням
    Deque(int cap = 10);

    // Конструктор копіювання
    Deque(const Deque& other);

    // Деструктор
    ~Deque();

    // Оператор присвоювання
    Deque& operator=(const Deque& other);

    // Методи отримання значень 
    int getCapacity() const;
    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;

    // Метод встановлення значення (сеттер) з жорсткою валідацією
    void setCapacity(int newCap);

    // Додавання та вилучення з обох кінців
    void pushFront(int value);
    void pushBack(int value);
    int popFront();
    int popBack();

    // Перетворення до літерного рядку 
    operator std::string() const;

    // Операції вводу/виводу
    friend std::ostream& operator<<(std::ostream& out, const Deque& d);
    friend std::istream& operator>>(std::istream& in, Deque& d);
};