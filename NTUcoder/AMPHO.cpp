#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int g = m - i + 1;
        for (int j = 1; j <= n; j++)
            if (a[j] < g)
            {
                cout << ".";
            }
            else
            {
                cout << "#";
            }
        cout << endl;
    }
}