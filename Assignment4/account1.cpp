#include<iostream>
using namespace std;
class Account;
class Withdraw
{
    int acc_no;
    double amount;

public:
    Withdraw(int acc, double am = 0);
    void update(Account &a);
};
class Account
{
    static int last_id;
    int acc_no;
    double balance;
    Account *ptr;
    void show(int n)
    {
        cout << "Balance for Account No.:" << ptr[n].acc_no << " = " << ptr[n].balance << endl;
    }
    public:
    Account(int acc=0,double b=0);
    void show_list();
    void search(int acc);
    friend void Withdraw::update(Account &a);
};
int Account::last_id=0;
Account::Account(int acc=0,double b=0)
{
    if(acc!=0)
    {
        for(int i=0;i<last_id;i++)
        {
            if(ptr[i].acc_no==acc)
            {
                cout<<"Account already exists!!"<<endl;
                return;
            }
        }
        ptr[last_id].acc_no=acc;
        ptr[last_id].balance=b;
        last_id++;
    }     
}

void Account::show_list()
{
    for(int i=0;i<last_id;i++)
    {
        cout<<"Balance for Account No.:"<<ptr[i].acc_no<<" = "<<ptr[i].balance<<endl;
    }
}
void Account::search(int acc)
{
    for(int i=0;i<last_id;i++)
    {
        if(ptr[i].acc_no==acc)
        {
            show(i);
            return;
        }
    }
    cout<<"SORRY!! account doesn't exist."<<endl;
}

Withdraw::Withdraw(int acc,double am=0)
{
    acc_no=acc;
    amount=am;
}

void Withdraw::update(Account &a)
{
    for(int i=0;i<a.last_id;i++)
    {
        if(a.ptr[i].acc_no==acc_no && amount<a.ptr[i].balance)
        {
            a.ptr[i].balance-=amount;
            cout<<"Successfully withdrawn!!"<<endl;
        }
    }
    cout<<"Failed"<<endl;
}

int main()
{
    Account a1(1234,23459.00);
    Account a2(1232);
    a1.show_list();
    a1.search(1234);
    Withdraw w1(1234,1000);
    w1.update(a1);
    a1.show_list();
    return 0;
}