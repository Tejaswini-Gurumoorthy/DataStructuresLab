#include <iostream>
#include <string.h>
using namespace std;
#define size 100

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class stack
{
public:
    int top;
    Node *a[size];

    stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(Node *x)
    {
        if (isFull())
        {
            cout << "STACK OVERFLOW !!!" << endl;
        }
        else
        {
            a[++top] = x;
        }
    }
    Node *pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW !!!" << endl;
            return NULL;
        }
        else
        {
            return a[top--];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW !!!" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    Node *getTop()
    {
        return a[top];
    }
};
class BinaryTree
{
public:
    Node *root = NULL;
    Node *temp = NULL;

    Node *create(int x)
    {
        while (true)
        {
            int x;
            cin >> x;
            if (x == -1)
            {
                return NULL;
            }
            Node *newNode = new Node(x);
            cout << "Value of left node of " << x << " - ";

            newNode->left = create();

            cout << "Value of right node of " << x << " - ";
            newNode->right = create();

            return newNode;
        }
    }
    void InorderDisplay(Node *root)
    {

        Node *temp = root;
        stack stk;

        if (root == NULL)
        {
            return;
        }

        while ((temp != NULL) || (!stk.isEmpty()))
        {
            while (temp != NULL)
            {
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    void PreorderDisplay(Node *root)
    {
        Node *temp = root;
        stack stk;

        if (root == NULL)
        {
            return;
        }

        stk.push(temp);
        while (!stk.isEmpty())
        {
            temp = stk.pop();
            cout << temp->data << " ";
            if (temp->right != NULL)
            {
                stk.push(temp->right);
            }
            if (temp->left != NULL)
            {
                stk.push(temp->left);
            }
        }
    }
    void PostorderDisplay(Node *root)
    {
        stack s;
        Node *temp = root;
        Node *prev = NULL;

        while (!s.isEmpty() || temp != NULL)
        {
            if (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = s.getTop();
                if (temp->right == NULL || temp->right == prev)
                {
                    cout << temp->data << " ";
                    s.pop();
                    prev = temp;
                    temp = NULL;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
};

int main()
{
        BinaryTree b;
        cout << "value : " << endl;
        Node *root = b.create();
        cout << "\nInorder Traversal : ";
        b.InorderDisplay(root);
        cout << "\nPreorder Traversal : ";
        b.PreorderDisplay(root);
        cout << "\nPostder Traversal : ";
        b.PostorderDisplay(root);
        cout << endl;
        return 0;
}
