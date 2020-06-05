#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int w = 1; w <= t; w++)
    {
        int n;
        cin >> n;
        int a[n + 1];
        int chan = 0, le = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                chan++;
            }
            else
            {
                le++;
            }
        }
        if (((chan==0) && (le%2==0))||(le==0))
        {
            cout<<"No"<<endl;
        }
        else 
        {
            cout<<"Yes"<<endl;
        }
    }
}
