#include <iostream>
#include <string.h>
using namespace std;

class String
{
    int size;
    char *ptr;
    int *p;

public:
    String(int s = 0)
    {
        size = s;
        p = new int;
        *p = 1;
        if (size > 0)
        {
            ptr = new char[size];
        }
        else
        {
            ptr = NULL;
        }
    }
    String(char *a)
    {
        size = strlen(a);
        if (size != 0)
        {
            p = new int;
            *p = 1;
            ptr = new char[size];
            if (ptr != NULL)
            {
                strcpy(ptr, a);
            }
        }
        else
        {
            ptr = NULL;
        }
    }
    String(const String &s)
    {
        size = s.size;
        if (size > 0)
        {
            ptr=s.ptr;
            strcpy(ptr, s.ptr);
        }
        else
        {
            ptr = NULL;
        }
        (*p)++;
    }

    String operator+(String &s1)
    {
        int len = 0, i = 0;
        String s(size + s1.size);
        for (i = 0; ptr[i] != '\0'; i++)
        {
            s.ptr[len++] = ptr[i];
        }
        for (i = 0; s1.ptr[i] != '\0'; i++)
        {
            s.ptr[len++] = s1.ptr[i];
        }
        s.ptr[len] = '\0';
        return s;
    }
    friend ostream &operator<<(ostream &os, String &s)
    {
        os << s.ptr << endl;
        return os;
    }
    bool operator==(String &s)
    {
        for (int i = 0; s.ptr[i] != '\0'; i++)
        {
            if (ptr[i] != s.ptr[i])
                return false;
        }
        return true;
    }
    bool operator<(String &s)
    {
        int i = 0;
        bool flag = false;
        while (s.ptr[i] != '\0')
        {
            if (s.ptr[i] != ptr[i])
            {
                flag = true;
                break;
            }
            i++;
        }
        if (flag == false)
            return false;
        else
        {
            if (ptr[i] < s.ptr[i])
                return true;
            else
                return false;
        }
    }
    ~String()
    {
        *p--;
        cout << ".....";
        if (*p == 0)
        {
            delete p;
            delete[] ptr;
        }
    }
};

int main()
{
    String s1(1);
    char a1[] = "rita", a2[] = "swa";
    String s2(a1);
    String s3(a2);
    String s5(s2);
    String s4 = s2 + s3;
    cout<<s1;
    cout<<s2;
    cout<<s4;
    return 0;
}