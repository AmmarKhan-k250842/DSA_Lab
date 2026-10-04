#include <iostream>
#include <string>
using namespace std;


/*
4. A browser maintains recently visited pages in a doubly linked list. Each node
stores a Page ID, page title, and the number of times that page has been
visited. The user can move backward or forward through the browsing history.
When a page is revisited, its visit count is increased. The browser has a limit on
how many pages can remain in the history. Whenever a new page is visited while
the history is already full, the page that has remained unused for the longest time
must be removed. A page that becomes the current page is considered recently
used. Given a sequence of page visits and backward/forward navigation
commands, maintain the browsing history and finally display:
1. The complete history from the oldest page to the newest page.
2. The history in reverse order.
3. The current page and its visit count.
All navigation, insertion, and removal operations must maintain valid next and prev
links.
Hint for sorting question: Try to sort any type of array either it is 1d or 2d.
*/


class bNode
{
    public:
    bNode *next;
    bNode *prev;
    int pageID;
    string title;
    int visited;

    bNode(int p, string t) : pageID(p), title(t)
    {
        next = NULL;
        prev = NULL;
        visited = 0;
    }
};

class linkedList
{
    private:
    bNode *head;
    bNode *tail;
    bNode *curr;
    int limit;
    int size;

    public:
    linkedList(int l) : limit(l)
    {
        head = NULL;
        tail = NULL;
        curr = NULL;
        size = 0;
    }

    void Add(int id, string title)
    {
        bNode *newNode = new bNode(id, title);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode; 
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        newNode->visited++;
        curr = newNode;
        size++;
    }

    void Remove()
    {
        if(head ==  NULL)
        {
            cout << "No participants to remove" << endl;
            return;
        }

        bNode *temp = head;
        head = head->next;
        size--;

        delete temp;
    }

    bNode *findPage(int id, string title)
    {
        if(head == NULL)
        {
            cout << "History is empty" << endl;
            return NULL;
        }

        bNode *temp = head;
        while(temp != NULL)
        {
            if((temp->pageID == id) && (temp->title == title))
            {
                return temp;
            }
            
            temp = temp->next;
        }

        return NULL;
    }

    void visit(int id, string title)
    {   
        if(head == NULL)
        {
            Add(id, title);
        }

        bNode *temp = findPage(id, title);
        if(temp != NULL)
        {
            temp->visited++;
            curr = temp;
        }
        else
        {
            if(size < limit)
            {
                Add(id, title);
            }
            else if(size >= limit)
            {
                bNode *oldest = head;
                bNode *temp2 = oldest->next;

                while(temp2 != NULL)
                {
                    if(temp2->visited < oldest->visited)
                    {
                        oldest = temp2;
                    }

                    temp2 = temp2->next;
                }

                temp2 = oldest->prev;
                bNode *temp3 = oldest->next;
                temp2->next = temp3;
                temp3->prev = temp2;

                delete oldest;
                size--;

                bNode *newNode = new bNode(id, title);
                temp2->next = newNode;
                newNode->prev = temp2;
                newNode->next = temp3;
                temp3->prev = newNode;
                curr = newNode;
                newNode->visited++;
                size++;
            }
        }
    }

    void forward()
    {
        if(head == NULL)
        {
            cout << "history is empty" << endl;
            return;
        }

        if(curr->next != NULL)
        {
            curr = curr->next;
            curr->visited++;
        }
        else
        {
            cout << "Cant go forward"<< endl;
            return;
        }
    }

    void backwards()
    {
        if(head == NULL)
        {
            cout << "history is empty" << endl;
            return;
        }

        if(curr->next != NULL)
        {
            curr = curr->prev;
            curr->visited++;
        }
        else
        {
            cout << "Cant go forward"<< endl;
            return;
        }
    }

    void sort()
    {
        if(head == NULL)
        {
            cout << "history is empty" << endl;
            return;
        }

        bNode *temp = head;
        bNode *temp2 = temp;
        while(temp != NULL)
        {
            temp2 = temp;
            while(temp2 != NULL)
            {
                if(temp2->visited > temp2->next->visited)
                {
                    bNode *A = temp2->prev;
                    bNode *B = temp2;
                    bNode *C = temp2->next;
                    A->next = C;
                    C->prev = A;
                    C->next = B;
                    B->prev = C; 
                }

                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    void displayForward()
    {
        if(head == NULL)
        {
            cout << "history is empty" << endl;
            return;
        }

        bNode *temp = head;
        while(temp != NULL)
        {
            cout << temp->title << "  -->  ";
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        if(head == NULL)
        {
            cout << "history is empty" << endl;
            return;
        }

        bNode *temp = tail;
        while(temp != NULL)
        {
            cout << temp->title << "  -->  ";
            temp = temp->prev;
        }
    }

    void showCurrent()
    {
        if(curr == NULL)
        {
            cout << "No current page." << endl;
            return;
        }
        cout << "Current Page: " << curr->title
             << " | Visits: " << curr->visited << endl;
    }
};


// Paste this BELOW your linkedList class.
// It also needs showCurrent() inside your class (see the chat).

int main()
{
    // ---------- Test 1: empty history ----------
    cout << "=== Test 1: empty history ===" << endl;
    linkedList e(3);
    e.displayForward();       // history is empty
    e.forward();              // history is empty
    e.showCurrent();          // No current page.

    // ---------- Test 2: visit 3 pages ----------
    cout << "\n=== Test 2: visit 3 pages ===" << endl;
    linkedList h(5);
    h.visit(1, "A");
    h.visit(2, "B");
    h.visit(3, "C");
    h.displayForward();   cout << endl;    // A --> B --> C -->
    h.displayBackward();  cout << endl;    // C --> B --> A -->
    h.showCurrent();                       // C, 1

    // ---------- Test 3: revisit ----------
    cout << "\n=== Test 3: revisit B ===" << endl;
    h.visit(2, "B");          // B already exists, so visited goes up
    h.showCurrent();          // B, 2

    // ---------- Test 4: move around ----------
    cout << "\n=== Test 4: backwards / forward ===" << endl;
    h.backwards();            // B -> A
    h.showCurrent();          // A, 2
    h.forward();              // A -> B
    h.showCurrent();          // B, 3
    h.forward();              // B -> C
    h.showCurrent();          // C, 2
    h.forward();              // C is the last page: Cant go forward

    // ---------- Test 5: full history, limit 3 ----------
    // Written to run safely on your CURRENT code. The output shows 2 bugs (see chat).
    cout << "\n=== Test 5: full history, limit 3 ===" << endl;
    linkedList m(3);
    m.visit(1, "A");
    m.visit(1, "A");          // A visited = 2
    m.visit(2, "B");
    m.visit(3, "C");
    m.visit(4, "D");
    m.displayForward();   cout << endl;
    m.visit(5, "E");
    m.displayForward();   cout << endl;
    m.displayBackward();  cout << endl;
    m.showCurrent();

    // ---------- DO NOT turn these on until you fix the bugs: they crash ----------
    // h.backwards();  h.backwards();  h.backwards();   // going back from the FIRST page
    // linkedList x(2); x.visit(1,"P"); x.visit(2,"Q"); x.visit(3,"R");  // oldest page is the head
    // h.sort();                                         // sort() crashes on the last page

    return 0;
}