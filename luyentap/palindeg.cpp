#include <bits/stdc++.h>
using namespace std;
int f[1001][1001];
bool check(string s, int i, int j)
{
    if (i > j)
        return 1;
    if (f[i][j] != -1)
        return f[i][j];
    if (s[i] != s[j])
        return f[i][j] = 0;
    return f[i][j] = check(s, i + 1, j - 1);
}

int kt(string s)
{
    memset(f, -1, sizeof(f));
    int n = s.length(), dem = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(s, i, j))
                dem++;
        }
    }
    return dem - n;
}

int main()
{
    string s;
    cin >> s;
    cout << kt(s);
}
