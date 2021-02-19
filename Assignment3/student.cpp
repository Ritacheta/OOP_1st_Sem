#include<bits/stdc++.h>
using namespace std;

class STUDENT
{
    static int last_roll;
    int roll;
    char name[20];
    char course[20];
    int marks[5];
    char date[10];
    public:
    void get_admission(char n[],char c[],char date[]);
    void recieve_marks(int marks[5]);
    static void num_applicants()
    {
        cout << ">>total number of applicants = " << STUDENT::last_roll << endl;
    }
    void marksheet();
};

int STUDENT::last_roll=0;

void STUDENT::get_admission(char n[],char c[],char d[])
{
    last_roll++;
    roll=last_roll;
    strcpy(name,n);
    strcpy(course,c);
    strcpy(date,d);
    for (int i = 0; i < 5; i++)
    {
        marks[i] = -1;
    }
}

void STUDENT::recieve_marks(int m[])
{
    for(int i=0;i<5;i++)
    {
        marks[i]=m[i];
    }
}

void STUDENT::marksheet()
{
    cout<<"ROLL:: "<<roll<<" || "<<"NAME:: "<<name<<" || "<<"COURSE:: "<<course<<endl;
    if(marks[0]==-1)
    {
        cout << "SCORE ARE NOT AVAILABLE YET!!" << endl;
    }
    else
    {
        cout << "\tSubject-1\tSubject-2\tSubject-3\tSubject-4\tSubject-5" << endl;
        cout << "\t" << marks[0] << "\t\t" << marks[1] << "\t\t" << marks[2] << "\t\t" << marks[3] << "\t\t" << marks[4] << endl;
    }
}

int main()
{
    STUDENT s1,s2;
    s1.get_admission("Ritacheta","BCSE","12/08/2019");
    s2.get_admission("Sayani","BA","23/08/2020");
    s1.marksheet();
    int marks[5]={98,90,98,96,78};
    s1.recieve_marks(marks);
    s1.marksheet();
    STUDENT::num_applicants();
    return 0;
}