#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;
    int i=0,j=0,f=0;

    while(s1[i]!='\0')
    {
        i++;
    }
    while(s2[j]!='\0')
    {
        j++;
    }
    if(i==j)
    {
        for(int k=0;k<i;k++)
        {
            if (s1[k]==s2[k])
            {
                f=1;
            }
        }
    }
    if(f)
    {
        cout<<"The given two strings are equal";
    }
    else
    {
        cout<<"The given two strings are not equal";

    }


}
