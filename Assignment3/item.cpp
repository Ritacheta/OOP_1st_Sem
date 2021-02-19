#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

class Item
{
    int item_code;
    char name[20];
    int rate;
    int qty;
    public:
    void get_data(int ic,char* a,int r, int q)
    {
        item_code=ic;
        strcpy(name,a);
        rate=r;
        qty=q;
    }
    void show_data()
    {
        cout<<"item code"<<item_code<<endl;
        cout<<"the name of the item is:"<<name<<endl;
        cout<<"rate of the item:"<<rate<<endl;
        cout<<"quantity available:"<<qty<<endl;
    }
    void update_rate()
    {
        int r;
        cout<<"enter the new rate"<<endl;
        cin>>r;
        rate =r;
        cout<<"rate is updated"<<endl;
    }
    void update_stock(int qt)
    {
        qty-=qt;
        cout<<"Upadted Successfully!!"<<endl;
    }
    int get_code()
    {
        return item_code;
    }
    int get_qty()
    {
        return qty;
    }
};

class Item_list
{
    static int lastId;
    Item item[MAX_SIZE];
    public:
    void add_item(int ic, char *a, int r, int q);
    void show_item(int item_code);
    void update_rate(int item_code);
    void issue(int code,int qt);
    void show_list();
};

int Item_list::lastId = 0;

void Item_list::add_item(int ic, char a[], int r=0, int q=0)
{
    for (int i = 0; i < lastId; i++)
    {
        if (item[i].get_code() == ic)
        {
            cout << "the item is already here!!" << endl;
            return;
        }
    }
    item[lastId].get_data(ic, a, r, q);
    lastId++;
}

void Item_list::show_item(int item_code)
{
    for(int i=0;i<lastId;i++)
    {
        if(item[i].get_code()==item_code)
        {
            item[i].show_data();
            return;
        }
    }
    cout<<"item not available!"<<endl;
}

void Item_list::update_rate(int item_code)
{
    for (int i = 0; i < lastId; i++)
    {
        if (item[i].get_code() == item_code)
        {
            item[i].update_rate();
            return;
        }
    }
    cout << "item not available!" << endl;
}
void  Item_list::issue(int code,int qt)
{
    for(int i=0;i<lastId;i++)
    {
        if(item[i].get_code()==code)
        {
            if(item[i].get_qty()>=qt)
            {
                item[i].update_stock(qt);
            }
        }
    }
}
void Item_list::show_list()
{
    for(int i=0;i<lastId;i++)
    {
        item[i].show_data();
    }
}
int main()
{
    Item_list i1;
    i1.add_item(2,"dress",45,67);
    i1.add_item(5,"shoes",56,90);
    i1.add_item(4,"tyehnn",78,90);
    i1.show_item(2);
    i1.show_list();
    i1.update_rate(4);
    i1.show_item(4);
    i1.issue(4,10);
    i1.show_item(4);
    return 0;
}