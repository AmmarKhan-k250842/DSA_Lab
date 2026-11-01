#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    Node *left;
    Node *right;
    int data;

    Node(int d) : data(d)
    {
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    private:
    Node *root;

    Node* insert(Node *node, int value)
    {
        if(node == NULL)
        {
            return new Node(value);
        }

        if(value < node->data)
        {
            node->left = insert(node->left, value);
        }

        if(value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool search(Node *node, int key)
    {
        if(node == NULL)
        {
            return false;
        }
        if(node->data == key)
        {
            return true;
        }
        if(key < node->data)
        {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    Node* findMin(Node *node)
    {
        while(node->left != NULL)
        {
            node = node->left;
        }

        return node;
    }

    Node* remove(Node *node, int key)
    {
        if(node == NULL)
        {
            return NULL;
        }
        else if(key < node->data)
        {
            node->left = remove(node->left, key);
        }
        else if(key > node->data)
        {
            node->right = remove(node->right,key);
        }

        else
        {
            if(node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            if(node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            Node *successor = findMin(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }

        return node;
    }

    void preOrder(Node *node)
    {
        if(node == NULL)
        {
            return;
        }

        cout << node->data << "  ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node)
    {
        if(node == NULL)
        {
            return;
        }

        inOrder(node->left);
        cout << node->data << "  ";
        inOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if(node == NULL)
        {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << "  ";
    }

    void destroy(Node *node)
    {
        if(node == NULL)
        {
            return;
        }

        destroy(node->left);
        destroy(node->right);

        delete node;
    }


    public:
    Tree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }
    bool search(int key)
    {
        return search(root, key);
    }
    void remove(int value)
    {
        root = remove(root, value);
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }
};


int main()
{
    Tree tree;                             // Create
 
    int values[] = {40, 30, 60, 20, 35, 50, 70};
    for (int v : values) tree.insert(v);  // Insert
 
    cout << "In-order   : "; tree.inOrder();
    cout << "Pre-order  : "; tree.preOrder();
    cout << "Post-order : "; tree.postOrder();
 
    cout << "\nSearch 35: " << (tree.search(35) ? "found" : "not found") << "\n";
    cout << "Search 99: " << (tree.search(99) ? "found" : "not found") << "\n";
 
    cout << "\nDelete 20 (leaf):       "; tree.remove(20); tree.inOrder();
    cout << "Delete 30 (one child):  "; tree.remove(30); tree.inOrder();
    cout << "Delete 40 (two kids):   "; tree.remove(40); tree.inOrder();
 
    return 0;
}