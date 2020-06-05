#include <bits/stdc++.h>
using namespace std;
long long a,b;
int tinh (long long n)
{
    long long k=0;
    for (int i=1; i<=n/2; i++)
    {
        if ((n%i)==0) k+=i;
    }
    return k;
}
int main ()
{
    cin >>a>>b;
    if ( tinh (a) == b && tinh (b) == a ) cout << "YES";
    else cout << "NO";
}

