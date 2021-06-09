#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> c(50, vector<int>(50, 0));
    for (int i = 0; i <= 34; i++)
        c[0][i] = 1;
    for (int i = 1; i <= 34; i++)
        for (int j = 1; j <= 34; j++)
            c[i][j] = c[i - 1][j - 1] + c[i][j];
    for (int i = 0; i <= 34; i++)
    {
        for (int j = 0; j <= 34; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    int n, m;
    // while (cin >> n >> m)
    {
    }
}