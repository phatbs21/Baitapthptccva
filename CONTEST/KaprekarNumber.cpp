#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        string s = to_string(n);
        sort(s.begin(), s.end(), greater<char>());
        stringstream geek(s);
        int x = 0;
        geek >> x;
        sort(s.begin(), s.end());
        stringstream geek1(s);
        int z = 0;
        geek1 >> z;
        n = x - z;
        if (n == 0)
        {
            cout << 0;
            return 0;
        }
    }
    cout << n;
}