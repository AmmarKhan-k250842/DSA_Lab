#include <iostream>
#include <string>
using namespace std;


/*
2. Develop the required system using circular queue and demonstrate its behavior
for a sequence of customer arrivals, ticket processing, and departures. A
museum has security guards positioned around a circular exhibition hall. Each
guard is represented by a node containing a Guard ID and a security level. The
guards remain connected in a circle throughout the night. At the end of each
inspection round, the supervisor compares every guard with the guard two
positions ahead in the current circular order. If the guard two positions ahead has
a higher security level, the two guards exchange their positions. However, after
an exchange, the inspection continues from the guard that originally followed the
first guard, rather than restarting from the beginning. The process ends when
every guard has been inspected once without causing an exchange. The guards&#39;
information must not be copied or exchanged. A change in position must be
performed by reconnecting the nodes themselves. Implement the required
system using a circular linked list. The solution must correctly handle exchanges
involving the head, adjacent nodes, the last nodes of the circle, and a circle
containing only three guards.
*/


class Node
{
    public:
    Node *next;
    Node *prev;
    int guardID;
    int securityLevel;

    Node(int g, int s)
    {
        guardID = g;
        securityLevel = s;
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

    void Add(int id, int sLevel)
    {
        Node *newNode = new Node(id, sLevel);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }

    void Remove()
    {
        if(head == NULL)
        {
            cout << "No guard is here" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    void sort()
    {
        if(head == NULL)
        {
            cout << "No guard is here" << endl;
            return;
        }

        Node *temp = head;
        Node *temp2 = head;

        while(temp->next != tail)
        {
            temp2 = temp;
            while(temp2->next != tail)
            {
                Node *A = temp2->prev;
                Node *B = temp2;
                Node *M = temp2->next;
                Node *C = temp2->next->next;
                Node *D = temp2->next->next->next;

                if(B->securityLevel < C->securityLevel)
                {
                    A->next = C;
                    C->prev = A;
                    M->prev = C;
                    C->next = M;
                    D->prev = B;
                    B->next = D;
                    M->next = B;
                    B->prev = M;
                }

                temp2 = temp2->next;
            }
        }
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "No guards here" << endl;
            return;
        }

        Node *temp = head;

        cout << endl;
        do
        {
            cout << "Security Level: " << temp->securityLevel << endl;
            cout << "Guard ID: " << temp->guardID << endl;

            temp = temp->next;
        }while(temp->next != head);
    }
};


int main()
{
    // ---------- Test 1: empty list ----------
    cout << "=== Test 1: empty list ===" << endl;
    linkedList empty;
    empty.display();      // should say "No guards here"
    empty.Remove();       // should say "No guard is here"

    // ---------- Test 2: one guard ----------
    cout << "\n=== Test 2: one guard ===" << endl;
    linkedList one;
    one.Add(1, 5);
    one.display();        // prints guard 1 only
    one.Remove();         // tests the one-guard case
    one.display();        // should say "No guards here"

    // ---------- Test 3: several guards ----------
    cout << "\n=== Test 3: add and remove ===" << endl;
    linkedList g;
    g.Add(1, 5);
    g.Add(2, 3);
    g.Add(3, 5);
    g.Add(4, 3);
    g.display();          // all 4 guards, in order 1, 2, 3, 4

    g.Remove();           // removes the head (guard 1)
    g.display();  
};