#include <bits/stdc++.h>
using namespace std;
#define NAME "Cards"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, ca, cb, dem = 0;
    queue<int> a, b;
    string kq;
    bool check = false;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        fi >> ca;
        if (ca == 0)
            ca = 2 * n + 1;
        a.push(ca);
    }
    for (int i = 0; i < n; i++)
    {
        fi >> cb;
        if (cb == 0)
            cb = 2 * n + 1;
        b.push(cb);
    }
    while (check != true)
    {
        ca = a.front();
        a.pop();
        cb = b.front();
        b.pop();
        if (ca > cb)
        {
            a.push(ca);
            a.push(cb);
        }
        else
        {
            b.push(cb);
            b.push(ca);
        }
        dem++;
        if (dem >= 1000000 || a.empty() || b.empty())
        {
            check = true;
        }
    }
    if (a.empty() == false)
        kq = "First";
    else
        kq = "Second";
    if (dem >= 1000000)
        fo << "Draw";
    else
    {
        fo << kq << " " << dem;
    }
    tocdo;
}