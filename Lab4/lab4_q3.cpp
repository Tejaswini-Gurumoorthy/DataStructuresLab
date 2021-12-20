#include <iostream>
using namespace std;
#define size 100

string paranthesis(string exp1, char c, string exp2)
{
    string paran;
    paran+='(';
    paran+=exp1;
    paran+=c;
    paran+=exp2;
    paran+=')';
    paran+='\0';
    return paran;
}
class stack
{
    int top;
    string a[size];

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
    void push(string x)
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
    string pop()
    {
        if(isEmpty())
        {
            return "STACK UNDERFLOW !!!";
        }
        else
        {
            return a[top--];
        }
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


void post_eval(string s)
{
    stack stk;
    float output=0;
    int i,j=0;
    string tempnum;
    char tempop;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            string ch;
            ch+=s[i];
            stk.push(ch);

        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        {
            if(!stk.isEmpty())
            {
                tempnum= stk.pop();
                stk.push(paranthesis(stk.pop(),s[i],tempnum));
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
