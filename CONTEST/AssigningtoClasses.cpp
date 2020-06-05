#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        int n,min=0;
        cin >> n;
        int a[2 * n + 2];
        for (int i = 1; i <= 2*n; i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+2*n+1);
        cout<<a[n+1]-a[n]<<endl;
    }
}