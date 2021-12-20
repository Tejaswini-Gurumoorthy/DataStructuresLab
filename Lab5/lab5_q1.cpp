#include <iostream>
#include<string.h>
using namespace std;
#define size 100

string rev(string str)
{
    string s;
    for(int k=str.length()-1;k>=0;k--)
    {
        s+=str[k];
    }
    s+='\0';

    return s;
}

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


};

void inf_to_post(string str)
{
    
    
    stack stk;
    string output;
    int i,j=0;
    string s;

    s=rev(str);

    for(i=0;i<s.length();i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            output+=s[i];
        }
        else if(s[i]==')')
        {
            stk.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(stk.gettop()!=')')
            {
                output+=stk.pop();
            }
            stk.pop();
        }
        else 
        {
            while((!stk.isEmpty())&&(priority(s[i])>priority(stk.gettop())))
            {
                output+=stk.gettop();
                stk.pop();
            }
            stk.push(s[i]);
           
        }
    }

    while(!stk.isEmpty())
    {
        output+=stk.gettop();
        stk.pop();
    }
    output+='\0';

    string output_correct;
    output_correct= rev(output);

    cout<<output<<endl;
    cout<<output_correct<<endl;
}

int main()
{
    string exp = "a+b*c^d-e^f+g*h-i";
    inf_to_post(exp);
    return 0;
}
