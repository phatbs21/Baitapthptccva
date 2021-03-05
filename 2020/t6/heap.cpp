#include <bits/stdc++.h>
using namespace std;
int n, d, ln;
int h[100], a[100];
void pushheap(int x)
{
    n++;
    h[n] = x;
    d = n;
    while (h[d] > h[d / 2] && d > 1)
    {
        swap(h[d], h[d / 2]);
        d = d / 2;
    }
    return;
}
void heapify(int e)
{
    if ((2 * e) > n)
        return;
    ln = e;
    if (h[2 * e] > h[e])
        ln = (2 * e);
    if ((((2 * e) + 1) <= n) && (h[(2 * e) + 1] > h[ln]))
        ln = (2 * e) + 1;
    if (ln > e)
    {
        swap(h[e], h[ln]);
        heapify(ln);
    }
    return;
}
int main()
{
    freopen("input.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    /*
    int a;
    cin>>a;
    pushheap(a);
    for(int i=1;i<=n;i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    */
    h[1] = h[n];
    n--;
    heapify(1);
    for (int i = 1; i <= n; i++)
    {
        cout << h[i] << " ";
    }
}
