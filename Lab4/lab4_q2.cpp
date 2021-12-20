#include <iostream>
using namespace std;
#define size 100
class stack
{
    int top;
    int a[size];

    public:
    stack()
    {
        top=-1;
    }

    bool isFull()
    {
        return top==size-1;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    void push(int x)
    {
        int endli;
        if (isFull())
        {
            cout<<"STACK OVERFLOW !!!"<<endl;
        }
        else
        {
            a[++top]= x;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"STACK UNDERFLOW !!!"<<endl;
            return 0;
        }
        else
        {
            return a[top--];
        }
    }
    int gettop()
    {
        return a[top];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"STACK UNDERFLOW !!!"<<endl;
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }


};
float operate(float op1,char op,float op2)
{
    if(op=='+')
    {
        return op1+op2;
    }
    else if(op=='-')
    {
        return op1-op2;
    }
    else if(op=='*')
    {
        return op1*op2;
    }
    else if(op=='/')
    {
        return op1/op2;
    }
    else
    {
        return 0;
    }

}


void post_eval(string s)
{
    stack stk;
    float output=0;
    int i,j=0;
    int tempnum=0;
    char tempop;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='0'&&s[i]<='9'))
        {
            stk.push(s[i]-48);

        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        {
            if(!stk.isEmpty())
            {
                tempnum= stk.pop();
                stk.push(operate(stk.pop(),s[i],tempnum));
            }
            else
            {
                cout<<"ERROR !!"<<endl;
            }

        }
    }
    cout<<"THE OUTPUT IS : "<<stk.pop()<<endl;

}
int main()
{
    string exp;
    cout<<"Enter expression to be evaluated : "<<endl;
    cin>>exp;
    post_eval(exp);
    return 0;
}
