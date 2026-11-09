#include <iostream>
#include "Deque.h"
#include "Stack.h"
#include "Queue.h"

// Функція, що одержує і повертає об'єкт базового класу
// Демонструє принцип підстановки (Liskov Substitution Principle)
Deque processBase(Deque obj) {
    std::cout << "\n[Function processBase] Object received. State: " << obj << std::endl;
    if (!obj.isFull()) {
        int val;
        std::cout << "[Function processBase] Enter a value to add to the front of the deque (pushFront): ";
        std::cin >> val;
        obj.pushFront(val);
    }
    else {
        std::cout << "[Function processBase] Object is full, skipping addition." << std::endl;
    }
    return obj;
}

int main() {
    int capacity, value, count;

    std::cout << "=== 1. Static and dynamic creation of base class objects (Deque) ===" << std::endl;

    std::cout << "Enter capacity for the static Deque object: ";
    std::cin >> capacity;
    Deque d1(capacity);
    std::cout << "Enter value to push to the back (pushBack): ";
    std::cin >> value;
    d1.pushBack(value);
    std::cout << "Static object d1: " << d1 << std::endl;

    std::cout << "\nEnter capacity for the dynamic Deque object: ";
    std::cin >> capacity;
    Deque* dPtr = new Deque(capacity); // Виправлено синтаксичну помилку
    std::cout << "Enter value to push to the front (pushFront): ";
    std::cin >> value;
    dPtr->pushFront(value);
    std::cout << "Dynamic object dPtr: " << *dPtr << std::endl;
    delete dPtr;

    std::cout << "\n=== 2. Working with the derived class Stack (LIFO) ===" << std::endl;
    std::cout << "Enter capacity for the Stack: ";
    std::cin >> capacity;
    Stack myStack(capacity);
    std::cout << "How many elements to add to the Stack? ";
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        myStack.push(value);
    }
    std::cout << "Stack after addition: " << myStack << std::endl;
    if (!myStack.isEmpty()) {
        std::cout << "Popped from Stack: " << myStack.pop() << std::endl;
    }

    std::cout << "\n=== 3. Working with the derived class Queue (FIFO) ===" << std::endl;
    std::cout << "Enter capacity for the Queue: ";
    std::cin >> capacity;
    Queue myQueue(capacity);
    std::cin >> myQueue; // Використання перевантаженого оператора вводу
    std::cout << "Queue after input operations: " << myQueue << std::endl;
    if (!myQueue.isEmpty()) {
        std::cout << "Dequeued from Queue: " << myQueue.dequeue() << std::endl;
    }

    std::cout << "\n=== 4. Creation of object arrays ===" << std::endl;
    std::cout << "Creating an array of 3 stacks. Enter capacity for each of them:" << std::endl;
    int cap1, cap2, cap3;
    std::cout << "Stack 1: "; std::cin >> cap1;
    std::cout << "Stack 2: "; std::cin >> cap2;
    std::cout << "Stack 3: "; std::cin >> cap3;

    Stack stackArr[3] = { Stack(cap1), Stack(cap2), Stack(cap3) };
    for (int i = 0; i < 3; i++) {
        std::cout << "Enter 1 number to store in Stack [" << i << "]: ";
        std::cin >> value;
        stackArr[i].push(value);
        std::cout << "Content of Stack [" << i << "]: " << stackArr[i] << std::endl;
    }

    std::cout << "\n=== 5. Demonstration of Liskov Substitution Principle ===" << std::endl;
    std::cout << "Passing derived class Stack to processBase function, which expects a base Deque." << std::endl;
    Deque resultDeque = processBase(myStack);
    std::cout << "[main] Result after returning from function: " << resultDeque << std::endl;

    std::cout << "\n=== 6. Demonstration of Setter methods with validation ===" << std::endl;
    std::cout << "Current capacity of result: " << resultDeque.getCapacity() << std::endl;
    std::cout << "Enter new (larger) capacity: ";
    std::cin >> capacity;
    resultDeque.setCapacity(capacity);
    std::cout << "Success! New capacity: " << resultDeque.getCapacity() << std::endl;

    std::cout << "\n=== 7. Demonstration of validation error generation ===" << std::endl;
    std::cout << "Enter an invalid capacity (e.g., negative number or 0) to test error handling: ";
    std::cin >> capacity;
    // Цей виклик завершить роботу програми через std::exit(1)
    resultDeque.setCapacity(capacity);

    return 0;
}