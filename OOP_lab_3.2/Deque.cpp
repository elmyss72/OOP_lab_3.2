#include "Deque.h"
#include <iostream>

// Конструктор з перевіркою параметрів на коректність
Deque::Deque(int cap) : size(0), front(0) {
    if (cap <= 0) {
        std::cerr << "Error: Queue capacity must be greater than 0!" << std::endl;
        std::exit(1); // Завершення роботи при неправильних даних
    }
    capacity = cap;
    rear = capacity - 1;
    data = new int[capacity];
}

// Конструктор копіювання
Deque::Deque(const Deque& other)
    : capacity(other.capacity), size(other.size),
    front(0), rear(other.size - 1)
{
    data = new int[capacity];

    for (int i = 0; i < size; ++i) {
        data[i] = other.data[(other.front + i) % other.capacity];
    }
}

// Деструктор
Deque::~Deque() {
    delete[] data;
}

// Оператор присвоювання
Deque& Deque::operator=(const Deque& other) {
    if (this != &other) {
        int* newData = new int[other.capacity];

        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[
                (other.front + i) % other.capacity
            ];
        }

        delete[] data;

        data = newData;
        capacity = other.capacity;
        size = other.size;
        front = 0;
        rear = size - 1;
    }

    return *this;
}

int Deque::getCapacity() const { return capacity; }
int Deque::getSize() const { return size; }
bool Deque::isEmpty() const { return size == 0; }
bool Deque::isFull() const { return size == capacity; }

// Сеттер з неможливістю обійти валідацію
void Deque::setCapacity(int newCap) {
    if (newCap <= 0) {
        std::cerr << "Error: Queue capacity must be greater than 0!" << std::endl;
        std::exit(1);
    }
    if (newCap < size) {
        std::cerr << "Error: New capacity is less than the current number of elements!" << std::endl;
        std::exit(1);
    }

    // Перевиділення пам'яті (виправлено синтаксичну помилку intnewData)
    int* newData = new int[newCap];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[(front + i) % capacity];
    }
    delete[] data;
    data = newData;
    capacity = newCap;
    front = 0;
    rear = size - 1;
}

void Deque::pushFront(int value) {
    if (isFull()) {
        std::cerr << "Error: Queue is full (pushFront)!" << std::endl;
        std::exit(1);
    }
    front = (front - 1 + capacity) % capacity;
    data[front] = value;
    size++;
}

void Deque::pushBack(int value) {
    if (isFull()) {
        std::cerr << "Error: Queue is full (pushBack)!" << std::endl;
        std::exit(1);
    }
    rear = (rear + 1) % capacity;
    data[rear] = value;
    size++;
}

int Deque::popFront() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty (popFront)!" << std::endl;
        std::exit(1);
    }
    int value = data[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

int Deque::popBack() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty (popBack)!" << std::endl;
        std::exit(1);
    }
    int value = data[rear];
    rear = (rear - 1 + capacity) % capacity;
    size--;
    return value;
}

// Приведення типу до літерного рядку
Deque::operator std::string() const {
    std::string result = "Deque: [ ";
    for (int i = 0; i < size; ++i) {
        result += std::to_string(data[(front + i) % capacity]) + " ";
    }
    result += "]";
    return result;
}

// Операція виводу
std::ostream& operator<<(std::ostream& out, const Deque& d) {
    out << std::string(d);
    return out;
}

// Операція вводу (інтерактивна для користувача)
std::istream& operator>>(std::istream& in, Deque& d) {
    int elementsToRead;
    std::cout << "How many elements would you like to add? (maximum " << (d.getCapacity() - d.getSize()) << "): ";
    in >> elementsToRead;

    if (elementsToRead + d.getSize() > d.getCapacity()) {
        std::cerr << "Error: Not enough space to add this many elements!" << std::endl;
        std::exit(1);
    }

    for (int i = 0; i < elementsToRead; ++i) {
        int val;
        std::cout << "Enter value " << i + 1 << ": ";
        in >> val;
        d.pushBack(val);
    }
    return in;
}