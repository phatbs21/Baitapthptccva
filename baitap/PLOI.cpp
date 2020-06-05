#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int b[101], dem = 0;
    queue<int> q;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= m; i++)
    {
        cin >> dem;
        b[dem]++;
        if (b[dem] == 3)
        {
            b[dem] = 0;
            q.push(dem);
        }
    }
    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}