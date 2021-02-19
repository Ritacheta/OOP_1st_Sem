#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;
class Transaction;
class Book
{
    int book_id;
    int serial;
    char title[51],author[31],publisher[31];
    double price;
    int issued;
    friend Transaction;
    bool check_unique(int id,int ser)
    {
        Book b;
        ifstream fin;
        fin.open("book.dat",ios::binary);
        while(fin.read((char*)&b,sizeof(Book)))
        {
            if(b.book_id==id && b.serial==ser)
            {
                fin.close();
                return false;
            }
        }
        fin.close();
        return true;
    }
public:
    Book()
    {
        book_id =-1;
    }
    void get_data(int id, int s, char t[],char a[], char p[], double pr)
    {
        if(check_unique(id,s))
        {
            book_id = id;
            serial = s;
            strcpy(title,t);
            strcpy(author,a);
            strcpy(publisher,p);
            price = pr;
            issued = -1;
        }
    }
    void show_data()
    {
        cout << "book ID:" << book_id << "\nserial number:" << serial << "\nTitle:" << title << "\nAuthor:" << author;
        cout << "\nPublisher:" << publisher << "\nPrice:" << price << endl;
    }
    bool is_book(int id,int s)
    {
        return(book_id==id && serial==s);
    }
};
class member
{
protected:
    static int last_id;
    int member_id;
    char name[31],email[51],address[51];
    int num_book;
public:
    member()
    {
        member_id=-1;
    }
    member(char n[],char em[], char ad[])
    {
        last_id++;
        member_id = last_id;
        strcpy(name,n);
        strcpy(email, em);
        strcpy(address,ad);
        num_book = 0;
    }
    int get_id(){return member_id;}
    virtual void show_details() = 0;
};
int member::last_id = 0;
class student : public member
{
    int max_book;
    int student_id;
    friend Transaction;

public:
    student():member()
    {
        student_id=-1;
    }
    student(char n[],char em[], char ad[]): member(n, em, ad)
    {
        max_book = 2;
        student_id = member_id;
    }
    void show_details()
    {
        cout << "Name of the Student:" << name << "\nID:" << student_id << "\nEmail" << email << "\nAddress:" << address << endl;
    }
};
class faculty : public member
{
    int max_book;
    int faculty_id;
    friend Transaction;
public:
    faculty():member()
    {
        faculty_id = -1;
    }
    faculty(char n[], char em[], char ad[]) : member(n, em, ad)
    {
        max_book = 10;
        faculty_id = member_id;
    }
    void show_details()
    {
        cout << "Name of the Faculty:" << name << "\nID:" << faculty_id << "\nEmail" << email << "\nAddress:" << address << endl;
    }
};

class library_file
{
public:
    void store_book(const Book &b)
    {
        ofstream of;
        of.open("book.dat", ios::binary | ios::app);
        of.write((char *)&b, sizeof(Book));
        of.close();
    }
    void read_book()
    {
        Book b;
        ifstream f;
        f.open("book.dat", ios::binary);
        while (f.read((char *)&b, sizeof(Book)))
        {
            b.show_data();
        }
        f.close();
    }
    Book get_book(int id,int ser)
    {
        Book b;
        ifstream fin;
        fin.open("book.dat",ios::binary);
        while(fin.read((char*)&b,sizeof(Book)))
        {
            if(b.is_book(id,ser))
            {
                fin.close();
                return b;
            }
        }
        fin.close();
        Book bk;
        return bk;
    }
    student get_student(int id)
    {
        student s;
        ifstream fin;
        fin.open("student.dat", ios::binary);
        while (fin.read((char *)&s, sizeof(student)))
        {
            if (s.get_id()==id)
            {
                fin.close();
                return s;
            }
        }
        fin.close();
        student st;
        return st;
    }
    faculty get_faculty(int id)
    {
        faculty s;
        ifstream fin;
        fin.open("faculty.dat", ios::binary);
        while (fin.read((char *)&s, sizeof(faculty)))
        {
            if (s.get_id() == id)
            {
                fin.close();
                return s;
            }
        }
        fin.close();
        faculty ft;
        return ft;
    }
    void store_student(const student &s)
    {
        ofstream of;
        of.open("student.dat", ios::binary | ios::app);
        of.write((char *)&s, sizeof(student));
        of.close();
    }
    void store_faculty(const faculty &f)
    {
        ofstream of;
        of.open("faculty.dat", ios::binary | ios::app);
        of.write((char *)&f, sizeof(faculty));
        of.close();
    }
    void store_trans_info(const Transaction &t);
};
class Transaction
{
    static int last_id;
    char date[11];
    int book_ID, mem_ID, serial, returned;
    int trans_id;

public:
    Transaction(int b_id, int m_id, int ser)
    {
        last_id++;
        trans_id = last_id;
        book_ID = b_id;
        mem_ID = m_id;
        serial = ser;
        returned = -1;
    }
    void issue_book(char d[])
    {
        library_file lb;
        Book b = lb.get_book(book_ID, serial);
        student s = lb.get_student(mem_ID);
        faculty f = lb.get_faculty(mem_ID);
        if (b.book_id != -1 && f.faculty_id != -1 && f.num_book < f.max_book)
        {
            b.issued = 1;
            strcpy(date,d);
            f.num_book += 1;
            cout << "successfully issued\n";
            return;
        }
        else if (b.book_id != -1 && s.student_id != -1 && s.num_book < s.max_book)
        {
            b.issued = 1;
            strcpy(date, d);
            s.num_book += 1;
            cout << "successfully issued\n";
            return;
        }
        cout << "\nthe book is not available or max limit crossed\n";
    }
    void return_book(char d[])
    {
        library_file lb;
        Book b = lb.get_book(book_ID, serial);
        student s = lb.get_student(mem_ID);
        faculty f = lb.get_faculty(mem_ID);
        if (b.book_id != -1 && f.faculty_id != -1)
        {
            b.issued = -1;
            strcpy(date, d);
            f.num_book -= 1;
            returned = 0;
            cout << "successfully returned\n";
            return;
        }
        else if (b.book_id != -1 && s.student_id != -1)
        {
            b.issued = -1;
            strcpy(date, d);
            s.num_book -= 1;
            returned = 0;
            cout << "successfully returned\n";
            return;
        }
        cout << "\nInvalid\n";
    }
};
int Transaction::last_id = 0;
void library_file::store_trans_info(const Transaction &t)
{
    ofstream of;
    of.open("transaction.dat", ios::binary | ios::app);
    of.write((char *)&t, sizeof(Transaction));
    of.close();
}
int main()
{
    library_file lf;
    student s("Ritacheta", "rita@gmail.com", "keshiary");
    faculty f("CSE", "cse@gail.com", "kolkata");
    Book b1,b2,b3;
    b1.get_data(1,3,"book","author","pub",908);
    b2.get_data(2, 3, "book", "author", "pub", 1008);
    b3.get_data(2, 3, "book", "author", "pub", 1008);
    b3.show_data();
    lf.store_book(b1);
    lf.store_book(b2);
    lf.store_student(s);
    lf.store_faculty(f);
    Transaction t(2,2,3);
    t.issue_book("23/09/2020");
    t.return_book("23/89/2345");
    lf.store_trans_info(t);
    lf.read_book();
}