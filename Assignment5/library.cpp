#include<iostream>
#include<string.h>
using namespace std;
class Book_list;
class Transaction;
class Book
{
    int book_id;
    int serial;
    char title[100];
    char author[31];
    char publisher[51];
    double price;
    int issued;
    friend Book_list;
    friend Transaction;
    public:
    void get_data(int id,int s,char t[],char a[],char p[],double pr)
    {
        book_id=id;
        serial=s;
        strcpy(title,t);
        strcpy(author,a);
        strcpy(publisher,p);
        price=pr;
        issued=-1;
    }
    void show_data()
    {
        cout<<"book ID:"<<book_id<<"\nserial number:"<<serial<<"\nTitle:"<<title<<"\nAuthor:"<<author;
        cout<<"\nPublisher:"<<publisher<<"\nPrice:"<<price<<endl;
    }
};

class Book_list
{
    
    Book *b;
    static int last_id;
    friend Transaction;
    public:
    Book_list(int n=1)
    {
        b=new Book[n];
    }
    void add_book(int id, int s, char t[], char a[], char p[],double pr)
    {
        for(int i=0;i<last_id;i++)
        {
            if(b[i].book_id==id && b[i].serial==s)
            {
                cout<<"A book with the same Id and serial number already exist!!"<<endl;
                return;
            }
        }
        b[last_id].get_data(id,s,t,a,p,pr);
        last_id++;
    }
    void show_book_list()
    {
        for(int i=0;i<last_id;i++)
        {
            b[i].show_data();
        }
    }
    int Is_availble(int b_id,int s)
    {
        for (int i = 0; i < last_id; i++)
        {
            if (b[i].book_id == b_id && b[i].serial == s && b[i].issued==-1)
            {
                return 0;
            }
        }
        return 1;
    }
    ~Book_list()
    {
        delete[] b;
        cout<<"\nDestroyed\n";
    }
};
int Book_list::last_id=0;

class member
{
    protected:
    static int last_id;
    int member_id;
    char name[31];
    char email[51];
    char address[101];
    int num_book;
    public:
    member(char n[],char em[],char ad[])
    {
        last_id++;
        member_id=last_id;
        strcpy(name,n);
        strcpy(email,em);
        strcpy(address,ad);
        num_book=0;
    }
    virtual void show_details()=0;
};
int member::last_id=0;
class student:public member
{
    int max_book;
    int student_id;
    friend Transaction;
    public:
    student(char n[],char em[],char add[]):member(n,em,add)
    {
        max_book=2;
        student_id=member_id;
    }
    void show_details()
    {
        cout<<"Name of the Student:"<<name<<"\nID:"<<student_id<<"\nEmail"<<email<<"\nAddress:"<<address<<endl;
    }
};
class faculty:public member
{
    int max_book;
    int faculty_id;
    friend Transaction;
public:
    faculty(char n[], char em[], char add[]) : member(n, em, add)
    {
        max_book = 10;
        faculty_id = member_id;
    }
    void show_details()
    {
        cout << "Name of the Faculty:" << name << "\nID:" << faculty_id << "\nEmail" << email << "\nAddress:" << address << endl;
    }
};

class Transaction
{
    char date[11];
    int book_ID,mem_ID,serial,returned;
    public:
    Transaction(int b_id,int m_id,int ser,char d[])
    {
        book_ID=b_id;
        mem_ID=m_id;
        serial=ser;
        strcpy(date,d);
        returned=-1;
    }
    void issue_book(Book_list &bl,student &s,char d[])
    {
        for(int i=0;i<bl.last_id;i++)
        {
            if (bl.b[i].book_id == book_ID && bl.b[i].serial == serial)
                {if (bl.Is_availble(book_ID, serial) == 0 && s.num_book < s.max_book)
                {
                    s.num_book += 1;
                    strcpy(date, d);
                    bl.b[i].issued = 1;
                    cout<<"successfully issued\n";
                    return;
                }}
        }
        cout<<"\nthe book is not available or max limit crossed\n";
    }
    void issue_book(Book_list &bl, faculty &f, char d[])
    {
        for (int i = 0; i < bl.last_id; i++)
        {
            if(bl.b[i].book_id==book_ID && bl.b[i].serial == serial)
            {if (bl.Is_availble(book_ID, serial) == 0 && f.num_book < f.max_book)
            {
                f.num_book += 1;
                strcpy(date, d);
                bl.b[i].issued = 1;
                cout << "successfully issued\n";
                return;
            }
        }}
        cout << "\nthe book is not available or max limit crossed\n";
    }
    void return_book(Book_list &bl, faculty &f, char d[])
    {
        for (int i = 0; i < bl.last_id; i++)
        {
            if (bl.b[i].book_id == book_ID && bl.b[i].serial == serial)

                {if (bl.Is_availble(book_ID, serial) == 1)
                {
                    f.num_book -= 1;
                    strcpy(date, d);
                    returned = 0;
                    bl.b[i].issued = -1;
                    cout << "successfully returned\n";
                    return;
                }}
        }
        cout << "\nthe book was not issued or Invalid\n";
    }
    void return_book(Book_list &bl, student &s, char d[])
    {
        for (int i = 0; i < bl.last_id; i++)
        {
            if (bl.b[i].book_id == book_ID && bl.b[i].serial == serial)

                {if (bl.Is_availble(book_ID, serial) == 1)
                {
                    s.num_book -= 1;
                    strcpy(date, d);
                    returned = 0;
                    bl.b[i].issued = -1;
                    cout << "successfully returned\n";
                    return;
                }}
        }
        cout << "\nthe book was not issued or Invalid\n";
    }
};

int main()
{
    Book_list b(10);
    b.add_book(100,2,"book","author","pub",670);
    b.add_book(101, 2, "book", "author", "pub",900);
    b.show_book_list();
    student s("Ritacheta","rita@gmail.com","keshiary");
    faculty f("CSE","cse@gail.com","kolkata");
    s.show_details();
    f.show_details();
    Transaction t(100,2,2,"12/05/2020");
    t.issue_book(b,s,"12/06/2020");
    t.return_book(b,s,"12/07/2020");
    return 0;
}

