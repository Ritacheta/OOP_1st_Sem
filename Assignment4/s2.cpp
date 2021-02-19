#include <bits/stdc++.h>
using namespace std;

#define MAX_SUBJECTS 6

class STUDENT;
class SUBJECT_LIST;
class STUDENT_LIST
{
    STUDENT *students;

public:
    static int last_ind;
    STUDENT_LIST(int);
    void add_student(int, int, char *);
    void display_list();
    void select_subject(SUBJECT_LIST *, int, int);
    void display_subjects(int);
    void display_students(int);
};

int STUDENT_LIST::last_ind = -1;

class STUDENT
{
    int roll, phn;
    char name[30];
    int subjects[MAX_SUBJECTS];

public:
    void set_data(int r, int ph, char nm[])
    {
        roll = r;
        phn = ph;
        strcpy(name, nm);
        for (int i = 0; i < MAX_SUBJECTS; i++)
        {
            subjects[i] = -1;
        }
    }
    void display()
    {
        cout << "ROLL: " << roll << endl;
        cout << "NAME: " << name << endl;
        cout << "PHONE: " << phn << endl
             << endl;
    }
    void select_subject(int code)
    {
        for (int i = 0; i < MAX_SUBJECTS; i++)
        {
            if (subjects[i] == code)
            {
                cout << "Code already selected!\n";
                return;
            }
            if (subjects[i] == -1)
            {
                subjects[i] = code;
                return;
            }
        }
        cout << "Already Selected Maximum subjects!" << endl;
    }

    void display_subjects()
    {
        cout << "Subject Codes for " << roll << ": ";
        int i;
        for (i = 0; i < MAX_SUBJECTS && subjects[i] != -1; i++)
        {
            cout << subjects[i] << ", ";
        }
        if (i == 0)
        {
            cout << "No subjects selected!\n";
            return;
        }
        cout << endl;
    }

    friend void STUDENT_LIST::add_student(int, int, char *);
    friend void STUDENT_LIST::select_subject(SUBJECT_LIST *, int, int);
    friend void STUDENT_LIST::display_subjects(int);
    friend void STUDENT_LIST::display_students(int);
};

STUDENT_LIST::STUDENT_LIST(int n = 10)
{
    students = new STUDENT[n];
}

void STUDENT_LIST::add_student(int r, int ph, char nm[])
{
    for (int i = 0; i <= last_ind; i++)
    {
        if (students[i].roll == r)
        {
            cout << "Roll already present!!\n";
            return;
        }
    }
    students[++last_ind].set_data(r, ph, nm);
}

void STUDENT_LIST::display_list()
{
    cout << "Displaying Student List\n";
    for (int i = 0; i <= last_ind; i++)
    {
        students[i].display();
    }
}

void STUDENT_LIST::display_subjects(int roll)
{
    for (int i = 0; i <= last_ind; i++)
    {
        if (students[i].roll == roll)
        {
            students[i].display_subjects();
        }
    }
}

void STUDENT_LIST::display_students(int code)
{
    cout << "Displaying student rolls for subject code " << code << ": ";
    for (int i = 0; i <= last_ind; i++)
    {
        for (int j = 0; j < MAX_SUBJECTS; j++)
        {
            if (students[i].subjects[j] == code)
            {
                cout << students[i].roll << ", ";
            }
        }
    }
    cout << endl;
}

class SUBJECT;

class SUBJECT_LIST
{
    SUBJECT *subjects;

public:
    static int last_ind;
    SUBJECT_LIST(int);
    void add_subject(int, char *);
    void display_list();
    friend void STUDENT_LIST::select_subject(SUBJECT_LIST *, int, int);
};

int SUBJECT_LIST::last_ind = -1;

class SUBJECT
{
    int code;
    char name[30];

public:
    void set_data(int c, char nm[])
    {
        code = c;
        strcpy(name, nm);
        return;
    }
    void display()
    {
        cout << "CODE: " << code;
        cout << "  NAME: " << name << endl;
    }
    friend void SUBJECT_LIST::add_subject(int, char *);
    friend void STUDENT_LIST::select_subject(SUBJECT_LIST *, int, int);
};

SUBJECT_LIST::SUBJECT_LIST(int n = 10)
{
    subjects = new SUBJECT[n];
}

void SUBJECT_LIST::add_subject(int c, char nm[])
{
    for (int i = 0; i <= last_ind; i++)
    {
        if (subjects[i].code == c)
        {
            cout << "Code already present!!\n";
            return;
        }
    }
    subjects[++last_ind].set_data(c, nm);
}

void SUBJECT_LIST::display_list()
{
    cout << "Displaying Subject List\n";
    for (int i = 0; i <= last_ind; i++)
    {
        subjects[i].display();
    }
}

void STUDENT_LIST::select_subject(SUBJECT_LIST *sl, int code, int roll)
{
    int fl = 0;
    for (int i = 0; i <= (*sl).last_ind; i++)
    {
        if (sl->subjects[i].code == code)
            fl = 1;
    }
    if (fl == 0)
    {
        cout << "Subject not found!!\n";
        return;
    }
    for (int i = 0; i <= last_ind; i++)
    {
        if (students[i].roll == roll)
        {
            students[i].select_subject(code);
        }
    }
}

int main()
{
    STUDENT_LIST sl;
    sl.add_student(1001, 11111111, "Swadesh");
    sl.add_student(1002, 11111112, "Ritesh");
    sl.display_list();
    SUBJECT_LIST subl;
    subl.add_subject(101, "CSE");
    subl.add_subject(101, "BCSE");
    subl.add_subject(102, "ECE");
    subl.add_subject(103, "EE");
    subl.display_list();
    sl.select_subject(&subl, 100, 1001);
    sl.select_subject(&subl, 101, 1001);
    sl.select_subject(&subl, 102, 1002);
    sl.select_subject(&subl, 102, 1001);
    sl.display_subjects(1001);
    sl.display_students(102);
    return 0;
}