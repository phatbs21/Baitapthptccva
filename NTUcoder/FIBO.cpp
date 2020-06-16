#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, i;
    int a[35];
    cin>>n;
    a[1] = 1; a[2] = 1;
    for (i = 3; i <= n; i++)
        a[i] = a[i-1] + a[i-2];
    for (i = 1; i <= n; i++) cout << a[i] <<" ";
    return 0;
}
    