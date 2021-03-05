#include <bits/stdc++.h>
using namespace std;
int luu[10001], mind[10001];
int a[10001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mind[a[i]] = 0;
    }
    mind[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int minn = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if ((mind[i - a[j]] + 1) < minn && a[j] <= i)
            {
                minn = mind[i - a[j]] + 1;
                luu[i] = j;
            }
            mind[i] = minn;
        }
    }
    cout << mind[m] ;
}
/*
5 9 1 2 3 4 5
*/