#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unsigned char a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unsigned char x, c, h, m;
    m = 0;
    h = 0;
    for (int i = 0; i < n; i++)
    {
        x = a[i];
        h = h | (x & m);
        m = m ^ x;
        c = m & h;
        h = h ^ c;
        m = m ^ c;
    }
    cout << m;
}