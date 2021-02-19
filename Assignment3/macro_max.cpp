#include<iostream>
using namespace std;

#define max(x, y) ((x > y) ? x : y)
int main()
{

    int a, b;
    cout<< "enter the value of a and b:" ;
    cin >> a;
    cin >> b;
    cout << "maximum of them is:"<<max(a, b)<<endl;
    cout<<"max: "<<max('rita','swa')<<endl;
};