#include <bits/stdc++.h>
using namespace std;
vector<bool> path(300005, false);
vector<int> v;
void dfs(int u)
{
    path[u] = true;
    v.push_back(u);
    for (int i = 1; i <= sqrt(u); i++)
    {
        if (u % i == 0)
            if ((i - 1) * (u / i + 1) != 0)
                if (path[(i - 1) * (u / i + 1)] == false)
                {
                    dfs((i - 1) * (u / i + 1));
                }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    dfs(n);
    //v.push_back(0);
    cout << v.size() << "\n";
    v.push_back(0);
    sort(v.begin(), v.end());
    v.pop_back();
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}