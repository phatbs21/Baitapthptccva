#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, M;
    cin>>n>>M;
    int a[n + 1];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int tong=0;
    for (int i=1;i<=n-2;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            for (int k=j+1;k<=n;k++)
            {
                tong+= (a[i]*a[j]*a[k])%5;
            }
        }
    }
    cout<<tong%M;
}
