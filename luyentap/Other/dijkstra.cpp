
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<int> MinPath;
vector<int> From;
vector<bool> Free;

int m, n, s, e;

void DIJKSTRA()
{
    int u;
    do
    {
        u = e;
        for (int i = 1; i <= n; i++)
            if (Free[i] == false && MinPath[u] > MinPath[i])
            {
                u = i;
            }
        Free[u] = true; //Gan nhan cho dinh G co' dinh

        if (MinPath[u] == INT_MAX || u == e)
            break;

        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && !Free[v])
            {
                if (a[u][v] + MinPath[u] < MinPath[v])
                {
                    MinPath[v] = a[u][v] + MinPath[u];
                    From[v] = u;
                }
            }
        }
    } while (true);
}

void TruyVet(int end)
{
    int u = end;
    vector<int> vet;
    while (u != s)
    {
        vet.push_back(u);
        u = From[u];
    }
    vet.push_back(s);
    cout << "Vet:";
    for (int i = vet.size() - 1; i >= 0; i--)
        cout << vet[i] << " ";
    cout << "\n";
}

int main()
{
    cin >> n >> m >> s >> e;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++)
        a[i].resize(n + 1);
    MinPath.resize(n + 1);
    Free.resize(n + 1);
    From.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;
        a[u][v] = a[v][u] = p;
    }

    //Gan duong di ngan nhat = MAXX
    for (int i = 1; i <= n; i++)
        MinPath[i] = INT_MAX;
    MinPath[s] = 0;
    DIJKSTRA();
    if (MinPath[e] == INT_MAX)
        cout << "Khong co duong di!";
    else
        cout << "Duong di ngan nhat la: " << MinPath[e];
    cout << "\n";
    TruyVet(e);
}
