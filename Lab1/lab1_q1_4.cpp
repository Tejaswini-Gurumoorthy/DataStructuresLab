#include <iostream>
using namespace std;

int main()
{
    string main_str,sub_str;
    int pos;
    cout<<"Enter the main string : "<<endl;
    cin>>main_str;
    cout<<"Enter the string to be inserted : "<<endl;
    cin>>sub_str;
    cout<<"Enter the position from which the substring must be inserted :  "<<endl;
    cin>>pos;
    pos--;

    int len_main=0,len_sub=0;
    while(main_str[len_main]!='\0')
    {
        len_main++;
    }
    while(sub_str[len_sub]!='\0')
    {
        len_sub++;
    }

    char final_str[100];
    int i=0;
    while(i<pos)
    {
        final_str[i]=main_str[i];
        i++;
    }
    int j=0;
    while(j<len_sub)
    {
        final_str[i]=sub_str[j];
        i++;
        j++;
    }
    int k= pos;
    while(k<len_main)
    {
        final_str[i]= main_str[k];
        i++;
        k++;
    }
    final_str[i]='\0';
    cout<<final_str<<endl;

}
