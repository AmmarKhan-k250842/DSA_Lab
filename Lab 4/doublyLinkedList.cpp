#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    Node *next;
    Node *prev;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtBack(int val)
    {
        Node *newNode = new Node(val);

        if(tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);

        if(pos == 1)
        {
            insertAtFront(val);
            delete newNode;
            return;
        }

        Node *temp = head;
        for(int i = 1; i < pos - 1; i++)
        {
            if(temp == NULL)
            {
                cout << "Invalid position" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        temp->next = newNode->next;
        newNode->prev = temp;

        if(temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        temp->next = newNode;
    }

    void deleteFromStart()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }

        delete temp;
    }

    void deleteFromBack()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if(tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }

        delete temp;
    }

    void deleteFromPosition(int pos)
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        for(int i = 1; i < pos; i++)
        {
            if(temp == NULL)
            {
                cout << "Invalid position" << endl;
                delete temp;
                return;
            }

            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid position" << endl;
            delete temp;
            return;
        }

        if(temp == tail)
        {
            deleteFromBack();
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int val)
    {
        Node *temp = head;
        while(temp != NULL)
        {
            if(temp->data == val)
            {
                cout << "Found" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Not Found" << endl;
    }

    void display()
    {
        int count = 1;
        Node *temp = head;

        cout << endl;
        while(temp != NULL)
        {
            cout << count << ": " << temp->data << "  -->  ";
            count++;
            temp = temp->next;
        }

        cout << endl;
    }
};


int main() {
    linkedList dll;

    dll.insertAtBack(10);
    dll.insertAtBack(20);
    dll.insertAtBack(30);
    dll.insertAtFront(5);

    cout << "Forward: ";
    dll.display();  

    dll.insertAtPosition(15, 3);
    cout << "After insert 15 at position 3: ";
    dll.display();   

    dll.deleteFromPosition(1);
    cout << "After deleting position 1: ";
    dll.display();   

    dll.search(20);
    dll.search(99);

    return 0;
}