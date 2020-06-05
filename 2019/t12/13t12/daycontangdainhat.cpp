#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1000];
    int jmax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int c[1000];
    c[1] = 1;
    c[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        jmax = 0;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && c[j] > c[jmax])
                jmax = j;
        c[i] = c[jmax] + 1;
    }
    int k = 1;
    for (int i = 2; i <= n; i++)
    {
        if (c[k] < c[i])
            k = i;
    }
    stack<int> s;
    while (c[k] > 1)
    {
        s.push(a[k]);
        for (int i = 1; i < k; i++)
        {
            if ((a[i] < a[k]) and (c[i] == (c[k] - 1)))
            {
                //cout << a[i] << " ";
                k = i;
                break;
            }
        }
    }
    s.push(a[k]);
    for (int i = s.size(); i >= 0; i--)
    {
        cout << s.top();
        s.pop();
    }
}