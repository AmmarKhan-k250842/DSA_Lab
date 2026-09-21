#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
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


    void insertAtBack(int val)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtFront(int val)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);

        if(pos == 1)
        {
            newNode->next = head;
            head = newNode;

            if(tail == NULL)
            {
                tail = newNode;
            }
            return;
        }

        Node *temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            if(temp == NULL)
            {
                cout << "Inavlid Index" << endl;
                delete newNode;
                return;
            }

            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Inavlid Index" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        
        if(newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    void deleteFromStart()
    {
        if(head == NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;

        if(head == NULL)
        {
            tail = NULL;
        }
    }

    void deleteFromBack()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        
        delete tail;
        temp->next == NULL;
        tail = temp;
    }

    void deleteFromPosition(int pos)
    {
        if(head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        if(pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if(head = NULL)
            {
                tail = NULL;
            }
        }

        Node *temp = head;
        for(int i = 0; i < pos - 1; i++)
        {
            if(temp->next == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        Node *toDelete = temp;
        if(toDelete == NULL)
        {
            cout << "Invalid Position" << endl;
        }
        if(toDelete == tail)
        {
            tail = temp;
        }

        temp->next = temp->next;
        delete toDelete;
    }

    void printList()
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
    }
};