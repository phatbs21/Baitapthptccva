#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int bfs(int u)
{
}
int ktshh(int x)
{
    int s = 0;
    for (int i = 1; i <= x / 2 + 1; i++)
        if (x % i == 0)
            s += i;
    if (x == s)
        return s;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    int x = ktshh(n);
    if (ktshh(n) != 0)
        cout << n << " la so hoan hao";
    else
        cout << n << " khong phai la so hoan hao";
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << "tong cac uoc la:" << x;
}
int main()
{
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
}