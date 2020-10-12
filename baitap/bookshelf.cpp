#include <bits/stdc++.h>
using namespace std;
#define w second
#define h first
int main()
{
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int q, e;
        cin >> q >> e;
        a[i].w = q;
        a[i].h = e;
    }
    sort(a.begin(), a.end());
    int tang = 0, tong = 0;
    int f[1000][1000];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l; j++)
            for (int k = 0; k < i; k++)
            {
                
            }
}