#include <iostream>

using namespace std;

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    int i=0;
    for(i=0;s[i]!='\0';i++);
    cout<<"The length of the string is : "<<i<<endl;
    return 0;
}
