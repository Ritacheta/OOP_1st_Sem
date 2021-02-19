#include<iostream>
#include<queue>
using namespace std;

class Student
{
    int roll, score;
    string name;

public:
    Student(int r, int s, string n) : name(n)
    {
        roll = r;
        score = s;
    }
    int get_roll()
    {
        return roll;
    }
    string get_name()
    {
        return name;
    }
    bool operator<(const Student s) const
    {
        return score < s.score;
    }
    bool operator==(int r)
    {
        return roll == r;
    }
    friend ostream &operator<<(ostream &os, Student s)
    {
        os << "ROLL: " << s.roll << "\nName: " << s.name << "\nScore: " << s.score;
        return os;
    }
    int get_score() { return score; }
};

class Student_queue
{
    queue<Student> sq;
    public:
    void add_student(Student s)
    {
        sq.push(s);
    }
    void get_marksheet()
    {
        while(!sq.empty())
        {
            Student S=sq.front();
            cout<<S<<endl;
            sq.pop();
        }
    }
};

int main()
{
    Student s1(1, 70, "SJ1");
    Student s2(2, 90, "SJ2");
    Student s3(3, 80, "SJ3");
    Student_queue sa;
    sa.add_student(s1);
    sa.add_student(s2);
    sa.add_student(s3);
    sa.get_marksheet();
    return 0;
}