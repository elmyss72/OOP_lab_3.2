
#include "pch.h"
#include "CppUnitTest.h"

#include "../OOP_lab_3.2/Deque.cpp"
#include "../OOP_lab_3.2/Queue.cpp"
#include "../OOP_lab_3.2/Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DequeUnitTests
{

    TEST_CLASS(DequeTests)
    {
    public:

        // Перевірка конструктора
        TEST_METHOD(ConstructorTest)
        {
            Deque d(5);

            Assert::AreEqual(5, d.getCapacity());
            Assert::AreEqual(0, d.getSize());
            Assert::IsTrue(d.isEmpty());
            Assert::IsFalse(d.isFull());
        }

        // Перевірка pushBack()
        TEST_METHOD(PushBackTest)
        {
            Deque d(3);

            d.pushBack(10);
            d.pushBack(20);

            Assert::AreEqual(2, d.getSize());
            Assert::AreEqual(10, d.popFront());
            Assert::AreEqual(20, d.popFront());
            Assert::IsTrue(d.isEmpty());
        }

        // Перевірка pushFront()
        TEST_METHOD(PushFrontTest)
        {
            Deque d(3);

            d.pushFront(10);
            d.pushFront(20);

            Assert::AreEqual(20, d.popFront());
            Assert::AreEqual(10, d.popFront());
        }

        // Перевірка popBack()
        TEST_METHOD(PopBackTest)
        {
            Deque d(3);

            d.pushBack(10);
            d.pushBack(20);
            d.pushBack(30);

            Assert::AreEqual(30, d.popBack());
            Assert::AreEqual(20, d.popBack());
            Assert::AreEqual(10, d.popBack());
            Assert::IsTrue(d.isEmpty());
        }

        // Перевірка циклічного масиву
        TEST_METHOD(CircularBufferTest)
        {
            Deque d(3);

            d.pushBack(10);
            d.pushBack(20);
            d.pushBack(30);

            Assert::AreEqual(10, d.popFront());

            d.pushBack(40);

            Assert::AreEqual(20, d.popFront());
            Assert::AreEqual(30, d.popFront());
            Assert::AreEqual(40, d.popFront());
        }

        // Перевірка збільшення місткості
        TEST_METHOD(SetCapacityTest)
        {
            Deque d(2);

            d.pushBack(10);
            d.pushBack(20);

            d.setCapacity(5);

            Assert::AreEqual(5, d.getCapacity());
            Assert::AreEqual(2, d.getSize());
            Assert::AreEqual(10, d.popFront());
            Assert::AreEqual(20, d.popFront());
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(CopyConstructorTest)
        {
            Deque original(5);

            original.pushBack(10);
            original.pushBack(20);

            Deque copy(original);

            Assert::AreEqual(5, copy.getCapacity());
            Assert::AreEqual(2, copy.getSize());

            Assert::AreEqual(10, copy.popFront());
            Assert::AreEqual(20, copy.popFront());

            // Оригінал не повинен змінитися
            Assert::AreEqual(2, original.getSize());
        }

        // Перевірка оператора присвоювання
        TEST_METHOD(AssignmentOperatorTest)
        {
            Deque original(5);
            original.pushBack(100);
            original.pushBack(200);

            Deque copy(2);
            copy = original;

            Assert::AreEqual(5, copy.getCapacity());
            Assert::AreEqual(2, copy.getSize());

            Assert::AreEqual(100, copy.popFront());
            Assert::AreEqual(200, copy.popFront());
        }
    };


    // ==================== STACK TESTS ====================

    TEST_CLASS(StackTests)
    {
    public:

        // Перевірка конструктора
        TEST_METHOD(StackConstructorTest)
        {
            Stack s(5);

            Assert::AreEqual(5, s.getCapacity());
            Assert::AreEqual(0, s.getSize());
            Assert::IsTrue(s.isEmpty());
        }

        // Перевірка принципу LIFO
        TEST_METHOD(StackLIFOTest)
        {
            Stack s(5);

            s.push(10);
            s.push(20);
            s.push(30);

            Assert::AreEqual(30, s.pop());
            Assert::AreEqual(20, s.pop());
            Assert::AreEqual(10, s.pop());

            Assert::IsTrue(s.isEmpty());
        }

        // Перевірка заповнення стеку
        TEST_METHOD(StackFullTest)
        {
            Stack s(2);

            s.push(10);
            s.push(20);

            Assert::IsTrue(s.isFull());
            Assert::AreEqual(2, s.getSize());
        }
    };


    // ==================== QUEUE TESTS ====================

    TEST_CLASS(QueueTests)
    {
    public:

        // Перевірка конструктора
        TEST_METHOD(QueueConstructorTest)
        {
            Queue q(5);

            Assert::AreEqual(5, q.getCapacity());
            Assert::AreEqual(0, q.getSize());
            Assert::IsTrue(q.isEmpty());
        }

        // Перевірка принципу FIFO
        TEST_METHOD(QueueFIFOTest)
        {
            Queue q(5);

            q.enqueue(10);
            q.enqueue(20);
            q.enqueue(30);

            Assert::AreEqual(10, q.dequeue());
            Assert::AreEqual(20, q.dequeue());
            Assert::AreEqual(30, q.dequeue());

            Assert::IsTrue(q.isEmpty());
        }

        // Перевірка заповнення черги
        TEST_METHOD(QueueFullTest)
        {
            Queue q(2);

            q.enqueue(10);
            q.enqueue(20);

            Assert::IsTrue(q.isFull());
            Assert::AreEqual(2, q.getSize());
        }
    };
}
