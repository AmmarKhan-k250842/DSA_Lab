#include <iostream>
#include <string>
using namespace std;


/*
3. A competition maintains participants in a circular doubly linked list. Each
participant has a Participant ID and a score. Starting from the head, the system
examines participants one by one. The number of steps to the next examination
is determined by the score of the participant who was just examined. If a
participants score is even, the next examination proceeds forward by two
positions. If the score is odd, it proceeds backward by two positions. Whenever a
participant is examined for the third time, that participant leaves the competition.
The process continues until only one participant remains.
Implement the process using a circular doubly linked list and display the ID of the
final remaining participant. The links must be adjusted correctly whenever a
participant is removed, regardless of whether the traversal is currently moving
forward or backward.
*/


class pNode
{
    public:
    pNode *next;
    pNode *prev;
    int score;
    int ID;
    int visits;

    pNode(int s, int i) : score(s), ID(i)
    {
        next = NULL;
        prev = NULL;
        visits = 0;
    }
};

class linkedList
{
    private:
    pNode *head;
    pNode *tail;
    int size;

    public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void Add(int score, int id)
    {
        pNode *newNode = new pNode(score, id);

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
        size++;
    }

    void Remove()
    {
        if(head ==  NULL)
        {
            cout << "No participants to remove" << endl;
            return;
        }

        pNode *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        size--;

        delete temp;
    }

    void examSort()
    {
        pNode *temp = head;

        while(size > 1)
        {
            if(temp->visits++ < 3)
            {
                if((temp->score % 2) == 0)
                {
                    temp = temp->next->next;
                }
                else if((temp->score % 2) != 0)
                {
                    temp = temp->prev->prev;
                }
            }
            else
            {
                pNode *A = temp;
                pNode *B = temp->prev;
                pNode *C = temp->next;
                B->next = C;
                C->prev = B;
                
                if((temp->score % 2) == 0)
                {
                    temp = temp->next->next;
                }
                else
                {
                    temp = temp->prev->prev;
                }

                delete A;
                size--;
            }
        }

        cout << endl;
        cout << "Winner: " << temp->ID << endl;
    }
};


int main()
{
    // Test 1: the 4-kid example from before, expected winner: 2
    cout << "=== Test 1: 4 kids ===" << endl;
    linkedList a;
    a.Add(2, 1);    // score 2, ID 1
    a.Add(1, 2);    // score 1, ID 2
    a.Add(3, 3);    // score 3, ID 3
    a.Add(2, 4);    // score 2, ID 4
    a.examSort();   // should print: Winner: 2

    // Test 2: the 5-kid example, compare with YOUR paper answer
    cout << "\n=== Test 2: 5 kids ===" << endl;
    linkedList b;
    b.Add(2, 1);
    b.Add(3, 2);
    b.Add(4, 3);
    b.Add(1, 4);
    b.Add(6, 5);
    b.examSort();

    // Test 3: exactly 3 kids (small circle)
    cout << "\n=== Test 3: 3 kids ===" << endl;
    linkedList c;
    c.Add(2, 10);
    c.Add(3, 20);
    c.Add(4, 30);
    c.examSort();

    // Test 4: exactly 2 kids (moving 2 steps lands on yourself or the other one)
    cout << "\n=== Test 4: 2 kids ===" << endl;
    linkedList d;
    d.Add(2, 7);
    d.Add(5, 8);
    d.examSort();

    // Test 5: one kid (loop should not even start)
    cout << "\n=== Test 5: 1 kid ===" << endl;
    linkedList e;
    e.Add(2, 99);
    e.examSort();   // should print: Winner: 99

    return 0;
}