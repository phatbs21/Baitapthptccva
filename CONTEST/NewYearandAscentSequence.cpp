#include <bits/stdc++.h>
using namespace std;
int kt(int a[]);

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
            int s[n + 1][n + 1000];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int s[n + 1][a[i] + 1];
        for (int j = 1; j <= a[i]; j++)
        {
            cin >> s[i][j];
        }
    }
    
}
int kt(int a[])
{
    
}