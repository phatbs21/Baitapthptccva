#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        f[i] = (f[i - 1] + a[i]) % m;
        cout<<f[i]<<" ";
    }
   
}