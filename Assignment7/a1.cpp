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
    bool operator<(STUDENT s)
    {
        return score < s.score;
    }
    bool operator==(STUDENT s)
    {
        return name == s.name && roll == s.roll && score == s.score;
    }
    friend ostream &operator<<(ostream &os, STUDENT s);
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
    void remove(STUDENT s)
    {
        vector<STUDENT>::iterator it;
        if ((it = find(sv.begin(), sv.end(), s)) != sv.end())
        {
            sv.erase(it);
            cout << "Removed\n";
        }
        else
            cout << "Not found\n";
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
    sa.add(s1);
    sa.add(s2);
    sa.add(s3);
    sa.remove(s2);
    cout << "Index 1:\n"
         << sa[1] << endl;
    cout << "\nStudent with Highest Score:\n"
         << sa.max_score() << "\n\n";
    sa.with_subs("SJ");
    sa.without_subs("SK");
    return 0;
}