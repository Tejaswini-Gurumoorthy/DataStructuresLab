#include <iostream>
#include<cstring>
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
    int pop()
    {
        if(top==-1)
        {
            return 0;
        }
        else
        {
            return a[top--];
        }
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }

};

int main()
{
    
    char str[50], strpal[50];
    int len=0;
    cout<<"Enter the String : ";
    cin>>str;
    stack s;

    for(int i=0;str[i]!='\0';i++)
    {
        s.push(str[i]);
        len =i;
    }
    int j=0;
    while(j!=len+1)
    {
        strpal[j]=s.pop();
        j++;
    }
    strpal[j]='\0';
    cout<<strpal<<endl;
    if(strcmp(str,strpal)==0)
    {
        cout<<"THE ABOVE STRING IS A PALINDROME"<<endl;
    }
    else
    {
        cout<<"THE ABOVE STRING IS NOT A PALINDROME"<<endl;
    }



}
