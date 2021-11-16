#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;

    int i=0,j=0;
    while(s1[i]!='\0')
    {
    i++;
    }
    while(s2[j]!='\0')
    {
        s1[i]=s2[j];
        i++;
        j++;
    }

    s1[i]='\0';
    cout<<"The concatenated string is : "<<s1<<endl;

}
