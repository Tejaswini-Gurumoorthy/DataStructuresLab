#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtBeg(int x)
    {
        Node *newNode = new Node(x);
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
    }

    void insertBeforeEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        Node *tempPrev = NULL;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == x) && (temp == head))
            {
                insertAtBeg(ele);
            }
            else if (temp->data == x)
            {
                tempPrev->next = newNode;
                newNode->next = temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }

    void insertAfterEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        Node *tempPrev = temp;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == x) && (temp == head))
            {
                insertAtBeg(ele);
            }
            else if (tempPrev->data == x)
            {
                tempPrev->next = newNode;
                newNode->next = temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }

    void deleteEle(int ele)
    {
        Node *temp = head;
        Node *tempPrev = temp;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == ele) && (temp == head))
            {
                head = temp->next;
                delete temp;
            }

            else if (temp->data == ele)
            {
                tempPrev->next = temp->next;
                delete temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }

    void print()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data;

            temp = temp->next;
            if (temp == NULL)
            {
                break;
            }
            cout << "->";
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l;
    int ch;
    while (1)
    {

        cout << "Enter your choice : " << endl;
        cout << "1) Insert an element in the beginning of the list" << endl;
        cout << "2) Insert an element at the end of the list" << endl;
        cout << "3) Insert an element before another element in the existing list" << endl;
        cout << "4) Insert an element after another element in the existing list" << endl;
        cout << "5) Delete a given element from the list" << endl;
        cout << "6) Print the list" << endl;
        cout << "7) Exit" << endl;
        cout << endl;
        cout << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            int x;
            cout << "Enter element to be inserted : " << endl;
            cin >> x;
            l.insertAtBeg(x);
            break;

        case 2:
            cout << "Enter element to be inserted : " << endl;
            cin >> x;
            l.insertAtEnd(x);
            break;

        case 3:
            int ele;
            cout << "Enter the element before which you want to insert : " << endl;
            cin >> x;
            cout << "Enter element to be inserted : " << endl;
            cin >> ele;
            l.insertBeforeEle(x, ele);
            break;

        case 4:
            cout << "Enter the element after which you want to insert : " << endl;
            cin >> x;
            cout << "Enter element to be inserted : " << endl;
            cin >> ele;
            l.insertAfterEle(x, ele);
            break;

        case 5:
            cout << "Enter the element you want to delete : " << endl;
            cin >> ele;
            l.deleteEle(ele);
            break;

        case 6:
            l.print();
            break;

        case 7:
            return 0;
            break;
        }
    }
}
