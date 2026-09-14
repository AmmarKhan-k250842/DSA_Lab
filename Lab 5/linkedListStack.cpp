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

class stack
{
	private:
	Node *top;
	
	public:
	stack()
	{
		top = NULL;	
	}	
	
	bool isEmpty()
	{
		if(top == NULL)
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
		Node *newNode = new Node(val);
		newNode->next = top;
		top = newNode;
		
		cout << "Pushed: " << newNode->data << endl;
	}
	
	void pop()
	{
		if(isEmpty() == true)
		{
			cout << "List is empty" << endl;
			return;
		}
		
		cout << "Popped: " << top->data << endl;
		
		Node *temp = top;
		top = top->next;
		delete temp;
	}
	
	void peek()
	{
		if(isEmpty() == true)
		{
			cout << "List empty" << endl;
		}
		
		cout << "Top: " << top->data << endl;
	}
};


int main()
{
	stack s;
    s.push(1);
    s.push(2);
    s.push(3);

 	s.peek(); 
 	s.pop();
	s.pop();
 	s.peek(); 

    return 0;
}















