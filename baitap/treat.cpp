#include <bits/stdc++.h>
using namespace std;
int n, x, v, cnt = 0;
bool flag = false;
stack<int> S;
vector<int> a, visit, nex;

void detect(int u)
{
    cnt++;
    visit[u] = cnt;
    S.push(u);
    for (;;)
    {
        //tim goc
        v = nex[u];
        if (visit[v] != 0)
        {
            if (a[v] != 0)
                x = a[v] + 1;
            else
                x = visit[u] - visit[v] + 1;
            if (a[v] == 0)
                flag = false;
            while (!S.empty())
            {
                int temp = S.top();
                a[temp] = x;
                if (temp == v)
                    flag = true;
                if (flag == true)
                    x++;
                S.pop();
            }
            break;
        }
        else
        {
            cnt++;
            visit[v] = cnt;
            S.push(v);
            u = v;
        }
    }
}

int main()
{
    cin >> n;
    a.resize(n);
    visit.resize(n);
    nex.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nex[i];
        nex[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
            detect(i);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
}
