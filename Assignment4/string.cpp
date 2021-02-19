#include<iostream>
#include<string.h>
using namespace std;

class String
{
    int size;
    char *ptr;
    public:
    String(int s=0)
    {
        size=s;
        if(size>0)
        {
            ptr=new char[size];
        }
        else
        {
            ptr=NULL;
        }
        
    }
    String(char* a)
    {
        size=strlen(a);
        if(size!=0)
        {
            ptr=new char[size];
            if(ptr!=NULL)
            {
                strcpy(ptr,a);
            }
        }
        else
        {
            ptr=NULL;
        }  
    }
    String(const String &s)
    {
        size=s.size;
        if (size > 0)
        {
            ptr=new char[size];
            strcpy(ptr,s.ptr);
        }
        else
        {
            ptr = NULL;
        }
    }
   
    String operator+(String &s1)
    {
        int len = 0, i = 0;
        String s(size+s1.size);
        for(i=0;ptr[i] != '\0';i++)
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
    friend ostream& operator<<(ostream &os,String &s)
    {
        os<<s.ptr<<endl;
        return os;
    }
    bool operator==(String &s)
    {
        for(int i=0;s.ptr[i]!='\0';i++)
        {
            if(ptr[i]!=s.ptr[i])
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
        cout<<"....";
        delete[] ptr;
    }  
};

int main()
{
    String s1(1);
    String s2("rita");
    String s3("swa");
    String s4=s2+s3;
    cout<<s1;
    cout<<s4;
    return 0;
}

