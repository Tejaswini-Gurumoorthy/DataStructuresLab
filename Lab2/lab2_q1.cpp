#include <iostream>
using namespace std;
#define max_size 100
class stack
{
    int top;
    int a[max_size];
public:
    stack()
    {
        top=-1;
    }
    void push(int x)
    {
        if(top==max_size-1)
        {
            cout<<"STACK OVERFLOW !!!"<<endl;
        }
        else
        {
            a[++top]=x;
        }

    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"STACK UNDERFLOW !!!"<<endl;
        }
        else
        {
            top--;
        }
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();

}
