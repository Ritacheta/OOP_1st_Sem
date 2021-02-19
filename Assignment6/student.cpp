#include <iostream>
#include<string.h>
#define MAX_SIZE 2
using namespace std;

class Student
{
protected:
    int roll;
    char name[31];
    int score;
public:
    void getData(int r,char n[],int s=-1)
    {
        roll=r;
        strcpy(name,n);
        score=s;
    }
    void showData()
    {
        cout << "Name of the student: " << name << "\n";
        cout << "Roll Number: " << roll << "\n";
        cout << "Score Achieved: " << score << "\n";
    }
};
class Student_list
{
    int count = -1;
    Student arr[MAX_SIZE];
public:
    void addStudent(int r,char n[],int s=-1)
    {
        ++count;
        if (count > MAX_SIZE-1)
            throw "max student limit exceeded !\n";
        else
            arr[count].getData(r,n,s);
    }
    void displayall()
    {
        if (count == -1)
            throw -1;
        else
        {
            for (int i = 0; i <= min(count, MAX_SIZE-1); i++)
            {
                arr[i].showData();
            }
        }
    }
};
int main()
{
    Student_list obj1;
    while (1)
    {
        cout << "1. add student\n2. display all students\n3. exit\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                obj1.addStudent(1,"Rita",78);
            }
            catch (const char *c)
            {
                cout << c;
            }
            break;
        case 2:
            try
            {
                obj1.displayall();
            }
            catch (const char *c)
            {
                cout << c;
            }
            catch (int a)
            {
                cout << a << "\n";
            }
            break;
        default:
            exit(0);
        }
    }
    return 0;
}