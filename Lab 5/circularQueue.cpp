#include <iostream>
#include <string>
using namespace std;


# define MAX 5


class circularQueue
{
    private:
    int front;
    int rear;
    int arr[MAX];

    public:
    circularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if(front == -1)
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
        if((rear + 1) % MAX == front)
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
        if(isFull() == true)
        {
            cout << "Queue Full" << endl;
            return;
        }
        if(isEmpty() == true)
        {
            front = 0;
        } 

        rear = (rear + 1) % MAX;
        arr[rear] = val;

        cout << "Enqueued: " << val << endl;
    }

    void Dequeue()
    {
        if(isEmpty() == true)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int x = arr[front];
        front = (front + 1) % MAX;

        cout << "Dequeued: " << x << endl;
    }

    void peek()
    {
        if(isEmpty() == true)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
    }

    void display()
    {
        if(isEmpty() == true)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;

        while(1)
        {
            cout << i << ": " << arr[i] << "   ";

            if(i == rear)
            {
                break;
            }

            i = (i + 1) % MAX;
        }
    }
};


int main()
{
    circularQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.display();

    q.Dequeue(); 
    q.Dequeue(); 

    q.Enqueue(60);
    q.Enqueue(70);

    q.display();

    return 0;
}