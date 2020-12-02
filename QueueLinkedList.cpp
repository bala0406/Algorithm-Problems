#include <iostream>

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

public:
    Node *front = NULL;
    Node *rear = NULL;

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (front == rear)
        {
            free(rear);
            free(front);
        }
        else
        {
            Node *temp = front;
            front = temp->next;
            free(temp);
        }
    }

    void print()
    {
        if (front != NULL && rear != NULL)
        {
            Node *currentNode = front;
            while (currentNode != rear)
            {
                std::cout << currentNode->data << "\t";
                currentNode = currentNode->next;
            }
            std::cout << currentNode->data << "\n";
        }
    }
};

int main()
{
    Queue *queue = new Queue;
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6);
    queue->print();
    queue->dequeue();
    queue->dequeue();
    queue->print();
}
