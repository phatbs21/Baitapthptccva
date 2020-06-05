#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<long long> q;
    char s;
    int n, w, dem, tam;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s == 'A')
        {
            cin >> w;
            q.push(w);
        }
        else
        {
            if (!q.empty())
            {
                dem = 1;
                tam = q.top();
                q.pop();
                while ((q.top() == tam) && (!q.empty()))
                {
                    dem++;
                    q.pop();
                }
                cout << tam << " " << dem << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    if (q.size() == 0)
    {
        cout << "-1";
        return 0;
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
}