#include<iostream>
#include<string.h>
using namespace std;
class cricketer
{
    protected:
    char name[31];
    char dob[11];
    int num_match;
public:
    void get_data(char* n,char *d,int m)
    {
        strcpy(name, n);
        strcpy(dob, d);
        num_match=m;
    }
    virtual void show_data()
    {
        cout << "Name:" << cricketer::name<< "\nDOB:" << cricketer::dob << "\nTotal match played:" << cricketer::num_match<< endl;
    }  
};

class bowler:virtual public cricketer
{
    protected:
    int wkt;
    int avg_eco;
public:
        void get_data(char *n, char *d, int m,int w,int avg_e)
        {
            cricketer::get_data(n,d,m);
            wkt=w;
            avg_eco=avg_e;
        }    
        void show_data()
        {
            cout << "Name:" << cricketer::name << "\nDOB:" << dob << "\nTotal match played:" << num_match << endl;
            cout << "total wicket taken:" << wkt << "\naverage economy:" << avg_eco << "\n";
    }
};

class batsman :virtual public cricketer
{
protected:
    int score;
    int avg_score;
public:
    void get_data(char *n, char *d, int m, int s, int a)
    {
        cricketer::get_data(n,d,m);
        score=s;
        avg_score = a;
    }
    void show_data()
    {
        cout << "Name:" << cricketer::name << "\nDOB:" << dob << "\nTotal match played:" << num_match << endl;
        cout << "total runs scored:" << score << "\naverage score:" << avg_score << "\n";
    }
};

class wpair
{
    bowler *bw;
    batsman *bt;
public:
    void get_data()
    {
        bw=new bowler;
        bt=new batsman;
        char name1[31],name2[31],dob1[11],dob2[11];
        int match1,match2,w,avg_ec,avg_s,s;
        cout<<"enter the detail of the bowler(name,dob,matches palyed,wicket,average economy):\n";
        cin>>name1>>dob1>>match1>>w>>avg_ec;
        bw->get_data(name1,dob1,match1,w,avg_ec);
        cout << "enter the detail of the batsman(name,dob,matches palyed,run scored,average score):\n";
        cin >> name2 >> dob2 >> match2 >> s>> avg_s;
        bt->get_data(name2,dob2,match2,s,avg_s);
    }
    void show_data()
    {
        cout<<"Detail of the bowler:\n";
        bw->show_data();
        cout << "\nDetail of the batsman:\n";
        bt->show_data();
    }
    ~wpair()
    {
        delete bw;
        delete bt;
    }
};

class allrounder:public bowler,public batsman
{
    public:
    void get_data(char *name,char *dob,int matches,int wk,int score,int avg_e,int avg_s)
    {
        bowler::get_data(name,dob,matches,wk,avg_e);
        batsman::get_data(name,dob,matches,score,avg_s);
    }
    void show_data()
    {
        cout << "Name:" << cricketer::name << "\nDOB:" << dob << "\nTotal match played:" << num_match << endl;
        cout << "total runs scored:" << score << "\naverage score:" << avg_score << "\n";
        cout << "total wicket taken:" << wkt << "\naverage economy:" << avg_eco << "\n";
    }
};

int main()
{
    bowler b1;
    b1.get_data("rita","28/07/2001",3,6,78);
    b1.show_data();
    batsman b2;
    b2.get_data("swa","13/06/2001",5,122,67);
    b2.show_data();
    wpair p;
    p.get_data();
    p.show_data();
    allrounder a1;
    a1.get_data("Sri","45/67/2020",7,888,99,888,99);
    a1.show_data();
}