#include<iostream>
#include<string.h>
using namespace std;

class Array
{
    int *ptr;
    int size;
    int *p_count;
    public:
    //constructor with default size=0
    Array(int size=0)
    {
        if(size>0)
        {
            size=size;
            ptr=new int[size];
            for(int i=0;i<size;i++)
            {
                ptr[i]=0;
            }
        }
        else
        {
            ptr=NULL;
            size=0;
        }   
    }
    //copy constructor
    Array(const Array &a)
    {
        if(a.size==0)
        {
            ptr=NULL;
            size=0;
        }
        else
        {
            size=a.size;
            for(int i=0;i<size;i++)
            {
                ptr[i]=a.ptr[i];
            }
        }
    }
    friend istream& operator>>(istream &is, Array &a)
    {
        for (int i = 0; i < a.size; i++)
            is >> a.ptr[i];
        
    }
    friend ostream& operator<<(ostream &os, Array a)
    {
        for (int i = 0; i < a.size; i++)
            os << a.ptr[i] << " ";
    }
    void operator=(Array &a)
    {
        size = a.size;
        if(size!=0)
        {
            ptr=new int[size];
            for(int i=0;i<size;i++)
            {
                ptr[i]=a.ptr[i];
            }
        }
        else
        {
            ptr=NULL;
        }
        
    }
    friend Array operator+(Array &a, Array &b)
    {
        Array c(a.size > b.size ? a.size : b.size);
        if (a.size < b.size)
        {
            for (int i = 0; i < a.size; i++)
                c.ptr[i] = a.ptr[i] + b.ptr[i];
            for (int i = a.size; i < b.size; i++)
                c.ptr[i] = b.ptr[i];
        }
        else
        {
            for (int i = 0; i < b.size; i++)
                c.ptr[i] = a.ptr[i] + b.ptr[i];
            for (int i = b.size; i < a.size; i++)
                c.ptr[i] = b.ptr[i];
        }
        return c;
    }
    Array friend operator*(int a, Array arr)
    {
        Array b(arr.size);
        for(int i=0;i<b.size;i++)
        {
            b.ptr[i]=arr.ptr[i]*a;
        }
        return b;
    }
    Array operator*(int a)
    {
        Array b(size);
        for (int i = 0; i < b.size; i++)
        {
            b.ptr[i] = ptr[i] * a;
        }
        return b;
    }
    int operator[](int id)
    {
        return ptr[id];
    }
};

int main()
{
    Array a1(5);
    cin>>a1;
    cout<<a1;
    Array a2,a3(a1);
    cout<<a3;
    return 0;
}