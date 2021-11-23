#include <iostream>
using namespace std;

class Student
{
    char name[50];
    int roll_no;
    char grade;

public:
    void read(Student *s, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<endl;
            cout << "DETAILS OF STUDENT " << i + 1 << ": "<<endl;
            cout << endl;
            cout << "Enter Student name : ";
            cin >> s[i].name;
            cout << "Enter student roll number : ";
            cin >> s[i].roll_no;
            cout << "Enter student grade : ";
            cin >> s[i].grade;
        }
    }

    void display(Student *s, int size)
    {
        s[0].sort(s, size);
        for (int i = 0; i < size; i++)
        {
            cout << "DETAILS OF STUDENT " << i + 1 << ": "<<endl;
            cout << endl;
            cout << "Student name : " << s[i].name << endl;
            cout << "Student roll number : " << s[i].roll_no << endl;
            cout << "Student grade : " << s[i].grade << endl;
            cout << endl;
            cout << endl;
        }
    }
    void sort(Student *s, int size)
    {
        int min, pos;
        Student temp;
        for (int i = 0; i < size; i++)
        {
            min = s[i].roll_no;
            for (int j = i + 1; j < size; j++)
            {
                if (s[j].roll_no < min)
                {
                    min = s[j].roll_no;
                    pos=j;
                }
            }
            temp = s[pos];
            s[pos] = s[i];
            s[i] = temp;
        }
    }
};

int main()
{
    int size;
    cout << "Enter number of students : ";
    cin >> size;
    Student s[size];
    s[0].read(s, size);
    s[0].display(s, size);
}
