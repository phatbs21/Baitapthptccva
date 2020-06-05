#include <bits\stdc++.h>
using namespace std;
int main()
{
    int m=-23,n=5;
    //cin>>m>>n;
    int d=__gcd(m,n);
    m=m/d;
    n=n/d;
    double kq=static_cast<double>(m)/n;
    cout<<kq;
}