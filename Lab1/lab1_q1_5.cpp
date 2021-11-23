#include <iostream>
using namespace std;

int main()
{
    string main_str;
    int start, end;
    cout << "Enter the main string : " << endl;
    cin >> main_str;
    cout << "Enter the position it must be deleted from : " << endl;
    cin >> start;
    cout << "Till where : " << endl;
    cin >> end;
    start--;
    end--;

    int len_main = 0;
    while (main_str[len_main] != '\0')
    {
        len_main++;
    }

    char finalstr[len_main];
    int i = 0;
    while (i < start)
    {
        finalstr[i] = main_str[i];
        i++;
    }
    int j = end + 1;
    while (j < len_main)
    {
        finalstr[i] = main_str[j];
        i++;
        j++;
    }
    finalstr[i] = '\0';
    cout << "STRING AFTER DELETION : " << finalstr << endl;
}
