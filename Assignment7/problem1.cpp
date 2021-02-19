#include<bits/stdc++.h>

using namespace std;

class Student
{
    int roll;
    string name;
    int score;
    public:
    Student(int r,string n, int s=-1)
    {
        roll=r;
        name=n;
        score=s;
    }
    bool operator<(const Student s)const
    {
        return(score<s.score);
    }
    void show()
    {
        cout<<roll<<endl<<name<<endl<<score<<endl;
    }
    bool operator==(const char a[])const
    {
        return(name.find(a)!=std::string::npos);
    }
    string get_name(){return name;}
};
class Student_list
{
    vector<Student> std;
    public:
    void add_student(Student s)
    {
        std.push_back(s);
    }
    void remove_student(Student s)
    {
        vector<Student>::iterator it;
        if ((it = find(std.begin(), std.end(), s)) != std.end())
        {
            std.erase(it);
            cout << "Removed\n";
        }
        else
            cout << "Not found\n";
    }
    Student highest_score()
    {
        vector<Student>::iterator it = max_element(std.begin(), std.end());
        if (it == std.end())
        {
            cout << "NOT FOUND";
        }
        return *it;
    }
    void with_subs(string s)
    {
        vector<Student>::iterator it;
        cout<<"student with substring\n";
        for(it=std.begin();it!=std.end();it++)
        {
            it=find(std.begin(),std.end(),s);
            if(it!=std.end())
            {
                (*it).show();
            }
        }
        if(it==std.end())
        {
            cout<<"notfound\n";
            return;
        }
    }
    void without_sub(string s)
    {
        int flag=0;
        vector<Student>::iterator it;
        cout<<"without substring\n";
        for (it = std.begin(); it != std.end(); it++)
        {
            string name = (*it).get_name();
            size_t t = name.find(s);
            if (t > name.size())
            {
                (*it).show();
                flag=1;
            }
        }
        if (flag==0)
        {
            cout << "NONE\n";
        }
    }
    void display_all()
    {
        vector<Student>::iterator it;
        for(it=std.begin();it!=std.end();it++)
        {
            (*it).show();
        }
    }
};
int main()
{
    /*do{
        cout << "1. add student\n2. display all students\n3. find highest\n";
        cout << "4. search substring\n5. search without substring\n6. remove\n";
    }while(1);*/
    Student_list s;
    Student s1(1,"Rita",89);
    Student s2(2,"Rita1",90);
    Student s3(3,"Rita2",98);
    s.add_student(s1);
    s.add_student(s2);
    s.add_student(s3);
    s.display_all();
    Student s4=s.highest_score();
    s4.show();
    s.with_subs("Rita");
    s.without_sub("Rit");
    s.with_subs("SJ");
    s.remove_student(s1);
    s.display_all();
    return 0;
}