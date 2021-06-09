#include <bits/stdc++.h>
using namespace std;
#define NAME "G_IN_OUT"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
#define cin fi
#define cout fo
#define time dasdasda
#define N 3000005
vector<int> g[N];
vector<bool> dung(N, false);
vector<int> time_in(N), time_out(N);
int time = 0;
void dfs(int v)
{
    time_in[v] = time++;
    dung[v] = true;
    for (auto &i : g[v])
    {
        if (dung[i] != true)
            dfs(i); 
    }
    dung[v] = true;
    time_out[v] = time++;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tm1, tm2;
        cin >> tm1 >> tm2;
        tm1--, tm2--;
        g[tm1].push_back(tm2);
        g[tm2].push_back(tm1);
    }
    dfs(0);
    //print array time
    for (int i = 0; i < n; i++)
    {
        cout << time_in[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << time_out[i] << " ";
    }
}