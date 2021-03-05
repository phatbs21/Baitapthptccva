#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n, m, s = "9";
    cin >> n >> m;
    int a[100];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m.length(); i++)
    {
        a[m[i]]++;
    }
    for (int i = 0; i < n.length(); i++)
    {
        while (s[0] > 48 && a[s[0]] == 0)
            s[0] = char(s[0] - 1);
        if (s[0] == 48)
            break;
        if (n[i] < s[0])
        {
            n[i] = s[0];
            a[s[0]]--;
        }
    }
    cout << n;
}