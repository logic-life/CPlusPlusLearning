#include <vector>


class MyCircularQueue
{
private:
    std::vector<int> buffer;
    int front;
    int end;
    int size;

public:
    MyCircularQueue(int k)
    {
        buffer.resize(k + 1);
        front = 0;
        end = 0;
        size = k + 1;
    }

    bool enQueue(int value)
    {
        if (this->isFull())
        {
            return false;
        }
        buffer[end] = value;
        end = (end + 1) % size;
        return true;
    }

    bool deQueue()
    {
        if (this->isEmpty())
        {
            return false;
        }
        front += 1;
        front %= size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return buffer[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return buffer[(end - 1 + size) % size];
    }

    bool isEmpty()
    {
        return front == end;
    }

    bool isFull()
    {
        if (((end + 1 + size) % size) == front)
        {
            return true;
        }
        return false;
    }
};

