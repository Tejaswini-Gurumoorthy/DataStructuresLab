#include <iostream>
using namespace std;
#define size 100

int priority(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
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

void inf_to_post(string s)
{
    stack stk;
    char output[s.length()+1];
    int i,j=0;

    for(i=0;i<s.length();i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            output[j++]=s[i];
        }
        else if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(stk.gettop()!='(')
            {
                output[j++]=stk.pop();
            }
            stk.pop();
        }
        else 
        {
            while((!stk.isEmpty())&&(priority(s[i])<=priority(stk.gettop())))
            {
                output[j++]=stk.gettop();
                stk.pop();
            }
            stk.push(s[i]);
           
        }
    }

    while(!stk.isEmpty())
    {
        output[j++]=stk.gettop();
        stk.pop();
    }
    output[j]='\0';

    cout<<output<<endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    inf_to_post(exp);
    return 0;
}
