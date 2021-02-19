#include <iostream>
#include <string.h>
#define MAX_SIZE 100
using namespace std;
class Withdraw;
class Account
{
    int acc_no;
    double balance;

public:
    void get_data(int ac = 0, double b = 0)
    {
        acc_no = ac;
        balance = b;
    }
    void show_data()
    {
        cout << "\nBalance for account no. " << acc_no << " is Rs." << balance << endl;
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
        balance -= ammount;
    }
};

class List
{
    static int last_id;
    Account list[MAX_SIZE];
    friend Withdraw;

public:
    void add_account(int acc_no, double bal = 0)
    {
        for (int i = 0; i <= last_id; i++)
        {
            if (list[i].get_acc_no() == acc_no)
            {
                cout << "\nAn account already exists with the same!!" << endl;
                return;
            }
        }
        list[last_id].get_data(acc_no, bal);
        last_id++;
    }
    void show_info()
    {
        for (int i = 0; i < last_id; i++)
        {
            list[i].show_data();
        }
    }
    void search(int acc_no)
    {
        for (int i = 0; i < last_id; i++)
        {
            if (list[i].get_acc_no() == acc_no)
            {
                list[i].show_data();
                return;
            }
        }
        cout << "\nSorry!! Account with this number doesn't exists." << endl;
    }
};
int List::last_id = 0;
class Withdraw
{
    int acc_no;
    double amount;

public:
    Withdraw(List &l, int a_no, double am = 0)
    {
        for (int i = 0; i < l.last_id; i++)
        {
            if (l.list[i].get_acc_no() == a_no && l.list[i].get_balance() > am)
            {
                l.list[i].update(am);
                cout << "\nSuccessfully updated\n";
            }
        }
        cout << "\nInvalid account or Insuffisient Balance!!\n";
    }
};

int main()
{
    List l1;
    l1.add_account(1234, 8986.00);
    l1.add_account(4321, 7889);
    l1.add_account(1234);
    l1.show_info();
    l1.search(4321);
    Withdraw w1(l1, 1234, 9000);
    l1.show_info();
}