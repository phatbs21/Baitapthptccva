#include <bits/stdc++.h>
using namespace std;
int n, s, d;
int a[21];
vector<int> v[1000001];
bool x[21] = {0};
void chia(int i)
{
    if (i > n)
    {
        int s1 = 0;
        for (int i = 1; i <= n; i++)
            s1 += x[i] * a[i];
        if (s1 == s / 2)
        {
            d++;
            for (int i = 1; i <= n; i++)
                v[d].push_back(x[i]);
        }
        return;
    }
    x[i] = 0;
    chia(i + 1);
    x[i] = 1;
    chia(i + 1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    chia(1);
    if (d == 0 || s % 2 == 1)
    {
        cout << "khong chia duoc";
        return 0;
    }
    cout << d << "\n";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            if (v[i][j] == 0)
                cout << "A ";
            else
                cout << "B ";
        cout << endl;
    }
    return 0;
}
