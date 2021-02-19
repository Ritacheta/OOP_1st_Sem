#include<iostream>
#include <iomanip>
using namespace std;

class TIME
{
    int hour;
    int min;
    int sec;
    public:
    void take_input(int h,int m,int s,string format);
    void display(int h, int m, int s);
    void add(int add);
};

void TIME :: take_input(int h,int m,int s, string format)
{
    if(format != "AM" || "PM")
    {
        if(h<=23 && m<60 && s<60)
        {
            hour = h;
            min=m;
            sec=s;
        }
        else
        {
            cout<<"Invalid Input!!"<<endl;
            return;
        }
        
    }
    else
    {
        if(h<12 && m<60 && s<60)
        {
            if (format == "AM")
            {
                hour = h;
                min= m;
                sec= s;
            }
            else if(format =="PM")
            {
                hour = h+12;
                min = m;
                sec = s;
            }}
        else
        {
            cout << "Invalid Input!!" << endl;
            return;
        }
        
    }
}

void TIME :: display(int h,int m,int s)
{
    int c;
    cout<<"in which format do you want to see the time?"<<endl<<"1.24-hour format"<<endl<<"2.12-hour format"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0')<< s << endl;
        break;
        case 2:
        if(h<12)
        {
            cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s <<"AM"<<endl;
            break;
        }
        else
        {
           cout<< setw(2) << setfill('0') << (h-12) << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s <<"PM"<<endl;
           break;
        }
        default:cout<<"ERROR!!"<<endl;
        break;
    }    
}

void TIME::add(int add)
{
    min+=add;
    hour+=(min/60);
    min%=min;
}

int main()
{
    TIME t;
    int c,h,s,m;
    string format;
    cout<<"enter time in 1. 24 hour format(hour:min:sec)"<<endl<<"OR"<<endl<<"2. in 12 hour format (hour:min:sec AM/PM)"<<endl;
    cout<<"enter choice"<<endl;
    cin>>c;
    if(c==1)
    {
        cin>>h>>m>>s;
        t.take_input(h,m,s,format=' ');
    }
    else if(c==2)
    {
        cin>>h>>m>>s>>format;
        t.take_input(h,m,s,format);
    }
    t.display(h,m,s);
    cout<<"enter minutes to add time";
    int add;
    cin>>add;
    t.add(add);
    t.display(h,m,s);
    return 0;

}