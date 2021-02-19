#include<iostream>
using namespace std;

template<class X>
class Array
{
    X* arr;
    int size;
    public:
    Array(int s=0)
    {
        if(s==0)
        {
            arr= NULL;
            size=0;
        }
        else
        {
            size=s;
            arr=new X[size];
        }   
    }
    Array(X array[],int s)
    {
        if(s!=0)
        {
            size=s;
            arr=new X[size];
            for(int i=0;i<size;i++)
            {
                arr[i]=array[i];
            }
        }
        size=0;
        arr=NULL;
    }
    void get_elements()
    {
        cout << "enter the elements of the array:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    X get_max()
    {
        X max = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (max < arr[i])
                max = arr[i];
        }
        return max;
    }
    X get_sum()
    {
        X sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
    ~Array()
    {
        delete[] arr;
        cout<<"destroyed\n";
    }
};
template<>
char Array<char>::get_sum()
{
    cout<<"not possible\n";
    return '\0';
}
int main()
{
    Array<char> c1(5);
    c1.get_elements();
    char p1=c1.get_max();
    char q1=c1.get_sum();
    cout << "max  sum :\n" <<q1 << "\n"
         << p1 << endl;
    return 0;
}