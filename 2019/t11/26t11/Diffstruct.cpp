#include <bits\stdc++.h>
using namespace std;
struct TOADO
{
    int diff,maxv,minv;
};
TOADO tinh(int a[], int x, int y)
{
    TOADO kq;
    if (x == y)
    {
        kq={0,a[x],a[x]};
    }
    else
    {
        int k = (x + y) / 2;
        TOADO d1=tinh(a,x,k);
        TOADO d2=tinh(a,k+1,y);
        kq.maxv=max(d1.maxv,d2.maxv);
        kq.minv=min(d1.minv,d2.minv);
        kq.diff=max(max(d1.diff,d2.diff),d2.maxv-d1.minv);
    }
    return kq;
}
int main()
{
    freopen("dulieu.inp", "r", stdin);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    TOADO kq=tinh(a,0,n-1);
    cout<<kq.diff;
}