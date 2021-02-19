#include<iostream>
#include<string.h>
using namespace std;

class BALANCE;

class TRANSACTION
{
    int acc_no;
    char date_trans[10];
    int amount;
    char type;
    public:
    void get_data(int ac,char *a,int am,char t)
    {
        acc_no=ac;
        strcpy(date_trans,a);
        amount=am;
        type=t;
    }
    void show_data()
    {
        cout<<"account number:"<<acc_no<<endl;
        cout<<"date of transaction:"<<date_trans<<endl;
        if(type=='W' || type=='w')
        {
            cout<<amount<<" will be be withdrawn "<<endl;
            return;
        }
        else if(type == 'D' || type=='d')
        {
            cout << amount << " will be deposited " << endl;
            return;
        }
    }
    void update(BALANCE &b);
};

class BALANCE
{
    int acc_no;
    int balance;
    char date_update[10];
    public:
    void get_data(int acc,int b,char* a)
    {
        acc_no=acc;
        balance=b;
        strcpy(date_update,a);
    }
    void show_data()
    {
        cout<<"account number: "<<acc_no<<endl;
        cout<<"current balance : "<<balance<<endl;
        cout<<"last date of update : "<<date_update<<endl;
    }
    friend void TRANSACTION::update(BALANCE &b);
};

void TRANSACTION::update(BALANCE &b)
{
    if(b.acc_no==acc_no)
    {
        if(type=='W'|| type=='w')
        {
            if(amount>b.balance)
            {
                cout<<"current balance is not sufficient to withdraw amount :"<<amount<<endl;
                return;
            }
            else
            {
                b.balance=b.balance-amount;
                cout<<"Transaction successful"<<endl;
                strcpy(b.date_update,date_trans);
                return;
            }
            
        }
        else if (type == 'D' || type == 'd')
        {
            if (amount > b.balance)
            {
                cout << "current balance is not sufficient to deposit amount :" << amount << endl;
                return;
            }
            else
            {
                b.balance = b.balance - amount;
                cout << "Transaction successful" << endl;
                strcpy(b.date_update, date_trans);
                return;
            }
        }
    }
    else
    {
        cout<<"sorry!! invalid account number"<<endl;
        return;
    }
    
}

int main()
{
    BALANCE b1;
    b1.get_data(123321,56767,"23/08/2020");
    b1.show_data();
    TRANSACTION t1,t2;
    t1.get_data(123321,"12/10/2020",7899,'w');
    t1.show_data();
    t2.get_data(123321,"23/09/2020",345566,'d');
    t1.update(b1);
    t2.update(b1);
    b1.show_data();
    return 0;
}