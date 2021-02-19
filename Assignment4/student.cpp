#include<iostream>
#include<string.h>
using namespace std;
#define MAX_SIZE 100
class Student;
class Student_list;
class Subject
{
    int sub_code;
    char sub_name[31];
    public:
    void get_data(int s,char*n)
    {
        sub_code=s;
        strcpy(sub_name,n);
    }
    void show_data()
    {
        cout<<"subject code:"<<sub_code<<"  subject:"<<sub_name<<endl;
    }
    int get_sub_code()
    {
        return sub_code;
    }
};

class Subject_list
{
    Subject s[MAX_SIZE];
    static int last_id;
    public:
    void get_data(int code)
    {
        for(int i=0;i<last_id;i++)
        {
            if(s[i].get_sub_code()==code)
            {
                cout<<"A subject will the same code already exists!!"<<endl;
                return;
            }
        }
        char name[31];
        cout<<"enter the subject name:"<<endl;
        cin>>name;
        s[last_id].get_data(code,name);
        last_id++;
    }
    void show_list()
    {
        for(int i=0;i<last_id;i++)
        {
            s[i].show_data();
        }
    }
};
int Subject_list::last_id=0;

class Student
{
    static int last_roll;
    char name[31];
    int roll;
    char phn[11];
    int sub[6]; //to store the subject codes of the chosen sub
public:
    void get_data(char *n, char *ph)
    {
        last_roll++;
        roll = last_roll;
        strcpy(name, n);
        strcpy(phn, ph);
        for (int i = 0; i < 6; i++)
        {
            sub[i] = 0;
        }
    }
    int get_roll()
    {
        return roll;
    }
    void show_data()
    {
        cout<<"roll:"<<roll<<" name: "<<name<<endl<<"phone number:"<<phn<<endl;
        cout<<sub[3]<<endl;
    }
    void set_sub(int a[])
    {
        for(int i=0;i<6;i++)
        {
            sub[i]=a[i];
        }
    }
    void show_sub()
    {
        for(int i=0;i<6;i++)
        {
            cout<<sub[i]<<endl;
        }
    }
    int get_subcode(int i)
    {
        return sub[i];
    }
};
int Student::last_roll=0;
class Student_list
{
    Student std[MAX_SIZE];
    static int last_id;
    public:
    void get_data()
    {
        char name[31],ph[11];
        int a[10],n;
        cout<<"\nenter the name of the student:";
        cin>>name;
        cout<<"enter the phone number of student:";
        cin>>ph;
        std[last_id].get_data(name,ph);
        last_id++;
    }
    void show_roll(int roll)
    {
        for(int i=0;i<last_id;i++)
        {
            if(std[i].get_roll()==roll)
            {
                std[i].show_data();
            }
        }
    }
    void select_sub(int roll,Subject_list subl)
    {
        for (int i = 0; i < last_id; i++)
        {
            if (std[i].get_roll() == roll)
            {
                subl.show_list();
                int a[6];
                cout<<"please select 6 subject and enter the respective subject code:"<<endl;
                for(int j=0;j<6;j++)
                {
                    cin>>a[j];
                }
                std[i].set_sub(a);
            }
        }
    }
    void show_student(int code)
    {
        for(int i=0;i<last_id;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(std[i].get_subcode(j)==code)
                {
                    std[i].show_data();
                }
            }
        }
    }
};
int Student_list::last_id=0;

int main()
{
    Student_list s1;
    Subject_list sub1;
    sub1.get_data(1);
    sub1.get_data(2);
    sub1.get_data(4);
    sub1.get_data(5);
    sub1.get_data(3);
    sub1.get_data(1);
    sub1.get_data(7);
    sub1.show_list();
    s1.get_data();
    s1.get_data();
    s1.select_sub(1,sub1);
    s1.select_sub(2,sub1);
    s1.show_roll(2);
    s1.show_student(4);
    return 0;
}