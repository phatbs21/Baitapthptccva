#include <bits/stdc++.h>
using namespace std;
int h[4001];
int  maxs(int a,int b)
{
    int H=-1;
    for (int i=a; i<b;i++)
    {
        H=max(h[i],h[i+1]);
    }
    return H;
}
int s(int a,int b)
{
    long long int q=0;
    for(int i=a;i<b;i++)
        q+=h[i];
        return q; 
}
int main()
{
    freopen("tesst.inp","r",stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    int f[100][100];
    for (int i=1;i<=n;i++)
    {
        f[i][0]=i*maxs(1,i) - s(1,i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int u=0;u<i;u++)
            {
                f[i][j]=min(f[u][j-1],(i-u)*maxs(u,i)-s(u+1,i));
            }
        }
    }
    cout<<f[n][k];
}