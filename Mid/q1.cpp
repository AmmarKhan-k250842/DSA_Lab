#include <iostream>
#include <string>
using namespace std;


/*
1. A cinema has a single ticket counter with a limited waiting area. Customers
arriving at the counter receive a customer ID and request a certain number of
tickets. The waiting area has a fixed number of spaces and operates
continuously throughout the day. Whenever the counter becomes free, the
customer who has been waiting the longest is served. A customer who cannot be
served because the requested number of tickets is unavailable leaves the waiting
area. New customers continue arriving throughout the day, including after earlier
customers have left. The waiting area is implemented using an array, but
customers should be able to occupy spaces that became free earlier, even when
the end of the array has already been reached. At a particular moment, the
manager wants to know the customer currently at the front, the customer
currently at the rear, and the number of customers waiting.
*/


# define MAX 5

class customer
{
    private:
    int ID;
    int tickets;

    public:
    customer() : ID(0), tickets(0) {} 
    customer(int i, int t) : ID(i), tickets(t) {}

    int getID() {return ID;}
    int getTickets() {return tickets;}
};  


class Queue
{
    private:
    int front;
    int rear;
    int count;
    customer arr[MAX];

    public:
    Queue() : front(-1), rear(-1),  count(0) {}

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

    void Enqueue(customer val)
    {
        if(isFull() == true)
        {
            cout << "Room is full" << endl;
            return;
        }

        if(front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = val;
        count++;

        cout << "Enqueued: " << arr[rear].getID() << endl;
    }

    void Dequeue()
    {
        if(isEmpty() == true)
        {
            cout << "No one to remove" << endl;
            return;
        }

        customer temp = arr[front];
        front = (front + 1) % MAX;
        count--;

        cout << "Dequeued: " << temp.getID() << endl; 
    }

    void Serve(int &ticketsLeft)
    {
        if(isEmpty() == true)
        {
            cout << "No one is waiting" << endl;
            return;
        }

        customer temp = arr[front];

        if(temp.getTickets() < ticketsLeft)
        {
            ticketsLeft = ticketsLeft - temp.getTickets();
            cout << "Tickets given" << endl;
            Dequeue();
        }
        else
        {
            cout << "Customer wanted more tickets then tickets left" << endl;
        }
    }

    void status()
    {
        cout << "Front: " << arr[front].getID() << endl;
        cout << "Rear: " << arr[rear].getID() << endl;
        cout << "Waiting: " << count << endl;
    }
};


int main()
{
    Queue q;
    int ticketsLeft = 10;

    q.Enqueue(customer(1, 3));
    q.Enqueue(customer(2, 4));
    q.Enqueue(customer(3, 5));   
    q.status();

    q.Serve(ticketsLeft);        
    q.Serve(ticketsLeft);        
    q.Serve(ticketsLeft);  
    q.status();               
}