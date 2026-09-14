#include <iostream>
#include <string>
using namespace std;


#define MAX 5


class stack
{
	private:
	int top;
	int arr[MAX];
	
	public:
	stack()
	{
		top = -1;	
	}	
	
	bool isFull()
	{
		if (top == MAX - 1)
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
		if(top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(int val)
	{
		if(isFull() == true)
		{
			cout << "Stack is full" << endl;
			return;
		}
		
		top++;
		arr[top] = val;
	}
	
	void pop()
	{
		if(isEmpty() == true)
		{
			cout << "Stack is already empty" << endl;
			return;
		}
		
		cout << "Popped: " << arr[top] << endl;
		top--;
	}
	
	int peek()
	{
		if(isEmpty() == true)
		{
			cout << "Stack is Empty" << endl;
			return 0;
		}
		
		return arr[top];
	}
};


int main()
{
	stack s;
	s.push(10);   // pile: [10]
	s.push(20);   // pile: [10, 20]
	s.push(30);   // pile: [10, 20, 30]  <- 30 is on top
	s.peek();     // shows 30 (top pancake)
	s.pop();      // removes and shows 30. pile: [10, 20]
	s.pop();      // removes and shows 20. pile: [10]
	cout << "Top: " << s.peek() << endl;     // shows 10
}


















