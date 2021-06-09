#include <map>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, temp;
    cin >> n >> m;
    map<int, int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (q[temp] == 0)
            q[temp] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << q[temp] << " ";
    }
}
