#include <iostream>
using namespace std;
void f(int a,int b)
{
    cout<<"int\n";
}
void f(char a, char b)
{
    cout << "char\n";
}
int main()
{
    int i=9;
    char c='i';
    f(i,c);
}
