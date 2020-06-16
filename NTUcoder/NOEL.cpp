#include <bits/stdc++.h>
using namespace std;
void noel(int n, int m)
{
    for (int i = 1; i <= n + 2 - 1; i++)
        cout << ".";
    cout << "#";
    for (int i = 1; i <= n + 2 - 1; i++)
        cout << ".";
    cout << endl;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n + 2 - i; j++)
            cout << ".";
        cout << "#";
        for (int j = 1; j <= (i - 1) * 2 - 1; j++)
            cout << "x";
        cout << "#";
        for (int j = 1; j <= n + 2 - i; j++)
            cout << ".";
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m = n;
    noel(n, m);
    noel(n, m + 1);
    noel(n, m + 2);
}
