#include <iostream>
#include <string>
using namespace std;


#define MAX 5


class queue
{
	private:
	int front;
	int rear;
	int arr[MAX];
	
	public:
	queue()
	{
		front = -1;
		rear = -1;	
	}	
	
	bool isFull()
	{
		if(rear == MAX - 1)
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
	
	void enqueue(int val)
	{
		if(isFull() == true)
		{
			cout << "Queue is full" << endl;
			return;
		}
		
		if(front == -1)
		{
			front = 0;
		}
		
		rear++;
		arr[rear] = val;
		
		cout << "Enqueued: " << val << endl;
	}
	
	void dequeue()
	{
		if(isEmpty() == true)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		
		cout << "Dequeued: " << arr[front] << endl;
		front++;
	}
	
	void peek()
	{
		if(isEmpty() == true)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		
		cout << "Front: " << arr[front] << endl;
		cout << "Rear: " << arr[rear] << endl;
	}
};


int main()
{
	queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

	q.peek(); 
  	q.dequeue(); 
	q.dequeue();
	q.peek();
	
	return 0; 
}














