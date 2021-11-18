#include <iostream>
using namespace std;

class Student
{
  char name[50];
  int roll_no;
  char grade;

public:
  void read(Student s[], int size)
  {
    for (int i = 0; i < size; i++)
    {
      cout << "Enter Student name : ";
      cin >> s[i].name;
      cout << "Enter student roll number : ";
      cin >> s[i].roll_no;
      cout << "Enter student grade : ";
      cin >> s[i].grade;
    }
  }

  void display(Student s[], int size)
  {
    s->sort(s, size);
    for (int i = 0; i < size; i++)
    {
      cout << "Student name : " << s[i].name << endl;
      cout << "Student roll number : " << s[i].roll_no << endl;
      cout << "Enter student grade : " << s[i].grade << endl;
    }
  }
  void sort(Student s[], int size)
  {
    int min, temp, pos;
    for (int i = 0; i < size; i++)
    {
      min = s[i].roll_no;
      for (int j = i + 1; j < size; j++)
      {
        if (s[j].roll_no < min)
        {
          min = s[j].roll_no;
          pos = j;
        }
      }
      temp = s[pos].roll_no;
      s[pos].roll_no = s[i].roll_no;
      s[i].roll_no = temp;
    }
  }
};

int main()
{
  int size;
  cout << "Enter number of students : ";
  cin >> size;
  Student s[size];
  s->read(s, size);
  s->display(s, size);
}
