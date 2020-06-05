#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
bool S[1000000];
int p[10000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, WA = 0, AC = 0;
    string s;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> s;
        if (S[a] == false)
        {
            if (s == "WA")
                p[a]++;
            else
            {
                AC++;
                S[a] = true;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (S[i] == true)
            WA += p[i];
    }
    cout << AC << " " << WA;
}