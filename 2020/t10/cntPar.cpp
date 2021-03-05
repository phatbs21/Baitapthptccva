#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int main()
{
    freopen("cntPar.inp", "r", stdin);
    freopen("cntPar.out", "w", stdout);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    map<pair<int, int>, int> tinh;
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int X = a[i] + a[j];
            int Y = b[i] + b[j];
            tinh[make_pair(X, Y)]++;
        }
    }
    for (auto it = tinh.begin(); it != tinh.end(); it++)
    {
        int t = it->second;
        tong += t * (t - 1) / 2;
    }
    cout << tong;
}
