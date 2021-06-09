#include<bits/stdc++.h>
using namespace std;
int a[1000000],minn[1000000],maxx[1000000],vtma[1000000],vtmi[1000000],n;
void nhap()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}
void xuat()
{
    maxx[n+1]=0;
    minn[0]=INT_MAX;
    for (int i=1;i<=n;i++) 
    {
        if(minn[i-1]>a[i]) vtmi[i]=i; else vtmi[i]=vtmi[i-1];
        minn[i]=min(minn[i-1],a[i]);
    }
    for (int i=n;i>=1;i--) 
    {
        if (maxx[i-1]<a[i]) vtma[i]=i; else vtma[i]=vtma[i-1];
        maxx[i]=max(maxx[i-1],a[i]);
    }
    int ans=0,d,c;
    for (int i=1;i<=n;i++)
    if (maxx[i]-minn[i]>ans && vtmi[i]!=vtma[i])
    {
        ans=maxx[i]-minn[i];
        d=vtmi[i];
        c=vtma[i];
    }
    cout<<min(d,c)<<" "<<max(d,c)<<endl;
    cout<<ans;
}
int main()
{
    nhap();
    xuat();
}