#include <bits/stdc++.h>
using namespace std;
#define NAME "k-max"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, m, k;
    fi >> n >> m >> k;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fi >> a[i][j];
            
}