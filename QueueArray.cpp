#include <iostream>

class Queue
{
private:
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    const static int size = 10;
    int array[size];
    int front = -1;
    int rear = -1;

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "queue is full"
                      << "\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            // array[rear] = value;
        }
        else
        {
            rear = (rear + 1) % size;
            // array[rear] = value;
        }
        array[rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "queue is empty"
                      << "\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void print()
    {
        if (front != -1 && rear != -1)
        {
            for (int i = front; i <= rear; i++)
            {
                std::cout << array[i] << "\t";
            }
        }
        else
        {
            std::cout << "queue is empty";
        }

        std::cout << "\n";
    }
};

int main()
{
    Queue *queue = new Queue;
    queue->print();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);
    queue->enqueue(50);
    queue->enqueue(60);
    queue->print();
    queue->dequeue();
    queue->dequeue();
    queue->print();
    queue->enqueue(70);
    queue->enqueue(80);
    queue->enqueue(90);
    queue->enqueue(100);
    queue->enqueue(110);
    queue->enqueue(120);
    queue->enqueue(130);
    std::cout << queue->array[queue->front] << "\t" << queue->array[queue->rear] << "\n";
    delete (queue);
}
