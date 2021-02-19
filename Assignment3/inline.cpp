#include <bits/stdc++.h>
using namespace std;

inline int product(int x,int y)
{
    return x*y;
}
int main()
{
    int a,b;
    cout<<"enter two integer values:"<<endl;
    cin>>a>>b;
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);
    cout<<"the product of two number is: "<<product(a,b)<<endl;
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5)<<endl;
    return 0;
}