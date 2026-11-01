#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
    Node *left;
    Node * right;
    int data;

    Node(int d) : data(d)
    {
        left = NULL;
        right = NULL;
    }
};


class BST
{
    private:
    Node *root;

    Node *insert(Node *node, int value)
    {
        if(node == NULL)
        {
            return new Node(value);
        }

        else if(value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if(value > node->data)
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
        else if(key < node->data)
        {
            return search(node->left, key);
        }
        else
        {
            return search(node->right, key);
        }
    }

    Node *findMin(Node *node)
    {
        if(node == NULL)
        {
            return NULL;
        }

        Node *temp = node;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp;
    }

    Node *findMax(Node *node)
    {
        if(node == NULL)
        {
            return NULL;
        }

        Node *temp = node;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        
        return temp;
    }

    Node *remove(Node *node, int key)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(key < node->data)
        {
            node->left = remove(node->left, key);
        }
        else if(key > node->data)
        {
            node->right = remove(node->right, key);
        }
        else
        {
            if(node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else if(node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else
            {
                Node *successor = findMin(node->right);
                node->data = successor->data;
                node = remove(node->right, successor->data);
            }
        }

        return node;
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

    int height(Node *node)
    {
        if(node == NULL)
        {
            return -1;
        }

        int l = height(node->left);
        int r = height(node->right);

        if(l > r)
        {
            return 1 + l;
        }
        return 1 + r;
    }

    Node *inOrderSuccessor(Node *node, int key)
    {
        Node *successor = NULL;

        while(node != NULL)
        {
            if(key < node->data)
            {
                successor = node;
                node = node->left;
            }
            else if(key > node->data)
            {
                node = node->right;
            }
            else
            {
                if(node->right != NULL)
                {
                    return findMin(node->right);
                }
                else
                {
                    return successor;
                }
            }
        }

        return successor;
    }
    
    public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }
    bool searchFor(int value)
    {
        return search(root, value);
    }
    void remove(int value)
    {
        root = remove(root, value);
    }
    void inOrderDisplay()
    {
        inOrder(root);
    }
    void height()
    {
        cout << "\n\nHeight: " << height(root) << endl;
    }
    void inOrderSucc(int value)
    {
        Node *temp = inOrderSuccessor(root, value);

        cout << "Successor of " << value << ": " << temp->data << endl; 
    }
};


int main()
{
    BST tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In Order Display Before removing: " << endl;
    tree.inOrderDisplay();

    tree.remove(40);

    cout << "\n\nIn Order Display After removing: " << endl;
    tree.inOrderDisplay();

    tree.height();
    tree.inOrderSucc(40);

    return 0;
}

