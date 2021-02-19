#include <iostream>
#include <map>
using namespace std;

class Student_map
{
    map<int,int> s_map;
    public:
    void add_student(int r,int s)
    {
        s_map.insert(map<int, int>::value_type(r, s));
    }
    void show()
    {
        map<int,int>::iterator it;
        for(it=s_map.begin();it!=s_map.end();it++)
        {
            cout<<"ROLL:"<<it->first<<endl<<"SCORE:"<<it->second<<endl;
        }
    }
    int get_score(int r)
    {
        map<int, int>::iterator it;
        for (it = s_map.begin(); it != s_map.end(); it++)
        {
            if(it->first==r)
            {
                return it->second;
            }
        }

        return -1;
    }
};

int main()
{
    Student_map sm;
    sm.add_student(23,89);
    sm.add_student(12,45);
    sm.add_student(20,90);
    sm.show();
    cout<<"score"<<sm.get_score(12);
    return 0;
}