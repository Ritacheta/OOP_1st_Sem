#include <bits/stdc++.h>
using namespace std;

class STUDENT
{
    int roll, score;
    string name;

public:
    STUDENT(int r, int s, string n) : name(n)
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
    bool operator<(const STUDENT s)const
    {
        return score < s.score;
    }
    bool operator==(int r)
    {
        return roll == r;
    }
    friend ostream &operator<<(ostream &os, STUDENT s);
    int get_score(){return score;}
};
class STUDENT_ARRAY
{
    vector<STUDENT> sv;
    void subs(string sub, int c)
    {
        int flag = 0;
        vector<STUDENT>::iterator it;
        for (it = sv.begin(); it != sv.end(); it++)
        {
            string name = (*it).get_name();
            size_t t = name.find(sub);
            if ((t <= name.size() && c == 0) || (t > name.size() && c == 1))
            {
                cout << *it << "\n";
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "NONE\n";
        }
    }
public:
    void add(STUDENT s)
    {
        sv.push_back(s);
    }
    void remove(int r)
    {
        vector<STUDENT>::iterator it;
        if ((it = find(sv.begin(), sv.end(), r)) != sv.end())
        {
            sv.erase(--it);
            cout << "Removed\n";
        }
        else
            cout << "Not found\n";
    }
    void display_all()
    {
        vector<STUDENT>::iterator it;
        for (it = sv.begin(); it != sv.end(); it++)
        {
            cout << (*it)<<endl
            ;
        }
    }
    STUDENT operator[](int i)
    {
        vector<STUDENT>::iterator it = sv.begin();
        return *(it + i);
    }
    int size()
    {
        return sv.size();
    }
    STUDENT max_score()
    {
        vector<STUDENT>::iterator it = max_element(sv.begin(), sv.end());
        if (it == sv.end())
        {
            cout << "NOT FOUND";
        }
        return *it;
    }
    void with_subs(string sub)
    {
        cout << "Matching Substring " << sub << ":\n";
        subs(sub, 0);
    }
    void without_subs(string sub)
    {
        cout << "Without Substring " << sub << ":\n";
        subs(sub, 1);
    }
    STUDENT_ARRAY merge_student(const STUDENT_ARRAY sv1)const
    {
        STUDENT_ARRAY sv3;
        merge(sv.begin(),sv.end(),sv1.sv.begin(),sv1.sv.end(),sv3.sv.begin());
        return sv3;
    }
    void sort_array()
    {
        sort(sv.rbegin(),sv.rend());
    }
};

ostream &operator<<(ostream &os, STUDENT s)
{
    os << "ROLL: " << s.roll << "\nName: " << s.name << "\nScore: " << s.score;
    return os;
}

int main()
{
    STUDENT s1(1, 70, "SJ1");
    STUDENT s2(2, 90, "SJ2");
    STUDENT s3(3, 80, "SJ3");
    STUDENT_ARRAY sa;
    STUDENT_ARRAY sa1;
    STUDENT_ARRAY sa2;
    sa1.add(s3);
    sa1.add(s1);
    sa.add(s1);
    sa.add(s2);
    sa.add(s3);
    cout << "\nStudent with Highest Score:\n"
         << sa.max_score() << "\n\n";
   // sa.with_subs("SJ");
    //sa.without_subs("SK");
    //sa2=sa.merge_student(sa1);
    cout<<"\n\n";
    sa.sort_array();
    sa.display_all();
    cout<<"\n\n";
    sa.display_all();
    cout<<"\n\n";
    sa2.display_all();
    sa.remove(2);
    return 0;
}