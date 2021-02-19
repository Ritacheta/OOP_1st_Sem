#include<iostream>
using namespace std;

struct Student{
int roll;
int score;
void take_input(int &a,int &b)
{
    cout<<"enter roll and score respectively:";
    cin>>a>>b;
}
void show(int a,int b)
{
    cout<<"roll:"<<a<<" score"<<b<<endl;
}
};

int main()
{
    Student s;
    s.take_input(s.roll,s.score);
    s.show(s.roll,s.score);
    s.roll+=10;
    s.score+=10;
    s.show(s.roll, s.score);
    return 0;
}