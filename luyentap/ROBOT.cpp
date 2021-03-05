#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, p, k;
    cin >> m >> n >> p >> k;
    string s;
    cin >> s;
    vector<vector<int>> check(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        check[x][y] = 1;
    }
    int x = 1, y = 1;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'R' && y < n)
            if (check[x][y + 1] == 0)
                y++;
        if (s[i] = 'L' && y > 1)
            if (check[x][y - 1] == 0)
                y--;
        if (s[i] == 'U' && x < m)
            if (check[x - 1][y] == 0)
                x--;
        if (s[i] = 'D' && x > 1)
            if (check[x + 1][y] == 0)
                x++;
    }
    cout << x << " " << y;
}
