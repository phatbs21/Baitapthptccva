#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int k;
    cin>>k;
    int a=k,b=k,c=k;
    int tong=0;
    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=b;j++)
        {
            for (int k=1;k<=c;k++)
            {
                tong+=__gcd(__gcd(i,j),k);
            }
        }
    }
    cout<<tong;
}