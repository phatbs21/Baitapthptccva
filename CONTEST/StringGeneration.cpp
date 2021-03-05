#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s, s1;
        int i, dem = k, j;
        for (i = 1; i <= dem && i <= n; i++)
            s += "a";
        for (i = dem + 1; i <= dem * 2 && i <= n; i++)
        {
            s += "b";
        }
        for (i = dem * 2 + 1; i <= dem * 3 && i <= n; i++)
        {
            s += "c";
        }
        while (s.length() < n)
            s = s + s;
        s.erase(n, s.length() - n);
        cout << s << "\n";
    }
}