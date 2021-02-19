#include<iostream>
using namespace std;
 
float income(float income, float taxrate=0.1)
{
    return (income*taxrate);
}

int main()
{
    float a,b;
    cout<<"enter income:";
    cin>>a;
    cout<<"tax ="<<income(a)<<endl;
    cout<<"enter income and tax rate respectively:";
    cin>>a>>b;
    cout<<"tax = "<<income(a,b);
    return 0;
}