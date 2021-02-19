#include<iostream>
#include<string.h>
using namespace std;

class employee
{
    static int last_id;
    int id;
    char name[31];
    char designation[31];
    double basic_salary;
    public:
    employee(char *n,char *des)
    {
        last_id++;
        id=last_id;
        strcpy(name,n);
        strcpy(designation,des);
        basic_salary=10000;
    }
    virtual double compute_salary()=0;
    double get_basic(){return basic_salary;}
    virtual void show_data()
    {
        cout<<"ID:"<<id<<"\nName:"<<name<<"\nDesignation:"<<designation<<"\nBasic Salary:"<<basic_salary<<endl;
    }
};
int employee::last_id=0;
class permanent:public employee
{
    double salary;
    public:
    double compute_salary()
    {
       double s = get_basic() * 11 / 10;
        return s;
    }
    permanent(char* n,char *des):employee(n,des)
    {
        salary=compute_salary();
    }
    void show_data()
    {
        employee::show_data();
        cout<<"Salary:"<<salary<<endl;
    }
};

class contractual : public employee
{
    double salary;
    double allowance;
public:
    contractual(char *n, char *des,double al) : employee(n, des)
    {
        allowance=al;
        salary=compute_salary();
    }
    double compute_salary()
    {
        double s=get_basic()+allowance;
        return s;
    }
    void show_data()
    {
        employee::show_data();
        cout << "Salary:" << salary << endl;
    }
};

int main()
{
    employee *a;    
    permanent p("Ritacheta","manager");
    a=&p;
    a->show_data();
    contractual c("Sri","intern",5000);
    a=&c;
    a->show_data();
    return 0;
}