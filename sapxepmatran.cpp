#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int q[10000];
void spiralFill(int m, int n, int a[][MAX])
{
    int val = 1;

    int k = 0, l = 0;
    while (k < m && l < n)
    {
        for (int i = l; i < n; ++i)
            a[k][i] = q[val++];
        k++;
        for (int i = k; i < m; ++i)
            a[i][n - 1] = q[val++];
        n--;
        if (k < m)
        {
            for (int i = n - 1; i >= l; --i)
                a[m - 1][i] = q[val++];
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; --i)
                a[i][l] = q[val++];
            l++;
            
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        cin >> q[i];
    }
    sort(q + 1, q + n * n + 1);
    int m = n;
    int a[MAX][MAX];
    spiralFill(m, n, a);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}


/*
5
16 22 13 4 5
11 15 19 23 14 
25 21 20 2 7
6 24 17 18 8
3 1 12 10 9
*/