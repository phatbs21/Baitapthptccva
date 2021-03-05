#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int bd = 1, kt = 1, leg = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i - 1])
            kt = i;
        else
        {
            bd = i;
            kt = i;
        }
        leg = max(leg, kt - bd);
    }
    cout << leg + 1;
}