#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    int x;
    cin>>x;
    for(i=7;i>=0;i--)
    {
        cout<<((x & (1<<i))>0 ? 1:0);
    }
}
