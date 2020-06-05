#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct duongthang
    {
        int a;
        int b;
        int c;
    };
    freopen("LINES.inp", "r", stdin);
    int n;
    cin >> n;
    duongthang s[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].a >> s[i].b >> s[i].c;
    }
    int dem = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int A, B, C;
            A = 0;
            B = 0;
            if (s[j].a != 0 && s[j].b != 0)
            {
                A = (s[i].a / s[j].a);
                B = (s[i].b / s[j].b);
            }
            else
            {
                dem++  ;
            }
            if (A != B)
            {
                dem++;
            }
        }
    }
    cout << dem;
}