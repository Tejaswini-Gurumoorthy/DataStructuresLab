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
    pos--;  //Te actual position (since indexing in array starts from 0)

    int len_main=0,len_sub=0;
    while(main_str[len_main]!='\0')
    {
        len_main++; //length of the main string
    }
    while(sub_str[len_sub]!='\0')
    {
        len_sub++;  //length of the substring
    }

    char final_str[100]; //char array to store the final string
    int i=0; //used to iterate through the final string
    
    while(i<pos) //copying the elements of the main string till substring position
    {
        final_str[i]=main_str[i];
        i++;
    }
    
    int j=0;
    while(j<len_sub) //copying the elements of the substring to the final string
    {
        final_str[i]=sub_str[j];
        i++;
        j++;
    }
    
    int k= pos;
    while(k<len_main) //copying the elements of the main string from substring position till end
    {
        final_str[i]= main_str[k];
        i++;
        k++;
    }
    final_str[i]='\0';
    cout<<"The final string is : "<<endl;
    cout<<final_str<<endl;

}
