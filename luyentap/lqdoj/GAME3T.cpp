#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<pair<int, int>> q;
int n;
void subtask1()
{
    for(int i=0)
}
int main()
{
    cin >> n;
    a.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                q.push_back({i, j});
        }
    }
    subtask1();
}