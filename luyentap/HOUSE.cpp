#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
            a[i] = 0;
        if (s[i] == 'V')
            a[i] = 1;
        if (s[i] == 'X')
            a[i] = 2;
        if (s[i] == 'T')
            a[i] = 3;
    }
    int dem = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        if (a[i] == a[i + 1])
        {

            dem++;
            if (i > 0)
                temp = a[i - 1];
            if (i < n - 2)
                if (a[i + 1] == a[i + 2])
                    a[i + 1] = temp;
        }
    }
    cout << dem;
}