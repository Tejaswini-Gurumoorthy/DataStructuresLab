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
            cout<<a[top--];
        }
    }
    int gettop()
    {
        return top;
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
    int dec_num,base;
    cout<<"Enter decimal number : "<<endl;
    cin>>dec_num;
    cout<<"Enter the base to which you wish to convert the number : "<<endl;
    cin>>base;
    while(dec_num>0)
    {
        s.push(dec_num%base);
        dec_num/=base;
    }
    for(int i=s.gettop();i>=0;i--)
    {
        s.pop();
    }
    cout<<endl;



}
