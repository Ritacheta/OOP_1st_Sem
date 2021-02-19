#include<iostream>
using namespace std;

void f(int a)
{
    cout<<"inside f(int)"<<endl;
}

void f(float b)
{
    cout<<"inside f(float)"<<endl;
}

int main()
{
    f(1);
    f('a');
    float e=1.0;
    f(e);
    return 0;
}