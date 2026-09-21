#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
    private:
    Node *rear;
    Node *front;

    public:
    Queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty()
    {
        if(front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue(int val)
    {
        Node *newNode = new Node(val);

        if(isEmpty() == true)
        {
            front = newNode;
            rear = newNode;
            cout << "Enqueued: " << newNode->data << endl;
            return;
        }

        rear->next = newNode;
        rear = newNode;

        cout << "Enqueued: " << newNode->data << endl;
    }

    void Dequeue()
    {
        Node *temp = front;

        if(isEmpty() == true)
        {
            cout << "Queue is empty" << endl;
            delete temp;
            return;
        }

        if(front == rear)
        {
            front = rear = NULL;
            delete temp;
            return;
        }

        front = front->next;

        delete temp;
    }

    void peek()
    {
        if(isEmpty() == true)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front: " << front->data << endl;
        cout << "Rear: " << rear->data << endl;
    }
};


int main()
{
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.peek();

    q.Dequeue();
    q.peek();

    q.Dequeue();
    q.peek();

    q.Dequeue();
    q.peek();

    return 0;
}