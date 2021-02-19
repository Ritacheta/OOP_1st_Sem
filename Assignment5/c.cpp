#include <bits/stdc++.h>
using namespace std;

class BOOK;

class BOOK_LIST
{
    BOOK *books;

public:
    static int last_ind;
    BOOK_LIST(int);
    void add_book(int, char *, char *, char *, float, int);
    int transaction_slip(int, int, int *);
    void display_books();
};

class BOOK
{
    int id, serial, issued_to_id;
    char title[30], author[30], publisher[30];
    float price;

public:
    BOOK()
    {
        id = -1;
    }
    void set_book(int i, int s, char t[], char a[], char p[], float pr)
    {
        issued_to_id = -1;
        id = i;
        serial = s;
        price = pr;
        strcpy(title, t);
        strcpy(author, a);
        strcpy(publisher, p);
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Serial No: " << serial << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl
             << endl;
    }
    friend void BOOK_LIST::add_book(int i, char t[], char a[], char p[], float pr, int);
    friend int BOOK_LIST::transaction_slip(int, int, int *);
};

BOOK_LIST::BOOK_LIST(int n = 10)
{
    books = new BOOK[n];
}

void BOOK_LIST::add_book(int book_id, char t[], char a[], char p[], float pr, int ser = -1)
{
    if (ser == -1)
    {
        int count = 0;
        for (int i = 0; i < last_ind; i++)
        {
            if (books[i].id == book_id)
            {
                count++;
            }
        }
        ser = ++count;
    }
    books[++last_ind].set_book(book_id, ser, t, a, p, pr);
}

int BOOK_LIST::transaction_slip(int mem_id, int book_id, int *serial)
{
    if (*serial == -1)
    {
        for (int i = 0; i < last_ind; i++)
        {
            if (books[i].id == book_id && books[i].issued_to_id == -1)
            {
                books[i].issued_to_id = mem_id;
                *serial = books[i].serial;
                return 2;
            }
        }
        return 1;
    }
    else
    {
        for (int i = 0; i < last_ind; i++)
        {
            if (books[i].id == book_id && books[i].serial == *serial)
            {
                books[i].issued_to_id = -1;
                return -2;
            }
        }
        return -1;
    }
}

void BOOK_LIST::display_books()
{
    cout << "BOOK LIST:\n";
    for (int i = 0; i <= last_ind; i++)
    {
        books[i].display();
    }
}

int BOOK_LIST::last_ind = -1;

class MEMBER
{
    int id;
    char name[30], mail[20], add[50];

protected:
    int no_of_books;

public:
    MEMBER(int i, char nm[], char m[], char ad[])
    {
        id = i;
        strcpy(name, nm);
        strcpy(mail, m);
        strcpy(add, ad);
        no_of_books = 0;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "E-Mail: " << mail << endl;
        cout << "Address: " << add << endl
             << endl;
    }
    int transaction_slip(BOOK_LIST *bl, int mem_id, int book_id, int *serial)
    {
        if (mem_id == id)
        {
            const int x = (*bl).transaction_slip(mem_id, book_id, serial);
            switch (x)
            {
            case 2:
                cout << "Book successfully issued!" << endl;
                no_of_books++;
                return 1;
            case 1:
                cout << "No Book available!!" << endl;
                return 0;
            case -2:
                cout << "Book returned successfully!" << endl;
                no_of_books--;
                return -1;
            case -1:
                cout << "Book id or serial not found!!" << endl;
                return 0;
            }
        }
        else
        {
            cout << "Member Id does not match!!" << endl;
            return 0;
        }
    }
};

class STUDENT : public MEMBER
{
    int max_books;

public:
    STUDENT(int i, char nm[], char m[], char ad[]) : MEMBER(i, nm, m, ad)
    {
        max_books = 2;
    }
    int transaction_slip(BOOK_LIST *bl, int mem_id, int book_id, int *serial)
    {
        if (*serial == -1 && max_books == no_of_books)
        {
            cout << "Maximum Limit Reached!\n";
            return 0;
        }
        int fl = MEMBER::transaction_slip(bl, mem_id, book_id, serial);
        return fl;
    }
};

class FACULTY : public MEMBER
{
    int max_books;

public:
    FACULTY(int i, char nm[], char m[], char ad[]) : MEMBER(i, nm, m, ad)
    {
        max_books = 10;
    }
    int transaction_slip(BOOK_LIST *bl, int mem_id, int book_id, int *serial)
    {
        if (*serial == -1 && max_books == no_of_books)
        {
            cout << "Maximum Limit Reached!\n";
            return 0;
        }
        int fl = MEMBER::transaction_slip(bl, mem_id, book_id, serial);
        return fl;
    }
};

class TRANSACTION
{
    char date[15];
    int mem_id, book_id, serial, returned;

public:
    TRANSACTION(char dt[], int mid, int bid)
    {
        returned = -1;
        strcpy(date, dt);
        mem_id = mid;
        book_id = bid;
        serial = -1;
    }
    void issue_book(FACULTY *f, BOOK_LIST *bl)
    {
        if (serial != -1)
        {
            cout << "Transaction already made!";
            return;
        }
        int fl = (*f).transaction_slip(bl, mem_id, book_id, &serial);
        if (fl == 1)
            returned = 0;
    }
    void issue_book(STUDENT *s, BOOK_LIST *bl)
    {
        if (serial != -1)
        {
            cout << "Transaction already made!";
            return;
        }
        int fl = (*s).transaction_slip(bl, mem_id, book_id, &serial);
        if (fl == 1)
            returned = 0;
    }
    void return_book(FACULTY *f, BOOK_LIST *bl, char dt[])
    {
        if (serial == -1)
        {
            cout << "No Transaction has been made!\n";
            return;
        }
        int fl = (*f).transaction_slip(bl, mem_id, book_id, &serial);
        if (fl == -1)
        {
            returned = 1;
            strcpy(date, dt);
        }
    }
    void return_book(STUDENT *s, BOOK_LIST *bl, char dt[])
    {
        if (serial == -1)
        {
            cout << "No Transaction has been made!\n";
            return;
        }
        int fl = (*s).transaction_slip(bl, mem_id, book_id, &serial);
        if (fl == -1)
        {
            returned = 1;
            strcpy(date, dt);
        }
    }
    void display_current_status()
    {
        cout << "DATE: " << date << endl;
        cout << "MEMBER ID: " << mem_id << endl;
        cout << "BOOK ID: " << book_id << endl;
        if (serial != -1)
            cout << "Serial Number: " << serial << endl;
        cout << "Retuned: " << (returned >= 1 ? "True" : "False") << endl
             << endl;
    }
};

int main()
{
    BOOK_LIST bl;
    bl.add_book(100, "BOOK1", "AUTH", "PUB", 101.5);
    bl.add_book(101, "BOOK2", "AUTH", "PUB", 110.5);
    bl.add_book(100, "BOOK1", "AUTH", "PUB", 101.5);
    bl.add_book(102, "BOOK3", "AUTH", "PUB", 109.5);
    bl.display_books();
    STUDENT s1(1001, "Swadesh", "swadesh@gmail.com", "Kolkata");
    s1.display();
    TRANSACTION t1("22/11/2020", 1001, 100);
    t1.issue_book(&s1, &bl);
    t1.display_current_status();
    t1.return_book(&s1, &bl, "29/11/2020");
    t1.display_current_status();
    return 0;
}