#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s = 0, k = 0;
    string s2;
    cin >> s2;
    for (int i = 0; i < s2.size(); i++)
    {
        k = int(s2[i]) - 48;
        s = s + k;
    }
    while (s >= 10)
    {
        long long int tong = 0;
        while (s > 0)
        {
            tong = tong + s % 10;
            s = s / 10;
        }
        s = tong;
    }
    cout << s;
}
