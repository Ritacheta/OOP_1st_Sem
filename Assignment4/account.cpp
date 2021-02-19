#include<iostream>
#include<string.h>
#define MAX_SIZE 100
using namespace std;

class Account
{
    int acc_no;
    double balance;
    public:
    void get_data(int ac=0,double b=0)
    {
        acc_no=ac;
        balance=b;
    }
    void show_data()
    {
        cout<<"Balance for account no. "<<acc_no<<" is Rs."<<balance<<endl;
    }
    int get_acc_no()
    {
        return acc_no;
    }
    double get_balance()
    {
        return balance;
    }
    void update(double ammount)
    {
        balance-=ammount;
    }
};

class Withdraw
{
    int acc_no;
    double ammount;
    public:
    Withdraw(int a_no,double am=0)
    {
        acc_no=a_no;
        ammount=am;
    }
    int get_acc()
    {
        return acc_no;
    }
    double get_amount()
    {
        return ammount;
    }
};

class List
{
    static int last_id;
    Account list[MAX_SIZE];
    public:
    void add_account(int acc_no,double bal=0)
    {
        for(int i=0;i<=last_id;i++)
        {
            if(list[i].get_acc_no()==acc_no)
            {
                cout<<"An account already exists with the same!!"<<endl;
                return;
            }           
        }
        list[last_id].get_data(acc_no, bal);
        last_id++;
    }
    void show_info()
    {
        for(int i=0;i<last_id;i++)
        {
            list[i].show_data();
        }
    }
    void search(int acc_no)
    {
        for(int i=0;i<last_id;i++)
        {
            if(list[i].get_acc_no()==acc_no)
            {
                list[i].show_data();
                return;
            }
        }
        cout<<"Sorry!! Account with this number doesn't exists."<<endl;
    }
    void update(Withdraw w)
    {
        for(int i=0;i<last_id;i++)
        {
            if(list[i].get_acc_no()==w.get_acc())
            {
                if(list[i].get_balance()>w.get_amount())
                {
                    list[i].update(w.get_amount());
                    cout<<"Successfully Withdrawn!!"<<endl;
                    return;
                }
                else
                {
                    cout<<"Insufficient balance to withdraw!!"<<endl;
                    return;
                }
                
            }
        }
        cout<<"Failed!!"<<endl;
    }
};
int List::last_id=0;
int main()
{
    List l1;
    l1.add_account(1234,8986.00);
    l1.add_account(4321,7889);
    l1.add_account(1234);
    l1.show_info();
    l1.search(4321);
    Withdraw w1(1234,1000.00);
    l1.update(w1);
    l1.show_info();
}