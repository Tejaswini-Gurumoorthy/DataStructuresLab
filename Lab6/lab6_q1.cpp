#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev= NULL;
    }
};

class LinkedList
{
    Node *head,*tail;
    public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        Node *temp= head;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next= newNode;
        newNode->prev=temp;
        temp=newNode;
        tail=newNode;

    }
    void deleteFromEnd()
    {
        tail= tail->prev;
        tail->next=NULL;
    }
    void printFromBeg()
    {
        Node *temp= head;
        if(head==NULL)
        {
            cout<<"NO ELEMENTS FOUND!"<<endl;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtPos(int x, int pos)
    {
        Node *newNode = new Node(x);
        Node *temp = head;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            temp=temp->next;
        }
        (temp->prev)->next=newNode;
        newNode->prev= temp->prev;
        temp->prev= newNode;
        newNode->next=temp;
    }
    void deleteAtPos(int pos)
    {
        Node *temp = head;
        Node *tempPrev = NULL;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        (temp->prev)->next=temp->next;
        (temp->next)->prev= temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
    }
    void insertBeforeEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while(temp->data!=x)
        {
            temp= temp->next;
        }
        (temp->prev)->next=newNode;
        newNode->prev= temp->prev;
        temp->prev= newNode;
        newNode->next=temp;

    }
    void insertAfterEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while(temp->data!=x)
        {
            temp= temp->next;
        }
        temp=temp->next;
        (temp->prev)->next=newNode;
        newNode->prev= temp->prev;
        temp->prev= newNode;
        newNode->next=temp;

    }
    
};
int main()
{
    LinkedList l;
    int f=1;
    while(f)
    {
    int ch;
    cout<<"Which of the following operations would you like to perform?"<<endl;
    cout<<endl;
    cout<<"1. Insert an element at the rear end of the list"<<endl;
    cout<<"2.Delete an element from the rear end of the list"<<endl;
    cout<<"3.Insert an element at a given position of the list"<<endl;
    cout<<"4.Delete an element from a given position of the list"<<endl;
    cout<<"5.Insert an element after another element"<<endl;
    cout<<"6.Insert an element before another element"<<endl;
    cout<<"7.Print the list"<<endl;
    cout<<"Type '-1' to exit the program"<<endl;
    cout<<endl;
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
        case 1:
        int x;
        cout<<"Enter the element you would like to insert : "<<endl;
        cin>>x;
        l.insertAtEnd(x);
        break;

        case 2:
        l.deleteFromEnd();
        break;

        case 3:
        int pos;
        cout<<"Enter the position at which you would like to insert : "<<endl;
        cin>>pos;
        cout<<"Enter the element that you want to insert : "<<endl;
        cin>>x;
        l.insertAtPos(x,pos);
        break;

        case 4:
        cout<<"Enter the position from which you would like to dekete : "<<endl;
        cin>>pos;
        l.deleteAtPos(pos);
        break;

        case 5:
        int ele;
        cout<<"Enter the element after which you would like to insert : "<<endl;
        cin>>ele;
        cout<<"Enter the element that you want to insert : "<<endl;
        cin>>x;
        l.insertAfterEle(ele,x);
        break;

        case 6:
        cout<<"Enter the element before which you would like to insert : "<<endl;
        cin>>ele;
        cout<<"Enter the element that you want to insert : "<<endl;
        cin>>x;
        l.insertBeforeEle(ele,x);
        break;

        case 7:
        cout<<"The list is : "<<endl;
        l.printFromBeg();
        break;

        case -1:
        f=0;
        break;
    }


    }


}
