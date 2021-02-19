#include<bits/stdc++.h>
using namespace std;

class APPLICANT
{
    static int last_id;
    int id;
    char name[20];
    int score;
    public:
        void recieve_data(char a[20], int s);
        void show_data();
        static void num_applicants()
        {
            cout << ">>total number of applicants = " << APPLICANT::last_id << endl;
    }
};

int APPLICANT::last_id=0;
void APPLICANT::recieve_data(char a[],int s)
{
    last_id++;
    id=last_id;
    strcpy(name,a);
    score = s;
}

void APPLICANT::show_data()
{
    cout<<"ID:"<<id<<" || "<<"Name:"<<name<<" || "<<"Score:"<<score<<endl;
}

int main()
{
    APPLICANT a1,a2;
    a1.recieve_data("Ritacheta Das", 90);
    a2.recieve_data("Srirupa Ray",95);
    a1.show_data();
    a2.show_data();
    APPLICANT::num_applicants();
    return 0;
}