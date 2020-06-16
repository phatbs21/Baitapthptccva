#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int k;
    cin >> s >> k;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    for (int i = s.size() - 1; i >= k; i--)
    {
        cout << s[i];
    }
}