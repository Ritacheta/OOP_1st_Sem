#include<iostream>
using namespace std;

class Complex
{
    int r,im;
    public:
    Complex(int real=0,int imaginary=0)
    {
        r=real;
        im=imaginary;
    }
    friend istream& operator>>(istream &is, Complex &c)
    {
        cout << "enter the real->";
        is >> c.r;
        cout << "enter the imaginary part->";
        is >> c.im;
    }
    friend ostream& operator<<(ostream &os, Complex c)
    {
        os << "real->";
        os << c.r << "imaginary" << c.im << endl;
    }
    Complex operator+(Complex c)
    {
        Complex out;
        out.r=r+c.r;
        out.im=im+c.im;
        return out;
    }
    Complex operator-(Complex c)
    {
        Complex out;
        out.r = r - c.r;
        out.im = im - c.im;
        return out;
    }
    
};

int main()
{
    Complex c1;
    cin>>c1;
    cout<<c1;
    Complex c2(6,8);
    Complex c3=c1+c2;
    cout<<c3;
    Complex c4=c3-c2;
    cout<<c4;
    return 0;
}