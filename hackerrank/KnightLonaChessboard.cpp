#include <bits/stdc++.h>
using namespace std;
int n;
// bo, dung bfs xet duyet tat ca truong hopw
vector<vector<int>> a(26, vector<int>(26, 0));
vector<vector<int>> kt(26, vector<int>(26, 0));

bool check = false;
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dem = 0;
void inmang()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                a[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
void quaylui(int i, int j)
{
    dem++;
    kt[i][j] = dem;
    for (int x = 0; x < 8; x++)
    {
        if (dem == n * n)
        {
            inmang();
            exit(0);
        }
        int u = i + X[x];
        int v = j + Y[x];
        if (u >= 0 && u < n && v >= 0 && v < n && kt[u][v] == 0)
        {
            a[i][j]++;
            quaylui(u, v);
        }
    }
    dem--;
    kt[i][j] = 0;
}
int main()
{
    cin >> n;
    quaylui(0, 0);
}