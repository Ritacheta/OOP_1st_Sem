#include<iostream>
using namespace std;

void f(int,int)
{
    cout<<"inside f(int,int)";
}
 void f(char,int)
 {
     cout << "inside f(char,int)";
 }
 main()
 {
     float a=1.0;
     float b=2.0;
     f(1,'a');
     f('d','e');
     f(a,b);
 }