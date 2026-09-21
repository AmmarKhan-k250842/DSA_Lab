#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    Node *next;
    int data;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class linkedList
{
    private:
    Node *head;
    Node *tail;

    public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(int val)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtBack(int val)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void insertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        Node *temp = head;
        for(int i = 1; i < pos; i++)
        {
            if(temp == NULL)
            {
                cout << "Invalid Position" << endl;
                delete temp;
                delete newNode;
            }

            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid Position" << endl;
            delete temp;
            delete newNode;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == tail)
        {
            tail = newNode;
            tail->next = head;
        }
    }

    void deleteByValue(int val)
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if(head->data == val && head == tail)
        {
            head == NULL;
            tail == NULL;
            return;
        }

        if(head->data == val)
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        Node *prev = head;
        Node *curr = head->next;

        while(curr != head)
        {
            if(curr->data == val)
            {
                prev->next = curr->next;
                if(curr == tail)
                {
                    tail = prev;
                    tail->next = head;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Value Not found" << endl;
    }

    void search(int key)
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;

        do
        {
            if(temp->data == key)
            {
                cout << "Found" << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Not Found" << endl;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;

        cout << endl;
        do
        {
            cout << temp->data << "  -->  ";
            temp = temp->next;
        }
        while(temp != head);
    }
};


int main()
{
    linkedList cll;

    cll.insertAtBack(10);
    cll.insertAtBack(20);
    cll.insertAtBack(30);
    cll.insertAtFront(5);

    cout << "List: ";
    cll.display();               // 5 10 20 30

    cll.insertAtPosition(15, 3);
    cout << "After insert 15 at position 3: ";
    cll.display();                // 5 10 15 20 30

    cll.deleteByValue(10);
    cout << "After deleting 10: ";
    cll.display();                // 5 15 20 30

    cll.search(20);
    cll.search(99);

    return 0;
}